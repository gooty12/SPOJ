#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	int T;
	cin>>T;
	while(T--){
		int N, K;
		cin>>N>>K;
		vector<int> heights(N);
		for(int i=0; i<N; i++){
			cin>>heights[i];
		}
		sort(heights.begin(), heights.end());
		int res = 1000000000+1;
		for(int i=0; i+K-1<=N-1; i++){
			res = min(res, heights[i+K-1]-heights[i]);
		}
		cout<<res<<endl;
	}


	return 0;
}