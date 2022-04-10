#include <iostream>

using namespace std;

class Dept{
	int size;
	int *scores; 
	
public:
	Dept(int size){ //생성자 
		this->size =size;
		scores = new int [size]; //size 길이 만큼 동적 배열 생성 
	}
	Dept(const Dept &d); //복사생성자
	~Dept(); //소멸자
	int getSize(){
		return size;
	} 
	void read(); //size 만큼 읽어 scores에 저장
	bool isOver60(int index); //index의 학생의 성적이 60보다 크면 true 리턴. 
	 
};
Dept::Dept(const Dept &d){ //복사 생성자 
	this->size = d.size;
	this->scores =new int [this->size]; //새로운 배열 공간 할당

	for(int i=0; i< this->size; i++){ //배열 전체 복사 
		this->scores[i] = d.scores[i];
	}
	
		
}
Dept::~Dept(){
	//소멸자
	delete [] scores; //동적배열 해제 
}

void Dept::read(){
	
	cout<<size<<"개 점수 입력: ";
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

int countPass(Dept dept){
	int count=0;
	for(int i=0; i<dept.getSize(); i++){
		if(dept.isOver60(i))  //true면 
			count++; //60점 이상이면 count 수 증가 
	}
	
	return count; //60점 이상 학생수 리턴 
}

int main(){
	
	int size;
	
	cout<<"학생수: ";
	cin >>size;
	
	Dept com(size); 
	com.read();
	
	int n = countPass(com); //60점 이상으로 통과한 학생수 (복사생성자 호출) 
	cout<<"60점 이상 학생은 "<<n<<" 명."<<endl; 
	
	return 0;
}
