#include <stdio.h>
#include <math.h>
#include <complex.h>

// Define PI for use in the FFT algorithm
#define PI 3.14159265358979323846

// Function to perform the Cooley-Tukey FFT algorithm
void fft(complex double *X, int N) {
    if (N <= 1) return;

    // Divide the array into even and odd indices
    complex double even[N/2];
    complex double odd[N/2];
    for (int i = 0; i < N/2; i++) {
        even[i] = X[i*2];
        odd[i] = X[i*2 + 1];
    }

    // Recursive calls
    fft(even, N/2);
    fft(odd, N/2);

    // Combine
    for (int k = 0; k < N/2; k++) {
        complex double t = cexp(-I * 2.0 * PI * k / N) * odd[k];
        X[k] = even[k] + t;
        X[k + N/2] = even[k] - t;
    }
}

// Function to check if a number is a power of 2
int is_power_of_2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int N;
    printf("Enter the number of points (must be a power of 2): ");
    scanf("%d", &N);

    if (!is_power_of_2(N)) {
        printf("The number of points must be a power of 2.\n");
        return 1;
    }

    complex double X[N];
    double real, imag;

    for (int i = 0; i < N; i++) {
        printf("Enter the real and imaginary parts of point %d: ", i + 1);
        scanf("%lf %lf", &real, &imag);
        X[i] = real + imag * I;
    }

    printf("\nInput:\n");
    for (int i = 0; i < N; i++) {
        printf("%2.1f + %2.1fi\n", creal(X[i]), cimag(X[i]));
    }

    fft(X, N);

    printf("\nOutput:\n");
    for (int i = 0; i < N; i++) {
        printf("%2.1f + %2.1fi\n", creal(X[i]), cimag(X[i]));
    }

    return 0;
}
