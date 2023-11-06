#include <stdio.h>
// Function to add two polynomials and store the result in a third array
void addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int result[]) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    for (int i = 0; i <= maxDegree; i++) {
        int coef1 = (i <= degree1) ? poly1[i] : 0;
        int coef2 = (i <= degree2) ? poly2[i] : 0;

        result[i] = coef1 + coef2;
    }
}

// Function to print a polynomial
void printPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i < degree) {
                if (poly[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            }
            printf("%d", (poly[i] < 0) ? -poly[i] : poly[i]);
            if (i > 0) {
                printf("x^%d", i);
            }
        }
    }
    printf("\n");
}

int main() {
    // Define the coefficients and degrees of two polynomials
    int poly1[] = {-7, 5, -2, 3}; // P(x) = -7 + 5x - 2x^2 + 3x^3
    int degree1 = 3;

    int poly2[] = {-1, 4, 2}; // Q(x) = -1 + 4x + 2x^2
    int degree2 = 2;

    // Determine the maximum degree among the two polynomials
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    // Create an array to store the result polynomial
    int result[maxDegree + 1];

    // Add the two polynomials
    addPolynomials(poly1, degree1, poly2, degree2, result);

    // Print the polynomials and the result
    printf("Polynomial 1: ");
    printPolynomial(poly1, degree1);

    printf("Polynomial 2: ");
    printPolynomial(poly2, degree2);

    printf("Sum: ");
    printPolynomial(result, maxDegree);

    return 0;
}

