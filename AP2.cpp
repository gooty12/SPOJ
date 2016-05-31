#include<iostream>

using namespace std;
typedef long long int ll;

int main(){

	ll T, f, l, s;
	cin>>T;
	while(T--){
		cin>>f>>l>>s;
		ll n, d, a;
		n = (2*s)/(l+f);
		d = (l-f)/(n-5);
		a = f - (2*d);
		cout<<n<<endl;
		for(ll i=0; i<n; i++)
			cout<<(a + i*d)<<" ";
		cout<<endl;
	}
	return 0;
}