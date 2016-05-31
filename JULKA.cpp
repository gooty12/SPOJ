#include<iostream>
#include<cstring>
//#include<debugger.h>

using namespace std;

void convert_to_int(int* arr, char* str, int len);

int main(){

	for(int i=0; i<10; i++){
		
		char str1[101];
		char str2[101];
		cin>>str1;
		cin>>str2;
		
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int total_candies[101];
		int excess_candies[101];

		convert_to_int(total_candies, str1, len1);
		convert_to_int(excess_candies, str2, len2);

		/*cout<<"Integers are"<<endl;
		db_print_container(total_candies, total_candies+len1);
		db_print_container(excess_candies, excess_candies+len2);*/

		//subtract excess
		for(int j=len1-1, k=len2-1; k>=0; k--, j-- ){
			int d1 = total_candies[j];
			int d2 = excess_candies[k];
			if(d1<d2){
				d1 += 10;
				if(total_candies[j-1]>0){
					total_candies[j-1] -= 1;
				}
				else{
					int l;
					for(l=j-1; total_candies[l]==0; l--)
						total_candies[l] = 9;
					total_candies[l] -= 1;
				}
			}

			total_candies[j] = d1-d2;
		}

		/*cout<<"Subtracted int"<<endl;
		db_print_container(total_candies, total_candies+len1);*/

		//divide by 2
		int borrow = 0;
		for(int j=0; j<len1; j++){
			int d = total_candies[j] + 10*borrow;
			total_candies[j] = d/2;
			borrow = d%2;
		}

		/*cout<<"Divided int"<<endl;
		db_print_container(total_candies, total_candies+len1);*/
		
		borrow = 0;
		int klaudia[100]={0};
		for(int j=len1-1, k=len2-1; j>=0 ; j--, k--){
			int d1 = total_candies[j];
			int d2 = 0;
			if(k>=0)
				d2 = excess_candies[k];
			int d = d1 + d2 + borrow;
			klaudia[j] = d%10;
			borrow =  d/10;
		}

		int j;
		for(j=0; j<len1 && klaudia[j]==0; j++){
			;
		}
		if(j==len1)
			cout<<0;
		else
			for(; j<len1; j++)
				cout<<klaudia[j];
		cout<<endl;
		
		
		for(j=0; j<len1 && total_candies[j]==0; j++){
			;
		}
		if(j==len1)
			cout<<0;
		else
			for(; j<len1; j++)
				cout<<total_candies[j];
		cout<<endl;

	}
	return 0;
}

void convert_to_int(int* arr, char* str, int len){
	for(int i=0; i<len; i++){
		arr[i] = str[i] - '0';
	}

}