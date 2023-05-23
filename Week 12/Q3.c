/*
Write a C program which takes two identical files. But some characters are corrupted. 
find the line number and their position where those corrupted letter exists as well as total number of corrupted (error) letters.(4Marks)
*/

//Solution:
#include <stdio.h>

int main() {
    FILE *file1, *file2;
    char filename1[] = "file1.txt";
    char filename2[] = "file2.txt";
    int lineCount = 1;
    int errorCount = 0;

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (1) {
        char ch1 = fgetc(file1);
        char ch2 = fgetc(file2);

        if (ch1 == EOF && ch2 == EOF)
            break;

        if (ch1 != ch2) {
            printf("Corruption at line %d, position %ld\n", lineCount, ftell(file1));
            errorCount++;
        }

        if (ch1 == '\n' || ch2 == '\n')
            lineCount++;
    }

    printf("Total corrupted letters: %d\n", errorCount);

    fclose(file1);
    fclose(file2);

    return 0;
}
