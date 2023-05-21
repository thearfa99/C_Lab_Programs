/*

Array of Structures

Define a structure in C called cricket that will describe the following information:
player name
team name (country name)
batting average 

Using cricket, write a program to read the information about all the N players, and print a team-wise sorted list (ascending order) also containing the names of players with their batting average.
Write functions for the following: 
i) Read the information of all the N players: void readInfo(CRICKET a[],int n);
ii) Sorting the players: void sort(CRICKET a[],int n);
iii) Displaying a team-wise list containing names of player with their batting average: void display(CRICKET a[],int n);

Input Format:
N-No of Players
PN TN BA - Player Name, Team Name, batting Average

Output Format:
After Team-wise Sorting, the Player list is :
PN TN BA
so on....

Testcase

Input:
5
Sachin India 98
Rahul India 45
Jhonty Australia 89
Imran Pakistan 75
Shane Australia 29

Output:
Jhonty Australia 89
Shane Australia 29
Sachin India 98
Rahul India 45
Imran Pakistan 75

*/

//Solution:
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char team[50];
    float b_avg;
} CRICKET;

void readInfo(CRICKET a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s%s%f", a[i].name, a[i].team, &a[i].b_avg);
    }
}

void sort(CRICKET a[], int n) {
    // Bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(a[j].team, a[j+1].team) > 0) {
                CRICKET temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display(CRICKET a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s %.0f\n", a[i].name, a[i].team, a[i].b_avg);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    CRICKET players[n];
    readInfo(players, n);
    sort(players, n);
    display(players, n);
    return 0;
}