#include <stdio.h>

double abs_val(double x) {
    return (x < 0) ? -x : x;
}

double sqrt_newton(double x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    double guess = x, prev;
    int iterations = 0;
    do {
        prev = guess;
        guess = (guess + x / guess) / 2.0;
        iterations++;
    } while (abs_val(guess - prev) > 1e-10 && iterations < 100);
    return guess;
}

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    // a = 0, b = 0, c = 0 -> infinitely many
    if (a == 0 && b == 0 && c == 0) {
        printf("inf\n");
        return 0;
    }

    // a = 0, b = 0, c != 0 -> no solutions
    if (a == 0 && b == 0) {
        printf("none\n");
        return 0;
    }

    // linear: a = 0
    if (a == 0) {
        printf("%.6f\n", -c / b);
        return 0;
    }

    double d = b * b - 4 * a * c;

    if (d > 0) {
        double s = sqrt_newton(d);
        double x1 = (-b + s) / (2 * a);
        double x2 = (-b - s) / (2 * a);
        printf("%.6f %.6f\n", x1, x2);
    } else if (d == 0) {
        printf("%.6f\n", -b / (2 * a));
    } else {
        double re = -b / (2 * a);
        double im = sqrt_newton(-d) / (2 * a);
        if (im < 0) im = -im;
        printf("%.6f+%.6fi %.6f-%.6fi\n", re, im, re, im);
    }

    return 0;
}