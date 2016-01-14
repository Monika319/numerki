#include <iostream>
#include <iomanip>

using namespace std;

bool isPrime(int N)
{

	for (int i=2;i<N;++i)
	{
		if(N%i==0)
		{
			return false;
		}

	}
	return true;

}


int main()
{
	cout<<isPrime(10);




}