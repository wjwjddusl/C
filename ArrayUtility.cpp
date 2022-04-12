#include <iostream>

using namespace std;

class ArrayUtility{
public: 
	static void intToDouble(int source[], double dest[], int size); //int []를 double [] 로 변환
	static void doubleToInt(double source[], int dest[], int size); //double[]를 int []로 변환 
	
};

void ArrayUtility::intToDouble(int source[], double dest[], int size){
	for(int i=0; i<size; i++){
		dest[i]=static_cast<double>(source[i]); //double로 형변환 
	}
}
void ArrayUtility::doubleToInt(double source[], int dest[], int size){
	for(int i=0; i<size; i++){
		dest[i] = source[i];  
	}
}

int main(){
	//동일한 크기의 배열 3개 선언 
	int x[] = {1,2,3,4,5};
	double y[5];
	double z[] ={9.9, 8.8, 7.7, 6.6,5.6};
	
	//double로 변환 
	ArrayUtility::intToDouble(x,y,5);  // x->y
	for(int i=0; i<5; i++)
		cout<<y[i]<<' ';
	cout<<endl;
	
	//int 로 변환
	ArrayUtility::doubleToInt(z,x,5); //z->x
	for(int i=0; i<5; i++)
		cout<<x[i]<<' ';
	cout<<endl; 
	
	return 0;
}
