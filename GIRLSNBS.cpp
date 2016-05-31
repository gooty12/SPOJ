#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){

	int G, B;
	while(1){
		cin>>G>>B;
		if(G==-1 && B==-1)
			break;
		if(G==0 || B==0)
			cout<<abs(G-B)<<endl;
		else{
			int n1 = min(G, B);
			int n2 = G+B-n1;
			int res = n2/(n1+1);
			if(n2%(n1+1))
				res++;
			cout<<res<<endl;
		}
	}
}