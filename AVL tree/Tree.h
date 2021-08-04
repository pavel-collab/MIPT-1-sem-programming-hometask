#ifndef _TREE_H_
#define _TREE_H_

typedef struct _tree 
{
    int data;
    int hight;
    struct _tree* Left;
    struct _tree* Right;
} Tree;

#endif