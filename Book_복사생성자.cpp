#include <iostream>
#include <cstring>

using namespace std;

class Book{
	char *title;
	int price;
	
public:
	Book(const char *title, int price);//생성자
	Book(const Book &b); //복사생성자 선언. 
	~Book(); //소멸자
	void set(const char* title, int price);
	void show(){
		cout<<title<<" "<<price<<"원"<<endl;
	} 
	
};

Book::Book(const char* title, int price){ //생성자  
	int len = strlen(title); //title 문자 개수 저장 
	this->title = new char [len+1]; //동적 배열 생성
	this->price=price;
	
	strcpy(this->title, title); //title 복사 
	
}
Book::~Book(){
	//소멸자
	if(title)
		delete [] title; //title 동적 배열 반환 
}

void Book::set(const char *title, int price){ //복사한걸 지우고 새로운 정보 넣는 함수 
		if(this->title)
			delete [] this->title; //현재 title 메모리 반환 (현재 적혀진 내용 리셋) 
		int len = strlen(title); //길이 저장
		this->title = new char [len +1];  //새로운 동적 할당 배열 생성 (새로운 공간)
		strcpy(this->title, title); //복사
		
		this->price =  price;
}

Book::Book(const Book &b){ //복사생성자 (깊은복사) 
	//title, price 복사 
	this->title = b.title;
	this->price=b.price;
	
	int len =  strlen(title); //title 문자개수
	this->title = new char [len+1]; //문자열 공간할당
	strcpy(this->title, b.title); //title에 문자열 복사 
} 


int main(){
	Book cpp("명품C++",10000); //객체 생성, 생성자 호출 
	Book java =cpp; //복사생성자 호출 
	java.set("명품자바",12000); //값변경
	
	cpp.show();
	java.show(); 
	
	return 0;
}
