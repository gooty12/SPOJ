#include<iostream>
#include<algorithm>
#include<cmath>
#include<cfloat>

using namespace std;

int main(){

	long long int N;
	while(1){
		cin>>N;
		if(N == -1)
			break;
		else if(N == 1)
			cout<<"Y"<<endl;
		else if((N-1)%6){
			cout<<"N"<<endl;
		}
		else{
			long long int c;
			double r, t;
			c = (N-1)/3;
			t = pow(4.0*c+1, 0.5);
			if(abs(t-trunc(t)) > DBL_EPSILON){
				cout<<"N"<<endl;
				continue;
			}
			r = (t-1.0)/2.0;
			if(abs(r-trunc(r)) > DBL_EPSILON){
				cout<<"N"<<endl;
				continue;
			}
			if(abs(c-r*(r+1)) < DBL_EPSILON){//
				cout<<"Y"<<endl;
			}
			else{
				cout<<"N"<<endl;
			}

		}
	}
	return 0;
}