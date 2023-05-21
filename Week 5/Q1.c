/*

C program on Functions

Write a C function to check whether a given number is prime and use that to find the
next prime number, greater than a given number.

Implement the below functions:
bool isPrime(int n):
Returns true or false depending on if a number is prime or not

int nextPrime(int n);
Returns the next prime number after n 

Input Format:
X: A positive integer

Output Format:
Y: First Prime number after X

*/

//Solution:
#include<stdio.h>
#include<stdbool.h>
bool isPrime(int n){
    if (n<2){
        return false;
    }
    for (int i = 2;i * i <= n; i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    n++;
    while (!isPrime(n)){
        n++;
    }
    return n;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",nextPrime(n));
    return 0;
}