#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

#define IT(T) T::iterator
#define REV_IT(T) T::reverse::iterator
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
//#define tr(c,i) for(stack<ii>::iterator i = (c).begin(); i != (c).end(); i++) 
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

int main(){

	int N;
	cin>>N;
	if(N<=1){
		cout<<0<<endl;
	}
	else{
		vvi graph(N+1, vi());
		for(int i=1; i<N; i++){
			int u, v;
			cin>>u>>v;
			graph[u].pb(v);
		}

		//vi depth(N+1);
		vi parent(N+1);
		vi height(N+1, 0);
		stack<int> nodes;
		nodes.emplace(1);
		//depth[1] = 0;
		parent[1] = -1;
		int longest_path = 0;
		//cout<<"Hi there"<<endl;

		while(!nodes.empty()){
			int u = nodes.top();
			//cout<<u<<endl;
			int all_visited = 0;
			tr(graph[u], it){
				int v = *it;
				//cout<<v<<"parent " <<parent[v]<<endl;
				if(parent[v] != 0){
					all_visited = 1;
					break;
				}
				//depth[v] = depth[u] + 1;
				parent[v] = u;
				nodes.push(v);
			}
			if(all_visited || graph[u].empty()){
				int max_depth = 0, next_max_depth = 0;
				tr(graph[u], it){
					int v = *it;
					int h = height[v] ;
					if(h > max_depth){
						max_depth = h;
					}
					else if(next_max_depth > h){
						next_max_depth = h;
					}
				}
				height[u] = max_depth+graph[u].empty();
				cout<<u<<" "<<height[u]<<" "<< next_max_depth+max_depth<<endl;
				longest_path = max(longest_path, max_depth+next_max_depth);
				nodes.pop();
			}

		}

		cout<<longest_path<<endl;
	}


	return 0;
}