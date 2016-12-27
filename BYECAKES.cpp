#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

	while(1){
		int ingredients[8];
		for(int i=0; i<8; i++){
			cin>>ingredients[i];
		}
		if(ingredients[0] == -1){
			break;
		}
		int maxm = -1;
		for(int i=0; i<4; i++){
			int n = ingredients[i]/ingredients[i+4] + 
									(ingredients[i]%ingredients[i+4]?1:0);
			maxm = max(maxm, n);
		}
		for(int i=0; i<4; i++){
			cout<<(ingredients[i+4]*maxm - ingredients[i])<<" ";
		}
		cout<<endl;
	}
	return 0;
}