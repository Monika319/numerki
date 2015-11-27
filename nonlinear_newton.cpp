#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


double f(double x)
{
	return sin(x+cos(x))-cos(x+sin(x));

}

double df(double x)
{
	return 3*pow(x,2);

} 

double newton(double x0)
{
double epsilon=0.0001;
double h=0.5;
double x=x0;
int i=0; 
double delta_y=abs(f(x0));
if (f(x0)==0) return x0;
while(delta_y>epsilon)
{   i++;
    h= f(x0)/df(x0);
	x=x-h;
	cout<<i<<"\t"<<x<<"\t";
    delta_y=abs(f(x));
    cout<<delta_y<<endl;
}




return x;

}

int main()
{
double result=newton(5);

cout<<result<<endl;



}
