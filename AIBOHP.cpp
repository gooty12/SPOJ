#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 

int main(){
	int t,len;
	
	cin>>t;
	
	while(t--){
		string str;
		cin>>str;
		int n = str.size();

		vvi minInsertions(n+1, vi(n, 0));
		for(int len=2; len<=n;len++){
			for(int i=0; i+len-1<=n-1; i++){
				if(str[i] == str[i+len-1]){
					minInsertions[len][i] = minInsertions[len-2][i+1];
				}
				else{
					minInsertions[len][i] = min(minInsertions[len-1][i]+1,
													minInsertions[len-1][i+1]+1);
				}
				//cout<<minInsertions[len][i]<<endl;
			}
		}

		cout<<minInsertions[n][0]<<endl;
	}

return 0;
}

