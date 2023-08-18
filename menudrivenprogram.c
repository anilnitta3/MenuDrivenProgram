#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void createArray(int *arr, int *n) {
  printf("Enter the size of the array: ");
  scanf("%d", n);

  for (int i = 0; i < *n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

void displayArray(int *arr, int n) {
  printf("The array elements are: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertElement(int *arr, int *n, int pos, int ele) {
  if (pos > *n || pos < 1) {
    printf("Invalid position!\n");
    return;
  }

  for (int i = *n - 1; i >= pos - 1; i--) {
    arr[i + 1] = arr[i];
  }

  arr[pos - 1] = ele;
  *n = *n + 1;
}

void deleteElement(int *arr, int *n, int pos) {
  if (pos > *n || pos < 1) {
    printf("Invalid position!\n");
    return;
  }

  for (int i = pos - 1; i < *n - 1; i++) {
    arr[i] = arr[i + 1];
  }

  *n = *n - 1;
}

int main() {
  int arr[MAX], n;

  int choice;

  do {
    printf("\n\nArray Operations\n");
    printf("1. Create Array\n");
    printf("2. Display Array\n");
    printf("3. Insert Element\n");
    printf("4. Delete Element\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        createArray(arr, &n);
        break;
      case 2:
        displayArray(arr, n);
        break;
      case 3: {
        int pos, ele;
        printf("Enter the position and element to insert: ");
        scanf("%d %d", &pos, &ele);
        insertElement(arr, &n, pos, ele);
        break;
      }
      case 4: {
        int pos;
        printf("Enter the position of the element to delete: ");
        scanf("%d", &pos);
        deleteElement(arr, &n, pos);
        break;
      }
      case 5:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}
