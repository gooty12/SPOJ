#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int  main(){

	int t;
	int C = 1;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int> monsters;
		for(int i=0; i<N; i++){
			int n;
			cin>>n;
			monsters.push_back(n);
		}

		long long a=0, b=0;
		if(N>0){
			a = monsters[0];
		}
		if(N>1){
			b = max(monsters[0], monsters[1]);
		}
		else{
			b = a;
		}
		for(int i=2; i<N; i++){
			long long tmp  = max(b, monsters[i]+a);
			a = b;
			b = tmp;
		}

		cout<<"Case "<<C<<": "<<b<<endl;
		C++;
	}
	return 0;
}