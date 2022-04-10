#include <iostream>

using namespace std;

class MyIntStack{
	int *p; //���� �޸� ������
	int size; //���� �ִ������
	int top; //���� ž

public:
	MyIntStack();
	MyIntStack(int size);  
	MyIntStack(const MyIntStack &s); //���� ������
	~MyIntStack();//�Ҹ���
	
	bool push(int n); //���� n Ǫ��
	//������ ���������� false, �ƴϸ� true
	bool pop(int &n); //�������� n , ���� ž ���� n�� pop 
	 
};
MyIntStack::MyIntStack(int size){
	this->size=size;
	p= new int [size]; //���� �迭 ���� 
	top =0; //�ʱ�ȭ
} 

MyIntStack::MyIntStack(const MyIntStack &s){
	//���� 
	this->p = new int [this->size]; //���ο� ���� ���� 
	this->size = s.size;
	this->top=s.top;
	
	for(int i=0; i<this->top; i++){ //���� ���� , top������ ���ݱ��� �����ϴ� ����. 
		this->p[i] = s.p[i];
	}
	
}

bool MyIntStack::push(int n){
	if(top>size)//���������� 
		return false;
	else
		p[top++]=n; //���� ž�� Ǫ�ð� �ֱ� 
		return true;
		
}

bool MyIntStack::pop(int &n){
	if(top<0) //���̻� ������ 
		return false;
	else 
		n=p[--top]; //�������� n�� ������ top-1�� �� �ֱ�(pop) , -- �� �տ� �ٿ��ֱ�. 
		return true;
}

MyIntStack::~MyIntStack(){
	delete [] p;
}

int main(){
	
	MyIntStack a(10); //��ü ����, 10����
	//������ ���� 
	a.push(10);
	a.push(20);
	
	MyIntStack b = a; //���� ������ ȣ�� 
	b.push(30); //������ b�� �� ����
	
	int n;
	a.pop(n);
	cout<<"���� a���� pop: "<<n<<endl;
	
	b.pop(n);
	cout<<"���� b���� pop: "<<n<<endl;
	
	return 0;
}
