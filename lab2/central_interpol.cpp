/*Write a program to approximate the functional value at any given x from given n no. of
data using Newton’s central divided difference interpolation.*/
#include <iostream>
#include <iomanip>
#include <cmath>
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

    // Calculate divided difference table
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Display divided difference table (optional)
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; ++i) {
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; ++j) {
            cout << setw(15) << y[i][j];
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    // Apply Newton's Divided Difference formula
    double result = y[0][0];
    double term = 1;

    for (int i = 1; i < n; ++i) {
        term *= (value - x[i - 1]);
        result += term * y[0][i];
    }

    cout << fixed << setprecision(6);
    cout << "\nThe interpolated value at x = " << value << " is " << result << endl;

    return 0;
}

