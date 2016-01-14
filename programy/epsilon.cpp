#include <iostream>
#include <iomanip>



using namespace std;


int main(){
    double one=1.0;
    double epsilon=1.0;
    int n=0;
    while(one+epsilon !=one){//bierzemy float, bo inaczej bierze double i bardzo psuje wyniki
    epsilon=epsilon/2.0; //szukamy poteg dwojki
    n=n-1;//pamietamy potege 2  
    }
    epsilon=epsilon*2.0;
    n=n+1;//cofanie sie 
    cout<<"eps= 2^"<<n<<"\t "<<epsilon<<endl;//bo znajdziemy pierwszy, ktory juz nie da1

}
