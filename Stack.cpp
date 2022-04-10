#include <iostream>

using namespace std;

class MyIntStack{
	int *p; //스택 메모리 포인터
	int size; //스택 최대사이즈
	int top; //스택 탑

public:
	MyIntStack();
	MyIntStack(int size);  
	MyIntStack(const MyIntStack &s); //복사 생성자
	~MyIntStack();//소멸자
	
	bool push(int n); //정수 n 푸시
	//스택이 꽉차있으면 false, 아니면 true
	bool pop(int &n); //참조변수 n , 스택 탑 값을 n에 pop 
	 
};
MyIntStack::MyIntStack(int size){
	this->size=size;
	p= new int [size]; //동적 배열 생성 
	top =0; //초기화
} 

MyIntStack::MyIntStack(const MyIntStack &s){
	//복사 
	this->p = new int [this->size]; //새로운 공간 생성 
	this->size = s.size;
	this->top=s.top;
	
	for(int i=0; i<this->top; i++){ //공간 복사 , top까지가 지금까지 존재하는 공간. 
		this->p[i] = s.p[i];
	}
	
}

bool MyIntStack::push(int n){
	if(top>size)//꽉차있으면 
		return false;
	else
		p[top++]=n; //스택 탑에 푸시값 넣기 
		return true;
		
}

bool MyIntStack::pop(int &n){
	if(top<0) //더이상 없으면 
		return false;
	else 
		n=p[--top]; //참조변수 n의 공간에 top-1한 값 넣기(pop) , -- 꼭 앞에 붙여주기. 
		return true;
}

MyIntStack::~MyIntStack(){
	delete [] p;
}

int main(){
	
	MyIntStack a(10); //객체 생성, 10전달
	//데이터 삽입 
	a.push(10);
	a.push(20);
	
	MyIntStack b = a; //복사 생성자 호출 
	b.push(30); //복사한 b에 값 삽입
	
	int n;
	a.pop(n);
	cout<<"스택 a에서 pop: "<<n<<endl;
	
	b.pop(n);
	cout<<"스택 b에서 pop: "<<n<<endl;
	
	return 0;
}
