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
    int n1,n2,degree1,degree2;
    printf("enter the no of terms in 1st polynomial");
    scanf("%d",&n1);
    int poly1[n1] ;
    printf("enter the degree of 1st polynomial");
    scanf("%d",&degree1);
    printf("enter the coefficients");
    for(int i=0;i<n1;i++){
    	scanf("%d",&poly1[i]);
    }
    printf("enter the no of terms in 2nd polynomial");
    scanf("%d",&n2);
    int poly2[n2] ;
    printf("enter the degree of 1st polynomial");
    scanf("%d",&degree2);
    printf("enter the coefficients");
    for(int i=0;i<n2;i++){
    	scanf("%d",&poly2[i]);
    }

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


