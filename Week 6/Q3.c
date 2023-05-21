/*

Inversion Count

Find the inversion count of array a[]. Given an array a[], two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Eg1: Consider an array a = {10, 5, 3, 2}
The inversions are: (10,5) (10,3) (10,2) (5,3) (5,2) (3,2).
Therefore, inversion count is 6.

Eg2: Consider an array a = {1, 2, 3, 5}
There are no inversions. 
Therefore, inversion count is 0.

Implement the below functions:
void readArray(int arr[],int n);
int getInvCount(int arr[], int n);

Input Format:
First Line: No. of elements in array 0<n≤10
Second Line: Array elements separated by space

Output Format:
Number n representing inversion count

Testcase

Input:
4
1 2 5 3

Output:
1

*/

//Solution:
#include<stdio.h>
void readArray(int arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int merge(int arr[],int temp[],int left,int mid,int right){
    int i,j,k;
    int inv_count=0;

    i=left;
    j=mid;
    k=left;
    while((i<=mid-1)&&(j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inv_count+=(mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return inv_count;
}

int mergeSort(int arr[],int temp[],int left,int right){
    int mid,inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        inv_count+=mergeSort(arr,temp,left,mid);
        inv_count+=mergeSort(arr,temp,mid+1,right);
        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int getinvCount(int arr[],int n){
    int temp[n];
    return mergeSort(arr,temp,0,n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    readArray(arr,n);
    printf("%d",getinvCount(arr,n));
    return 0;
}