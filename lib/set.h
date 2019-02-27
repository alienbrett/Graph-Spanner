#ifndef SET_H
#define SET_H

#include <stdlib.h>

typedef enum {false, true} bool;


typedef struct node {
    
    //struct node * parent;
    int parent;
    int val;
    int size;
    
} node;
typedef node* set;


set single_set(int x, set parent);


bool same_set (set s, int len, int x, int y);
int parent (set s, int len, int child);

int join (set s, int len, int x, int y);

void print_set(set x);









#endif