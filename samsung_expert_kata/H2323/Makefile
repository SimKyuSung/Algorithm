CXX      := g++
SRCS     := main.cpp H2323.cpp
TARGET   := H2323

# 배열 인덱스 실수를 바로 잡아내려고 기본 빌드에 sanitizer 를 켠다.
CXXFLAGS := -std=c++14 -O1 -g -Wall -Wextra -fsanitize=address,undefined

.PHONY: all run release clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# 샘플 입력으로 채점 실행
run: $(TARGET)
	./$(TARGET) < sample_input.txt

# 제출 환경에 가까운 최적화 빌드 (sanitizer 없음)
release: $(SRCS)
	$(CXX) -std=c++14 -O2 -Wall -Wextra -o $(TARGET)_release $(SRCS)
	./$(TARGET)_release < sample_input.txt

clean:
	rm -f $(TARGET) $(TARGET)_release
