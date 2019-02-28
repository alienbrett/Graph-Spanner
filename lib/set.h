#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include <stdbool.h>



typedef struct node {
    int parent;
    int val;
    int size;
} node;
typedef node* set;




bool same_set (set s, int len, int x, int y);
int parent (set s, int len, int child);

int join (set s, int len, int x, int y);









#endif