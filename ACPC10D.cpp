#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


int main(){

	int c = 1;
	int N;
	while(1){
		cin>>N;
		if(N == 0){
			break;
		}
		
		vvi graph(N, vi(3));
		for(int i=0; i<N; i++){
			cin>>graph[i][0];
			cin>>graph[i][1];
			cin>>graph[i][2];
		}
		//graph[0][0] += graph[0][1];
		graph[0][2] += graph[0][1];

		for(int i=1; i<N; i++){
			for(int j=0; j<3; j++){
				int a = j>0?graph[i][j-1]:numeric_limits<int>::max();
				int b = j>0 && !(i==1&&j==1) ? graph[i-1][j-1]:numeric_limits<int>::max();
				int c = !(i==1&&j==0) ? graph[i-1][j]:numeric_limits<int>::max();
				int d = j<2?graph[i-1][j+1]:numeric_limits<int>::max();

				graph[i][j] += min({a, b, c, d});
				//cout<<graph[i][j]<<endl;
			}
		}

		cout<<c<<". "<<graph[N-1][1]<<endl;
		c++;
	}

	return 0;
}