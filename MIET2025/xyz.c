#include<stdio.h>
#define MAX_SIZE 100
void Insert(int arr[],int *size,int value){
    if((*size) < MAX_SIZE){
        arr[*size] = value;
        (*size)++;
        printf("Inserted value is %d\n",value);
    }
    else{
        printf("list is full\n");
    }
}
void Delete(int arr[],int* size,int value){
    if(*size == 0){
        printf("List is empty cannot delete any element\n");
    }
    else{
        int i;
        int found = 0;
        for(i=0;i<*size;i++){
            if(arr[i] == value) {
                found = 1;
                break;
            }
        }
        if(found){
            for(int j=i;j<*size-1;j++){
                arr[j] = arr[j+1];
            }
            (*size)--;
        }
        else{
            printf("%d doesnot exist\n",value);
        }
    }
}
void Search(int arr[],int *size,int value){
    if(*size == 0) printf("List is empty\n");
    else{
        for(int i=0;i<*size;i++){
            if(arr[i] == value){
                printf("%d is found at index %d\n",value,i);
                return;
            }
        }
        printf("%d does not found in List\n");
    }
}
void Traversing(int arr[],int *size){
    if(*size == 0) printf("List is empty\n");
    else{
        printf("List elements are :");
        for(int i=0;i<*size;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
int main(){
    int arr[MAX_SIZE];
    int size=0,choice,value;

    while(1){
        printf("1. INSERTION\n");
        printf("2. DELETION\n");
        printf("3. SEARCH\n");
        printf("4. TRAVERSING\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be inserted :");
            scanf("%d",&value);
            Insert(arr,&size,value);
            break;
            case 2:
            printf("Enter the value to be deleted :");
            scanf("%d",&value);
            Delete(arr,&size,value);
            break;
            case 3:
            printf("Enter value for searching :");
            scanf("%d",&value);
            Search(arr,&size,value);
            break;
            case 4:
            Traversing(arr,&size);
            break;
            case 5:
            return 0;
            break;
            default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}