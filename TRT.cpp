#include<iostream>
#include<vector>

using namespace std;

int main(){

	int N;
	cin>>N;
	
	vector<int> treat(N);
	vector<int> sum(N);
	vector<int> dp(N);
	for(int i=0; i<N; i++){
		cin>>treat[i];
		sum[i] = dp[i] = treat[i];
	}

	for(int l=2; l<=N; l++){
		for(int i=0; i+l-1<=N-1; i++){
			int a = treat[i] + sum[i+1] + dp[i+1];
			int b = treat[i+l-1] + sum[i] + dp[i];
			dp[i] = max(a, b);
			sum[i] += treat[i+l-1]; 
		}
	}

	cout<<dp[0]<<endl;

	

	return 0;
}