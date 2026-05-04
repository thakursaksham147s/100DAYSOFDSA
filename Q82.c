/*
Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.

Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)
Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x

Example:
Input:
7
1 2 4 4 4 5 7
4

Output:
2 5
*/
#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);

    int a[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    int l = 0, r = n - 1, lb = n, ub = n;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x) {
            lb = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    l = 0; r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] > x) {
            ub = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d %d", lb, ub);

    return 0;
}