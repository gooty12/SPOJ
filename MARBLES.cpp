#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
const long long N = pow(10, 12);

long long GCD(long long a, long long b);

int main(){

	int t;
	cin>>t;
	while(t--){
		long long n, k;
		long long num = 1, denom = 1;
		cin>>n>>k;
		for(long long i=1, j=k-1; i<=k-1 || j>0; i++, j--){
			if(i <= k-1){
				num = num * (n-i);
			}
			if(j > 0){
				denom = denom * j;
			}
			if(num>N || denom>N){
				long long g = GCD(max(num, denom), min(num, denom));
				num /= g;
				denom /= g;
			}
		}
		cout<<num/denom<<endl;
	}
	return 0;
}

long long GCD(long long a, long long b){
	if(b==0)
		return a;
	else
		return GCD(b, a%b);
}