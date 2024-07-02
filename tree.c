#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    double value;
    struct node* left;
    struct node* right; 
};

void makeChildren(struct node* root);
void branch(struct node* root, int depth);

int main(int argc, char *argv[]){
    srand(time(NULL));

    struct node root;
    root.value = (double)(rand()) / RAND_MAX;
    root.left = NULL;
    root.right = NULL;
    
    makeChildren(&root);
    
    branch(&root, 3); 

    return 0;
}

void makeChildren(struct node* root){
    root->left = (struct node*)malloc(sizeof(struct node));
    root->right = (struct node*)malloc(sizeof(struct node));

    root->left->value = (double)(rand()) / RAND_MAX;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right->value = (double)(rand()) / RAND_MAX;
    root->right->left = NULL;
    root->right->right = NULL;
}

void branch(struct node* root, int depth){
    if (depth == 0 || root == NULL) return;

    root->left = (struct node*)malloc(sizeof(struct node));
    root->right = (struct node*)malloc(sizeof(struct node));

    root->left->value = (double)(rand()) / RAND_MAX;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right->value = (double)(rand()) / RAND_MAX;
    root->right->left = NULL;
    root->right->right = NULL;

    branch(root->left, depth - 1);
    branch(root->right, depth - 1);
}

void unSafeBranch(struct node* root){
    
    root->left = (struct node*)malloc(sizeof(struct node));
    root->right = (struct node*)malloc(sizeof(struct node));

    root->left->value = (double)(rand()) / RAND_MAX;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right->value = (double)(rand()) / RAND_MAX;
    root->right->left = NULL;
    root->right->right = NULL;

    unSafeBranch(root->left);
    unSafeBranch(root->right);
}