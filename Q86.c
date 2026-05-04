/*
Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n
Examples:
Input:
64
Output:
8

Input:
20
Output:
4

Input:
1
Output:
1
*/
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long l = 0, r = n, ans = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            printf("%lld", mid);
            return 0;
        }
        else if (sq < n) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    printf("%lld", ans);
    return 0;
}