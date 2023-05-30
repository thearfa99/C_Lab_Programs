/*
2) Write a program to sort students details based on students roll number/name in the ascending order using array of pointers, by taking input from csv file.

Input:
stud_details.csv file //create csv file

Output:
99 xx
7 bb
22 cc
45 zz
8 aa
12 ff
4 gg
3 dd
27 jj
1 kk
32 ee

Enter your option 
1.sort on roll 
2.sort on name 
0.exit
1
1 kk
3 dd
4 gg
7 bb
8 aa
12 ff
22 cc
27 jj
32 ee
45 zz
99 xx

Enter your option 
1.sort on roll 
2.sort on name 
0.exit
2
8 aa
7 bb
22 cc
3 dd
32 ee
12 ff
4 gg
27 jj
1 kk
99 xx
45 zz
Enter your option 1.sort on roll 2.sort on name
0
*/

//Solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct Student {
    int roll;
    char name[MAX_LENGTH];
};


void swap(struct Student **a, struct Student **b) {
    struct Student *temp = *a;
    *a = *b;
    *b = temp;
}


void sortOnRoll(struct Student *arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        struct Student *key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j]->roll > key->roll) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void sortOnName(struct Student *arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        struct Student *key = arr[i];
        j = i - 1;

        while (j >= 0 && strcmp(arr[j]->name, key->name) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printStudents(struct Student *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i]->roll, arr[i]->name);
    }
}

int main() {
    FILE *file = fopen("stud_details.csv", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    struct Student *students[MAX_LENGTH];
    char line[MAX_LENGTH];

    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        struct Student *student = malloc(sizeof(struct Student));
        sscanf(line, "%d %s", &student->roll, student->name);
        students[count] = student;
        count++;
    }

    fclose(file);

    int option;
    do {
        printf("Enter your option:\n");
        printf("1. Sort on roll\n");
        printf("2. Sort on name\n");
        printf("0. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                sortOnRoll(students, count);
                printStudents(students, count);
                break;
            case 2:
                sortOnName(students, count);
                printStudents(students, count);
                break;
            case 0:
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 0);

    for (int i = 0; i < count; i++) {
        free(students[i]);
    }

    return 0;
}
