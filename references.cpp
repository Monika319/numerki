#include <iostream>
#include <fstream>

using namespace std;


float f(float& x)
{
    cout<<" f(x) przed "<<x<<endl;
    x+=1;
    cout<<" f(x) po "<<x<<endl;
}

int main()
{
    float x=0.0;
    cout<<"Przed "<<x<<endl;
    f(x);
    cout<<"Po "<<x<<endl;


}
