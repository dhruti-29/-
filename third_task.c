#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNo;
    char name[30];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void checkBalance();

int main() {
    int choice;

    while(1) {
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Balance Check");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}

void createAccount() {
    FILE *fp;
    struct Account a;

    fp = fopen("bank.txt", "a");

    printf("Enter account no: ");
    scanf("%d", &a.accNo);

    printf("Enter name: ");
    scanf("%s", a.name);

    printf("Enter initial balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);

    fclose(fp);

    printf("Account Created\n");
}

void deposit() {
    printf("Deposit feature (basic file version)\n");
}

void withdraw() {
    printf("Withdraw feature (basic file version)\n");
}

void checkBalance() {
    FILE *fp;
    struct Account a;

    fp = fopen("bank.txt", "r");

    printf("\nAccount Records:\n");

    while(fread(&a, sizeof(a), 1, fp)) {
        printf("%d %s %.2f\n", a.accNo, a.name, a.balance);
    }

    fclose(fp);
}