/*

Length of each word

Write a C program to read and print the length of each word.
Implement the below function:
int countWords(char *text,int *count);
Note: str contains the input string, count is the array which contains the length of each word. Return back the number of words from the function.

Input Format:
String with or without spaces (String contains maximum of 10 words) 

Output Format:
No. of words in the given string 

Testcase

Input:
pesu ec campus

Output:
4 2 6 

*/

//Solution:
#include <stdio.h>
#include <string.h>

int countWords(char *text, int *count);

int main() {
    char text[100];
    int count[100] = {0};

    
    fgets(text, 100, stdin);

    int numWords = countWords(text, count);

   
    for (int i = 0; i < numWords; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}

int countWords(char *text, int *count) {
    int len = strlen(text);
    int numWords = 0;
    int wordLen = 0;

    for (int i = 0; i < len; i++) {
        char ch = text[i];
        if (ch == ' ' || ch == '\n') {
            if (wordLen > 0) {
                count[numWords] = wordLen;
                numWords++;
                wordLen = 0;
            }
        } else {
            wordLen++;
        }
    }

    if (wordLen > 0) {
        count[numWords] = wordLen;
        numWords++;
    }

    return numWords;
}