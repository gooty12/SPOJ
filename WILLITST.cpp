#include<iostream>
#include<cmath>

#define LOG(a, b) log(a)/log(b)

using namespace std;

int main(){

	long long n;
	cin>>n;
	if(n <= 1)
		cout<<"TAK";
	else {
		double p = LOG(n, 2);
		//cout<<p<<endl;
		if( p == trunc(p))
			cout<<"TAK";
		else
			cout<<"NIE";
	}
	return 0;
}