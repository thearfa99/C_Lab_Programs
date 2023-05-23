/*
1)Write a C program to merge contents of two files into a third file.(3Marks)

Input:
gedit file1.txt 
Hi,Good morning!
Have a nice day 

gedit file2.txt
Welcome to C programming- file handling concepts

gedit file3.txt
//empty file

Enter the 1st file name : file1.txt Enter the 2nd file name : file2.txt
Enter the new file name to merge the two files:file3.txt

Output:
The two files merged into file3.txt file successfully..!!
//Third file-Merged contents of two files(file1.txt and file2.txt)

gedit file3.txt
Hi,Good morning!
Have a nice day
Welcome to C programming- file handling concepts
*/

//Solution:
#include <stdio.h>

int main() {
    FILE *file1, *file2, *file3;
    char file1_name[100], file2_name[100], file3_name[100];
    char ch;

    printf("Enter the 1st file name: ");
    scanf("%s", file1_name);

    printf("Enter the 2nd file name: ");
    scanf("%s", file2_name);

    printf("Enter the new file name to merge the two files: ");
    scanf("%s", file3_name);

    file1 = fopen(file1_name, "r");
    if (file1 == NULL) {
        printf("Unable to open %s\n", file1_name);
        return 1;
    }

    file2 = fopen(file2_name, "r");
    if (file2 == NULL) {
        printf("Unable to open %s\n", file2_name);
        return 1;
    }

    file3 = fopen(file3_name, "w");
    if (file3 == NULL) {
        printf("Unable to create %s\n", file3_name);
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file3);
    }
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file3);
    }

    printf("The two files merged into %s successfully..!!\n", file3_name);

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}