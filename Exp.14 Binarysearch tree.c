#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int tree[SIZE];
void init(){
    for(int i=0; i<SIZE; i++){
        tree[i] = -1;
    }
}
void insert(int value){
   int i=0;
   while(tree[i]!= -1){
    if(value<tree[i])
    i = 2*i+1;
    else
    i=2*i+2;
   }
   tree[i]=value;
}
// void insert(int root, int value){
//      if(tree[root]== -1)
//       tree[root]=value;
//     else if(value<tree[root])
//     insert(2*root+1, value);
//     else if(value>tree[root])
//     insert(2*root+2, value);
//     }
 void preorder(int root){
    if(tree[root] == -1)
        return ;
        printf("%d ", tree[root]);
         preorder(2*root +1); // left child
        preorder(2*root +2);  // right child
}
void inorder(int root){
    if(tree[root] == -1)
        return ;
         inorder(2*root +1); // left child
         printf("%d ", tree[root]);
        inorder(2*root +2);  // right child
    }
void postorder(int root){
    if(tree[root] == -1)
        return ;
        postorder(2*root +1); // left child
        postorder(2*root +2);  // right child
        printf("%d ", tree[root]);
    }
// int search(int root, int key){
//          if(tree[root] == -1)
//          return 0;
//          if(tree[root] == key){
//             printf("Element Found !!\n");
//             return 1;
//          }
//          if(search(2*root +1, key) == 1)
//          return 1;
//          if(search(2*root +2, key) == 1)
//          return 1;
//          return 0;
//     }
int search(int i, int target){
      i=0;
     while(tree[i]!= -1){
         if(tree[i]==target)
         return i;
         else if(target<tree[i])
         i=2*i +1;
         else
         i=2*i +2;
     }
     return -1;
}
void delete(int value){
   
}
int main(){ //  10 20 30 40 -1 60 70 80 90 -1 -1 -1 -1 100
    int root, index, value, choice;
    while(1){
        printf("1. Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6. Delete Element\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value : ");
                printf("Enter root :");
                scanf("%d",&root);
                scanf("%d",&value);
                init();
                insert(value);
                break;
            case 2:
                printf("\nPreorder Traversal  : ");
                preorder(0);
                break;
            case 3:
                printf("\nInorder Traversal : ");
                inorder(0);        
                break;
            case 4:
                printf("\nPostorder Traversal : ");
                postorder(0);
                break;
            case 5:
                 printf("Enter element to search : ");
                 scanf("%d",&value);
                 index = search(0,value);
                 if(index == -1)
                     printf("Element Not Found !!\n");
                else
                     printf("Element Found at index %d !!\n", index);
                break;
            case 6:
                // printf("\nEnter element to delete : ");
                // scanf("%d",&value);
                // delete(value);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice !!\n");
        }
    }
    return 0;
}
