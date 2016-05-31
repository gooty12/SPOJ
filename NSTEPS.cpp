#include<iostream>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;

		if(x==0){
			if(y==0){
				cout<<0<<endl;
				continue;
			}
		}

		if(x==1){
			if(y==1){
				cout<<1<<endl;
				continue;
			}
		}

		if(x%2){
			if(y==x){
				cout<<2*x-1<<endl;
				continue;
			}
			if(y == x-2){
				cout<<2*x-3<<endl;
				continue;
			}
		}
		else{
			if(y==x){
				cout<<2*x<<endl;
				continue;
			}
			if(y == x-2){
				cout<<2*x-2<<endl;
				continue;
			}

		}

		cout<<"No Number"<<endl;
	}
	return 0;
}