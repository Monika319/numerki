#include <iostream>
#include <iomanip>

using namespace std;

void f(float& x)
{
    x +=1;
}


int sum ()
{
	int res=0;
	for (int i=0;i<=1000;++i)
		res+=i;

	return res;
}

double sum_double ()
{
	//double res=0.0;
	double i=0.0;
	while(i<1000.0)
		i+=1.0;
	//for (double i=0.0;i<=1000.0;++i)
		//res+=i;

	return res;
}

double reverse_sum_double ()
{
	double res=0.0;
	for (double i=1000.0;i>=1.0;i--)
		res+=i;

	return res;
}



int main()
{
	
	cout<<sum()<<endl;
	cout<<setprecision(10)<<sum_double()<<endl;
	cout<<setprecision(10)<<reverse_sum_double()<<endl;


    // float x = 3.141592;
    // f(x);
    // cout << x << endl;
}