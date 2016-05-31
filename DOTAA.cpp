#include<iostream>

using namespace std;

int main(){

	int t;
	int n, m, D;
	cin>>t;
	while(t--){
		cin>>n>>m>>D;
		int heroes = 0;
		for(int i=0; i<n; i++){
			int health;
			cin>>health;
			heroes += health/D;
			if((health%D == 0) && (health>=D)){
				heroes--;
			}
		}

		if(heroes>=m){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}