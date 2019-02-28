CXX=clang
OPT=3
LD_FLAGS= -L/usr/local/lib -lpng
CFLAGS= -O$(OPT) -Wall -Wextra  -std=c99

default: 2d
2d: 2d.c lib/*.h set.c graph.c
	$(CXX) $(CFLAGS) -o 2d 2d.c set.c graph.c $(LD_FLAGS)

maze: maze.c lib/*.h set.c graph.c
	$(CXX) $(CFLAGS) -o maze maze.c set.c graph.c $(LD_FLAGS)
    
.PHONY: clean
clean:
	rm -rf *.o 2d