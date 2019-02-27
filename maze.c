#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "lib/set.h"
#include "lib/graph.h"





vert next_v(int n, int h, int w)
{
    if (n < (w-1)*h)
    {
        int x = n % (w-1);
        int y = n / (w-1);
        
        return v(nd(x,y,w), nd(x+1,y,w));
    }
    else
    {
        n -= (w-1)*h;
        
        int x = n / (h-1);
        int y = n % (h-1);
        
        return v(nd(x,y,w), nd(x,y+1,w));
    }
}

int square_maze (vert ** ptr, int h, int w)
{
    if (h < 1 || w < 1) return 0;
    
    int n = 2 * h * w - h - w;
    
    *ptr = malloc( n * sizeof(vert) );
    if (ptr == NULL) return -1;
    
    
    for (int i = 0; i < n; i++)
    { (*ptr)[i] = next_v(i, h, w); }
    
    
    return n;
}



int main(int argc, char ** argv)
{
    
    
    if (argc < 3)
    {
        fprintf (stderr, "Usage:\n\tmaze h w\n\tmaze 10 15\n");
        return 1;
    }
    
    const int h = strtol(argv[1], NULL, 10);
    const int w = strtol(argv[2], NULL, 10);
    const int size = h * w;
    
    //const bool verbose = true;
    const bool verbose = false;
    
    vert * vs = NULL;
    int n_vs  = square_maze(&vs, h, w);
    
    
    if (verbose)
        for (int i = 0; i < n_vs; i++)
        { print_v(&vs[i]); printf("\n"); }
    
    
    node * ns = NULL;
    bool * incl = NULL;
    
    ns = malloc(size * sizeof(node));
    incl = malloc(n_vs * sizeof(bool));
    
    if (ns == NULL || incl == NULL)
    {
        fprintf(stderr, "Memory error! Couldn't create array of that size?!\n");
        return -1;
    }
    
    init_graph(ns, size);

    init_vert_incl(incl, n_vs);
    
    
    shuffle(vs, n_vs, 3, 1);
    
    
    build_maze(vs, incl, n_vs, ns, size);
    
    printf("finsihed maze!\nHere are connections...\n");
    for (int i = 0; i < n_vs; i++)
    {
        if (incl[i])
        {
            print_v(&vs[i]);
            printf("\n");
        }
    }
    
   
    
    
    /*
    leaf * t = NULL;
    t = balanced_tree(size, 0);
    print_tree(t);
    */
    
    
    
    
    free(vs);
    
    free(ns);
    
    return 0;
}
