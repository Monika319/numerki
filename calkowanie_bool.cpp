#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float function(float x){
    return x*sin(x);
}

double calka(float a,float b, int n){
    float h=(b-a)/(float)n;
  //  cout<<h<<endl;
    double result=0.0;
float poczatek=a;
float koniec=a;
    for (int i=0;i<n;++i){
	poczatek=a+h*i;
	koniec=a+h*(i+1);
	if (koniec>b){
		break;
	}
        result+=h/90*(7*function(poczatek)+7*function(koniec)+12*function((poczatek+koniec)/2)+32*function((3*poczatek+koniec)/4)+32*function((poczatek+3*koniec)/4));
    }

   return result;

}


int main()
{
cout<<setiosflags(ios::fixed)<<setprecision(10)<<endl;
cout<<-2*M_PI<<endl;
for (int i=1;i<1000000;i*=10){
cout<<i<<" "<<calka(0,2*M_PI,i)<<endl;
}
}
