#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>

#include "lib/set.h"
#include "lib/graph.h"





int main(int argc, char ** argv)
{
    
    
    if (argc < 2)
    {
        fprintf (stderr, "Usage:\n\t%s file.pdf\nFor a vertex file generated by 2d", argv[0]);
        return 1;
    }
    
    char* fname = argv[1];
    
    const bool verbose = true;
    //const bool verbose = false;
    
    
    
    
    
    
    
    
    return 0;
}
