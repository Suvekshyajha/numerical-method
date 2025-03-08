//Write a program to calculate integration using composite Simpson’s 1/3 rule.
#include<iostream>
using namespace std;
double f(double x){
 return 3*x-2;
}
int main(){
 int xn,x0,k;
	
 cout<<"enter upper limit:"<<endl;
 cin>>xn;
 cout<<"enter lower limit:"<<endl;
 cin>>x0;
 cout<<"enter the no of intervals:"<<endl;
 cin>>k;
 while(k%2!=0){
 	cout<<"k must be even! enter k :"<<endl;
 	cin>>k;
 }
 double h=(xn-x0)/(double)k;
 
 
 double result=f(x0)+f(xn);
 for(int i=1;i<k;++i){
 	double x=x0+i*h;
 	if(i%2==0){
 		result+=2*f(x);
	 }else{
	 	result+=4*f(x);
	 }
 }
 
	
 cout<<"the result is "<<result*(h/3)<<endl;
}
