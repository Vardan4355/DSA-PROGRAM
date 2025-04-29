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
     root->roght = insert(root->right, value);
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
   
}
  
void delete(TreeNode* root, int value){
     TreeNode* temp = search(root, value);
     if(temp == NULL)
        printf("Element Not found !!\n");
        else{
           
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
                printf("Enter value to insert : ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("\nPreorder Traversal  : ");
                preorder(root);
                break;
            case 3:
                printf("\nInorder Traversal : ");
                inorder(root);        
                break;
            case 4:
                printf("\nPostorder Traversal : ");
                postorder(root);
                break;
            case 5:
                printf("\nLevel Order Traversal : ");
                levelorder(root);
                break;
                case 6: 
                printf("Enter value to search :");
                scanf("%d",&value);
                TreeNode* result = search(root, value);
                case 7:
                printf("Enter value to delete :");
                scanf("%d",&value);
                TreeNode* last = findDeepest(root);
                break;
                
            case 8:
                exit(0);
            default:
                printf("Invalid choice !!\n");
        }
    }
}
