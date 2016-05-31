#include<iostream>
#include<vector>
#include<stack>

#define vvi vector< vector<int> >
#define pb push_back

using namespace std;

int main(){
	int N, M;
	cin>>N>>M;
	
	if(N==1 && M==0){
		cout<<"YES"<<endl;
	}
	else{
		vvi adj_list(N+1);
		int start_node = -1;
		
		for(int i=0; i<M; i++){
			int u, v;
			cin>>u>>v;
			if(i==0){
				start_node = u;
			}
			adj_list[u].pb(v);
		}

		vector<int> visit(N+1,0);
		stack<int> nodes;
		if(start_node != -1)
			nodes.push(start_node);
		int nodes_visited = 0;
		int is_tree = 1;
		
		while(!nodes.empty()){
			int u = nodes.top();
			visit[u] = 1;
			nodes_visited++;
			for(auto it= adj_list[u].begin(); it!=adj_list[u].end(); it++){
				int v = *it;
				if(visit[v]){
					is_tree = 0;
					break;
				}
				else{
					nodes.push(v);
				}
			}
			if(!is_tree)
				break;
		}

		if(!is_tree || nodes_visited!=N)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}

	return 0;
}