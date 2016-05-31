#include<iostream>

using namespace std;

int main(){
	int N;
	int candies[10000];
	while(1){
		cin>>N;
		if(N==-1)
			break;
		int total_candies = 0;
		for(int i=0; i<N; i++){
			cin>>candies[i];
			total_candies += candies[i];
		}
		if(total_candies%N){
			cout<<-1<<endl;
		}
		else{
			int res = 0;
			int candies_per_packet = total_candies/N;
			for(int i=0; i<N; i++){
				if(candies[i]>candies_per_packet)
					res += candies[i]-candies_per_packet;
			}
			cout<<res<<endl;
		}
	}
}