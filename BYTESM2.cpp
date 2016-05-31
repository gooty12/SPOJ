#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

	int T;
	cin>>T;
	
	while(T--){
		int h, w;
		cin>>h>>w;
		vector< vector<int> > chamber(h, vector<int>(w));
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin>>chamber[i][j];
			}
		}
		
		
		//vector< vector<int>  > chamber = chamber;
		//int r = 1;
		for(int r=1; r<h; r++){
			for(int i=0; i<w; i++){
				int above = chamber[r-1][i];
				int d_left = 0;
				int d_right = 0;
				if(i > 0)
					d_left = chamber[r-1][i-1];
				if(i < w-1)
					d_right = chamber[r-1][i+1];
				chamber[r][i] = chamber[r][i] + max(max(above, d_left), d_right);
			}
		}
		
		
		int res = *max_element(chamber[h-1].begin(), chamber[h-1].end());
		cout<<res<<endl;
	}

	return 0;
}