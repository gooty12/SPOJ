#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define MAX_DIFF 1000000
#define on_same_mountain(a, b) ((a).second==(b).second)
#define emp_bk emplace_back

int main(){

	int t;
	cin>>t;
	
	while(t--){
		int N1, N2;
		vpi points;
		
		cin>>N1;
		for(int i=0; i<N1; i++){
			int pos;
			cin>>pos;
			points.emp_bk(pos, 1);
		}

		cin>>N2;
		for(int i=0; i<N2; i++){
			int pos;
			cin>>pos;
			points.emp_bk(pos, 2);
		}

		sort(points.begin(), points.end());

		auto it = points.begin();
		int res = MAX_DIFF;
		while(res!=0 && it!=points.end()){
			auto tmp = it+1;
			while(tmp != points.end() && on_same_mountain(*it, *tmp)){
				tmp++;
			}
			if(tmp != points.end()){
				res = min(res, ((*tmp).first - (*(tmp-1)).first));
			}
			it = tmp;
		}

		cout<<res<<endl;
	}

	return 0;
}