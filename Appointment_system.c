#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "appointments.dat"

struct Appointment {
    int id;
    char name[50];
    char date[15];
    char time[10];
    char description[100];
};

// Function declarations
void addAppointment();
void viewAppointments();
void searchAppointment();
void deleteAppointment();
int getNewId();

int main() {
    int choice;
    do {
        printf("\n====== Appointment Management System ======\n");
        printf("1. Add Appointment\n");
        printf("2. View All Appointments\n");
        printf("3. Search Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch (choice) {
            case 1: addAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: searchAppointment(); break;
            case 4: deleteAppointment(); break;
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Generate a new unique ID (safe version)
int getNewId() {
    FILE *fp = fopen(FILENAME, "rb");
    struct Appointment app;
    int maxId = 0;

    if (fp == NULL)
        return 1;

    while (fread(&app, sizeof(app), 1, fp)) {
        // Avoid garbage values
        if (app.id > 0 && app.id < 1000000) {
            if (app.id > maxId)
                maxId = app.id;
        }
    }

    fclose(fp);
    return maxId + 1;
}

// Add a new appointment
void addAppointment() {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Appointment app;
    app.id = getNewId();

    printf("Enter Name: ");
    fgets(app.name, sizeof(app.name), stdin);
    app.name[strcspn(app.name, "\n")] = '\0';

    printf("Enter Date (DD/MM/YYYY): ");
    fgets(app.date, sizeof(app.date), stdin);
    app.date[strcspn(app.date, "\n")] = '\0';

    printf("Enter Time (HH:MM): ");
    fgets(app.time, sizeof(app.time), stdin);
    app.time[strcspn(app.time, "\n")] = '\0';

    printf("Enter Description: ");
    fgets(app.description, sizeof(app.description), stdin);
    app.description[strcspn(app.description, "\n")] = '\0';

    fwrite(&app, sizeof(app), 1, fp);
    fclose(fp);

    printf("Appointment added successfully with ID %d!\n", app.id);
}

// View all appointments
void viewAppointments() {
    FILE *fp = fopen(FILENAME, "rb");
    struct Appointment app;

    if (fp == NULL) {
        printf("No appointments found.\n");
        return;
    }

    printf("\n==== All Appointments ====\n");
    while (fread(&app, sizeof(app), 1, fp)) {
        printf("\nID: %d\nName: %s\nDate: %s\nTime: %s\nDescription: %s\n",
               app.id, app.name, app.date, app.time, app.description);
    }

    fclose(fp);
}

// Search appointment by name or date
void searchAppointment() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("No appointments found.\n");
        return;
    }

    struct Appointment app;
    char search[50];
    int found = 0, choice;

    printf("\nSearch by:\n1. Name\n2. Date\nEnter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter search term: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';

    while (fread(&app, sizeof(app), 1, fp)) {
        if ((choice == 1 && stricmp(app.name, search) == 0) ||
            (choice == 2 && strcmp(app.date, search) == 0)) {
            printf("\nID: %d\nName: %s\nDate: %s\nTime: %s\nDescription: %s\n",
                   app.id, app.name, app.date, app.time, app.description);
            found = 1;
        }
    }

    if (!found)
        printf("No matching appointments found.\n");

    fclose(fp);
}

// Delete an appointment by ID
void deleteAppointment() {
    FILE *fp = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Appointment app;
    int id, found = 0;

    printf("Enter Appointment ID to delete: ");
    scanf("%d", &id);

    while (fread(&app, sizeof(app), 1, fp)) {
        if (app.id != id)
            fwrite(&app, sizeof(app), 1, temp);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (found)
        printf("Appointment deleted successfully!\n");
    else
        printf("Appointment not found.\n");
}