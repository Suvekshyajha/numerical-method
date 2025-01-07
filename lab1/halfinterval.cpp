#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function definition
double f(double x) {
    return exp(-x) - 2 * x * x;
}

int main() {
    double u, l;
    cout << "Enter a number such that value in function is negative: ";
    cin >> u;
    while (f(u) >= 0) {  
        cout << "Invalid input. f(" << u << ") = " << f(u) << " is not negative. Try again: ";
        cin >> u;
    }

    cout << "Enter a number such that value in function is positive: ";
    cin >> l;
    while (f(l) <= 0) {  
        cout << "Invalid input. f(" << l << ") = " << f(l) << " is not positive. Try again: ";
        cin >> l;
    }

    if (f(u) * f(l) > 0) {
        cout << "The function does not change signs in the interval. Bisection method cannot be applied." << endl;
        return 1;
    }

    // Variables
    double m_old = 0,m_new = 0;
    double error;
    int i = 0;
    const double tolerance = 0.05;

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

    do {
        // Store old midpoint
        m_old = m_new;
        
        // Calculate new midpoint
        m_new = (u + l) / 2;

        // Print current iteration
        cout << setw(12) << i
             << setw(12) << u
             << setw(12) << f(u)
             << setw(12) << l
             << setw(12) << f(l)
             << setw(12) << m_new
             << setw(12) << f(m_new);
        
        // Print error only after first iteration
        if (i == 0) {
            cout << setw(12) << "-" << endl;
            error = 1; // Set initial error high enough to continue loop
        } else {
            if (m_new != 0) {
                error = fabs((m_new - m_old) / m_new);
            } else {
                error = fabs(m_new - m_old);
            }
            cout << setw(12) << error << endl;
        }

        // Update bounds based on f(m)
        if (f(m_new) < 0) {
            u = m_new;
        } else {
            l = m_new;
        }

        i++; // Increment iteration counter
    } while (error > tolerance);

    cout << "\nRoot is approximately: " << m_new << endl;
    cout << "Functional value at root: " << f(m_new) << endl;
    cout << "Required number of iterations: " << i << endl;
    return 0;
}
