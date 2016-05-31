#include "debugger2.hpp"
#include<iostream>
#include<vector>

using namespace std;

int main(){

	vector<int> v(10, 1);
	db_print_container(v.begin(), v.end(), "Hello ");

	print("a values is ", 10);
	return 0;
}
