CXX      := g++
SRCS     := main.cpp user.cpp
TARGET   := shelter

# 배열 인덱스 실수를 바로 잡아내려고 기본 빌드에 sanitizer 를 켠다.
# main.cpp 의 register 키워드는 C++14 까지는 합법이다 (C++17 에서 제거됨).
CXXFLAGS := -std=c++14 -O1 -g -Wall -Wextra -fsanitize=address,undefined

.PHONY: all run release optimal clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# 샘플 입력으로 채점 실행
run: $(TARGET)
	./$(TARGET) < sample_input.txt

# 제출 환경에 가까운 최적화 빌드 (sanitizer 없음). 시간 측정은 이쪽으로 본다.
release: $(SRCS)
	$(CXX) -std=c++14 -O2 -Wall -Wextra -o $(TARGET)_release $(SRCS)
	./$(TARGET)_release < sample_input.txt

# 검증 도구 (제출 대상 아님). 앞쪽 층들의 진짜 최적값을 완전탐색으로 구한다.
optimal: optimal.cpp
	$(CXX) -std=c++14 -O2 -Wall -Wextra -o $@ optimal.cpp
	./optimal 3 20

clean:
	rm -f $(TARGET) $(TARGET)_release optimal
