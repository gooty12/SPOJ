#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int L = pow(10.0, 6);
const int MOD = 1000000007;

int main(){

	int t;
	cin>>t;

	vi fib(L+3, 0);
	vi fib_sum(L+3, 0);

	fib[1] = fib_sum[1] = 1;
	for(int i=2; i<L+3; i++){
		fib_sum[i] = fib[i] = (fib[i-1]+fib[i-2])%MOD;
		fib_sum[i] = (fib_sum[i] + fib_sum[i-1])%MOD;
	}

	while(t--){
		int N, M;
		cin>>N>>M;

		int res = 0;
		if(M <= L){
			res = fib_sum[M];
			if(N > 0){
				res -= fib_sum[N-1];
			}
		}
		else{
			pii p1(1, 0);
			pii p2(0, 0);

			int d = min(M-N, L);
			if(d > 0){
				p1.first = p1.second = 0;
			}
			while(d > 0){

			   if(d <= 2){
					p2.first = d;
					p2.second = d;
				}
				else{
					p2.first = fib[d+1];
					p2.second = fib[d+2]-1;
				}

				// Converting 

				p2.first = ((p1.first*fib[d-1])%MOD + 
								(p1.second*fib[d])%MOD + p2.first)%MOD;

				p2.second = ((p1.first*fib[d])%MOD +
								(p1.second*fib[d+1])%MOD + p2.second)%MOD;

				p1.first = p2.first;
				p1.second = p2.second;

				p2.first = p2.second = 0;

				M = max(N, M-d-1);
				d = min(M-N, L);

			} 

			while(N > L){
				int a, b;
				a = ((p1.first*fib[L-1])%MOD + 
								(p1.second*fib[L])%MOD + p1.first)%MOD;

				b = ((p1.first*fib[L])%MOD +
								(p1.second*fib[L+1])%MOD + p1.second)%MOD;
				p1.first = a;
				p1.second = b;
				N = N - L;
			}
			res = ((p1.first*fib[N])%MOD + (p1.second*fib[N+1])%MOD)%MOD;
		}

		cout<<res<<endl;
	}

	return 0;
}