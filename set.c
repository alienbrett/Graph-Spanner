#include <stdio.h>

#include "lib/set.h"



bool same_set (set s, int len, int x, int y)
{
    x = parent(s,len,x);
    y = parent(s,len,y);
    //printf("same set? %d, %d\n", x,y);
    return x == y && x != -1 && y != -1;
}


int parent (set s, int len, int child)
{
    if (child >= len || child < 0) return child;
    return parent(s,len,s[child].parent);
}



int join (set s, int len, int x, int y)
{
    x = parent(s,len,x);
    y = parent(s,len,y);
    if (x < 0 || y < 0 || x >= len || y >= len) return -1;
    
    if (x == y) return x;
    
    if (s[x].size >= s[y].size)
    {
        s[y].parent = x;
        s[x].size += s[y].size;
        return y;
    }
    else { return join(s,len,y,x); }
}


/*
// given empty memory, load in a new set
set single_set (int val, set parent)
{
    set meme = malloc(sizeof(node));
    
    if (meme == NULL) return meme;
    
    meme->val    = val;
    meme->parent = parent;
    
    meme->size = 1;
    
    return meme;
}
*/


/*
void print_set(set s, int len, int x)
{
    printf("(%d)", x[x]->val);
    
    if (x->parent != NULL)
    {
        printf("-->");
        print_set(x->parent);
    }
    else
    {
        printf("\n");
        return;
    }
    return;
}
*/