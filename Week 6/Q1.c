/*

Reverse the Array

Write C functions to reverse the array elements 
a) using index notation
b) using pointer notation

Note: The elements in the array have to be reversed. Do not just display the array elements in reverse order. You are expected to solve the problem using both array index notation and pointer notation.
You may write a copyArray() function to store the input array in another array, so that the original input values can be used for reversing the array the second time.

Implement the below functions:
void readArray(int a[],int n);
void displayArray(int a[],int n);
void copyArray(int a[],int ori[],int n);
void reverseArray1(int a[],int n);
void reverseArray2(int *a,int n);

Input Format:
First line: n representing number of elements in the array, 0 < n ≤ 10
Second line: n numbers separated by space

Output Format:
First line Message: "Using index notation"
Second line: Input array separated by space
Third line: Reversed array separated by space
Fourth line Message: "Using pointer notation"
Fifth line: Input array separated by space
Sixth line: Reversed array separated by space

Testcase

Input:
5
11 22 33 44 55

Output:
Using index notation
11 22 33 44 55 
55 44 33 22 11 
Using pointer notation
11 22 33 44 55 
55 44 33 22 11 

*/

//Solution:
#include<stdio.h>
void readArray(int a[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void displayArray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void copyArray(int a[],int ori[],int n){
    for(int i=0;i<n;i++){
        a[i] = ori[i];
    }
}
void reverseArray1(int a[],int n){
   int temp;
   for(int i=0;i<n/2;i++){
       temp = a[i];
       a[i] = a[n-i-1];
       a[n-i-1] = temp;
   }
}
void reverseArray2(int *a,int n){
    int temp;
    int *p1=a;
    int *p2=a+n-1;
    while(p1<p2){
        temp=*p1;
        *p1=*p2;
        *p2=temp;
        p1++;
        p2--;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n],copy[n];
    readArray(arr,n);
    copyArray(copy,arr,n);
    printf("Using index notation\n");
    displayArray(arr,n);
    reverseArray1(arr,n);
    displayArray(arr,n);
    printf("Using pointer notation\n");
    displayArray(copy,n);
    reverseArray2(copy,n);
    displayArray(copy,n);
    return 0;
}