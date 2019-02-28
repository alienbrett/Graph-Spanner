#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "lib/set.h"
#include "lib/graph.h"



vert v(int a, int b){vert v; v.a = a; v.b = b; return v;}

int nd(int x, int y, int w) { return y * w + x; }

int test_vert(vert * v, node * arr, int len)
{
    int x = v->a;
    int y = v->b;
    
    //printf("len:%d, (%d,%d) \n",len, x,y);
    
    if (x >= len || y >= len) return -1;
    
    if (!same_set(arr, len, x, y))
    {
        join(arr, len, x, y);
        return 1;
    }
    else {return 0;}
}


void swap(vert * a, vert * b)
{
    if (a == b || a == NULL || b == NULL) return;
    vert c;
    c.a = a->a; c.b = a->b;
    a->a = b->a; a->b = b->b; 
    b->a = c.a; b->b = c.b;
}


int shuffle(vert * a, int len, int n, int seed)
{
    if (seed == 1)
    { srand(time(0)); }
    else if (seed > 1)
    {srand(seed);}
    
    int x;
    
    for (int j = 0; j < n; j++)
        for (int i = 0; i < len-1; i++)
        {
            x = rand() % (len - i);
            swap(&(a[i]), &(a[x]));
        }
    return 0;
}


void print_v(vert * v)
{
    int x = MIN(v->a,v->b);
    int y = MAX(v->a,v->b);
    printf("(%d,%d)",x,y);
}


// initialize nodes in array
void init_graph(node * ns, int size)
{
    for (int i = 0; i < size; i++)
    {
        //printf("%d,",i);
        ns[i].val = i;
        ns[i].parent = -1;
    }
}


    
// initialize vertex inclusion array
void init_vert_incl(bool * incl, int n_vs)
{
    for (int i = 0; i < n_vs; i++)
    { incl[i] = 0; }
}





int build_maze(vert * vs, bool * incl, int n_vs, node * ns, int size)
{
    int n_graphs = size;
    int f = 0;
    
    //printf("building maze...\n");

    for (int i = 0; n_graphs > 1; i++)
    {
        if (i > n_vs) {return -1;}
        
        //printf("testing vert ");
        //print_v(&(vs[i]));
        //printf("\n");
        f = test_vert(&(vs[i]), ns, size);

        if (f == -1)
        {
            fprintf(stderr, "err, vertex's node doesn't exist?!?\n");
            return -1;
        }
        else if (f == 1)
        {
            incl[i] = true;
            n_graphs--;
        }
    }
    return 0;
}


