#include<stdio.h>
#incldue<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
TreeNode* createNode(int value){
    TreeNode* node = (struct TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    mode->left = nod->right = NULL;
    return node;
}
void insert(TreeNode* root, int value){

}
void preorder(TreeNode* root){
    if(root == NULl)
    return;
    printf("%d", root->data);
    preorder(root->left);
    prerorder(root->right);
}
void inorder(TreeNode* root){
    if(root == NULl)
    return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void postorder(TreeNode* root){
    if(root == NULl)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}
