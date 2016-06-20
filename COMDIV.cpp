#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define pb push_back

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
		sieve[i] = 1;
	}
	sieve[2] = 1;
	primes.pb(2);
	int SS = sqrt(S);
	for(int i=3; i<=SS+1; i++){
		if(sieve[i] == 1){
			primes.pb(i);
			for(int j=i*i; j<=S; j+=2*i){
				sieve[j] = 0;
			}
		}
	}

	int t;
	//cin>>t;
	scanf("%d", &t);
	while(t--){
		int A, B;
		//cin>>A>>B;
		scanf("%d %d", &A, &B);
		int res = 1;
		auto it = primes.begin();
		while((A>1 || B>1) && (it!=primes.end())){
			int p1 = 0, p2 = 0;
			int p = *it;
			while((A%p == 0) || (B%p == 0)){
				if(A%p == 0){
					p1++;
					A /= p;
				}
				if((B%p == 0)){
					p2++;
					B /= p;
				}
			}
			res *= min(p1+1, p2+1);
			it++;
		}

		if((A>1 || B>1) && (A==B)){
			res *= 2;
		}

		//cout<<res<<endl;
		printf("%d\n", res);
	}


	return 0;
}