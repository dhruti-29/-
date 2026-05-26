#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[30];
    float marks;
};

void addStudent();
void displayStudents();

int main() {
    int choice;

    while(1) {
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}

void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("student.txt", "a");

    printf("Enter roll no: ");
    scanf("%d", &s.roll);

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("Student Added\n");
}

void displayStudents() {
    FILE *fp;
    struct Student s;

    fp = fopen("student.txt", "r");

    printf("\n--- Student List ---\n");

    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d %s %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}