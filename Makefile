CXX=clang
OPT=g
LD_FLAGS= -L/usr/local/lib -lpng
CFLAGS= -O$(OPT) -Wall -Wextra  -std=c99

default: maze
maze: maze.c lib/*.h set.c maze_tools.c
	$(CXX) $(CFLAGS) -o maze maze.c set.c maze_tools.c $(LD_FLAGS)
    
.PHONY: clean
	rm -Rf *.o maze
