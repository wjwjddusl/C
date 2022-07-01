#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	
	map<string, int> m;
	cout<<"**** 점수관리 프로그램 HIGH SCORE를 시작합니다. ****"<<endl;
	
	int num, score;
	string name;
	
	while(true){
		cout<<"입력:1, 조회:2, 종료:3 >> ";
		cin>>num;
		if(num==1){
			cout<<"이름과 점수>> ";
			cin>>name>>score;
			m[name]=score;
		}else if(num==2){
			cout<<"이름 >> ";
			cin>>name;
			cout<<name<<"의 점수는 "<<m[name]<<endl;;
			
		}else if(num==3){
			cout<<"종료합니다."<<endl;
			break;
		}
	}
	
	return 0;
	
}
