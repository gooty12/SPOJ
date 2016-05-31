#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int men[1000];
	int women[1000];
	int t, N;

	cin>>t;
	while(t--){
		cin>>N;
		for(int i=0; i<N; i++)
			cin>>men[i];
		for(int i=0; i<N; i++)
			cin>>women[i];
		sort(men, men+N);
		sort(women, women+N);
		
		int hotness = 0;
		for(int i=0; i<N; i++)
			hotness += men[i]*women[i];
		cout<<hotness<<endl;

	}
	return 0;
}