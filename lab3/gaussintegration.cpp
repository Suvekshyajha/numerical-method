#include <iostream>
#include <cmath>

using namespace std;

// Function to differentiate
double f(double x) {
    return x * x; // Example: f(x) = x^2
}

// Derivative function using central difference
double derivative(double (*func)(double), double x, double h = 1e-5) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

int main() {
    double x ; 
	cout<<"enter point to differentiate:"<<endl;// Point at which to differentiate
	cin>>x;
    double result = derivative(f, x);

    cout << "Derivative of f(x) at x = " << x << " is: " << result << endl;
    return 0;
}

