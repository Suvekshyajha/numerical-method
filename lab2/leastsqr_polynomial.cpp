//Write a program to implement least square approximation polynomial data.
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n, degree;

    // Input number of data points and degree of polynomial
    cout << "Enter the number of data points: ";
    cin >> n;
    cout << "Enter the degree of the polynomial (max degree <= " << n-1 << "): ";
    cin >> degree;

    // Declare arrays to store the x and y values
    double x[n], y[n];

    // Input x and y values
    cout << "Enter the values of x and corresponding y:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    // Create the matrix to store the powers of x
    double A[degree + 1][degree + 1] = {0};
    double B[degree + 1] = {0};
    double coeff[degree + 1] = {0};

    // Calculate the sums for the normal equations
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= degree; ++j) {
            B[j] += y[i] * pow(x[i], j);
            for (int k = 0; k <= degree; ++k) {
                A[j][k] += pow(x[i], j + k);
            }
        }
    }

    // Solve the system of linear equations A * coeff = B using Gaussian elimination
    for (int i = 0; i <= degree; ++i) {
        // Partial pivoting
        for (int k = i + 1; k <= degree; ++k) {
            if (fabs(A[k][i]) > fabs(A[i][i])) {
                for (int j = 0; j <= degree; ++j) {
                    swap(A[i][j], A[k][j]);
                }
                swap(B[i], B[k]);
            }
        }

        // Eliminate the variable
        for (int k = i + 1; k <= degree; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= degree; ++j) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    // Back substitution to solve for the coefficients
    for (int i = degree; i >= 0; --i) {
        coeff[i] = B[i] / A[i][i];
        for (int k = i - 1; k >= 0; --k) {
            B[k] -= A[k][i] * coeff[i];
        }
    }

    // Display the coefficients of the polynomial
    cout << fixed << setprecision(6);
    cout << "The polynomial that fits the data is:\n";
    for (int i = degree; i >= 0; --i) {
        cout << "a[" << i << "] = " << coeff[i] << endl;
    }

    // Predicting the value of y for a new x value
    double x_pred;
    cout << "Enter a value of x to predict y: ";
    cin >> x_pred;
    double y_pred = 0;
    for (int i = 0; i <= degree; ++i) {
        y_pred += coeff[i] * pow(x_pred, i);
    }
    cout << "The predicted value of y for x = " << x_pred << " is y = " << y_pred << endl;

    return 0;
}

