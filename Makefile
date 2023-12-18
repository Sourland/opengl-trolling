# Compiler settings - Can be customized.
CC=g++
CFLAGS=-Wall

# OpenGL libraries
LIBS=-lGLEW -lGL -lglfw

# Include and Library paths for GLEW, GLFW, and GLAD
INC_DIRS=-I./lib -I~/glfw/include
LIB_DIRS=-L~/glfw/lib

# Source files
SRCS=triangle_example.cpp lib/glad.c

# Executable name
EXE=myOpenGLApp

all: $(SRCS)
	$(CC) $(CFLAGS) $(INC_DIRS) $(LIB_DIRS) $(SRCS) -o $(EXE) $(LIBS)

clean:
	rm -f $(EXE)
