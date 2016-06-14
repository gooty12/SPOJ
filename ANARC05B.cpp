#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

int main(){

	int n1, n2;

	while(1){
		cin>>n1;
		
		if(n1 == 0){
			break;
		}

		vi v1(n1);
		for(int i=0; i<n1; i++){
			cin>>v1[i];
		}

		cin>>n2;
		vi v2(n2);
		for(int i=0; i<n2; i++){
			cin>>v2[i];
		}

		int i = 0;
		int j = 0;
		int res = 0;
		int sum1 = 0;
		int sum2 = 0;
		while(1){
			if(i==n1){
				while(j<n2){
					sum2 += v2[j];
					j++;
				}
				res += max(sum1, sum2);
				break;
			}
			else if (j == n2){
				while(i<n1){
					sum1 += v1[i];
					i++;
				}
				res += max(sum1, sum2);
				break;
			}
			else if (v1[i] == v2[j]){
				res += v1[i];
				i++;
				j++;
				res += max(sum1, sum2);
				sum1 = sum2 = 0;
			}
			else{
				if(v1[i] > v2[j]){
					while(j<n2 && v1[i]>v2[j]){
						sum2 += v2[j];
						j++;
					}
				}
				else{
					while(i<n1 && v2[j]>v1[i]){
						sum1 += v1[i];
						i++;
					}
				}
			}
		}//main-logic

		cout<<res<<endl;
	}

	return 0;
}