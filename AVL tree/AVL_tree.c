#include <stdio.h>
#include <stdlib.h>

#define DEBUG

typedef struct _tree {
    int data;
    int hight;
    struct _tree* Left;
    struct _tree* Right;
} Tree;

// контроль высоты дерева
int growth (Tree** root) {

    int left_hight = ((*root)->Left ? (*root)->Left->hight : 0);
    int right_hight = ((*root)->Right ? (*root)->Right->hight : 0);

    int max_hight = (left_hight > right_hight ? left_hight : right_hight);

    (*root)->hight = max_hight + 1;

    return 0;

}

void tree_free(Tree* root) {

    Tree* left = NULL;
    Tree* right = NULL;

    if (root) {
        left = root->Left;
        right = root->Right;

        free(root);
        tree_free(left);
        tree_free(right);
    }

}

int print_element(int x, int level, int hight) {

    while (level--) {
        printf("    ");
    }
    printf("%d(%d)\n", x, hight);

    return 0;

}

int tree_walk(Tree* root, int level) {

    if (!root) {
        return 0;
    }
    tree_walk(root->Left, level + 1);
    print_element(root->data, level, root->hight);
    tree_walk(root->Right, level + 1);

}

//по указателю передаеся счетчик
void tree_search(Tree* root, int x, int* count) {

    if (!root) {
        return;
    }
    else if (x == root->data) {
        (*count)++;
        tree_search(root->Right, x, count);
    }
    else if (x > root->data) {
        tree_search(root->Right, x, count);
    }
    else {
        tree_search(root->Left, x, count);
    }

}

Tree* Left_small_turn (Tree** root) {

    Tree* new_root = malloc(sizeof(Tree));
    new_root = (*root)->Right;

    (*root)->Right = new_root->Left;
    new_root->Left = (*root);

    growth(&new_root->Left);
    growth(&new_root);
   
    return new_root;

}

Tree* Right_small_turn (Tree** root) {

    Tree* new_root = malloc(sizeof(Tree));
    new_root = (*root)->Left;

    (*root)->Left = new_root->Right;
    new_root->Right = (*root);

    growth(&new_root->Right);
    growth(&new_root);

    return new_root;

}

Tree* Left_big_turn (Tree** root) {

    (*root)->Right = Right_small_turn(&(*root)->Right);
    *root = Left_small_turn(root);

    return *root;

}

Tree* Right_big_turn (Tree** root) {

    (*root)->Left = Left_small_turn(&(*root)->Left);
    *root = Right_small_turn(root);

    return *root;

}

int balanced (Tree** root) {

    Tree* right_child = (*root)->Right;
    Tree* left_child = (*root)->Left;

    int right_child_hight = (right_child ? right_child->hight : 0);
    int left_child_hight = (left_child ? left_child->hight : 0);

    int rr_child_hight = ((right_child && right_child->Right) ? right_child->Right->hight : 0);
    int rl_child_hight = ((right_child && right_child->Left) ? right_child->Left->hight : 0);
    int ll_child_hight = ((left_child && left_child->Left) ? left_child->Left->hight : 0);
    int lr_child_hight = ((left_child && left_child->Right) ? left_child->Right->hight : 0);

    if (right_child_hight - left_child_hight == 2) {
        if (rr_child_hight >= rl_child_hight) {
            *root = Left_small_turn(root);
        }
        else {
            *root = Left_big_turn(root);
        }
    }
    else if (right_child_hight - left_child_hight == -2) {
        if (ll_child_hight >= lr_child_hight) {
            *root = Right_small_turn(root);
        }
        else {
            *root = Right_big_turn(root);
        }
    }
    else {
        return 0;
    }

}

int tree_insert(Tree** root, int x) {

    if (*root == NULL) {
        Tree* box = malloc(sizeof(Tree));
        *box = (Tree){x, 1, NULL, NULL};
        *root = box;
        return 0;
    }
    else {
        if (x > (*root)->data) {
            tree_insert(&(*root)->Right, x);
            growth(root);

            #ifdef DEBUG
            if (balanced(root) != 0) {
                printf("there was a balanced!!!\n");
            }
            #endif
        }
        else {
            tree_insert(&(*root)->Left, x);
            growth(root);

            #ifdef DEBUG
            if (balanced(root) != 0) {
                printf("there was a balanced!!!\n");
            }
            #endif
        }
    }

}

int root_count (Tree* root, int* count) {

    if (!root) {
        return 0;
    }
    else {
        (*count)++;
        root_count(root->Left, count);
        root_count(root->Right, count);
    }

}

int main() {

    Tree* test = NULL;
    int a = 0;


    while (scanf("%d", &a) == 1) {
        tree_insert(&test, a);
    }

    printf("\n");
    tree_walk(test, 0);
    printf("\n");

    int left_N = 0;
    int right_N = 0;

    root_count(test->Left, &left_N);
    root_count(test->Right, &right_N);

    printf("%d %d", left_N, right_N);

    tree_free(test);

    return 0;
}