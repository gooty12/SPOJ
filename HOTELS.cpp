#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){

	int N;
	ll M;

	cin>>N;
	cin>>M;
	
	vector<int> hotels(N);
	vector<ll> sum(N);

	cout<<"Size is "<<hotels.end()-hotels.begin()<<endl;
	cin>>hotels[0];
	sum[0] = hotels[0];

	for(int i=1; i<N; i++){
		cin>>hotels[i];
		sum[i] = sum[i-1] + hotels[i];
	}

	int i = 0;
	ll res = 0;
	while(i<N && sum[i]<=M){
		res = sum[i];
		i++;
	}

	if(i<N && res!=M){
		int wndw_strt = 0;
		ll crnt_sum = res;
		auto it_start = sum.begin();
		while(i<N){
			if(hotels[i]>M){
				crnt_sum = 0;
				wndw_strt = -1;
			}	
			else{
				
				if(wndw_strt == -1){
					wndw_strt = i;
				}

				ll tmp = crnt_sum + hotels[i];
				if(tmp>M){
					ll val = tmp-M;
					if(wndw_strt>0){
						val += sum[wndw_strt-1];
					}
					auto it = lower_bound(it_start+wndw_strt,
											it_start+i, val);
					wndw_strt = it - it_start;
					crnt_sum = sum[i]-sum[wndw_strt-1];
				}
				else{
					crnt_sum = tmp;
				}
				
			}
			res = max(res, crnt_sum);
			if(res == M){
				break;
			}
			i++;
		}
	}

	cout<<res<<endl;

	return 0;
}