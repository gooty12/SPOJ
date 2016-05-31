#include<iostream>
#include<cmath>
#include<debugger.h>

#define LOG5 log10(5.0) 

using namespace std;

int sum_of_n(int n);

int main(){

	int T;
	int N;

	cin>>T;
	while(T--){
		cin>>N;
		int no_of_zeros = 0;
		int no_of_fives = N/5;
		/*int no_of_fifties = no_of_fives/10;
		int no_of_powers_of_fifties = floor(log10(1.0*N/10)/log10(5));
		int no_of_powers_of_five = floor(log10(1.0*N)/LOG5);
		int no_of_powers_of_10 = floor(log10(1.0*N));
		no_of_zeros = no_of_fives + no_of_fifties + sum_of_n(no_of_powers_of_fifties) + sum_of_n(no_of_powers_of_10-1) + sum_of_n(no_of_powers_of_five-1);
		db_print("tens powers is ", no_of_powers_of_10, " five powers is ",  no_of_powers_of_five);
		*/
		no_of_zeros = no_of_fives;
		int n = 25;
		while(n<=N){
			no_of_zeros += N/n;
			n *= 5;
		}

		cout<<no_of_zeros<<endl;
	}
	return 0;
}

int sum_of_n(int n){
	return((n * (n+1))/2);
}