/*

C program on Recursion

Create a recursive function to generate hailstone sequence up to 1.

Implement the below functions:
int getNextValue(int n);
Returns the next value in the sequence

int getHailstone(int n);
Recursively prints the values in the sequence

Note :
The Hailstone sequence of numbers can be generated from a starting positive integer, n
by: If n is 1 then the sequence ends. If n is even then the next n of the sequence = n/2. If
n is odd then the next n of the sequence = (3 * n) + 1. 

Input Format:
n
where n is a positive integer

Output Format:
Sequence of numbers separated by space

Testcase

Input:
3

Output:
3 10 5 16 8 4 2 1

*/

//Solution:
#include<stdio.h>
int getNextValue(int n){
    if (n%2==0){
        return n/2;
    }
    else{
        return (3*n)+1;
    }
}

void getHailstone(int n){
    printf("%d ",n);
    if (n==1){
        return;
    }
    else{
        getHailstone(getNextValue(n));
    }
}

int main(){
    int n;
    scanf("%d",&n);
    getHailstone(n);
    return 0;
}