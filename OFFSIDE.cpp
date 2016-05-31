#include<iostream>

using namespace std;

int main(){

	while(1){
		int A, D;
		cin>>A>>D;
		if(!A && !D)
			break;
		int attacker = 10001;
		for(int i=0; i<A; i++){
			int n;
			cin>>n;
			if(n < attacker)
				attacker = n;
		}
		int defendants = 0;
		for(int i=0; i<D; i++){
			int n;
			cin>>n;
			if(n <= attacker)
				defendants++;
		}
		if(defendants < 2)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}

	return 0;
}