
CPP := g++
CPPFLAGS := -Wall -Werror

SRCDIR := src
TARGETDIR := bin
TARGET := $(TARGETDIR)/demo
SRCFILES := $(shell ls src/*.cpp)

all: $(TARGET)

$(TARGET): $(SRCFILES)
	$(CPP) $(CPPFLAGS) $^ -o $@ 


clean:
	$(RM) $(TARGET)