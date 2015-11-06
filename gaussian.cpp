#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <limits>

using namespace std;

double f(double x){
    return 1/sqrt(2*M_PI)*exp(-x*x/2);
}
double boole(double a,double b, int n){
    double h=(b-a)/(double)n;
  //  cout<<h<<endl;
    double result=0.0;
    double poczatek=a;
    double koniec=a;
    for (int i=0;i<n;++i){
	    poczatek=a+h*i;
	    koniec=a+h*(i+1);
	    if (koniec>b){
		    break;
	}
        result+=h/90*(7*f(poczatek)+7*f(koniec)+12*f((poczatek+koniec)/2)+32*f((3*poczatek+koniec)/4)+32*f((poczatek+3*koniec)/4));
    }

   return result;

}

int main(int argc, char** argv)
{
   
if (argc<2){
cout<<"Podaj z: "<<endl;
exit(1);


}

double z=atof(argv[1]);

    cout<<setiosflags(ios::fixed)<<setprecision(4)<<endl;
    double a=-15;
  cout<<"boole'a integral: "<<boole(a,z,10000)<<endl;
 
  
}
