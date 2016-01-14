#include <iostream>
#include <iomanip>



using namespace std;


int main(){
    int N=20;
	int begin=0;
    while(begin <=N ){
	    float res_float=0.05*begin;
	    double res_double=0.05*begin;
	    cout<<setiosflags(ios::fixed)<<setprecision(20)<<res_float<<"\t"<<res_double<<endl;
	    begin+=1;
	}
	float check=10*(1.1-1)-1.0;
	cout<<"check= "<<check<<endl;

}
