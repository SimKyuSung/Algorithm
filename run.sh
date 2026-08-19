#!/usr/bin/env bash
# 아카이브 문제(.cpp 하나 = 프로그램 하나) 를 빌드하고 실행한다.
# samsung_expert_kata/ 는 대상이 아니다 — 거기선 각 kata 의 Makefile 을 쓴다.
#
#   ./run.sh <소스.cpp> [입력파일]      디버그 빌드(sanitizer) 후 실행
#   ./run.sh -r <소스.cpp> [입력파일]   릴리즈 빌드(-O2, sanitizer 없음) + 시간 측정
#   ./run.sh -b <소스.cpp>              빌드만
#
# 입력파일을 생략하면 stdin 을 그대로 넘긴다 (직접 타이핑 / 파이프).

set -euo pipefail

# 산출물 위치는 실행 위치가 아니라 스크립트 위치를 기준으로 잡는다.
# 어느 디렉터리에서 부르든 <루트>/.build/run 하나로 모인다.
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
OUT_DIR="$ROOT/.build"
OUT="$OUT_DIR/run"

MODE=debug
BUILD_ONLY=0

while getopts ":rbh" opt; do
    case "$opt" in
        r) MODE=release ;;
        b) BUILD_ONLY=1 ;;
        h) sed -n '2,10p' "${BASH_SOURCE[0]}"; exit 0 ;;
        \?) echo "알 수 없는 옵션: -$OPTARG" >&2; exit 2 ;;
    esac
done
shift $((OPTIND - 1))

if [ $# -lt 1 ]; then
    echo "사용법: $0 [-r|-b] <소스.cpp> [입력파일]" >&2
    exit 2
fi

SRC="$1"
IN="${2-}"
[ -f "$SRC" ] || { echo "소스를 찾을 수 없다: $SRC" >&2; exit 2; }

# 시험 환경 기준이 C++14 다. 경고는 어느 모드에서도 끄지 않는다.
FLAGS=(-std=c++14 -Wall -Wextra)
if [ "$MODE" = release ]; then
    # 시간 판단은 반드시 이 모드에서만 한다 (MISTAKES M-004).
    FLAGS+=(-O2)
else
    # 배열 범위 초과와 UB 를 런타임에 잡는다. 대신 몇 배 느리므로 시간은 보지 않는다.
    FLAGS+=(-O1 -g -fsanitize=address,undefined)
fi

mkdir -p "$OUT_DIR"
g++ "${FLAGS[@]}" -o "$OUT" "$SRC"
echo "빌드 완료 ($MODE): $SRC" >&2

if [ "$BUILD_ONLY" = 1 ]; then
    exit 0
fi

# 비정상 종료(세그폴트 등)를 조용히 넘기지 않고 종료 코드를 찍어준다.
run_it() {
    local rc=0
    if [ -n "$IN" ]; then
        [ -f "$IN" ] || { echo "입력 파일을 찾을 수 없다: $IN" >&2; return 2; }
        "$OUT" < "$IN" || rc=$?
    else
        "$OUT" || rc=$?
    fi
    [ "$rc" -eq 0 ] || echo "종료 코드 $rc (비정상 종료)" >&2
    return "$rc"
}

if [ "$MODE" = release ]; then
    time run_it
else
    run_it
fi
