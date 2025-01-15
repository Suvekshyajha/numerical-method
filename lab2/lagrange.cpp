#include <iostream>
using namespace std;

// Function to calculate Lagrange Interpolation
double lagrangeInterpolation(double x_values[], double y_values[], int n, double x) {
    double result = 0.0; // Resulting interpolated value

    for (int i = 0; i < n; i++) {
        double term = y_values[i]; // Start with y_i
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Given points (x, y)
    const int n = 3;
    double x_values[n] = {1, 2, 3};
    double y_values[n] = {2, 4, 9};

    // Value to interpolate
    double x;
    cout << "Enter the value of x to estimate y: ";
    cin >> x;

    // Calculate and display the result
    double interpolated_value = lagrangeInterpolation(x_values, y_values, n, x);
    cout << "The interpolated value at x = " << x << " is y = " << interpolated_value << endl;

    return 0;
}

