#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>

using namespace std;

int main(){

	int t;
	string s;
	getline(cin, s);
	t = stoi(s);
	
	while(t--){
		int n;
		getline(cin, s);
		n = stoi(s);

		map<string, int> accounts;
		for(int i=0; i<n; i++){
			getline(cin, s);
			auto p = accounts.insert(make_pair(s, 1));
			if(!p.second){
				p.first->second++;
			}
		}

		for(auto& a: accounts){
			cout<<a.first<<" "<<a.second<<endl;
		}
		cout<<endl;

		if(t>0){
			getline(cin, s);
		}

	}//while

	return 0;
}