//Write a program to implement least square approximation for non- linear data.
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;

    // Input number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

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

    // Transform the data for linear regression (log-log transformation)
    double log_x[n], log_y[n];
    for (int i = 0; i < n; ++i) {
        log_x[i] = log(x[i]);
        log_y[i] = log(y[i]);
    }

    // Calculate the sums needed for the least squares method
    double sum_log_x = 0, sum_log_y = 0, sum_log_x2 = 0, sum_log_x_log_y = 0;

    for (int i = 0; i < n; ++i) {
        sum_log_x += log_x[i];
        sum_log_y += log_y[i];
        sum_log_x2 += log_x[i] * log_x[i];
        sum_log_x_log_y += log_x[i] * log_y[i];
    }

    // Calculate the slope (b) and intercept (log(a))
    double b = (n * sum_log_x_log_y - sum_log_x * sum_log_y) / (n * sum_log_x2 - sum_log_x * sum_log_x);
    double log_a = (sum_log_y - b * sum_log_x) / n;

    // Calculate the actual value of a
    double a = exp(log_a);

    // Display the results
    cout << fixed << setprecision(6);
    cout << "The best fitting curve is: y = " << a << " * x^" << b << endl;

    // Predicting the value of y for a new x value
    double x_pred;
    cout << "Enter a value of x to predict y: ";
    cin >> x_pred;
    double y_pred = a * pow(x_pred, b);
    cout << "The predicted value of y for x = " << x_pred << " is y = " << y_pred << endl;

    return 0;
}

