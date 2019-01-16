CPP 	 := g++
CPPFLAGS := -Wall -Werror

.PHONY := directories all clean

SRCDIR 	   := src
BUILDDIR   := build
OBJSDIR    := $(BUILDDIR)/objs
DEPSDIR    := $(BUILDDIR)/deps
TARGETDIR  := bin
TARGETNAME := libsapphire.a
TARGET 	   := $(TARGETDIR)/$(TARGETNAME)

SRCS := $(shell ls $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJSDIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp, $(DEPSDIR)/%.d, $(SRCS))

INCLUDEPATH := .

DIRS := $(TARGETDIR) $(BUILDDIR) $(DEPSDIR) $(OBJSDIR)

all: directories $(TARGET)

-include $(DEPS)


$(TARGET): $(OBJS)
	@echo "Building the Sapphire engine library..."
	ar rcs $@ $^


$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -I$(INCLUDEPATH) -c $< -o $@ -MMD -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)


directories:
	@echo "Creating necessary build and output directories for sapphire..."
	@mkdir -p bin
	@mkdir -p build
	@mkdir -p build/deps
	@mkdir -p build/objs


clean:
	@echo "Cleaning files and directories of build for sapphire..."
	@$(RM) -r bin
	@$(RM) -r build
