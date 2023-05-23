/*
2)Write a C program to write multiple lines in a text file.(3Marks)
Input:
enter the filename file.txt
Enter the number of lines to be written : 2
The lines are
hi hello
how are you
Output:
The content of the file file.txt is :
hi hello
how are you
*/

//Solution
#include <stdio.h>

int main() {
    char filename[100];
    int numLines, i;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    printf("Enter the number of lines to be written: ");
    scanf("%d", &numLines);
    
    printf("Enter the lines:\n");
    
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    
    for (i = 0; i < numLines; i++) {
        char line[100];
        scanf(" %[^\n]", line);
        fprintf(file, "%s\n", line);
    }
    
    fclose(file);
    
    printf("The content of the file %s is:\n", filename);
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(file);
    
    return 0;
}
