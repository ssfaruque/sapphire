CPP 	 := g++
CPPFLAGS := -Wall -Werror -std=c++11 -g

.PHONY := directories all clean

SRCDIR 	   := src
BUILDDIR   := build
OBJSDIR    := $(BUILDDIR)/objs
DEPSDIR    := $(BUILDDIR)/deps
TARGETDIR  := bin
TARGETNAME := libsapphire.a
TARGET 	   := $(TARGETDIR)/$(TARGETNAME)
DIRS 	   := $(TARGETDIR) $(BUILDDIR) $(DEPSDIR) $(OBJSDIR)

SRCS := $(shell ls $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJSDIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp, $(DEPSDIR)/%.d, $(SRCS))

INCLUDEPATHS := $(shell find libs -name "include") 
INCLUDEPATHS := $(patsubst %, -I%, $(INCLUDEPATHS))
LIBPATHS := $(shell find libs -name "lib") 
LIBPATHS := $(patsubst %, -L%, $(LIBPATHS))
LIBS := $(shell find libs -name "*.a") 

all: directories $(TARGET)

-include $(DEPS)

#PROBLEM: linking of glfw, GL, etc. is in Makefile for dmeo
# Should later solve this problem and move linking to this Makefile
$(TARGET): $(OBJS)
	@echo "Building the Sapphire engine library..."
	ar rcs $@ $^


$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDEPATHS) $(LIBPATHS) -lglfw -c $< -o $@ -MMD -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)


directories:
	@echo "Creating necessary build and output directories for sapphire..."
	@mkdir -p $(DIRS)


clean:
	@echo "Cleaning files and directories of build for sapphire..."
	@$(RM) -r $(DIRS)

