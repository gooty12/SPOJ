#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(){

	ll T, N;
	cin>>T;
	while(T--){
		cin>>N;
		if(N == 1){
			cout<<1<<endl;
			continue;
		}
		ll res = 0;
		res += (N*(N+1)*(N+2))/6;
		ll n = N/2;
		res += 2 * ((n*(n+1)*(n+2))/3);
		ll s = (n*(n+1))/2;
		if(N%2 == 0){
			res -= 2*s;
		}
		res -= s;
		
		cout<<res<<endl;

	}
	return 0;
}