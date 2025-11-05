#include <stdio.h>

int main() {
    int i;
    int U[5] = {1, 2, 3, 4, 5};
    int A[5] = {1, 0, 0, 1, 1};
    int B[5] = {0, 1, 1, 1, 0};
    int uni[5], ints[5], diffB[5], diffA[5], compA[5], compB[5];

    // Display Universal Set
    printf("\nUNIVERSAL SET IS { ");
    for (i = 0; i < 5; i++) {
        printf("%d ", U[i]);
    }
    printf("}\n");

    // Display Set A
    printf("\nSET A { ");
    for (i = 0; i < 5; i++) {
        if (A[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Display Set B
    printf("\nSET B { ");
    for (i = 0; i < 5; i++) {
        if (B[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Union of A and B
    printf("\nUnion of A and B in bit representation: ");
    for (i = 0; i < 5; i++) {
        uni[i] = A[i] | B[i];
        printf("%d", uni[i]);
    }
    printf("\nUNION { ");
    for (i = 0; i < 5; i++) {
        if (uni[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Intersection of A and B
    printf("\nIntersection of A and B in bit representation: ");
    for (i = 0; i < 5; i++) {
        ints[i] = A[i] & B[i];
        printf("%d", ints[i]);
    }
    printf("\nINTERSECTION { ");
    for (i = 0; i < 5; i++) {
        if (ints[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Complement of A
    printf("\nComplement of A in bit representation: ");
    for (i = 0; i < 5; i++) {
        compA[i] = 1 - A[i];
        printf("%d", compA[i]);
    }
    printf("\nA COMPLEMENT { ");
    for (i = 0; i < 5; i++) {
        if (compA[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Complement of B
    printf("\nComplement of B in bit representation: ");
    for (i = 0; i < 5; i++) {
        compB[i] = 1 - B[i];
        printf("%d", compB[i]);
    }
    printf("\nB COMPLEMENT { ");
    for (i = 0; i < 5; i++) {
        if (compB[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Difference of A - B
    printf("\nDifference of A - B in bit representation: ");
    for (i = 0; i < 5; i++) {
        diffA[i] = A[i] & compB[i];
        printf("%d", diffA[i]);
    }
    printf("\nA - B { ");
    for (i = 0; i < 5; i++) {
        if (diffA[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    // Difference of B - A
    printf("\nDifference of B - A in bit representation: ");
    for (i = 0; i < 5; i++) {
        diffB[i] = B[i] & compA[i];
        printf("%d", diffB[i]);
    }
    printf("\nB - A { ");
    for (i = 0; i < 5; i++) {
        if (diffB[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    return 0;
}

