#include <iostream>
using namespace std;

double f(double x) {
    return 3 * x - 2;
}

int main() {
    double x0, xn;
    int k;

    cout << "Enter lower limit: ";
    cin >> x0;
    cout << "Enter upper limit: ";
    cin >> xn;
    cout << "Enter the number of intervals: ";
    cin >> k;

    double h = (xn - x0) / double(k); // Correct step size calculation
    double result = f(x0) + f(xn); // Start with first and last terms

    // Summing intermediate terms
    for (int i = 1; i < k; i++) {
        double xi = x0 + i * h; // Compute x value at i-th step
        result += 2 * f(xi); // Multiply intermediate terms by 2
    }

    result *= (h / 2); // Multiply by h/2 as per trapezoidal formula

    cout << "The result is " << result << endl;
    return 0;
}

