/*

C program on Data Types

The program should take an integer n and a character c and should print a
floating point value of sum of n and c NOTE \n i.e new line is also a character

Input Format:
1
k

Output Format:
108.000000

*/

//Solution:
#include<stdio.h>
int main()
{
    int n;
    char c;
    scanf("%d",&n);
    c=getchar();
    scanf("%c",&c);
    float res=(float)n+c;
    printf("%f",res);
}