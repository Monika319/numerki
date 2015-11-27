#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;



double f(double x)
{

return pow(x,3)-8.0;
}

int sign(double x){
	if (f(x)>0) return 1;
	else if (f(x)<0) return -1;
	else return 0;



}
void zamiana(double &x, double &y)
{
    double tmp=x;
    x=y;
    y=tmp;


}


double dekker_new(double a, double b, double eps)
{
    int licznik=0;
    while (fabs(f(b-a))>eps)
    {
        licznik +=1;
        if (fabs(f(b))<eps)
            return b;
        double s=b-(b-a)/(f(b)-f(a))*f(b);
        double m= (a+b)/ 2.0;
        
        double b2=m;
        
        cout<<licznik<<": "<<a<<" "<<b<<" "<<s<<" "<<m<<endl;
        
        if((b<s && s<m)|| (b>s && s>m))
            b2=s;
        
        if (sign(f(b2))==sign(f(b)))
            b=b2;  
        else
            a=b2;
        if (fabs(f(a))<fabs(f(b)))
        {
            double c = a;
            a = b;
            b = c;
       
        }    
    }
    return b;


}


double dekker(double a, double b, double epsilon)
{
    double b_k_prev=a;
   
    double a_k; //centrapoint
    double b_k=b; //current iterate
    double s; // temporary result
    double result=b_k;
    double delta_y=abs(f(b_k));
    double m;
    
    
    if (f(a_k)==0) return a_k;
    else if(f(b_k)==0) return b_k;
    
    
    while(delta_y>epsilon)

    {
        m=(a_k+b_k)/2.0;
        s=b_k-(b_k-b_k_prev)/(f(b_k)-f(b_k_prev))*f(b_k);
        if (fabs(f(b_k)-f(b_k_prev))>epsilon)
        {
        cout<< "obliczam s z pierwszego: "<<endl;
        

        }
        else
        {

            s=m;
          
        }
          cout<<"s: "<<s<<endl;
        if (((b_k<s) && (s<m))|| ((b_k>s)&&(s>m)))
        {
            b_k=s;
            cout<<"nie biore s"<<endl;
        }
        else
        {
             b_k=m;
             
        }
        cout<<"bk: "<<b_k<<endl;
        
        if (sign(f(a_k)*f(b_k))<0)
        {
       
            a_k=a_k;
            
        }
         
        else 
        {
        
            a_k=b_k;
                        
        }
         cout<<"ak: "<<a_k<<endl;

        if (abs(f(a_k))<abs(f(b_k)))
        {
            zamiana(a_k,b_k);
           // result=a_k;
         
        }
        else 
        {
           // result=b_k;
           b_k=b_k;
        
        }
        cout<<"result: "<<b_k<<endl;
        delta_y=abs(f(b_k));
        cout<<"delta y: "<<delta_y<<endl;
    }
    return result;
}

int main()
{
double result=dekker_new(0,5,pow(10,-12));

cout<<result<<endl;



}
