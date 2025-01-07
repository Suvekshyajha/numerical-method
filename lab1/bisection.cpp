#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function definition
double f(double x) {
    return exp(-x) - 2 * x * x; // Replace with your function
}

int main() {
    double u, l;

    // Input upper bound (negative function value)
    cout << "Enter a number such that value in function is negative: ";
    cin >> u;
    while (f(u) >= 0) {  
        cout << "Invalid input. f(" << u << ") = " << f(u) << " is not negative. Try again: ";
        cin >> u;
    }

    // Input lower bound (positive function value)
    cout << "Enter a number such that value in function is positive: ";
    cin >> l;
    while (f(l) <= 0) {  
        cout << "Invalid input. f(" << l << ") = " << f(l) << " is not positive. Try again: ";
        cin >> l;
    }

    // Check if signs are opposite
    if (f(u) * f(l) > 0) {
        cout << "The function does not change signs in the interval. Bisection method cannot be applied." << endl;
        return 1;
    }

    // Variables
    double m_new = (u + l) / 2;
    double m_old;
    double error = 1;  // Initialize error to a high value
    int i = 0; // Iteration counter
    const double tolerance = 0.05; // Stopping condition based on precision

    // Table header
    cout << fixed << setprecision(6);
    cout << left
         << setw(12) << "i"
         << setw(12) << "u"
         << setw(12) << "f(u)"
         << setw(12) << "l"
         << setw(12) << "f(l)"
         << setw(12) << "m"
         << setw(12) << "f(m)"
         << setw(12) << "error" << endl;

    // Iterations
    do { // Print all iterations until error <= 0.05
        m_old = m_new;
        m_new = (u + l) / 2;

        // Error calculation
        if (m_new != 0) {
            error = fabs((m_new - m_old) / m_new); // Relative error
        } else {
            error = fabs(m_new - m_old); // Absolute error if m_new = 0
        }

        // Print iteration values
        cout << setw(12) << i
             << setw(12) << u
             << setw(12) << f(u)
             << setw(12) << l
             << setw(12) << f(l)
             << setw(12) << m_new
             << setw(12) << f(m_new)
             << setw(12) << error << endl;

        // Update bounds based on f(m)
        if (f(m_new) < 0) {
            u = m_new;
        } else {
            l = m_new;
        }

        i++; // Increment iteration counter
    } while (error > tolerance); // Continue until error is <= 0.05

    // Final output
    cout << "\nRoot is approximately: " << m_new << endl;
    return 0;
}

