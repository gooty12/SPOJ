#include<iostream>

using namespace std;

int main(){

	int N, a, b;
	int periodicity[10]={1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
	int last_digit[10][5]={{0},{1, 1, 1, 1, 1},{1, 2, 4, 8, 6},{1, 3, 9, 7, 1},{1, 4, 6},
							{1, 5},{1, 6},{1, 7, 9, 3, 1},{1, 8, 4, 2, 6},{1, 9, 1}};
	cin>>N;
	while(N--){
		cin>>a>>b;
		a = a%10;
		if(a==0)
			cout<<0<<endl;
		else if(b==0)
			cout<<1<<endl;
		else{
			int period = periodicity[a];
			int indx = b%period;
			if(indx==0)
				indx = period;
			cout<<last_digit[a][indx]<<endl; 
		}
	}
	return 0;
}