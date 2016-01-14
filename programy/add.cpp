#include <iostream>
#include <iomanip>



using namespace std;


int main(){
  int min=1;
  float min_float=1.0;
  int max=1000;
  float max_float=1000.0;
  int sum=0;
  float sum_float=0.0;
  float sum_float_d=0.0;
  
  cout<<setiosflags(ios::fixed)<<setprecision(20)<<endl;
  for (float i=0.0;i<1001.0;++i){
        sum_float+=i;
  }
  
   for (float i=1001.0;i>0;i--){
        sum_float_d+=i;
  }
 
    cout<<"suma= "<<sum<<endl;
    cout<<"suma_float gora= "<<sum_float<<endl;
    cout<<"suma_float dol= "<<sum_float_d<<endl;
}
