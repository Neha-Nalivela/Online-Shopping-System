#include <stdio.h>
#include <string.h>

// Structures
typedef struct {
    char username[50];
    char password[50];
} User;

// Global variables
User users[100];
int numUsers = 0;
char y, i;

// Function prototypes
void login();
void createUser();
int authenticateUser(char username[], char password[]);
int isUsernameExists(char username[]);
void welcome();
char selectCategory();
void displayItems(char category);
void handleFruitPurchase(double* totalBill);
void handleVegetablePurchase(double* totalBill);
void handleStationeryPurchase(double* totalBill);
void handleElectronicsPurchase(double* totalBill);
void handleMiscellaneousPurchase(double* totalBill);

int main() {
    int choice;
    do {
        printf("\n--- Online Shopping ---\n");
        printf("1. Login\n");
        printf("2. Create an account\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: login(); break;
            case 2: createUser(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 3);

    return 0;
}

void login() {
    char username[50], password[50];
    printf("\nEnter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (authenticateUser(username, password)) {
        printf("Login successful. Welcome, %s!\n", username);
        welcome();
        char categoryChoice;
        double totalBill = 0.0;
        do {
            categoryChoice = selectCategory();
            if (categoryChoice != 'q') {
                displayItems(categoryChoice);
                switch (categoryChoice) {
                    case '1': handleFruitPurchase(&totalBill); break;
                    case '2': handleVegetablePurchase(&totalBill); break;
                    case '3': handleStationeryPurchase(&totalBill); break;
                    case '4': handleElectronicsPurchase(&totalBill); break;
                    case '5': handleMiscellaneousPurchase(&totalBill); break;
                    default: printf("Invalid category choice.\n"); break;
                }
            }
        } while (categoryChoice != 'q');

        printf("Your total bill is: Rs. %.2f\n", totalBill);
    } else {
        printf("Invalid username or password.\n");
    }
}

void createUser() {
    char username[50], password[50];
    printf("\nEnter new username: ");
    scanf("%s", username);
    if (isUsernameExists(username)) {
        printf("Username already exists. Try another.\n");
        return;
    }
    printf("Enter new password: ");
    scanf("%s", password);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    numUsers++;
    printf("Account created successfully!\n");
}

int authenticateUser(char username[], char password[]) {
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int isUsernameExists(char username[]) {
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) return 1;
    }
    return 0;
}

void welcome() {
    printf("\n\n--------------------\n");
    printf(" Online Shopping System\n");
    printf(" Made By *** ANONYMOUS ***\n");
    printf("--------------------\n\n");
}

char selectCategory() {
    char choice;
    printf("\n** GENERAL CATEGORIES **\n");
    printf("1. Fruits\n");
    printf("2. Vegetables\n");
    printf("3. Stationery\n");
    printf("4. Electronics\n");
    printf("5. Miscellaneous\n");
    printf("Press 'q' to Quit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice); // Note: space before %c
    return choice;
}

void displayItems(char category) {
    switch (category) {
        case '1':
            printf("Fruits:\n1. Bananas - 50\n2. Mangoes - 100\n3. Apples - 150\n4. Pineapples - 130\n5. Grapes - 200\n");
            break;
        case '2':
            printf("Vegetables:\n1. Eggplant - 75\n2. Beetroot - 110\n3. Green Chillies - 180\n4. Sweetcorn - 300\n5. Onion - 30\n");
            break;
        case '3':
            printf("Stationery:\n1. Gum Bottle - 10\n2. Punching Machine - 30\n3. Sealing Wax - 50\n4. Tea Set - 300\n5. Cleaning Powder - 30\n");
            break;
        case '4':
            printf("Electronics:\n1. Computer Items - 50\n2. Mobile Items - 50\n3. Wires - 550\n4. Appliances - 50\n5. All Electronics - 50\n");
            break;
        case '5':
            printf("Miscellaneous:\n1. Bubble Bath Card - 6000\n2. Kitchen Items - 50\n3. Room Items - 50\n4. Bathroom Items - 50\n");
            break;
    }
}

void handleFruitPurchase(double* totalBill) {
    int choice;
    double prices[] = {50, 100, 150, 130, 200};
    printf("Enter fruit choice (1-5): ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 5) {
        *totalBill += prices[choice - 1];
        printf("Item added. Current Bill: Rs. %.2f\n", *totalBill);
    } else {
        printf("Invalid fruit choice.\n");
    }
}

void handleVegetablePurchase(double* totalBill) {
    int choice;
    double prices[] = {75, 110, 180, 300, 30};
    printf("Enter vegetable choice (1-5): ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 5) {
        *totalBill += prices[choice - 1];
        printf("Item added. Current Bill: Rs. %.2f\n", *totalBill);
    } else {
        printf("Invalid vegetable choice.\n");
    }
}

void handleStationeryPurchase(double* totalBill) {
    int choice;
    double prices[] = {10, 30, 50, 300, 30};
    printf("Enter stationery choice (1-5): ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 5) {
        *totalBill += prices[choice - 1];
        printf("Item added. Current Bill: Rs. %.2f\n", *totalBill);
    } else {
        printf("Invalid stationery choice.\n");
    }
}

void handleElectronicsPurchase(double* totalBill) {
    int choice;
    double prices[] = {50, 50, 550, 50, 50};
    printf("Enter electronics choice (1-5): ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 5) {
        *totalBill += prices[choice - 1];
        printf("Item added. Current Bill: Rs. %.2f\n", *totalBill);
    } else {
        printf("Invalid electronics choice.\n");
    }
}

void handleMiscellaneousPurchase(double* totalBill) {
    int choice;
    double prices[] = {6000, 50, 50, 50};
    printf("Enter miscellaneous choice (1-4): ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 4) {
        *totalBill += prices[choice - 1];
        printf("Item added. Current Bill: Rs. %.2f\n", *totalBill);
    } else {
        printf("Invalid miscellaneous choice.\n");
    }
}

