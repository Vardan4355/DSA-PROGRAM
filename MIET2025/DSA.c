#include <stdio.h>

#define MAX_SIZE 100  

void insert(int arr[], int *size, int value) {
    if (*size < MAX_SIZE) {
        arr[*size] = value;
        (*size)++;
        printf("Inserted %d\n", value);
    } else {
        printf("List is full! Cannot insert.\n");
    }
}

void delete(int arr[], int *size, int value) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *size - 1; j++) {
            arr[j] = arr[j + 1];  
        }
        (*size)--;  
        printf("Deleted %d\n", value);
    } else {
        printf("Value %d not found!\n", value);
    }
}

void search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Found %d at index %d\n", value, i);
            return;
        }
    }
    printf("Value %d not found!\n", value);
}

void traverse(int arr[], int size) {
    if (size == 0) {
        printf("The list is empty!\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;  
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &size, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(arr, &size, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(arr, size, value);
                break;
            case 4:
                traverse(arr, size);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
