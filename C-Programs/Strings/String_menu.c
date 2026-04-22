#include <stdio.h>
#include <string.h>

void check_for_Palindrome(char str[]);
void reverse_String(char str[]);
void check_for_Substring(char str[]);
void compare_Strings(char str1[]);

int main() 
{
    char str1[100];
    int choice;

    printf("Enter the main string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    while (1) 
	{
        printf("\n----String Operations----");
        printf("\n1 Calculate Length");
        printf("\n2 Reverse String");
        printf("\n3 Check for Equality");
        printf("\n4 Check for Palindrome");
        printf("\n5 Check for Substring");
        printf("\n6 Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
	{
            case 1:
                printf("Length of string: %lu\n", strlen(str1));
                break;
            case 2:
                reverse_String(str1);
                break;
            case 3:
                compare_Strings(str1);
                break;
            case 4:
                check_for_Palindrome(str1);
                break;
            case 5:
                check_for_Substring(str1);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void reverse_String(char str[]) 
{
    int len = strlen(str);
    printf("Reversed string: ");
    for(int i = len - 1; i >= 0; i--) 
	{
        putchar(str[i]);
    }
    printf("\n");
}

void compare_Strings(char str1[]) 
{
    char str2[100];
    printf("Enter string to compare: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    if (strcmp(str1, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");
}

void check_for_Palindrome(char str[]) 
{
    int len = strlen(str);
    int isPalindrome = 1;
    for (int i = 0; i < len / 2; i++) 
	{
        if (str[i] != str[len - 1 - i]) 
	{
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("NOT a Palindrome\n");
}

void check_for_Substring(char str[]) 
{
    char sub[100];
    printf("Enter substring to search: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0;

    if (strstr(str, sub))
        printf("'%s' found in '%s'\n", sub, str);
    else
        printf("Substring not found\n");
}

