#include<iostream>
#include<set>

using namespace std;

int main(){

	int N;
	cin>>N;
	set<int> frnds_list;
	for(int i=0; i<N; i++){
		int frnd;
		cin>>frnd;
		frnds_list.insert(frnd);
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			int id;
			cin>>id;
			frnds_list.insert(id);
		}

	}
	cout<<frnds_list.size()-N<<endl;
	return 0;
}