/*

C program on escape sequence

The program should take integer as an input and should print the same
between two asterisk symbols in separate lines.

Input Format:
122

Output Format:
*
122
*

*/

//Solution:

#include<stdio.h>
int main()
{
    int p;
    scanf("%d",&p);
    printf("*\n%d\n*",p);
    return 0;
}