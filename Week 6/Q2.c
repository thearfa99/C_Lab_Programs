/*

Union and Intersection of array elements

Print the union and intersection of 2 sorted arrays.
Example: Input: 
arr1[4] = {1, 5, 8 ,10}     arr2[3] = {7, 10, 20}
Output:  
Union = 1 5 7 8 10 20
Intersection = 10

Implement the below functions:
void readArray(int a[],int n);
void printUnion(int arr1[], int arr2[], int m, int n);
void printIntersection(int arr1[], int arr2[], int m, int n);

Input Format:
First line: 'm' indicating the number of elements in array1, 0<m≤10
Second line: m values separated by space
Third line: 'n', indicating the number of elements in array2, 0<n≤10
Fourth line: n values separated by space

Output Format:
First line: Union of numbers separated by space
Second line: Intersection of numbers separated by space (if exists)

Testcase

Input:
4
2 4 6 8
5
1 2 3 4 5

Output:
1 2 3 4 5 6 8 
2 4 

*/

//Solution:
#include<stdio.h>
void readArray(int a[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void printUnion(int arr1[],int arr2[],int m,int n){
    int i=0,j=0;
//    printf("Union = ");
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            printf("%d ",arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j]){
            printf("%d ",arr2[j]);
            j++;
        }
        else{
            printf("%d ",arr1[i]);
            i++;
            j++;
        }
    }
    while(i<m){
        printf("%d ",arr1[i]);
        i++;
    }
    while(j<n){
        printf("%d ",arr2[j]);
        j++;
    }
    printf("\n");
}
void printIntersection(int arr1[],int arr2[],int m,int n){
    int i=0,j=0;
//    printf("Intersection = ");
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            printf("%d ",arr1[i]);
            i++;
            j++;
        }
    }
    printf("\n");
}
int main(){
    int m,n;
    scanf("%d",&m);
    int arr1[m];
    readArray(arr1,m);
    scanf("%d",&n);
    int arr2[n];
    readArray(arr2,n);
    printUnion(arr1,arr2,m,n);
    printIntersection(arr1,arr2,m,n);
    return 0;
}