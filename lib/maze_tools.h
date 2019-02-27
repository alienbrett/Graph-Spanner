#ifndef MAZE_TOOLS
#define MAZE_TOOLS

#include "set.h"

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a


typedef struct vert
{
    int a;
    int b;
} vert;


// create vertex via function
vert v(int a, int b);


// convert rectangular graph into countable nodes
// x,y cords. w width
int nd(int x, int y, int w);




// -1: failure
//  0: bad vertex
//  1: good vertex
//  1:   additionally, join nodes
int test_vert(vert * v, node * arr, int len);
 


// seed = 1:  auto-set seed
// seed = 0:  no seed
// seed = ?:  use ?
// n    = ?:  shuffle n times
int shuffle(vert * a, int len, int n, int seed);



// vs: vertex array
// incl: inclusion array
// n_vs: length of vertex array
// ns: node array
// size: node array length
int build_maze(vert * vs, bool * incl, int n_vs, node * ns, int size);


// print vertex, ie "(1->2)"
void print_v(vert * v);



void swap(vert * a, vert * b);


// initialize nodes in array
void init_graph(node * ns, int size);



// initialize vertex inclusion array
void init_vert_incl(bool * incl, int n_vs);




#endif