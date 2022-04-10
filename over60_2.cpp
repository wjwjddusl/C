#include <iostream>

using namespace std;

class Dept{
	int size;
	int *scores; 
	
public:
	Dept(int size){ //������ 
		this->size =size;
		scores = new int [size]; //size ���� ��ŭ ���� �迭 ���� 
	}
	~Dept(); //�Ҹ���
	int getSize(){
		return size;
	} 
	void read(); //size ��ŭ �о� scores�� ����
	bool isOver60(int index); //index�� �л��� ������ 60���� ũ�� true ����. 
	 
};

Dept::~Dept(){
	//�Ҹ���
	delete [] scores; //�����迭 ���� 
}

void Dept::read(){
	
	cout<<size<<"�� ���� �Է�: ";
	for(int i=0; i<getSize(); i++){
		cin>> scores[i]; 
	}
	
}

bool Dept::isOver60(int index){
	
	if(scores[index] >= 60)
		return true;
	else
		return false;
}

int countPass(Dept &dept){ //���������� ȣ�� 
	int count=0;
	for(int i=0; i<dept.getSize(); i++){
		if(dept.isOver60(i))  //true�� 
			count++; //60�� �̻��̸� count �� ���� 
	}
	
	return count; //60�� �̻� �л��� ���� 
}

int main(){
	
	Dept com(10); 
	com.read();
	
	int n = countPass(com); //60�� �̻����� ����� �л���
	cout<<"60�� �̻� �л��� "<<n<<" ��."<<endl; 
	
	return 0;
}
