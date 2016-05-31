#include<iostream>

using namespace std;

const int N = 100000;

int main(){
	int perm[N+1];
	perm[0] = -1;
	while(1){
		int n;
		int flag = 1;
		cin>>n;
		if(n == 0)
			break;
		for(int i=1; i<=n; i++)
			cin>>perm[i];
		for(int i=1; i<=n; i++){
			if(perm[perm[i]] != i){
				flag = 0;
				break;
			}
		}
		if(flag)
			cout<<"ambiguous"<<endl;
		else
			cout<<"not ambiguous"<<endl;
	}
	return 0;
}