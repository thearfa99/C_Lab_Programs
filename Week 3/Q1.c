/*

Write a C program to illustrate control structures as given,

Take a variable n , print the string "Welcome" initially and then print the numbers 
from 0 to n and finally print the string "Thank you". 

Input Format:
N

Output Format:
String depending on the problem statement 

*/

//Solution:
#include<stdio.h>
int main(){
    int n;
    int i = 0;
    scanf("%d\n",&n);
    printf("Welcome \n");
    while(i<=n){
        printf("%d \n",i);
        i++;
    }
    printf("Thank you\n");
}