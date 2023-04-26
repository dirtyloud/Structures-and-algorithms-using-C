#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertNode(struct TreeNode*, int);
void printNode(struct TreeNode*);
struct TreeNode* newNode(int);
struct TreeNode* findMinNodeRec(struct TreeNode*);
struct TreeNode* findMaxNodeRec(struct TreeNode*);
struct TreeNode* deleteNode(struct TreeNode*, int);

int main(){
    struct TreeNode* root = NULL;
    root = insertNode(root, 1);
    root = insertNode(root, 0);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = deleteNode(root, 2);
    printNode(root);
    return 0;
}

struct TreeNode* newNode(int data){
    struct TreeNode* buffer = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    buffer -> data = data;
    buffer -> left = NULL;
    buffer -> right = NULL;
    return buffer;
}

struct TreeNode* insertNode(struct TreeNode* root, int data){
    if (root == NULL)
        root = newNode(data);
    else if(root -> data > data)
        root -> left = insertNode(root -> left, data);
    else
        root -> right = insertNode(root -> right, data);
    return root;
}

void printNode(struct TreeNode* root){
    if (root){
        printNode(root -> left);
        printf("%5d", root -> data);
        printNode(root -> right);
    }
}

struct TreeNode* findMaxNodeIt(struct TreeNode* root){
    while(root -> right){
        root = root -> right;
    }
    return root;
}

struct TreeNode* findMinNodeIt(struct TreeNode* root){
    while(root -> left){
        root = root -> left;
    }
    return root;
}

struct TreeNode* findMaxNodeRec(struct TreeNode* root){
    if (root == NULL){
        exit(4);
    }
    if (root -> right){
        return findMaxNodeRec(root -> right);
    }
    return root;
}

struct TreeNode* findMinNodeRec(struct TreeNode* root){
    if (root == NULL){
        exit(4);
    }
    if (root -> left){
        return findMinNodeRec(root -> left);
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int value){
    if (root -> data > value){
        root -> left = deleteNode(root -> left, value);
        return root;
    }
    else if(root -> data < value){
        root -> right = deleteNode(root -> right, value);
        return root;
    }
    else{
        if (root -> left && root -> right){
            struct TreeNode* buffer = findMaxNodeRec(root -> left);
            root -> data = buffer -> data;
            root -> left = deleteNode(root -> left, buffer -> data);
            return root;
        }
        else if (root -> left){
            struct TreeNode* buffer = root -> left;
            free(root);
            return buffer;
        }
        else if (root -> right){
            struct TreeNode* buffer = root -> right;
            free(root);
            return buffer;
        }
        else{
            free(root);
            return NULL;
        }
    }
}
