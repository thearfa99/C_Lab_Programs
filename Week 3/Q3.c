/*

C program on Pointers

Declare two variables a, b and a pointer variable p such that the pointer variable p 
holds the address of a. Increment the value in the pointer variable and assign it to 
b. Print the values of a and b. 

Input Format:
The first line of input takes the value of a 

Output Format:
The first line of output gives the value of a 
The second line of output gives the value of b

*/

//Solution:
#include<stdio.h>
int main()
{
    int a,b,*p;
    scanf("%d",&a);
    p=&a;
    b=++(*p);
    printf("%d\n%d",a,b);
}