#include<iostream>
#include<stack>

using namespace std;
const int N = 1000;

int main(){

	int n;
	int parade[N];
	stack<int> side_street;
	while(1){
		cin>>n;
		if(n == 0)
			break;
		for(int i=0; i<n; i++){
			cin>>parade[i];
		}
		
		side_street.push(N+1);
		int i=0;
		while(parade[i]!=1 &&  parade[i]<side_street.top()){
			side_street.push(parade[i]);
			i++;
		}
		if(parade[i]>side_street.top()){
			cout<<"no"<<endl;
			continue;
		}

		int approach_street_truck = 1;
		int possible = 1;
		for(int j=i+1; j<n; j++){
			//cout<<approach_street_truck<<" ";
			if(side_street.top() == approach_street_truck+1){
				side_street.pop();
				approach_street_truck++;
				j--;
				continue;
			}
			else if(parade[j] == approach_street_truck+1){
				approach_street_truck++;
			}
			else if(parade[j] < side_street.top())
				side_street.push(parade[j]);
			else{
				possible = 0;
				break;
			}
		}
		/*for(int i=0; i<n; i++){
			if((approach_street_truck==-1 && parade[i]==1) ||
				 (approach_street_truck!=-1 && parade[i]==approach_street_truck+1))
				approach_street_truck = parade[i];
			else if(side_street_truck == -1)
				side_street_truck = parade[i];
			else if((approach_street_truck==-1) ||
					(approach_street_truck!=-1 && parade[i]!=approach_street_truck+1)){
				if(parade[i] < side_street_truck){
					side_street_truck = parade[i];
				}
				else{
					possible = 0;
					break;
				}
			}
		  }*/

		if(possible)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}