#include <iostream>
#include <string>

using namespace std;

//������׷� �ۼ� 
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
	this->a +=c; //���ڿ��� ���� �̾���̱� 
	return *this;
}
void Histogram::operator!(){
	int alpha[26] = {0}; //�迭 ����
	int count =0; ///�� ���ĺ� �� 
	char c;
	for(int i=0; i<a.size(); i++){
		c= a[i]; //������ c�� �ѱ��ھ� �ֱ�
		if(isalpha(c) !=0){ //c�� ���ĺ��̸� / isalpha�Լ��� ���ĺ��� �ƴѰ�� 0 ��ȯ 
			c= tolower(a[i]); //�ҹ��ڷ� ����
			alpha[(int)c - 97]++; //97='a', 26������ �¹� �ּ� +1, ������ ������ ��� ���� 
			++count; 
		} 
	} 
	//���
	cout <<"�� ���ĺ� ��: "<<count<<endl;
	
	for(int i=0; i<26; i++){
		cout<<(char)(i+97)<<": "; //97=a ���� ���ʴ�� ���
		for(int j=0; j<alpha[i]; j++){ //���ĺ��� �� ����ŭ ��� 
			cout<<"*";
		} 
		cout<<endl;
	} 
}
int main(){
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song <<"falling"<<" in love with you."<<" -by"; //���ڿ� �߰�
	song <<'k'<<'i'<<'t'; //���� �߰�
	!song; //������׷� �׸��� 
	
}
