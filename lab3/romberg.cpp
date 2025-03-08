#include <iostream>
#include <cmath>

using namespace std;

// Define the function to be integrated
double f(double x) {
    return x * x; // Example function: f(x) = x^2
}

// Compute the Trapezoidal Rule approximation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b)); // First and last terms
    
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

// Romberg Integration function
double romberg(double a, double b, int maxOrder) {
    double R[maxOrder][maxOrder]; // Table for Richardson Extrapolation
    
    // Compute the first column (Trapezoidal Rule)
    for (int i = 0; i < maxOrder; i++) {
        int n = pow(2, i); // Number of intervals (1, 2, 4, 8, ...)
        R[i][0] = trapezoidal(a, b, n);
    }

    // Compute Romberg extrapolation table
    for (int j = 1; j < maxOrder; j++) {
        for (int i = j; i < maxOrder; i++) {
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    return R[maxOrder-1][maxOrder-1]; // Most refined result
}

int main() {
    double a, b ;
	cout<<"enter lower limit (a) and upper limit(b):"<<endl;
	cin>>a;
	cin>>b; // Integration limits
    int maxOrder = 5; // Higher value increases accuracy

    double result = romberg(a, b, maxOrder);

    cout << "Romberg Integration result: " << result << endl;
    return 0;
}
