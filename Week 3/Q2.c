/*

Write a C program to illustrate the control structures as given ,

Declare a variable i and until i is less than 10 , print the string "hello" ,further if until 
i is less than 8 , then print the string "bye" 

Input Format:
i

Output Format:
Strings depending on problem statement 

Testcase

Input:
2

Output:
hello 
bye 
bye 
bye 
bye 
bye 
hello 
hello

*/

//Solution:
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n<10){
        printf("hello \n");
        n++;
        while(n<8){
            printf("bye \n");
            n++;
        }
    }
}