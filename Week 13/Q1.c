/*
1) Write a program to sort positive integers in the ascending order.

Intput:
Enter the number of elements u want to sort 5

Output:
Enter 5 elements
13
6
23
1
89

Before sorting 
13
6
23
1
89

After sorting 
1
6
13
23
89
*/

//Solution
#include <stdio.h>
void sort(int arr[],int n) {
    int i, j, m;
    for (i=0; i<n-1; i++) {
        m = i;
        for(j=i+1; j<n; j++) {
            if (arr[j] < arr[m])
                m = j;
        }
        if (m != i) {
            int t = arr[m];
            arr[m] = arr[i];
            arr[i] = t;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("Before sorting:\n");
    for(int i=0; i<n; i++)
        printf("%d\n",arr[i]);
    sort(arr,n);
    printf("After sorting:\n");
    for(int i=0; i<n; i++)
        printf("%d\n",arr[i]);
}