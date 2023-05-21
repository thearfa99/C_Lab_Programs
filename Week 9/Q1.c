/*

Structures

Write a Program in C to add two distances in the inch-feet system using structures.
Implement the below functions:
void readDistance(DISTANCE *d);
DISTANCE addDistance(DISTANCE *d1, DISTANCE *d2);
void displayDistance(DISTANCE *d);

Input Format:
Feet :  int
Inch : float
Feet' : int
Inch' : float

Output Format:
Sum of Distances in the form: Feet'-Inch

Testcase

Input:
23
10
34
2.4

Output:
58'-0.4

*/

//Solution:
#include<stdio.h>

struct DISTANCE {
    int feet;
    float inch;
};

void readDistance(struct DISTANCE *d) {
    scanf("%d",&d->feet);
    scanf("%f",&d->inch);
}

void displayDistance(struct DISTANCE *d) {
    printf("%d'%.1f",d->feet+(int)d->inch/12,d->inch/12 ?(int)d->inch/12*12-d->inch:d->inch);
}

struct DISTANCE addDistance(struct DISTANCE *d1,struct DISTANCE *d2) {
    struct DISTANCE dist = {d1->feet+d2->feet,d1->inch+d2->inch};
    return dist;
}
int main(void) {
    struct DISTANCE d1,d2,d3;
    readDistance(&d1);
    readDistance(&d2);
    d3 = addDistance(&d1,&d2);
    displayDistance(&d3);
    return 0;
}