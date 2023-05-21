/*

Vowels and Consonants

Write a C program to find frequency of each of the vowels and total count of consonants.
Implement the below function:
void vowFreqConCount(char *str,int *count);
Note: str contains the input string, count is the array which contains frequency of the vowels a, e, i, o, u in index location 0, 1, 2, 3, 4 respectively and total count of consonants in index location 5. 

Input Format:
S: Input string

Output Format:
I': integers representing the frequency of the vowels a,e,i,o,u and total count of consonants with spaces in the given order

Testcase

Input:
Pesu ECRR 

Output:
0 2 0 0 1 5 

*/

//Solution:
#include <stdio.h>

void vowFreqConCount(char *str, int *count) {
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    count[3] = 0;
    count[4] = 0;
    count[5] = 0;
    

    for (int i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case 'a':
            case 'A':
                count[0]++;
                break;
            case 'e':
            case 'E':
                count[1]++;
                break;
            case 'i':
            case 'I':
                count[2]++;
                break;
            case 'o':
            case 'O':
                count[3]++;
                break;
            case 'u':
            case 'U':
                count[4]++;
                break;
            default:
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                    count[5]++;
                }
        }
    }
}

int main() {
    char str[100];
    int count[6];
    fgets(str, 100, stdin);
    vowFreqConCount(str, count);
    printf("%d %d %d %d %d %d", count[0], count[1], count[2], count[3], count[4], count[5]);
    
    return 0;
}