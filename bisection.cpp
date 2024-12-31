#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    return exp(-x) - 2 * x * x;
}

int main() {
    double u, l;

    do {
        cout << "Enter a number such that value in function is negative: ";
        cin >> u;
        cout << "u = " << u << ", f(u) = " << f(u) << endl;
    } while (f(u) > 0);

    do {
        cout << "Enter a number such that value in function is positive: ";
        cin >> l;
        cout << "l = " << l << ", f(l) = " << f(l) << endl;
    } while (f(l) < 0);

    double m_new = (u + l) / 2;
    double m_old;
    double error = 1.0;
    int i = 0;

    cout << fixed << setprecision(3);
    cout << "i\t u\t\t f(u)\t\t l\t\t f(l)\t\t m\t\t f(m)\t\t error" << endl;
    do{
    	m_old=m_new;
    	m_new=(u+l)/2;
    	error=fabs((m_new-m_old)/m_new);
    	cout << i << "\t" << u << "\t" << f(u) << "\t" << l << "\t" << f(l)<< "\t" << m_new << "\t" << f(m_new) << "\t" << error << endl;
    	if(f(m_new)<0){
    		u=m_new;
		}
		else{
			l=m_new;
		}
		
		i++;
	}while(error>0.05);
	cout<<"root is "<<m_new<<endl;
}
