# Makefile

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -Wextra -std=c++11 -g

# Source files directory
SRCDIR := src

# Include files directory
INCDIR := include

# Object files directory
OBJDIR := obj

# Source files
SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Executable name
TARGET := 3rdSemester.exe

# Platform-specific commands
RM := del /Q
MKDIR := mkdir

#library directory
LIBDIR    ?= /lib

# OpenGL library
LIBS := -lopengl32 -lgdi32

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Rule to build object files from source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(MKDIR) -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

# Clean rule
clean:
	$(RM) $(OBJDIR) $(TARGET)

# Phony target to avoid conflicts with file names
.PHONY: all clean
