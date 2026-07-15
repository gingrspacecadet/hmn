CXX := g++
CXXFLAGS := $(shell pkg-config --cflags --libs sdl3)

SRCS := $(shell find -type f -name '*.cpp' 2>/dev/null)
OBJS := $(patsubst %.o,%.cpp,$(SRCS))

TARGET := chat

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^
