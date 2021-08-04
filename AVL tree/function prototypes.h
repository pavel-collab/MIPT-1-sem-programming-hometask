#ifndef _FUNCTION_PROTOTYPES_H_
#define _FUNCTION_PROTOTYPES_H_

int growth (Tree** root);

void tree_free(Tree* root);

int print_element(int x, int level, int hight);

int tree_walk(Tree* root, int level);

void tree_search(Tree* root, int x, int* count);

Tree* Left_small_turn (Tree** root);

Tree* Right_small_turn (Tree** root);

Tree* Left_big_turn (Tree** root);

Tree* Right_big_turn (Tree** root);

int balanced (Tree** root);

int tree_insert(Tree** root, int x);

int root_count(Tree* root, int* count);

#endif