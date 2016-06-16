#include<iostream>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b);

int main(){


	long long t;
	cin>>t;
	while(t--){
		long long A, B;
		cin>>A>>B;
		long long lcm = (A*B)/gcd(max(A, B), min(A, B));
		cout<<lcm/A<<" "<<lcm/B<<endl;
	}
	return 0;
}

long long gcd(long long a, long long b){
	
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}

}