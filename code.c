#include<stdio.h>
#include<stdlib.h>
#define SIZE 
int tree[SIZE];
void init(){
    for(int i=0; i<SIZE; i++){
        tree[i] = -1;
    }
}
void insert(int n){
    for(int i=0; i<n; i++){
        scanf("%d",&tree[i]);
        }
    }
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
int search(int i, int target){
    while(tree[i] != -1){
        if(tree[i] == target)
        return i;
        else if(target < tree[i])
        i = 2*i + 1; // left child
        else
        i = 2*i + 2; // right child
    }
    return -1;
}
int findSIZE(int i){// left child
    while(i*2 +1 < SIZE && tree[i*2 +1] != -1){
        i = i*2 + 1;
    }
    return i;
}
int findSIZE(int i){ // right child
    while(i*2 +1 < SIZE && tree[i*2 +1] != -1){
        i = i*2 + 2;
    }
    return i;
}
void delete(int i , int value){
    i = search(i, value);
   if(i==-1)
   printf("Element Not found !!\n");
   else{
        int left = 2*i + 1;
        int right = 2*i + 2;
        if((left >=SIZE || tree[left]==-1) && (right >=SIZE || tree[right]==-1))
        tree[i] = -1;
  else if(tree[right]==-1){ // only left child
       int SIZE = findSIZE(left);
       tree[i] = tree[SIZE];
       delete(SIZE, tree{SIZE});
   }
   else if(tree[left]==-1){ // only right child
      int SIZE = findSIZE(right);
      tree[i] = tree[SIZE];
      delete(SIZE, tree[SIZE]);
   }
      else{// both child
         int SIZE = findSIZE(right);
         tree[i] = tree[SIZE];
         delete(SIZE, tree[SIZE]);
      }
   }
}
int main(){ //  10 20 30 40 -1 60 70 80 90 -1 -1 -1 -1 100
    int n, result, value, choice,i;
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
                printf("Enter number of nodes : ");
                scanf("%d",&n);
                init();
                insert(n);
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
                printf("\nEnter element to search : ");
                scanf("%d",&value);
                result = search(i, value);
                if(result == -1)
                    printf("Element Not Found !!\n");
                else
                    printf("Element Found at index %d !!\n", result);
                break;
            case 6:
                printf("\nEnter element to delete : ");
                scanf("%d",&value);
                delete(i,value);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice !!\n");
        }
    }
    return 0;
}
