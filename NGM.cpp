#include<iostream>

using namespace std;

int main(){

	long long int N;
	cin>>N;
	if(N%10){
		cout<<1<<endl;
		cout<<N%10<<endl;
	}
	else{
		cout<<2<<endl;
	}
	return 0;
}