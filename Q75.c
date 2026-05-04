/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    // hashmap (array for simplicity)
    int map[20001];
    for (int i = 0; i < 20001; i++) map[i] = -2;

    map[10000] = -1;  // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int idx = sum + 10000;  // shift to avoid negative index

        if (map[idx] != -2) {
            int len = i - map[idx];
            if (len > maxLen)
                maxLen = len;
        } else {
            map[idx] = i;
        }
    }
    printf("%d", maxLen);
    return 0;
}