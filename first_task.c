#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *count);
void displayStudents(struct Student s[], int count);
void searchStudent(struct Student s[], int count);
void findTopper(struct Student s[], int count);

int main() {

    struct Student students[100];
    int count = 0;
    int choice;

    do {

        printf("\n--- STUDENT MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Find Topper\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                findTopper(students, count);
                break;

            case 5:
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}


// Add Student
void addStudent(struct Student s[], int *count) {

    printf("Enter Roll Number: ");
    scanf("%d", &s[*count].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;

    printf("Student Added Successfully\n");
}


// Display Students
void displayStudents(struct Student s[], int count) {

    if(count == 0) {
        printf("No Records Found\n");
        return;
    }

    printf("\nStudent Records:\n");

    for(int i = 0; i < count; i++) {

        printf("\nStudent %d\n", i + 1);
        printf("Roll No : %d\n", s[i].rollNo);
        printf("Name    : %s\n", s[i].name);
        printf("Marks   : %.2f\n", s[i].marks);
    }
}


// Search Student
void searchStudent(struct Student s[], int count) {

    int roll;
    int found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {

        if(s[i].rollNo == roll) {

            printf("\nStudent Found\n");
            printf("Roll No : %d\n", s[i].rollNo);
            printf("Name    : %s\n", s[i].name);
            printf("Marks   : %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Student Not Found\n");
    }
}


// Find Topper
void findTopper(struct Student s[], int count) {

    if(count == 0) {
        printf("No Records Available\n");
        return;
    }

    int topper = 0;

    for(int i = 1; i < count; i++) {

        if(s[i].marks > s[topper].marks) {
            topper = i;
        }
    }

    printf("\nTopper Details\n");
    printf("Roll No : %d\n", s[topper].rollNo);
    printf("Name    : %s\n", s[topper].name);
    printf("Marks   : %.2f\n", s[topper].marks);
}