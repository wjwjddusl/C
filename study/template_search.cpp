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
	
	cout<<"���� �Է����ּ���>> ";
	cin>> num;
	
	if(search(num,x,5))cout<<num<<" => �迭�� ���ԵǾ� �ִ�";
	else cout<<num<<" => �迭�� ���ԵǾ� ���� �ʴ�.";
	
	
	return 0;
	
}
