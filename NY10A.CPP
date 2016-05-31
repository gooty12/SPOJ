#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main(){

	int P;
	cin>>P;
	while(P--){
		int t;
		cin>>t;
		string sequence;
		cin>>sequence;
		
		vector<int> occurrences(8,0);
		for(int i=2; i<40; i++){
			int indx = 0;
			for(int j=0; j<3; j++){
				indx += pow(2, j)*(sequence[i-j]=='H');
			}
			occurrences[indx]++;
		}
		
		cout<<t;
		for(int i=0; i<8; i++){
			cout<<" ";
			cout<<occurrences[i];
		}
		cout<<endl;

	}
	return 0;
}