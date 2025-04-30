// Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
TreeNode* createNode(int value){
    TreeNode* node = (struct TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
TreeNode* insert(TreeNode* root, int value){
     if(root==NULL)
     return createNode(value);
     else if(value<root->data)
     root->left = insert(root->left, value);
     else
     root->right = insert(root->right, value);
     return root;
}
void preorder(TreeNode* root){
    if(root == NULL)
    return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root){
    if(root == NULL)
    return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void postorder(TreeNode* root){
    if(root ==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}
void levelorder(TreeNode* root){
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front!=rear){
        TreeNode* temp = queue[front++];
        printf("%d",temp->data);
        if(temp->left !=NULL)
            queue[rear++] = temp->left;
            if(temp->right !=NULL)
                queue[rear++] = temp->right;

    }
}
TreeNode* search(TreeNode* root, int target){
   if(root==NULL)
   return NULL;
   else if(root->data == target)
   return root;
   else if(target < root->data)
   return search(root->left, target);
   else
   return search(root->right, target);
} 
TreeNode* findMin(TreeNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
TreeNode* delete(TreeNode* root, int value){
     TreeNode* temp = search(root, value);
     if(temp == NULL)
        printf("Element Not found !!\n");
        else if(value<root->data)
        root->left = delete(root->left,value);
        else if(value>root->data)
        root->right = delete(root->right, value);
        else{
            if(root->left==NULL && root->right==NULL){ // Zero child
                free(root);
                return NULL;
            }
            else if(root->right==NULL){ // only one child(left)
                TreeNode* temp = root->left;
                free(root);
                return temp;
            }
            else if(root->left==NULL){ // only one child(right)
                TreeNode* temp = root->right;
                free(root);
                return temp;
            }
            else { // both child
                TreeNode* temp = findMin(root->right); // find minimum in right subtree
                root->data = temp->data; // replace with minimum value
                delete(root->right, temp->data);// delete the minimum node
                return root; // return the updated root
        }
    }
}
int main(){
    TreeNode* root=NULL;
    int choice, value;
    while(1){
        printf("1. Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Level Order Traversal\n");
        printf("6. Search Element\n");
        printf("7. Delete Element\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Level Order Traversal: ");
                levelorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                TreeNode* result = search(root, value);
                if(result != NULL)
                    printf("Element Found !!\n");
                    else
                    printf("Element Not found !!\n");
                    break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(root, value);
                break;
            case 8:
                exit(0);
                default:
                printf("Invalid choice !!\n");
        }
    }
    return 0;
}
