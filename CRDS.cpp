#include<iostream>

using namespace std;

int main(){

	int T;
	const int M = 1000007;
	cin>>T;
	while(T--){
		long long int N, res;
		cin>>N;
		res = (N*(3*N+1))/2;
		cout<<res%M<<endl;
	}
	return 0;
}