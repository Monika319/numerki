#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


double f(double x)
{
	return pow(x,3);

}

double df(double x)
{
	return 3*pow(x,2);

} 

double sieczne(double x0, double x1)
{
double epsilon=0.00001;
double h;
double xn=x1;
double xn_prev=x0;
int i=0; 
double delta_y=abs(f(xn));
if (f(x0)==0) return x0;
else if(f(x1)==0) return x1;
while(delta_y>epsilon)
{   
	i++;
   	h= f(xn)*(xn-xn_prev)/(f(xn)-f(xn_prev));
   	cout<<"h: "<<h<<endl;
   	xn_prev=xn;
	xn=xn-h; //tutaj juz bedzie x_n+1
	cout<<i<<"\t"<<xn<<"\t";
    	delta_y=abs(f(xn));
    	cout<<delta_y<<endl;
	
	cout<<"xnprev: "<<xn_prev<<endl;
}




return xn;

}

int main()
{
double result=sieczne(-5,2);

cout<<result<<endl;



}
