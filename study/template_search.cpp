#include <iostream>

using namespace std;

template <class T>
bool search(int num,T x[], int arr_size ){
	
	for(int i=0; i<arr_size; i++){
		if(x[i]==num) return true;
	}
	
	return false;
}

int main(){
	
	int x[] = {1,10,100,5,4};
	int num;
	
	cout<<"수를 입력해주세요>> ";
	cin>> num;
	
	if(search(num,x,5))cout<<num<<" => 배열에 포함되어 있다";
	else cout<<num<<" => 배열에 포함되어 있지 않다.";
	
	
	return 0;
	
}
