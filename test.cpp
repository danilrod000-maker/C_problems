#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double D, sqrtD, x1, x2, epsilon;
    epsilon = 10^(-7);
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("error\n");
        return 1;
    }

    if (fabs(a - 0) < epsilon ) {
        if (fabs(b - 0) < epsilon) {
            if (fabs(c -0) < epsilon) {
                printf("inf solutions\n");
            } else {
                printf("No roots\n");
            }
        } else {
            double x0 = -c / b;
            printf("x0 = %lf\n", x0);
        }
        return 0;
    }


    D = b * b - 4 * a * c;

    
    if (D > 0) {
        sqrtD = sqrt(D);
        x1 = (-b + sqrtD) / (2 * a);
        x2 = (-b - sqrtD) / (2 * a);
        printf("x1 = %lf\n", x1);
        printf("x2 = %lf\n", x2);
    } else if (D == 0) {
        double x0 = -b / (2 * a);
        printf("x0 = %lf\n", x0);
    } else {
        double re = -b / (2 * a);
        double im = sqrt(-D) / fabs(2 * a);
        printf("x1 = %lf + %lfi\n", re, im);
        printf("x2 = %lf - %lfi\n", re, im);
    }

    return 0;
}