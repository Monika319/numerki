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
    for (int i=0;i<n;++i){
    float x=a+(h*i+h*(i+1))/2;
        result+=h*function(x);
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
