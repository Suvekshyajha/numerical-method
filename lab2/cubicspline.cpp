/*Write a program to approximate the functional value at any given x from given n no. of
data using Cubic Spline interpolation.*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    // Input number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y[n], h[n - 1], alpha[n], l[n], mu[n], z[n], c[n], b[n - 1], d[n - 1], a[n];

    // Input x and y values
    cout << "Enter the values of x and corresponding y:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    // Step 1: Calculate h (interval widths)
    for (int i = 0; i < n - 1; ++i) {
        h[i] = x[i + 1] - x[i];
    }

    // Step 2: Calculate alpha
    alpha[0] = 0; // First and last alpha are not used
    alpha[n - 1] = 0;
    for (int i = 1; i < n - 1; ++i) {
        alpha[i] = (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    // Step 3: Solve tridiagonal system for c
    l[0] = 1;
    mu[0] = z[0] = 0;

    for (int i = 1; i < n - 1; ++i) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;

    for (int j = n - 2; j >= 0; --j) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
        a[j] = y[j];
    }

    // Input x for interpolation
    double value;
    cout << "Enter the value of x to interpolate: ";
    cin >> value;

    // Find the interval where x lies
    int interval = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (value >= x[i] && value <= x[i + 1]) {
            interval = i;
            break;
        }
    }

    if (interval == -1) {
        cout << "Value is out of range of data points.\n";
        return 0;
    }

    // Calculate the interpolated value
    double dx = value - x[interval];
    double result = a[interval] + b[interval] * dx + c[interval] * dx * dx + d[interval] * dx * dx * dx;

    cout << fixed << setprecision(6);
    cout << "The interpolated value at x = " << value << " is " << result << endl;

    return 0;
}

