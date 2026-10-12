
#include <stdio.h>

#define MAX 100

struct Package {
    int id;
    float value;
    float weight;
    float ratio;
    float fraction;
};

struct Package packages[MAX];
int n = 0;
float capacity = 0;

// Calculate value/weight ratio
void calculateRatio() {
    if (n == 0) {
        printf("\nPlease enter package details first!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        packages[i].ratio = packages[i].value / packages[i].weight;
    }

    printf("\nValue/Weight ratios calculated successfully.\n");
}

// Sort packages in decreasing order of ratio
void sortPackages() {
    if (n == 0) {
        printf("\nPlease enter package details first!\n");
        return;
    }

    // Ensure ratios are calculated
    for (int i = 0; i < n; i++) {
        packages[i].ratio = packages[i].value / packages[i].weight;
    }

    struct Package temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (packages[j].ratio < packages[j + 1].ratio) {
                temp = packages[j];
                packages[j] = packages[j + 1];
                packages[j + 1] = temp;
            }
        }
    }

    printf("\nPackages sorted by Value/Weight ratio.\n");
}

// Enter package details
void enterPackages() {
    printf("Enter number of packages (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of packages!\n");
        n = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        packages[i].id = i + 1;

        printf("\nPackage %d\n", i + 1);

        do {
            printf("Enter value/profit: ");
            scanf("%f", &packages[i].value);

            if (packages[i].value < 0)
                printf("Value cannot be negative.\n");

        } while (packages[i].value < 0);

        do {
            printf("Enter weight: ");
            scanf("%f", &packages[i].weight);

            if (packages[i].weight <= 0)
                printf("Weight must be greater than zero.\n");

        } while (packages[i].weight <= 0);

        packages[i].ratio =
            packages[i].value / packages[i].weight;

        packages[i].fraction = 0;
    }

    do {
        printf("\nEnter vehicle capacity: ");
        scanf("%f", &capacity);

        if (capacity < 0)
            printf("Capacity cannot be negative.\n");

    } while (capacity < 0);

    printf("\nPackage details entered successfully.\n");
}

// Display package details
void displayPackages() {
    if (n == 0) {
        printf("\nPlease enter package details first!\n");
        return;
    }

    printf("\n%-10s %-12s %-12s %-15s\n",
           "Package", "Value", "Weight", "V/W Ratio");

    printf("---------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-12.2f %-12.2f %-15.2f\n",
               packages[i].id,
               packages[i].value,
               packages[i].weight,
               packages[i].ratio);
    }
}

void findMaximumValue() {
    if (n == 0) {
        printf("\nPlease enter package details first!\n");
        return;
    }

    sortPackages();

    float remaining = capacity;
    float totalValue = 0;
    float totalWeight = 0;

    for (int i = 0; i < n; i++) {
        packages[i].fraction = 0;
    }

    for (int i = 0; i < n && remaining > 0; i++) {
        if (packages[i].weight <= remaining) {
            // Take the complete package
            packages[i].fraction = 1.0;

            remaining -= packages[i].weight;
            totalWeight += packages[i].weight;
            totalValue += packages[i].value;
        } else {
            // Take only the fraction that fits
            packages[i].fraction =
                remaining / packages[i].weight;

            totalValue +=
                packages[i].value * packages[i].fraction;

            totalWeight += remaining;
            remaining = 0;
        }
    }

    printf("\n========== OPTIMAL DELIVERY PLAN ==========\n");

    printf("\nSelected Packages:\n");
    printf("%-10s %-12s %-12s %-12s %-12s\n",
           "Package", "Value", "Weight",
           "Fraction", "Value Taken");

    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (packages[i].fraction > 0) {
            printf("%-10d %-12.2f %-12.2f %-12.2f %-12.2f\n",
                   packages[i].id,
                   packages[i].value,
                   packages[i].weight,
                   packages[i].fraction,
                   packages[i].value * packages[i].fraction);
        }
    }

    printf("\nVehicle Capacity : %.2f\n", capacity);
    printf("Total Weight Used: %.2f\n", totalWeight);
    printf("Remaining Capacity: %.2f\n", remaining);
    printf("Maximum Value    : %.2f\n", totalValue);

    printf("\nTime Complexity: O(n^2) using Bubble Sort.\n");
    printf("Space Complexity: O(n).\n");
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n========== SMART DELIVERY PLANNING ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterPackages();
                break;

            case 2:
                displayPackages();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                displayPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                findMaximumValue();
                break;

            case 7:
                printf("\nExiting program. Thank you!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
