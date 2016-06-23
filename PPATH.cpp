#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

const int L = pow(10, 3);
const int R = pow(10, 4);


int main(){

	vi sieve(R-L+1, 1);
	const int LL = sqrt(L);
	const int RR = sqrt(R);

	//cout<<L<<" "<<R<<" "<<LL<<" "<<RR<<endl;

	for(int i=2; i<=RR; i++){
		for(int j=max(i*i, ((L+i-1)/i)*i); j<=R; j+=i){
			sieve[j-L] = 0;
		}
	}

	/*int count = 0;
	for(int i=0; i<=R-L; i++){
		if(sieve[i] == 1){
			//cout<<L+i<<endl;
			count++;
		}
	}

	cout<<count<<endl;*/
	vvi adj(R-L+1);
	//adj[0].pb(0);
	//cout<<"Yes"<<endl;
	for(int i=0; i<=R-L; i++){
		if(sieve[i]){
			int n = L+i;
			int mul = 1;
			int tmp = n;
			while(mul<=1000){
				int num = n;
				int d = tmp%10 + 1;
				
				while(d <= 9){
					num += mul;
					if(sieve[num-L]==1){
						adj[n-L].pb(num);
						adj[num-L].pb(n);
					}
					d++;
				}
				
				mul *= 10;
				tmp /= 10;
			}
		}
	}
	//cout<<"End"<<endl;

	/*for(int i=0; i<=R-L; i++){
		if(sieve[i]){
			cout<<endl<<L+i<<"***"<<endl;
			for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
				cout<<*it<<" ";
			}
			cout<<endl<<L+i<<"***"<<endl;
		}
	}*/

	int t;
	cin>>t;
	while(t--){
		int A, B;
		cin>>A>>B;
		
		vi is_visited(R-L+1, 0);
		vi distance(R-L+1, 0);
		
		queue<int> nodes;
		nodes.push(A);
		distance[A-L] = 0;
		is_visited[A-L] = 1;
		int is_possible = 0;
		while(!nodes.empty()){
			
			int u = nodes.front();
			if(u == B){
				is_possible = 1;
				break;
			}
			int indx = u-L;
			vi& v = adj[indx];
			for(auto it=v.begin(); it!=v.end(); it++){
				int indx_v = *it-L;
				if(is_visited[indx_v] == 0){
					distance[indx_v] = distance[indx]+1;
					is_visited[indx_v] = 1;
					nodes.push(*it);
				}
			}
			
			nodes.pop();
		}

		if(is_possible){
			cout<<distance[B-L]<<endl;
		}
		else{
			cout<<"Impossible"<<endl;			
		}

	}//while


	return 0;
}