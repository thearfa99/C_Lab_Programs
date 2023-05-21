/*

Structures and Functions

Write a C Program to Add  two Complex Numbers by Passing Structure to a Function.
Implement the below functions:
void readComplex(COMPLEX *a);
void addComplex(COMPLEX *a,COMPLEX *b,COMPLEX *c);
void displayComplex(COMPLEX *a);

Input Format:
R  I : real & imaginary part of Complex no 1 separted by space
R'  I' : real & imaginary part of Complex no 2 separted by space

Output Format:
Sum of Complex nos in the form: Real part + Imaginary part succeded by character i

Testcase

Input:
5 4
3 2

Output:
8.0 + 6.0i

*/

//Solution:
#include<stdio.h>

struct COMPLEX {
    float r;
    float i;
} a1,a2,a3;

void readComplex(struct COMPLEX *a) {
    scanf("%f %f",&a->r,&a->i);
}
void addComplex(struct COMPLEX *a,struct COMPLEX *b,struct COMPLEX *c) {
    c->r = a->r+b->r;
    c->i = a->i+b->i;
}
void displayComplex(struct COMPLEX *a) {
    printf("%.1f + %.1fi",a->r,a->i);

}
int main() {
    readComplex(&a1);
    readComplex(&a2);
    addComplex(&a1,&a2,&a3);
    displayComplex(&a3);
    return 0;
}