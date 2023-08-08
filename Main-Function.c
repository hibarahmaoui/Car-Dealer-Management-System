#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Load data from file into the linked list
    FILE *file = fopen("carList.txt", "r");
    if (file) {
        while (!feof(file)) {
            struct Car *newCar = (struct Car *)malloc(sizeof(struct Car));
            if (fscanf(file, "%s %s %d %f", newCar->make, newCar->model, &newCar->year, &newCar->cost) == 4) {
                newCar->id = (tail ? tail->id + 1 : 1);
                newCar->next = NULL;
                
                if (tail == NULL) {
                    head = newCar;
                    tail = newCar;
                } else {
                    newCar->prev = tail;
                    tail->next = newCar;
                    tail = newCar;
                }
            }
        }
        fclose(file);
    }
    
    int choice;
    while (1) {
        printf("\nCar Dealer Management System\n");
        printf("1. Display all Cars\n");
        printf("2. Insert a new Car\n");
        printf("3. Update a Car by Vehicle-ID\n");
        printf("4. Delete a Car by Vehicle-ID\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCars();
                break;
            case 2:
                insertCar();
                break;
            case 3:
                updateCar();
                break;
            case 4:
                deleteCar();
                break;
            case 5:
                printf("Search options:\n");
                printf("1. Search by Vehicle-ID\n");
                printf("2. Search by Make\n");
                printf("3. Search by Year\n");
                printf("4. Search by Cost\n");
                printf("Enter your search option: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        searchCarByID();
                        break;
                    case 2:
                        searchCarByMake();
                        break;
                    case 3:
                        searchCarByYear();
                        break;
                    case 4:
                        searchCarByCost();
                        break;
                    default:
                        printf("Invalid search option.\n");
                }
                break;
            case 6:
                saveAndExit();
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
