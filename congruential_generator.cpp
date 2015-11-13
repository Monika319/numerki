#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;


double congruential()
{
    int a=1103515245;
    int c=12345;
    int m=(int)pow(2,31);
   // int x_0=0;
    
    static int x=0;
    x=(a*x+c) % m;
    return x;
}


//brzeg nalezy do przedzialu z prawej strony

int main()
{
    for (int i=1;i<10000;++i)
    {
    cout<<i<<"\t"<<congruential()<<endl;
}


}
