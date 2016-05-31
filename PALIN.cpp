#include<iostream>
#include<cstring>

using namespace std;

char number[1000000];

int main(){

	int K;
	cin>>K;

	while(K--){
		cin>>number;
		int len = strlen(number);
		int big = number[0]>number[len-1];
		int inc_digits = 0;
		int indx = -1;
		int flag=0;
		for(int i=0; i<(len+1)/2; i++){
			
			if(number[i]!='9')
				indx = i;
			if(i != len-i-1)
				big = number[i]>number[len-i-1];
			
			if(i == (len+1)/2 - 1){
				number[i] = number[len-i-1] = number[i];
				if(!big){
					if(number[i]!='9'){
						number[i] = number[len-i-1] = (char)(number[i]+1);
					}
					else{
						flag = 1;
						if(indx!=-1){
							number[indx] = number[len-indx-1] = (char)(number[indx]+1);
						}
					}
				}
			}
			else{
				number[len-i-1] = number[i];
			}
		}

		if(indx==-1){
			cout<<1;
		}
		for(int i=0; i<len; i++){
			if(i>indx && i<len-indx-1 && flag){
				if(i == len-1)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<number[i];
		}
		cout<<endl;
	}
	return 0;
}
