#include <stdio.h>

#define MAX 100

struct Student 
{
    int roll;
    char name[50];
    float marks;
};

void inputStudents(struct Student s[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void displayStudents(struct Student s[], int n)
 {
    printf("\n----- STUDENT DETAILS -----\n");
    for (int i = 0; i < n; i++) 
	{
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName   : %s", s[i].name);
        printf("\nMarks  : %.2f\n", s[i].marks);
    }
}

int main() 
{
    struct Student students[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) 
	{
        printf("Invalid number!\n");
        return 1;
    }

    inputStudents(students, n);
    displayStudents(students, n);

    return 0;
}
