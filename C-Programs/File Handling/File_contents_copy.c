#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *sourcefile, *destfile;
    char sourcefilename[100], destfilename[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", sourcefilename);

    sourcefile = fopen(sourcefilename, "r");
    if (sourcefile == NULL) 
    {
        printf("Could not open source file '%s'\n", sourcefilename);
        exit(1);
    }

    printf("Enter destination file name: ");
    scanf("%s", destfilename);

    destfile = fopen(destfilename, "w");
    if (destfile == NULL) 
    {
        printf("Could not create destination file '%s'\n", destfilename);
        fclose(sourcefile);
        exit(1);
    }

    while ((ch = fgetc(sourcefile)) != EOF) 
    {
        fputc(ch, destfile);
    }

    printf("File copied successfully from '%s' to '%s'\n", sourcefilename, destfilename);

    fclose(sourcefile);
    fclose(destfile);

    return 0;
}
