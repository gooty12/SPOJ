#include<iostream>

using namespace std;

int main(){
	
	long long T;
	cin>>T;
	while(T--){
		long long N;
		long long candies, total_candies = 0;
		cin>>N;
		for(long long i=0; i<N; i++){
			cin>>candies;
			total_candies = (total_candies%N + candies%N)%N;
		}
		if(total_candies)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}