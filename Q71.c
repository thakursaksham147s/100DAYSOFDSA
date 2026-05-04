/*
Problem Statement
Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND
Explanation
Collisions resolved using i² jumps.
*/
#include <stdio.h>

int t[100];

int main() {
    int m, q, key;

    printf("Enter table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    for (int i = 0; i < m; i++) t[i] = -1;

    char op[10];

    while (q--) {
        printf("Enter operation (INSERT/SEARCH) and key: ");
        scanf("%s %d", op, &key);

        int h = key % m;

        if (op[0] == 'I') {
            for (int i = 0; i < m; i++) {
                int idx = (h + i*i) % m;
                if (t[idx] == -1) {
                    t[idx] = key;
                    break;
                }
            }
        }
        else { 
            int found = 0;
            for (int i = 0; i < m; i++) 
            {
                int idx = (h + i*i) % m;

                if (t[idx] == -1) break;
                if (t[idx] == key) {
                    found = 1;
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}