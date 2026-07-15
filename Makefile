CXX := g++
CXXFLAGS := $(shell pkg-config --cflags sdl3) -MMD -MD
LDFLAGS := $(shell pkg-config --libs sdl3)

SRCS := $(shell find -type f -name '*.cpp' 2>/dev/null)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
DEPS := $(patsubst %.o,%.d,$(OBJS))

TARGET := chat

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

-include $(DEPS)
