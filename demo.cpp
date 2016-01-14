#include <iostream>
#include <vector>
#include <iomanip>



using namespace std;


int main(){

	double x=1234.567890;
	cout << "1) " << x << endl;
	cout << "2) " << setw(10) << x << endl;
	cout << "3) " << setprecision(10) << x << endl;
	cout << "4) " << setiosflags(ios::fixed) << x << endl;
	cout << resetiosflags(ios::fixed);
	cout << "5) " << setiosflags(ios::scientific) << x << endl;
	cout << "6) " << setprecision(2) << x << endl;


}
