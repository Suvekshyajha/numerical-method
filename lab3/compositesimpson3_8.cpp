//Write a program to evaluate integration of a function using composite Simpson’s 3/8 rule
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
 if(k%3!=0){
 	cout<<"k must be divisible by 3! enter k :"<<endl;
 	cin>>k;
 }
 double h=(xn-x0)/(double)k;
 
 
 double result=f(x0)+f(xn);
 for(int i=1;i<k;++i){
 	double x=x0+i*h;
 	if(i%3==0){
 		result+=2*f(x);
	 }else{
	 	result+=3*f(x);
	 }
 }
 result=result*(3*h/8);
	
 cout<<"the result is "<<result<<endl;
}

