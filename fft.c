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

int main() {
    int N = 8; // Number of points, must be a power of 2 for simplicity
    complex double X[] = {1.0 + 0.0*I, 1.0 + 0.0*I, 1.0 + 0.0*I, 1.0 + 0.0*I, 0.0 + 0.0*I, 0.0 + 0.0*I, 0.0 + 0.0*I, 0.0 + 0.0*I};

    printf("Input:\n");
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
