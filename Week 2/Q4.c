/*

C program on Operators

Given a = x && y || z++
INPUT: First line takes value of x
Second line takes value of y
Third line takes value of z

Input Format:
1
0
5

Output Format:
6

*/

//Solution:
#include<stdio.h>
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int a = x&&y||z++;
    printf("%d",z);
}