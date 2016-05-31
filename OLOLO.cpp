#include<iostream>
#include<algorithm>

using namespace std;
//const int SZ = 100000;
//int arr[SZ];
//const int SZ = 500000;
int main(){

	int N;
	cin>>N;
	int arr[N];
	for(int i=0; i<N; i++){
		//int pi;
		cin>>arr[i];
		/*int indx = pi%SZ;
		if(arr[pi])
			res -= pi;
		else{
			arr[pi] = 1;
			res += pi;
		}*/
	}
	sort(arr, arr+N);
	int res = -1;
	for(int i=0; i<N-1; ){
		if(arr[i] != arr[i+1]){
			res = arr[i];
			break;
		}
		else
			i = i+2;
	}
	if(res == -1)
		res = arr[N-1];
	cout<<res<<endl;
	return 0;
}