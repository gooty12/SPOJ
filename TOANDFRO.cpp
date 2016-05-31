#include<iostream>
#include<cstring>

using namespace std;

int main(){

	int cols;
	while(1){
		cin>>cols;
		if(cols==0){
			break;
		}
		char msg[200], deciphered_msg[200];
		cin>>msg;
		int j=0, rows = strlen(msg)/cols;
		for(int i=0; i<cols; i++){
			for(int k=0; k<rows; k++){
				int ind;
				if(k%2==0)
					ind = k*cols + i;
				else
					ind = (k+1)*cols - i - 1;
				deciphered_msg[j++] = msg[ind];
			}
			
		}
		deciphered_msg[j++]=0;
		cout<<deciphered_msg<<endl;
	}
	return 0;
}