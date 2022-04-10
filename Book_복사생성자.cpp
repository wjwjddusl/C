#include <iostream>
#include <cstring>

using namespace std;

class Book{
	char *title;
	int price;
	
public:
	Book(const char *title, int price);//������
	Book(const Book &b); //��������� ����. 
	~Book(); //�Ҹ���
	void set(const char* title, int price);
	void show(){
		cout<<title<<" "<<price<<"��"<<endl;
	} 
	
};

Book::Book(const char* title, int price){ //������  
	int len = strlen(title); //title ���� ���� ���� 
	this->title = new char [len+1]; //���� �迭 ����
	this->price=price;
	
	strcpy(this->title, title); //title ���� 
	
}
Book::~Book(){
	//�Ҹ���
	if(title)
		delete [] title; //title ���� �迭 ��ȯ 
}

void Book::set(const char *title, int price){ //�����Ѱ� ����� ���ο� ���� �ִ� �Լ� 
		if(this->title)
			delete [] this->title; //���� title �޸� ��ȯ (���� ������ ���� ����) 
		int len = strlen(title); //���� ����
		this->title = new char [len +1];  //���ο� ���� �Ҵ� �迭 ���� (���ο� ����)
		strcpy(this->title, title); //����
		
		this->price =  price;
}

Book::Book(const Book &b){ //��������� (��������) 
	//title, price ���� 
	this->title = b.title;
	this->price=b.price;
	
	int len =  strlen(title); //title ���ڰ���
	this->title = new char [len+1]; //���ڿ� �����Ҵ�
	strcpy(this->title, b.title); //title�� ���ڿ� ���� 
} 


int main(){
	Book cpp("��ǰC++",10000); //��ü ����, ������ ȣ�� 
	Book java =cpp; //��������� ȣ�� 
	java.set("��ǰ�ڹ�",12000); //������
	
	cpp.show();
	java.show(); 
	
	return 0;
}
