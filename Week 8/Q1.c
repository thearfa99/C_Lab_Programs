/*

Frequency of words

Write a C function to count the number of occurrences of a given character.
Use this to find the number of occurrences of every character in a word.

Input Format:
S: Input String

Output Format:
S’: characters with their frequencies

Testcase

Input:
hello

Output:
e 1
h 1
l 2
o 1

*/

//Solution:
#include <stdio.h>
#include <string.h>

int count(char *str, char ch);

int main() {
    char word[100];
    scanf("%s", word);

    int counts[26] = {0};

    
    for (int k = 0; k < strlen(word); k++) {
        char ch = word[k];
        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            counts[index] = count(word, ch);
        }
    }

    for (int j = 0; j < 26; j++) {
        if (counts[j] > 0) {
            printf("%c %d\n", j + 'a', counts[j]);
        }
    }

    return 0;
}

int count(char *str, char ch) {
    int count = 0;
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}