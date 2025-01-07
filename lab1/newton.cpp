//newton raphdon method
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    return exp(-x)-2*x*x;
}

double derivative(double x, double h = 0.000001) {
    return (f(x + h) - f(x - h)) / (2*h);
}

int main() {
    double a;
    cout << "Enter an initial guess: ";
    cin >> a;
    int i = 0;
    double a_new, error = 1.0;

    cout << fixed << setprecision(6);
    cout << setw(4) << "i" << setw(16) << "x" << setw(16) << "f(x)" << setw(16) << "f'(x)" << setw(16) << "x_n+1" << setw(16) << "error" << endl;
    do {
        double df = derivative(a);

        if (fabs(df) < 1e-6) {
            cout << "Derivative is too small. Method fails." << endl;
            return 1;
        }

        a_new = a - (f(a) / df);
            cout << setw(4) << i 
             << setw(16) << a 
             << setw(16) << f(a) 
             << setw(16) << df 
             << setw(16) << a_new;
        if (i == 0) {
            cout << setw(12) << "-" << endl;
        } else {
            error = fabs(a_new - a); // Absolute error
            cout << setw(12) << error << endl;
        }
        i++;
        a = a_new;

    } while (error >= 0.05);  

    cout << "Root is approximately: " << a << endl;

    return 0;
}

