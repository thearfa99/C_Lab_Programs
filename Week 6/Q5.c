/*

Find sum of digits of all even numbers in array

Write C functions to check whether the element in the array is odd or even and find the sum of digits of all even numbers.

Eg 1: Consider the array: arr[] = {11, 22, 33, 44}
Even numbers are 22 and 44: So sum of digits of these numbers is12

Eg 2: Consider the array: arr[] = {11, 33}
There are no even numbers. So sum of digits of even numbers is zero.

Implement the below functions:
void readArray(int arr[],int n);
int sumDigits(int n);  //helper function: return the sum of digits of given number
int EvenNoSumDigits(int arr[],int n);	//return the sum of digits of all even numbers in an array

Input Format:
First line: n representing number of elements in the array, 0 < n ≤ 10
Second line: n numbers separated by space

Output Format:
Sum of digits of all even numbers in array

Testcase

Input:
4
11 22 33 44

Output:
12

*/

//Solution:
#include<stdio.h>
void readArray(int arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
int sumDigits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int EvenNoSumDigits(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            sum+=sumDigits(arr[i]);
        }
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    readArray(arr,n);
    printf("%d",EvenNoSumDigits(arr,n));
    return 0;
}