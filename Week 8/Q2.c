/*

substring

Write a C function strend (s , t ), which returns 1 if the string t occurs at the end of the string s, and zero otherwise

Input Format:
S1:
Input String1
S2:
Input string 2

Output Format:
0 or 1 based on the input

Testcase

Input:
abcde
cde

Output:
1

*/

//Solution:
#include <stdio.h>

int strend(char* s, char* t) {
        int slen = strlen(s);
    int tlen = strlen(t);
    
    if (tlen > slen)
        return 0;
        
    s += slen - tlen;
    
    return strcmp(s, t) == 0;
}

int main() {
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    int result = strend(s1, s2);
    printf("%d\n", result);
    return 0;
}