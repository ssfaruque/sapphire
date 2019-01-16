CPP := g++
CPPFLAGS := -Wall -Werror

.PHONY := directories all clean

SRCDIR := src
BUILDDIR := build
OBJSDIR := $(BUILDDIR)/objs
DEPSDIR := $(BUILDDIR)/deps
TARGETDIR := bin
TARGETNAME := demo
TARGET := $(TARGETDIR)/$(TARGETNAME)

SRCS := $(shell ls $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJSDIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp, $(DEPSDIR)/%.d, $(SRCS))

INCLUDEPATH := ../engine/include

DIRS := $(TARGETDIR) $(BUILDDIR) $(DEPSDIR) $(OBJSDIR)

all: directories $(TARGET)

-include $(DEPS)


$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@ -I$(INCLUDEPATH) 


$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -I$(INCLUDEPATH) -c $< -o $@ -MMD -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)


directories:
	@echo "Creating necessary build and output directories..."
	@mkdir -p bin
	@mkdir -p build
	@mkdir -p build/deps
	@mkdir -p build/objs


clean:
	@echo "Cleaning files and directories of build..."
	@$(RM) -r bin
	@$(RM) -r build
