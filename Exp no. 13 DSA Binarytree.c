#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
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
int main(){ //  10 20 30 40 -1 60 70 80 90 -1 -1 -1 -1 100
    int n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    init();
    insert(n);
    printf("\nPreorder Traversal  : ");
    preorder(0);
    printf("\nInorder Traversal : ");
    inorder(0);
    printf("\nPostorder Traversal : ");
    postorder(0);
    return 0;
}
