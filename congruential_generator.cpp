#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;


double congruential()
{
    int a=33;
    int c=1;
    int m=1024;
   // int x_0=0;
    
    static int x=0;
    x=(a*x+c) % m;
    return x;
}

int main()
{
    for (int i=1;i<10000;++i)
    {
    cout<<i<<"\t"<<congruential()<<endl;
}


}
