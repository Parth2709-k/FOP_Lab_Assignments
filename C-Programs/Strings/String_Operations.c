#include <stdio.h>
#include <string.h>

void clearBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() 
{
    char str1[100], str2[100], str3[200];
    int choice;

    while (1) 
    {
        printf("\n--- String Operations Menu ---");
        printf("\n1. String Length (strlen)");
        printf("\n2. String Copy (strcpy)");
        printf("\n3. String Concatenation (strcat)");
        printf("\n4. String Comparison (strcmp)");
        printf("\n5. Reverse String (strrev)");
        printf("\n6. Search Substring (strstr)");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        if (choice == 7) break;

        printf("Enter the first string: ");
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = 0;

        switch (choice) 
        {
            case 1:
                printf("Length: %lu\n", strlen(str1));
                break;

            case 2:
                strcpy(str2, str1);
                printf("String 1 copied to String 2. String 2 is: %s\n", str2);
                break;

            case 3:
                printf("Enter string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter string to compare: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                if (strcmp(str1, str2) == 0)
                    printf("Strings are identical.\n");
                else
                    printf("Strings are different.\n");
                break;

            case 5:
                printf("Reversed string: ");
                for (int i = strlen(str1) - 1; i >= 0; i--) 
                {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Enter substring to find: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                if (strstr(str1, str2))
                    printf("Substring found at address: %p\n", strstr(str1, str2));
                else
                    printf("Substring not found.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

