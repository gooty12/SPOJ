#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

	int N;
	vector<int> v;
	cin>>N;
	v.push_back(N);
	for(int i=1; ; i++){
		int ss = 0;
		while(N){
			ss += pow((N%10), 2);
			N /= 10;
		}
		if(ss == 1){
			cout<<i<<endl;
			break;
		}
		else{
			vector<int>::iterator it = find(v.begin(), v.end(), ss);
			if(it == v.end()){
				v.push_back(ss);
				N = ss;
			}
			else{
				cout<<-1<<endl;
				break;
			}
		}
	}

	return 0;
}