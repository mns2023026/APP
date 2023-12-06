#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct AVL_Node {
    int val;
    struct AVL_Node *left;
    struct AVL_Node *right;
    int height;
} avlN;

int height(avlN *n);
int max_avl_height(avlN *b);
int get_Avl_balance_factor(avlN *n);
avlN *create_Avl_Node(int val);
avlN *RightRotation(avlN *a);
avlN *LeftRotation(avlN *a);
avlN *insert_AVL(avlN *root, int key);
avlN *delete_avl(avlN *root, int key);
void inorder_avl(avlN *root);

#endif /* AVL_TREE_H */
