/*

C program on Bitwise Operators

Evaluate y = a | b where a = x & y and b = y=4 

Input Format:
x,y 

Output Format:
y

*/

//Solution:
#include<stdio.h>
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int a = x & y;
    int b = y = 4;
    y = a | b;
    printf("%d\n",y);
}