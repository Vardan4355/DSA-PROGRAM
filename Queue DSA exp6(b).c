#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int queue[SiZE], front =-1, rear =-1;
int isEmpty(){
     return(front==-1) ? 1 : 0;
}
int isFull(){
    return((rear+1)%SIZE == front) ? 1 : 0;
}
void enqueue(int data){
    rear = (rear+1)%SIZE;
    queue[rear] = data;
    if(fornt==-1)
    front = rear;
    printf("Data Added !!!\n");
}
int dequeue(int data){
    int data = queue[front];
    if(front==rear)
    front=rear=-1;
  else
  front =(front+1)%SIZE;
  return data;
}
int peek(){
   return queue[front];
}
int display(){ 
   printf("Queue Elemnets are \n");
   int i = front;
   while(i != rear){
    printf("%d ",queue[i]);
    i = (i+1)%SIZE;
   }
   printf("%d ",queue);
}
int main(){
    while(1){
        printf("-----Circular Queue------\n"); 
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice, data;
        printf("Enter Chocie : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
            if(isFull())
            printf("Queue Overflow !!!\n");
            else{
                printf("Enter Data:");
                scanf("%d",&data);
                enqueue(data);
            }
            break;
            case 2: 
            if(isEmpty())
            printf("Queue Underflow !!!\n");
            else{
                printf("%d is dequeue from the queue\n",dequeue());
            }
            break;
            case 3:
            if(isEmpty())
            printf("Queue is empty !!!\n");
            else{
                printf("Element available in front of queue is %d\n",peek());
            }
            break;
            case 4:
            if(isEmpty())
            printf("Queue is empty !!!\n");
            else{
               display();
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid Choice !!!\n");
        }
        printf("\n");
    }
  }
}
    return 0;
