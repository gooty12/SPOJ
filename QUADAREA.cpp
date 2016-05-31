#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

double area(int i, int j, vector<double>& sides);

int main(){

	int t;
	cin>>t;

	while(t--){
		vector<double> sides(4);
		for(int i=0; i<4; i++){
			cin>>sides[i];
		}

		double res = -1;
		for(int i=0; i<3; i++){
			for(int j=i+1; j<4; j++){
				res = max(res, area(i, j, sides));
			}
		}

		printf("%.2lf\n", res);
	}

	return 0;
}

double area(int i, int j, vector<double>& sides){

	double res, h;
	double a = sides[i], b = sides[j];
	double c = -1, d;
	for(int k=0; k<4; k++){
		if((k!=i && k!=j) && (c==-1)){
			c = sides[k];
		}
		if((k!=i && k!=j) && (c!=-1)){
			d = sides[k];
		}
	}
	h = pow(c, 2.0) + pow(d, 2.0) - pow(a-b, 2.0);
	h = pow(h/2.0, 0.5);
	
	if(h>c ||  h>d){
		res = -1;
	}
	else{
		res = 0.5*h*(a+b);
	}

	return res;
}