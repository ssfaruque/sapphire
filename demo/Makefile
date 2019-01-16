CPP 	 := g++
CPPFLAGS := -Wall -Werror

.PHONY := directories buildlib all clean cleanall

SRCDIR 	   := src
BUILDDIR   := build
OBJSDIR    := $(BUILDDIR)/objs
DEPSDIR    := $(BUILDDIR)/deps
TARGETDIR  := bin
TARGETNAME := demo
TARGET 	   := $(TARGETDIR)/$(TARGETNAME)

SRCS := $(shell ls $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJSDIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp, $(DEPSDIR)/%.d, $(SRCS))

INCLUDEPATH := ../engine/include
LIBPATH		:= ../engine/bin
LIB 		:= sapphire

DIRS := $(TARGETDIR) $(BUILDDIR) $(DEPSDIR) $(OBJSDIR)

all: directories buildlib $(TARGET)

-include $(DEPS)


$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -I$(INCLUDEPATH) -L$(LIBPATH) -l$(LIB) -o $@ 


$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -I$(INCLUDEPATH) -c $< -o $@ -MMD -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)


directories:
	@echo "Creating necessary build and output directories for demo..."
	@mkdir -p bin
	@mkdir -p build
	@mkdir -p build/deps
	@mkdir -p build/objs

buildlib:
	@$(MAKE) -C ../engine


clean:
	@echo "Cleaning files and directories of build for demo..."
	@$(RM) -r bin
	@$(RM) -r build

cleanall: clean
	@$(MAKE) -C ../engine clean
