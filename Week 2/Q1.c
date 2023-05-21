/*

Write a C program to evaluate the given expression.Compute the value of d, where d = (p + q)*n where p = p++ and q = ++q and 0<=n<=10

The first line of input takes the value of p
The second line of input takes the value of q
The third line of input takes the value of n

Input Format:
1
2
2

Output Format:
8

*/

//Solution:

#include<stdio.h>
int main()
{
    int p,q,n,d;
    scanf("%d%d%d",&p,&q,&n);
    d=((p++)+(++q))*n;
    printf("%d",d);
    return 0;
}