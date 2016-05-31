#include<iostream>
#include<vector>
#include<limits>

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef std::vector<pi> vpi;

int main(){

	int n;
	while(cin>>n){
		
		vi mixtures(n);
		for(int i=0; i<n; i++){
			cin>>mixtures[i];
		}

		vector<vpi> dp(n+1, vpi(n));
		for(int i=0; i<n; i++){
			dp[1][i].first = mixtures[i];
			dp[1][i].second = 0;
		}

		for(int l=2; l<=n; l++){
			for(int i=0; i+l-1<=n-1; i++){
				dp[l][i].second = numeric_limits<int>::max();
				for(int ll=1; ll<l; ll++){
					int a = dp[ll][i].first;
					int b = dp[l-ll][i+ll].first;
					int s = dp[ll][i].second + dp[l-ll][i+ll].second;
					if(a*b+s < dp[l][i].second){
						dp[l][i].second = a*b + s;
						dp[l][i].first = (a+b)%100;
					}

				}
			}
		}

		cout<<dp[n][0].second<<endl;
	}
	return 0;
}