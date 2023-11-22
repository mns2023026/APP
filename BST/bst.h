#include <stdio.h>
#include <stdlib.h>

struct Bst_Node {
    int val;
    struct Bst_Node * right;
    struct Bst_Node * left;
};

struct Bst_Node * createNode(int val)
{
    struct Bst_Node * nn = (struct Bst_Node *)malloc(sizeof(struct Bst_Node));
     if (nn == NULL) {
        perror("Can't acquire memory");
        exit(1);
    }
    nn -> val = val;
    nn->right = NULL;
    nn->left = NULL;
    return nn;
}

struct Bst_Node * insert_node(int n, struct Bst_Node * root)
{
    if ( root == NULL ) {
        return createNode(n);
    }

    if( n <= root -> val ) {
        root -> left = insert_node(n,root -> left);
    }
    else {
        root -> right = insert_node(n,root -> right);
    }

    return root;    
}
char search(struct Bst_Node* root , int val) 
{

    printf("-------------%d",val);
    while (root) {
        if(root ->val == val)
        {
            return 'y';
        }
        if(val <= root ->val  ) {
            root = root -> left;
        } else {
            root = root -> right;
        }
       
    }
     return 'n';
}


struct Bst_Node *find_min(struct Bst_Node *root) {
    struct Bst_Node *current = root;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

struct Bst_Node *delete_node(struct Bst_Node *root, int n) {
    if (!root) {
        return NULL;
    }

    if (n < root->val) {
        root->left = delete_node(root->left, n);
    } else if (n > root->val) {
        root->right = delete_node(root->right, n);
    } else {

        if (!root->left && root->right) {
            struct Bst_Node *tmp = root->right;
            free(root);
            return tmp;
        }

        if (root->left && !root->right) {
            struct Bst_Node *tmp = root->left;
            free(root);
            return tmp;
        }

        struct Bst_Node *tmp = find_min(root->right);
        root->val = tmp->val;

        root->right = delete_node(root->right, tmp->val);
    }
    return root;
}

void inorder(struct Bst_Node *root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}





