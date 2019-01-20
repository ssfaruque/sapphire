CPP 	 := g++
CPPFLAGS := -Wall -Werror -std=c++11 -g

.PHONY := directories buildlib all clean cleanall

SRCDIR 	   := src
BUILDDIR   := build
OBJSDIR    := $(BUILDDIR)/objs
DEPSDIR    := $(BUILDDIR)/deps
TARGETDIR  := bin
TARGETNAME := demo
TARGET 	   := $(TARGETDIR)/$(TARGETNAME)
DIRS 	   := $(TARGETDIR) $(BUILDDIR) $(DEPSDIR) $(OBJSDIR)

SRCS := $(shell ls $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJSDIR)/%.o, $(SRCS))
DEPS := $(patsubst $(SRCDIR)/%.cpp, $(DEPSDIR)/%.d, $(SRCS))

INCLUDEPATHS := ../engine/include
INCLUDEPATHS := $(patsubst %, -I%, $(INCLUDEPATHS))
LIBPATHS := ../engine/bin
LIBPATHS := $(patsubst %, -L%, $(LIBPATHS))
LIBS := -lsapphire -ldl -lGL -lglfw
# -lgL -lglfw should later be moved to makefile of engine

all: directories buildlib $(TARGET)

-include $(DEPS)


$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ $(INCLUDEPATHS) $(LIBPATHS) $(LIBS) -o $@ 


$(OBJSDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDEPATHS) -c $< -o $@ -MMD -MF $(patsubst $(OBJSDIR)/%.o, $(DEPSDIR)/%.d, $@)


directories:
	@echo "Creating necessary build and output directories for demo..."
	@mkdir -p $(DIRS)
	@mkdir -p logs


buildlib:
	@$(MAKE) -C ../engine
	@touch src/main.cpp #temporary line


clean:
	@echo "Cleaning files and directories of build for demo..."
	@$(RM) -r $(DIRS)


cleanall: clean
	@$(MAKE) -C ../engine clean
