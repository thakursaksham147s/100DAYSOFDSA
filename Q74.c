/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who 
received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
*/
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char a[100][50];
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(a[i], a[j]) > 0) 
            {
                char temp[50];
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
    int max = 1, count = 1;
    char winner[50];
    strcpy(winner, a[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(a[i], a[i - 1]) == 0)
            count++;
        else {
            if (count > max) {
                max = count;
                strcpy(winner, a[i - 1]);
            }
            count = 1;
        }
    }
    if (count > max) 
    {
        max = count;
        strcpy(winner, a[n - 1]);
    }
    printf("%s %d", winner, max);

    return 0;
}