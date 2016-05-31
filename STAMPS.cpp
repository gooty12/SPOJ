#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int stamps[1000];
	int t, stamps_req, n, scenario=0;

	cin>>t;
	while(t--){
		scenario++;
		cin>>stamps_req>>n;
		for(int i=0; i<n; i++){
			cin>>stamps[i];
		}
		sort(stamps, stamps+n, greater<int>());
		int stamps_borrowed = 0, i;
		for(i=0; i<n; i++){
			if(stamps_borrowed >= stamps_req)
				break;
			else
				stamps_borrowed += stamps[i];
		}
		cout<<"Scenario #"<<scenario<<":"<<endl;
		if(stamps_borrowed < stamps_req)
			cout<<"impossible"<<endl;
		else{
			if(stamps_req == 0)
				cout<<0<<endl;
			else
				cout<<i<<endl;
		}
	}
}