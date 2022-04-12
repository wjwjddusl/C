#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	//글자 맞추기 게임
	//string list [] = {"bnana", "strobarry","melon","apple","orange"}; //배열 생성
	
	int n;
	cout<<"몇개를 입력하시겠습니까? ";
	cin >>n;
	
	string *list = new string [n]; //동적 배열생성 
	
	cout<<"단어 "<<n<<"개를 입력하세요."<<endl;
	for (int i=0; i<n; i++){ //배열 입력받기 
		cout<<i+1<<"번째 단어 입력: ";
		cin>>list[i]; 
	}
	
	srand(time(NULL)); //실행때마다 랜덤 생성
	int r = rand()%n; 
	
	string str = list[r]; //str 문자열에 랜덤으로 뽑은 문자열 넣기
	string q(str.length(),'_'); //뽑은 문자열만큼 _로 채우기, 쌍따옴표 안됨. 
	
	char ans; //내가 입력할 답. 
	cout<<"=============================="<<endl;	
	cout<<"문자열 길이: "<<q<<endl;

	while(true){
		
		cout<<"입력: ";
		cin >> ans;
		
		for(int i=0; i<str.length(); i++){
			if(ans==str[i]){
				q[i] = ans; //맞춘곳에 내가 입력한 값 삽입. 
				cout<<q<<endl;
			}		
		
		}
		
		if(str==q){ //빈칸이 다 채워지면. 
			cout<<"성공";
			break;
		}
	}
	 
	
	
	return 0;
}
