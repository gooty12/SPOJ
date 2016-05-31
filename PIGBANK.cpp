#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;
#define MAX_INT numeric_limits<int>::max()

int main(){

	int T;
	cin>>T;
	while(T--){
		int E, F;
		cin>>E>>F;
		int W = F-E;
		int N;
		cin>>N;
		vector< pair<int, int> > currency;
		for(int i=0; i<N; i++){
			int p,w;
			cin>>p>>w;
			currency.emplace_back(p, w);
			//cout<<currency[i].first<<"\t"<<currency[i].second<<endl;
		}

		vector< vector<int> > dp(N, vector<int>(W+1, 
										MAX_INT));
		for(int i=0; i*currency[0].second<=W; i++){
			dp[0][i*currency[0].second] = i*currency[0].first;
		}

		for(int i=1; i<N; i++){
			for(int w=0; w<=W; w++){
				for(int n=0; n*currency[i].second<=w; n++){
					int w_others = w-n*currency[i].second;
					if(dp[i-1][w_others] != MAX_INT){
						int tmp = n*currency[i].first + 
									dp[i-1][w_others];
						//cout<<tmp<<endl;
						dp[i][w] = min(dp[i][w], tmp);
					}
				}
			}
		}

		if(dp[N-1][W] != MAX_INT){
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[N-1][W]<<"."<<endl;
		}
		else{
			cout<<"This is impossible."<<endl;
		}

	}
	
	return 0;
}