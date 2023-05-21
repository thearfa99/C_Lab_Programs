/*

C program on Functions

Write a C function to check if a given number is a perfect number or not.

Note:
Perfect number is a positive integer that is equal to the sum of its proper divisors. Eg: 6,
which is the sum of 1,2 and 3.

Implement the below functions:
int checkPerfect(int n);
Returns 1 if ‘n’ is a perfect number, otherwise returns 0. 

Input Format:
n
where n is a positive integer

Output Format:
Message: “Perfect number” if the number is a perfect number
Message: “Not a perfect number” if the the number is not a perfect number 

*/

//Solution:
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if (checkPerfect(n)){
        printf("Perfect number");
    }
    else{
        printf("Not a perfect number");
    }
}
int checkPerfect(int n){
    int sum=0;
    for (int i = 1; i<n; i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if (sum==n){
        return 1;
    }
    else{
        return 0;
    }
}