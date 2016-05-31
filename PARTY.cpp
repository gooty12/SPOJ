#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define vii vector< pair<int, int> >

int main(){

	while(1){
		int budget, n;
		cin>>budget>>n;
		
		if(!budget && !n){
			break;
		}

		if(n==0){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		
		//(fee, fun)
		vii parties(n);
		for(int i=0; i<n; i++){
			cin>>parties[i].first>>parties[i].second;
		}

		sort(parties.begin(), parties.end());

		if(budget==0){
			cout<<0<<" "<<0<<endl;
			continue;
		}

		vector< vii > max_fun(n, vii(budget+1));
		for(int fee=0; fee<=budget; fee++){
			if(fee >= parties[0].first){
				max_fun[0][fee].first = parties[0].first;
				max_fun[0][fee].second = parties[0].second;
			}
			else{
				max_fun[0][fee].first = 0;
				max_fun[0][fee].second = 0;
			}
		}

		for(int i=1; i<n; i++){
			for(int c_budget=0; c_budget<=budget; c_budget++){
				int fee = max_fun[i-1][0].first;
				int fun = max_fun[i-1][0].second;
				for(int t_budget=1; t_budget<=c_budget; t_budget++){
					int b = max_fun[i-1][t_budget].first;
					int f = max_fun[i-1][t_budget].second;
					if(b+parties[i].first <= c_budget){
						f += parties[i].second;
						b += parties[i].first; 
					}
					if(fun == f){
						fee = min(b, fee);
					}
					else{
						fun = max(fun, f);
						if(fun == f){
							fee = b;
						}
					}
				}
				max_fun[i][c_budget].first = fee;
				max_fun[i][c_budget].second = fun;
			}
		}

		cout<<max_fun[n-1][budget].first<<" "
							<<max_fun[n-1][budget].second<<endl;

	}
	
	return 0;
}