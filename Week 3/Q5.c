/*

C program to illustrate if-else block.

Write a C program to accept a coordinate point in an XY coordinate system and 
determine in which quadrant the coordinate point lies. 

Input Format:
x
y

Output Format:
Quadrant 

Testcase

Input:
1
2

Output:
First Quadrant
 
*/

//Solution:
#include<stdio.h>
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    if (x > 0 && y > 0){
        printf("First Quadrant \n");
    }
    else if (x < 0 && y > 0){
        printf("Second Quadrant \n");
    }
    else if (x < 0 && y < 0){
        printf("Third Quadrant \n");
    }
    else if (x > 0 && y < 0){
        printf("Forth Quadrant \n");
    }
    else{
        printf("origin\n");
    }
}