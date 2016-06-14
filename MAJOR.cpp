#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);

		for(int i=0; i<n; i++){
			scanf("%d", &v[i]);
		}

		sort(v.begin(), v.end());
		int res = 0;
		int data;
		for(int i=0; i<n; ){
			int count = 1;
			i++;
			while(i<n && v[i]==v[i-1]){
				i++;
				count++;
			}
			res = max(res, count);
			if(res == count){
				data = v[i-1];
			}
		}
		//cout<<"res is "<<res<<endl;
		if(res > (n/2)){
			printf("YES %d\n", data);
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}