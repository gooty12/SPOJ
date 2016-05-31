#include<iostream>
#include<algorithm>

using namespace std;

long long max_dollars(long long bytecoin);

const int SZ = 1000000;
long long dollars[SZ]={0};

int main(){

	int n;
	for(long long i=1; i<SZ; i++){
		dollars[i] = max(dollars[i/2]+dollars[i/3]+dollars[i/4], i);
	}
	while(cin>>n){
		
		//ostream::flush();
		cout<<max_dollars(n)<<endl;
	}
	return 0;
}

long long max_dollars(long long bytecoin){
	
	if(bytecoin<SZ){
		//cout<<bytecoin<<std::flush;
		return dollars[bytecoin];
	}
	//cout<<bytecoin<<std::flush;
	long long res = max(max_dollars(bytecoin/2)
								+ max_dollars(bytecoin/3)
									+ max_dollars(bytecoin/4),
										bytecoin);

	return res;
}