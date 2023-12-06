#include <stdio.h>
#include <stdlib.h>

typedef struct AVL_Node {
    int val;
    struct AVL_Node *left;
    struct AVL_Node *right;
    int height;
} avlN;

int height(avlN * n)
{
    if(!n){
        return 0;
    }
    return n->height;
}

int max_avl_height(avlN * b)
{
    return (height(b->left) > height(b->right)) ? height(b->left):height(b->right);
}

int get_Avl_balance_factor(avlN *n)
{
    if(!n){
        return 0;
    }
    return height(n->left) - height(n->right);
}

avlN * create_Avl_Node(int val)
{
    avlN * nn =(avlN *) malloc (sizeof(avlN));
    nn->val = val;
    nn->left = NULL;
    nn->right = NULL;
    nn->height = 1;

    return nn;
}




avlN * RightRotation(avlN * a)
{
    avlN * b = a ->left;
    avlN * tmp = b->right;

    b -> right = a;
    a-> left = tmp;

    b->height = max_avl_height(b)+1;
    a->height = max_avl_height(a)+1;

    return b;
}

avlN * LeftRotation(avlN * a)
{
    avlN * b = a ->right;
    avlN * tmp = b->left;

    b -> left = a;
    a-> right = tmp;

    b->height = max_avl_height(b)+1;
    a->height = max_avl_height(a)+1;

    return b;
}

avlN * insert_AVL(avlN* root,int key)
{    
    if(!root)
    {
        return create_Avl_Node(key);
    }

    if( key < root->val) {
        root->left = insert_AVL(root ->left,key);
    } else if (key > root->val) {
        root->right = insert_AVL(root ->right,key);
    } else {
        return root;
    }

    root ->height = max_avl_height(root) + 1;
    int balance = get_Avl_balance_factor(root);

    // left left error
    if (balance > 1 && key < root->left->val ) {
        return RightRotation(root); 
    }

    // right right error
    if (balance < -1 && key > root->right->val ) {
        return LeftRotation(root); 
    }
    // left right error
    if (balance > 1 && key > root->left->val ) {
        root->left =LeftRotation(root->left); 
        return RightRotation(root);
    }
    //right left error
    if (balance < -1 && key < root->right->val ) {
        root->right =RightRotation(root->right); 
        return LeftRotation(root);
    }

    return root;
}


avlN * delete_avl(avlN * root, int key)
{
    if (!root)
    {
        return NULL;
    }

    if (key < root->val) {
        root->left = delete_avl(root->left, key);
    } else if (key > root->val) {
        root -> right = delete_avl(root->right, key);
    } else {

        if (root->left == NULL || root -> right == NULL)
        {
            avlN * tmp = root->left == NULL? root->right : root ->left;

            if( !tmp)
            {
                tmp=root;
                root=NULL;
            }
            else{
                *root = *tmp;
            }
            free(tmp);
        } else {

            avlN * tmp = root ->right;
            while (tmp -> left)
            {
                tmp=tmp->left;
            }
            root ->val = tmp -> val;
            root -> right = delete_avl(root->right,tmp->val);

        }
    }

    if(!root)
    {
        return root;
    }

    root->height=1+ max_avl_height(root);

    int balance = get_Avl_balance_factor(root);

    // left left error
    if (balance > 1 && get_Avl_balance_factor(root->left)>=0) {
        return RightRotation(root); 
    }

    // right right error
    if (balance < -1 && get_Avl_balance_factor(root->right)<=0 ) {
        return LeftRotation(root); 
    }
    // left right error
    if (balance > 1 && key >get_Avl_balance_factor(root->left)<0 ) {
        root->left =LeftRotation(root->left); 
        return RightRotation(root);
    }
    //right left error
    if (balance < -1 && get_Avl_balance_factor(root->left)>0 ) {
        root->right =RightRotation(root->right); 
        return LeftRotation(root);
    }

    return root;
    
}

void inorder_avl ( avlN * root)
{
    if(!root) {
        return;
    }
    inorder_avl(root ->left);
    printf("%d ",root->val);
    inorder_avl(root ->right);
}

// int main() {
//     avlN *root = NULL;

//     root = insert_AVL(root, 10);
//     root = insert_AVL(root, 20);
//     root = insert_AVL(root, 30);
//     root = insert_AVL(root, 40);
//     root = insert_AVL(root, 50);
//     root = insert_AVL(root, 25);

//     printf("Inorder traversal of the AVL tree: ");
//     inorder_avl(root);
//     printf("\n");

//     root = delete_avl(root, 30);

//     printf("Inorder traversal after deletion of 30: ");
//     inorder_avl(root);
//     printf("\n");


//     return 0;
// }