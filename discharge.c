#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "discharge.dat"
#define MAX_NAME 100
#define MAX_DIAGNOSIS 200
#define MAX_CONTACT 50

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int id;
    char name[MAX_NAME];
    int age;
    char gender[10];
    char diagnosis[MAX_DIAGNOSIS];
    int daysAdmitted;
    float roomChargePerDay;
    float medicineCost;
    float otherCharges;
    char contact[MAX_CONTACT];
} Patient;

// ------------------ FUNCTION DECLARATIONS ------------------
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void savePatient(Patient p);
int idExists(int id);

void loadPatients(Patient patients[], int *count);
void writeAllPatients(Patient patients[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n======================================\n");
        printf("     HOSPITAL DISCHARGE MANAGEMENT\n");
        printf("======================================\n");
        printf("1. Add Patient Discharge Record\n");
        printf("2. View All Discharge Records\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient Record\n");
        printf("5. Delete Patient Record\n");
        printf("6. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD PATIENT ------------------
void addPatient() {
    Patient p;

    printf("\n--- Add Patient Discharge Record ---\n");

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    getchar();

    if (idExists(p.id)) {
        printf("Error: Patient ID already exists!\n");
        return;
    }

    printf("Enter Patient Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();

    printf("Enter Gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    p.gender[strcspn(p.gender, "\n")] = '\0';

    printf("Enter Diagnosis: ");
    fgets(p.diagnosis, sizeof(p.diagnosis), stdin);
    p.diagnosis[strcspn(p.diagnosis, "\n")] = '\0';

    printf("Enter Days Admitted: ");
    scanf("%d", &p.daysAdmitted);
    getchar();

    printf("Enter Room Charge Per Day: ");
    scanf("%f", &p.roomChargePerDay);
    getchar();

    printf("Enter Medicine Cost: ");
    scanf("%f", &p.medicineCost);
    getchar();

    printf("Enter Other Charges: ");
    scanf("%f", &p.otherCharges);
    getchar();

    printf("Enter Contact Info: ");
    fgets(p.contact, sizeof(p.contact), stdin);
    p.contact[strcspn(p.contact, "\n")] = '\0';

    savePatient(p);
    printf("Patient discharge record added successfully!\n");
}

// ------------------ SAVE TO FILE ------------------
void savePatient(Patient p) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("File error");
        return;
    }
    fwrite(&p, sizeof(Patient), 1, fp);
    fclose(fp);
}

// ------------------ CHECK IF ID EXISTS ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Patient p;
    while (fread(&p, sizeof(Patient), 1, fp)) {
        if (p.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW PATIENTS ------------------
void viewPatients() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No discharge records found.\n");
        return;
    }

    Patient p;
    printf("\n%-5s %-20s %-5s %-10s %-15s %-8s %-12s %-12s %-12s %-12s\n",
           "ID", "Name", "Age", "Gender", "Diagnosis",
           "Days", "Room/day", "Medicine", "Other", "Total");

    printf("-----------------------------------------------------------------------------------------------------------\n");

    while (fread(&p, sizeof(Patient), 1, fp)) {
        float total = (p.daysAdmitted * p.roomChargePerDay) +
                       p.medicineCost + p.otherCharges;

        printf("%-5d %-20s %-5d %-10s %-15s %-8d %-12.2f %-12.2f %-12.2f %-12.2f\n",
               p.id, p.name, p.age, p.gender, p.diagnosis,
               p.daysAdmitted, p.roomChargePerDay, p.medicineCost,
               p.otherCharges, total);
    }
    fclose(fp);
}

// ------------------ SEARCH PATIENT ------------------
void searchPatient() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Patient p;

    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp)) {
        if (p.id == id) {
            float total = (p.daysAdmitted * p.roomChargePerDay) +
                           p.medicineCost + p.otherCharges;

            printf("\nPatient Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nDiagnosis: %s\n",
                   p.id, p.name, p.age, p.gender, p.diagnosis);

            printf("Days Admitted: %d\nRoom Charge/Day: %.2f\nMedicine Cost: %.2f\n",
                   p.daysAdmitted, p.roomChargePerDay, p.medicineCost);

            printf("Other Charges: %.2f\nTotal Bill: %.2f\nContact: %s\n",
                   p.otherCharges, total, p.contact);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("No record found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE PATIENT ------------------
void updatePatient() {
    Patient patients[500];
    int count = 0, id, found = 0;

    loadPatients(patients, &count);

    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            found = 1;

            printf("Enter new diagnosis: ");
            fgets(patients[i].diagnosis, sizeof(patients[i].diagnosis), stdin);
            patients[i].diagnosis[strcspn(patients[i].diagnosis, "\n")] = '\0';

            printf("Enter new medicine cost: ");
            scanf("%f", &patients[i].medicineCost);
            getchar();

            printf("Enter new other charges: ");
            scanf("%f", &patients[i].otherCharges);
            getchar();

            printf("Enter new contact info: ");
            fgets(patients[i].contact, sizeof(patients[i].contact), stdin);
            patients[i].contact[strcspn(patients[i].contact, "\n")] = '\0';

            break;
        }
    }

    if (found) {
        writeAllPatients(patients, count);
        printf("Record updated successfully.\n");
    } else {
        printf("Patient ID not found.\n");
    }
}

// ------------------ DELETE PATIENT ------------------
void deletePatient() {
    Patient patients[500];
    int count = 0, id, found = 0;

    loadPatients(patients, &count);

    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            found = 1;

            printf("Are you sure you want to delete %s (ID %d)? (y/n): ",
                   patients[i].name, id);
            char c = getchar();
            getchar();

            if (c == 'y' || c == 'Y') {
                for (int j = i; j < count - 1; j++)
                    patients[j] = patients[j + 1];

                count--;
                writeAllPatients(patients, count);
                printf("Record deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Patient ID not found.\n");
}

// ------------------ LOAD & WRITE FUNCTIONS ------------------
void loadPatients(Patient patients[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;

    *count = 0;
    while (fread(&patients[*count], sizeof(Patient), 1, fp))
        (*count)++;

    fclose(fp);
}

void writeAllPatients(Patient patients[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("File error");
        return;
    }

    fwrite(patients, sizeof(Patient), count, fp);
    fclose(fp);
}
