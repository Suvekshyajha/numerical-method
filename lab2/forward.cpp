/*Write a program to approximate the functional value at any given x from given n no. of
data using Newton’s forward difference interpolation.*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main() {
    int n;

    // Input number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n][n]; // x for input points, y for difference table

    // Input x and y values
    cout << "Enter the values of x and corresponding y:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i][0];
    }

    // Calculate forward difference table
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Display forward difference table (optional)
    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; ++i) {
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; ++j) {
            cout << setw(10) << y[i][j];
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    // Calculate u
    double h = x[1] - x[0]; // Assuming equally spaced points
    double u = (value - x[0]) / h;

    // Apply Newton's forward interpolation formula
    double result = y[0][0];
    double u_term = 1;

    for (int i = 1; i < n; ++i) {
        u_term *= (u - (i - 1)); // Update u_term
        result += (u_term * y[0][i]) / tgamma(i + 1); // tgamma(n+1) = n!
    }

    cout << fixed << setprecision(6);
    cout << "\nThe interpolated value at x = " << value << " is " << result << endl;

    return 0;
}

