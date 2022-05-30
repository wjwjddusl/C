#include <iostream>
#include <string>

using namespace std;

//히스토그램 작성 
class Histogram{
	string a; 
	
public:
	Histogram(string a){
		this->a = a;
	}
	Histogram& operator<<(string a);
	Histogram& operator<<(char c);
	void operator!();
};

Histogram& Histogram::operator<<(string a){
	this->a +=a;
	return *this;
}
Histogram& Histogram::operator<<(char c){
	this->a +=c; //문자열에 문자 이어붙이기 
	return *this;
}
void Histogram::operator!(){
	int alpha[26] = {0}; //배열 생성
	int count =0; ///총 알파벳 수 
	char c;
	for(int i=0; i<a.size(); i++){
		c= a[i]; //문자형 c에 한글자씩 넣기
		if(isalpha(c) !=0){ //c가 알파벳이면 / isalpha함수는 알파벳이 아닌경우 0 반환 
			c= tolower(a[i]); //소문자로 변경
			alpha[(int)c - 97]++; //97='a', 26순서에 맞믐 주소 +1, 같은게 나오면 계속 증가 
			++count; 
		} 
	} 
	//출력
	cout <<"총 알파벳 수: "<<count<<endl;
	
	for(int i=0; i<26; i++){
		cout<<(char)(i+97)<<": "; //97=a 부터 차례대로 출력
		for(int j=0; j<alpha[i]; j++){ //알파벳의 그 수만큼 출력 
			cout<<"*";
		} 
		cout<<endl;
	} 
}
int main(){
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song <<"falling"<<" in love with you."<<" -by"; //문자열 추가
	song <<'k'<<'i'<<'t'; //문자 추가
	!song; //히스토그램 그리기 
	
}
