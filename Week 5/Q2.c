/*

C program on Recursion

Write a C function to compute the factorial of a number using recursion. Use it to
compute C(n,r).

Implement the below functions:
int factorial(int n);
Returns the factorial of the input value n

int ncr(int n, int r);
Returns the C(n,r) value for the input values n and r 

Input Format:
n r
where n and r are two positive integers, space separated, n>=r 

Output Format:
C(n,r) value for the input numbers

Testcase

Input:
5 2

Output:
10

*/

//Solution:
#include<stdio.h>
int factorial(int n){
    if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int ncr(int n,int r){
    if (r==0 || r==n)
        return 1;
    else
        return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
    int n,r;
    scanf("%d %d\n",&n,&r);
    printf("%d\n",ncr(n,r));
}