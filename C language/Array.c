#include <stdio.h>

int main() {
    int arr[50], n, choice;
    int i, pos, value, key, found;

    // Input array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n---- ARRAY OPERATIONS MENU ----\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Searching\n");
        printf("5. Sorting\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: // Traversal
                printf("Array elements are:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2: // Insertion
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);

                for (i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;

                printf("Insertion successful.\n");
                break;

            case 3: // Deletion
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);

                for (i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;

                printf("Deletion successful.\n");
                break;

            case 4: // Searching
                printf("Enter element to search: ");
                scanf("%d", &key);
                found = 0;

                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        printf("Element found at position %d\n", i);
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Element not found.\n");
                }
                break;

            case 5: // Sorting (Ascending)
                for (i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Array sorted in ascending order.\n");
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
