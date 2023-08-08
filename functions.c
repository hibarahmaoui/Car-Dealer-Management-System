#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a car
struct Car {
    int id;
    char make[50];
    char model[50];
    int year;
    float cost;
    struct Car *prev;
    struct Car *next;
};

// Global variables for the linked list
struct Car *head = NULL;
struct Car *tail = NULL;

// Function to insert a new car
void insertCar() {
    struct Car *newCar = (struct Car *)malloc(sizeof(struct Car));
    printf("Enter car make: ");
    scanf("%s", newCar->make);
    printf("Enter car model: ");
    scanf("%s", newCar->model);
    printf("Enter car year: ");
    scanf("%d", &newCar->year);
    printf("Enter car cost: ");
    scanf("%f", &newCar->cost);
    
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
    
    printf("Car added successfully.\n");
}

// Function to display all cars
void displayCars() {
    struct Car *current = head;
    printf("Car List:\n");
    while (current != NULL) {
        printf("ID: %d | Make: %s | Model: %s | Year: %d | Cost: %.2f\n",
               current->id, current->make, current->model, current->year, current->cost);
        current = current->next;
    }
}

// Function to update a car's information by ID
void updateCar() {
    int carId;
    printf("Enter car ID to update: ");
    scanf("%d", &carId);
    
    struct Car *current = head;
    while (current != NULL) {
        if (current->id == carId) {
            printf("Enter new car year: ");
            scanf("%d", &current->year);
            printf("Enter new car cost: ");
            scanf("%f", &current->cost);
            printf("Car information updated.\n");
            return;
        }
        current = current->next;
    }
    
    printf("Car not found.\n");
}

// Function to delete a car by ID
void deleteCar() {
    int carId;
    printf("Enter car ID to delete: ");
    scanf("%d", &carId);
    
    struct Car *current = head;
    while (current != NULL) {
        if (current->id == carId) {
            if (current == head) {
                head = current->next;
                if (head)
                    head->prev = NULL;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Car deleted.\n");
            return;
        }
        current = current->next;
    }
    
    printf("Car not found.\n");
}

// Function to search for a car by Vehicle-ID
void searchCarByID() {
    int carId;
    printf("Enter car ID to search: ");
    scanf("%d", &carId);
    
    struct Car *current = head;
    while (current != NULL) {
        if (current->id == carId) {
            printf("Car found:\n");
            printf("ID: %d | Make: %s | Model: %s | Year: %d | Cost: %.2f\n",
                   current->id, current->make, current->model, current->year, current->cost);
            return;
        }
        current = current->next;
    }
    
    printf("Car not found.\n");
}

// Function to search for cars by Make
void searchCarByMake() {
    char targetMake[50];
    printf("Enter car make to search: ");
    scanf("%s", targetMake);
    
    struct Car *current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->make, targetMake) == 0) {
            printf("Car found:\n");
            printf("ID: %d | Make: %s | Model: %s | Year: %d | Cost: %.2f\n",
                   current->id, current->make, current->model, current->year, current->cost);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No cars found with the specified make.\n");
    }
}

// Function to search for cars by Year
void searchCarByYear() {
    int targetYear;
    printf("Enter car year to search: ");
    scanf("%d", &targetYear);
    
    struct Car *current = head;
    int found = 0;
    while (current != NULL) {
        if (current->year == targetYear) {
            printf("Car found:\n");
            printf("ID: %d | Make: %s | Model: %s | Year: %d | Cost: %.2f\n",
                   current->id, current->make, current->model, current->year, current->cost);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No cars found with the specified year.\n");
    }
}

// Function to search for cars by Cost
void searchCarByCost() {
    float targetCost;
    printf("Enter car cost to search: ");
    scanf("%f", &targetCost);
    
    struct Car *current = head;
    int found = 0;
    while (current != NULL) {
        if (current->cost == targetCost) {
            printf("Car found:\n");
            printf("ID: %d | Make: %s | Model: %s | Year: %d | Cost: %.2f\n",
                   current->id, current->make, current->model, current->year, current->cost);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No cars found with the specified cost.\n");
    }
}

// Function to save data to file and exit
void saveAndExit() {
    FILE *file = fopen("carList.txt", "w");
    if (file) {
        struct Car *current = head;
        while (current != NULL) {
            fprintf(file, "%s %s %d %.2f\n", current->make, current->model, current->year, current->cost);
            current = current->next;
        }
        fclose(file);
    }
    
    printf("Data saved. Exiting program.\n");
    exit(0);
}
