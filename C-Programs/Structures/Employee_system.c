#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    char name[50];
    char designation[50];
    char gender;
    float salary;
};

void inputEmployees(struct Employee e[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Name: ");
        scanf("%s", e[i].name);

        printf("Designation: ");
        scanf("%s", e[i].designation);

        printf("Gender (M/F): ");
        scanf(" %c", &e[i].gender);

        printf("Salary: ");
        scanf("%f", &e[i].salary);
    }
}

void countGender(struct Employee e[], int n) {
    int male = 0, female = 0;

    for (int i = 0; i < n; i++) {
        if (e[i].gender == 'M' || e[i].gender == 'm')
            male++;
        else if (e[i].gender == 'F' || e[i].gender == 'f')
            female++;
    }

    printf("Male: %d\nFemale: %d\n", male, female);
}

void highSalary(struct Employee e[], int n) {
    printf("Employees with salary > 10000:\n");
    for (int i = 0; i < n; i++) {
        if (e[i].salary > 10000)
            printf("%s\n", e[i].name);
    }
}

void designationFilter(struct Employee e[], int n) {
    printf("Employees with designation 'Asst Manager':\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(e[i].designation, "Asst") == 0 ||
            strcmp(e[i].designation, "AsstManager") == 0)
            printf("%s\n", e[i].name);
    }
}

int main() {
    struct Employee emp[MAX];
    int n;

    printf("===== EMPLOYEE SYSTEM =====\n");
    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number!\n");
        return 1;
    }

    inputEmployees(emp, n);

    printf("\nTotal Employees: %d\n", n);
    countGender(emp, n);
    highSalary(emp, n);
    designationFilter(emp, n);

    return 0;
}
