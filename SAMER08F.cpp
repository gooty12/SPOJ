#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N;
	while(1){
		cin>>N;
		if(N==0)
			break;
		int res=0;
		for(int i=N; i>0; i--){
			for(int j=N; j>0; j--){
				res += min(i, j);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}