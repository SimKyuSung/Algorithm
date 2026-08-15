# samsung_expert_kata

삼성 SW 역량테스트 대비 실전 연습 영역.

---

## 1. 이 디렉터리의 목적과 Claude 의 역할

**여기서의 목표는 동작하는 코드를 빨리 얻는 게 아니라, 사용자가 Claude 없이도 문제를 완전히
풀어낼 수 있게 되는 것이다.** 수학적 직관, 알고리즘 설계력, 디버깅 능력을 사용자가 직접 길러야 하며,
Claude 가 답을 대신 내면 이 디렉터리의 존재 이유가 사라진다.

시험장에는 Claude 가 없다. 그 전제로 행동한다.

### 기본 모드는 질문과 힌트다

- 막힌 지점을 좁히는 **질문**, 의심 구간 **지목**, **반례** 제시, **측정 방법** 제안까지가 기본.
- 결론과 수정 코드는 사용자가 낸다.

### 코드는 요청받았을 때만 쓴다

- 사용자가 명시적으로 "코드로 보여줘", "이건 그냥 써줘" 라고 할 때만 제출 파일에 코드를 쓴다.
- 그 전까지는 방향 제시와 의사코드까지만. 막혔다고 해서 먼저 코드를 내밀지 않는다.
- 힌트를 줄 때는 한 번에 하나씩, 단계적으로. 여러 힌트를 몰아서 주면 그게 곧 답이다.

### 버그는 좌표만 좁혀준다

원인과 줄 번호를 바로 말하지 않는다. 사용자가 스스로 도달하도록 범위를 줄여준다.

> 나쁜 예: "`cleanHouse` 안에서 매번 BFS 를 새로 돌려서 O(N⁴) 이 됐어. 42 번째 줄 고쳐."
> 좋은 예: "호출당 BFS 재시작이 의심스러운데, 카운터 찍어서 실제 횟수 확인해볼래?"

### 문제 독해와 채점기 해석은 사용자의 몫이다

- `main.cpp` 의 채점 로직, 점수 공식, 입력 포맷을 Claude 가 먼저 읽고 요약해 주지 않는다.
  문제를 정확히 읽어내는 것 자체가 시험에서 평가되는 능력이다.
- 사용자가 직접 해석한 내용을 "이렇게 이해했는데 맞아?" 하고 **검증** 요청할 때만 응답한다.
  그때도 틀린 부분을 짚어주되, 맞는 해석을 통째로 대신 써주지 않는다.

---

## 2. 반복 실수 학습 루프

[MISTAKES.md](MISTAKES.md) 를 살아있는 문서로 굴린다. 같은 실수를 반복하는 것이
실력이 늘지 않는 가장 큰 원인이므로, 이 루프는 Claude 가 먼저 챙긴다.

| 시점 | Claude 가 할 일 |
|---|---|
| **문제 시작 전** | 새 kata 를 시작하거나 설계 논의에 들어가면 `MISTAKES.md` 체크리스트를 훑고, 이번 문제 유형과 겹치는 항목을 먼저 짚어준다 |
| **원인 확정 순간** | 디버깅으로 근본 원인이 밝혀지면 그 자리에서 항목 추가를 제안한다. 이미 있는 항목이면 발생 횟수와 발생 위치를 갱신한다 |
| **반복 감지** | 같은 항목이 또 나오면 **답을 주지 말고 항목 번호로 되짚어준다** — "이거 M-001, 3번째야. '다음 체크' 항목부터 확인해봐" |
| **제출 직전** | 체크리스트를 통과 여부와 함께 한 번 읽어준다 |

3 회 이상 반복된 항목은 `MISTAKES.md` 의 반복 사례 맨 위로 올려 눈에 띄게 둔다.

---

## 3. Claude 가 바로 처리해도 되는 일

문제 풀이가 아닌 잡일은 사용자 시간을 갉아먹을 뿐이므로, 묻지 말고 처리한다.

- **빌드/환경**: `make` 실행, 컴파일 에러 정리해서 전달, `sample_input.txt` 생성, 시간 측정, 산출물 정리
- **새 kata 스캐폴딩**: 디렉터리 + `Makefile` + 채점기 배치 + **빈** 제출 파일 골격.
  단 골격은 함수 시그니처와 `// Step.N` 주석 틀까지만 — **알고리즘 본문은 비워 둔다**
- **검증 도구 작성**: `optimal.cpp` 같은 브루트포스 / 최적값 계산기.
  제출 대상이 아니므로 STL 을 자유롭게 써도 된다

---

## 4. 디렉터리 구조

```
samsung_expert_kata/
├── CLAUDE.md                   이 문서
├── MISTAKES.md                 오답노트
├── .gitignore                  sample_input.txt 커밋 예외
├── H2323/                      청소 로봇
│   ├── Makefile
│   ├── main.cpp                채점기 + 로봇 하드웨어 시뮬레이터 (main() 소유)
│   ├── H2323.cpp               ← 제출 파일
│   └── sample_input.txt
├── WirelessNetworkCellTower/   기지국 사용자 할당
│   ├── Makefile
│   ├── main.cpp                채점기 + 인스턴스 생성 + 채점 (main() 소유)
│   ├── user.cpp                ← 제출 파일
│   ├── optimal.cpp             참 최적값 계산기 (검증용, 제출 대상 아님, 독립 main())
│   └── sample_input.txt        테스트케이스 수
└── UsedCarManager/             중고차 재고 관리
    ├── Makefile
    ├── main.cpp                채점기 (main() 소유)
    ├── user.cpp                ← 제출 파일
    └── sample_input.txt
```

손대는 파일은 **제출 파일뿐**이다. `main.cpp` 는 채점기이므로 수정 대상이 아니다
(채점기를 고쳐서 통과시키는 건 아무 의미가 없다).

채점기가 호출하는 진입점:

| kata | 제출 파일이 구현할 것 | 채점기가 제공하는 것 |
|---|---|---|
| H2323 | `void init(int, int)`, `void cleanHouse(int)` | `void scanFromRobot(int floorState[3][3])`, `int moveRobot(int mCommand)` |
| WNCT | `void test(void* param)` | `param` = `char[5000][5000]` 격자, 제자리 수정 |
| UsedCarManager | `void buy(CAR)`, `void filter_by_age/passenger/engine/price(int, int)`, `int sell(void)`, `void refund(int)`, `int empty(void)` | `struct CAR` 정의 (제출 파일에도 동일하게 선언) |

---

## 5. 빌드와 실행 (WSL + g++)

| 명령 | 하는 일 |
|---|---|
| `make` | 디버그 빌드 — `-std=c++14 -O1 -g -Wall -Wextra -fsanitize=address,undefined` |
| `make run` | 빌드 후 `< sample_input.txt` 로 채점 실행 |
| `make release` | `-O2`, sanitizer 없음 → **시간 측정은 반드시 이쪽으로** |
| `make clean` | 산출물 삭제 |
| `make optimal` | (WNCT 전용) 검증기 빌드 후 `./optimal 10` |

`sample_input.txt` 포맷:

- **WNCT**: 테스트케이스 수 정수 하나 (예: `10`)
- **H2323**: `T MARK` → 케이스마다 `N subTaskCount` → 서브태스크마다 `N×N` 격자 +
  `y x direction limitMoveCnt`

주의:

- WNCT 의 `-fno-sanitize=signed-integer-overflow` 와 `optimal` 의 `-fwrapv` 는
  채점기 `pseudo_rand()` 가 signed int 오버플로 wraparound 에 의존하기 때문이다. 빼면 UB 로 깨진다.
- sanitizer 빌드는 눈에 띄게 느리다. 알고리즘이 느린 건지 sanitizer 때문인지 헷갈리면 `make release`.

---

## 6. 실제 시험 환경 (Windows + Visual Studio)

연습은 WSL / g++, 시험장은 Windows / Visual Studio 다. 차이에서 오는 사고를 미리 막는다.

### 대용량 sample input 을 VS 에 넣는 방법

**① 디버깅 인수로 리다이렉션 (권장)**

> 프로젝트 속성 → 구성 속성 → **디버깅** →
> `명령 인수` 에 `< sample_input.txt`
> `작업 디렉터리` 를 `$(ProjectDir)`

소스를 전혀 건드리지 않고, F5 디버깅에서도 그대로 먹는다. 제출 파일에 흔적이 남지 않는 게 가장 큰 장점.

**② `freopen`**

```cpp
freopen("sample_input.txt", "r", stdin);
```

간단하지만 **제출 전에 반드시 지우거나 주석 처리**해야 한다. 지우는 걸 잊는 게 대표적인 사고 유형이다.
MSVC 는 `freopen_s` 를 권하며 경고를 내므로 `#define _CRT_SECURE_NO_WARNINGS` 가 필요할 수 있다.

**③ 콘솔에서 직접**

```
Release\prog.exe < sample_input.txt
```

**시간 측정은 이 방식 + Release 빌드로 한다.** VS 디버거를 붙인 F5 실행은 훨씬 느려서
시간 판단이 왜곡된다.

### 환경 차이 주의

- **표준은 C++14 로 맞춘다.** 세 kata 의 Makefile 이 모두 `-std=c++14` 이며, 시험 환경 기준이다.
  구조적 바인딩, `if` 초기화문, `auto` 반환 추론 확장 같은 C++17 문법은 쓰지 않는다.
  (`register` 키워드는 C++14 까지 합법이고 C++17 에서 제거됐다 — 채점기가 쓰는 경우가 있다)
- 입력이 크면 `cin` 기본 설정이 느리다. MSVC 에서도 `ios::sync_with_stdio(false); cin.tie(0);`
  또는 `scanf` 를 쓴다.
- MSVC 는 **가변 길이 배열(VLA)** 과 `<bits/stdc++.h>` 를 지원하지 않는다.
  제출 파일을 헤더 include 없이 고정 크기 배열로만 쓰는 습관이 그대로 이식성을 보장한다 (7절 참조).
- **AddressSanitizer 는 시험장에 없다고 가정한다.** 인덱스 실수는 여기서 미리 걸러 두고,
  VS 에서는 배열 범위 근거 주석으로 방어한다.
- **큰 배열을 지역 변수로 옮기면 스택 오버플로가 난다** (WNCT 의 `char[5000][5000]` = 25 MB).
  전역 또는 `static` 유지.

---

## 7. 제출 파일 코딩 규약

시험 환경을 그대로 재현하는 것이 목적이다.

### STL 금지

헤더 include 없이 raw 고정 크기 전역 배열만 쓴다. `vector` / `queue` / `sort` 대신 직접 짠다.
기존 코드가 이미 이 방식이다 — `user.cpp` 의 `mergeSort` / `sortNB`,
`H2323.cpp` 의 `static int qy[3600], qx[3600]` BFS 큐.

> 예외: `optimal.cpp` 같은 검증 도구는 제출 대상이 아니므로 STL 자유.

### 주석은 한국어로, 설계 근거를 남긴다

무엇을 하는지가 아니라 **왜 그 방식을 골랐는지** 를 쓴다. 버린 접근과 그 이유, 측정한 수치까지.
나중에 같은 유형을 만났을 때 이 기록이 가장 큰 자산이 된다.
(기존 예: `H2323.cpp` 의 "없앤 단계와 이유" 블록, `optimal.cpp` 상단의 정식화 설명)

### 형식

- 네이밍: 함수·변수 `lowerCamelCase`, 상수는 `#define` + `UPPER_SNAKE`
- 좌표는 **`y` 먼저, `x` 나중**
- 방향 배열 고정: `dy[4] = {-1,0,1,0}`, `dx[4] = {0,-1,0,1}` — 반시계 `0:UP 1:LEFT 2:DOWN 3:RIGHT`
- 배열은 방어적으로 크게 잡되 **왜 그 크기인지 주석으로 근거를 적는다**
  (기존 예: `houseMap[60][60]` — 로봇 초기 위치를 모르므로 29,29 에서 시작)
- 진입 함수 위에는 문제 제약을 재기술한 블록 주석, 본문에는 `// Step.N` 마커
- 들여쓰기 4 칸

---

## 8. 새 kata 추가 절차

`WirelessNetworkCellTower/` 를 템플릿으로 삼는다.

1. 디렉터리 생성
2. `Makefile` 복사 후 `SRCS` / `TARGET` 수정
3. 채점기 `main.cpp` 배치
4. 제출 파일은 **시그니처와 `// Step.N` 주석 틀만** — 본문은 사용자가 채운다
5. `.gitignore` 에 빌드 산출물 이름 추가
6. `sample_input.txt` 생성
7. `MISTAKES.md` 체크리스트를 훑고 시작
