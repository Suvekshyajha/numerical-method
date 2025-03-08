#include <iostream>
#include <cmath>

using namespace std;

// Define the function to be integrated
double f(double x, double y) {
    return x * y; // Example: f(x, y) = x * y
}

// Trapezoidal Rule for Double Integration
double doubleIntegral(double a, double b, double c, double d, int nx, int ny) {
    double hx = (b - a) / nx; // Step size in x
    double hy = (d - c) / ny; // Step size in y
    double sum = 0.0;

    for (int i = 0; i <= nx; i++) {
        double x = a + i * hx;
        for (int j = 0; j <= ny; j++) {
            double y = c + j * hy;
            double weight = ((i == 0 || i == nx) ? 0.5 : 1.0) * ((j == 0 || j == ny) ? 0.5 : 1.0);
            sum += weight * f(x, y);
        }
    }

    return sum * hx * hy;
}

int main() {
    double a,b;// Limits for x
    double c,d; // Limits for y
    cout<<"enter lower limit (a) and upper limit(b) for x:"<<endl;
	cin>>a;
	cin>>b; 
	cout<<"enter lower limit (a) and upper limit(b) for y:"<<endl;
	cin>>c;
	cin>>d; // Integration limits// Integration limits
    int nx ,ny;// Number of intervals
    cout<<"enter number of interval for x"<<endl;
    cin>>nx;
    cout<<"enter number of interval for y"<<endl;
    cin>>ny;

    double result = doubleIntegral(a, b, c, d, nx, ny);

    cout << "Double Integration result: " << result << endl;
    return 0;
}

