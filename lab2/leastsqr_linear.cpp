//Write a program to implement least square approximation for linear data.
#include <iostream>
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

    // Calculate the sums needed for the least squares method
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    // Calculate the slope (m) and intercept (c)
    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double c = (sum_y - m * sum_x) / n;

    // Display the results
    cout << fixed << setprecision(6);
    cout << "The best fitting line is: y = " << m << "x + " << c << endl;

    // Predicting the value of y for a new x value
    double x_pred;
    cout << "Enter a value of x to predict y: ";
    cin >> x_pred;
    double y_pred = m * x_pred + c;
    cout << "The predicted value of y for x = " << x_pred << " is y = " << y_pred << endl;

    return 0;
}

