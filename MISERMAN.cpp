#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<initializer_list>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	int N, M;
	cin>>N>>M;

	vvi fares(N, vi(M));
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>fares[i][j];
			if(i>0){
				int l = j>0?fares[i-1][j-1]:numeric_limits<int>::max();
				int r = j<M-1?fares[i-1][j+1]:numeric_limits<int>::max();
				int m = fares[i-1][j];
				//initializer_list<int> lst = {l, m, r};
				fares[i][j] += min({l, m, r});
			}
			//cout<<fares[i][j]<<" ";
		}
		//cout<<endl;
	}

	//cout<<"result is ";
	int res = 0;
	if(N>1){
		res = *min_element(fares[N-1].begin(), fares[N-1].end());
	}

	cout<<res<<endl;

	return 0;
}