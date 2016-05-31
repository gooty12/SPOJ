#include<iostream>

using namespace std;

int binary_search_ceiling(double* cardlengths, int start, int end, float val, int res);

int main(){

	double cardlengths[300];
	cardlengths[0] = 0.0;
	for(int i=1; i<300; i++){
		cardlengths[i] = cardlengths[i-1] + 1.0/(i+1);
	}
	//cout<<cardlengths[1]<<endl<<cardlengths[273]<<endl<<cardlengths[299]<<endl;
	double c;
	while(1){
		cin>>c;
		if(c==0)
			break;
		int min_no_of_cards = binary_search_ceiling(cardlengths, 0, 300, c, 0);
		cout<<min_no_of_cards<<" "<<"card(s)"<<endl;
	}
	return 0;
}

int binary_search_ceiling(double* cardlengths, int start, int end, float val, int res=0){
	int mid = (start+end)/2;
	//cout<< start << " " << end << " "<<mid<<endl;
	if(start==end){
		if(cardlengths[start]>=val)
			res = start;
	}
	else if(cardlengths[mid]==val)
		res = mid;
	else if(cardlengths[mid]>val){
		res = binary_search_ceiling(cardlengths, start, mid, val, mid);
	}
	else{
		res = binary_search_ceiling(cardlengths, mid+1, end, val, res);
	}
	return res;

}