#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define pb push_back

int gcd(int A, int B);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1000000;
const int S = sqrt(N);

int main(){

	vi sieve(S+1, 1);
	vi primes;
	sieve[1] = 0;
	for(int i=0; i<=S; i+=2){
		sieve[i] = 0;
	}
	sieve[2] = 1;
	primes.pb(2);
	int SS = sqrt(S);
	for(int i=3; i<=SS+1; i+=2){
		if(sieve[i] == 1){
			//primes.pb(i);
			for(int j=i*i; j<=S; j+=2*i){
				sieve[j] = 0;
			}
		}
	}

	for(int i=3; i<=S; i+=2){
		if(sieve[i] == 1){
			primes.pb(i);
		}
	}
	//cout<<"No of primes upto 10^3 is "<<primes.size()<<endl;

	int t;
	//cin>>t;
	scanf("%d", &t);
	while(t--){
		int A, B;
		//cin>>A>>B;
		scanf("%d %d", &A, &B);
		int g = gcd(max(A, B), min(A, B));
		int res = 1;
		auto it = primes.begin();
		while(g>1 && it!=primes.end()){
			int p1 = 0;
			int p = *it;
			while(g%p == 0){
				p1++;
				g /= p;
			}
			res *= (p1+1);
			it++;
		}

		if(g>1){
			res *= 2;
		}

		//cout<<res<<endl;
		printf("%d\n", res);
	}


	return 0;
}

int gcd(int A, int B){
	while(B != 0){
		int t = A%B;
		A = B;
		B = t;
	}

	return A;
}