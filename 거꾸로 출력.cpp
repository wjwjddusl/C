#include <iostream>
#include <string.h>
#include <algorithm> //reverse를 사용하기 위해 필요한 헤더 파일. 

using namespace std;

int main(){
	
	
	while(true){
		
		string s;
		
		cout<<"<문자 거꾸로 출력하기>"<<endl; 
		cout<<endl;
		cout<<"문자 입력: ";
		cin>>s;
		cout<<"입력: "<<s<<endl;
		
		string s_rever(s); //문자열 복사
		reverse(s_rever.begin(), s_rever.end()); //문자열 뒤집기
		cout<<"출력: "<<s_rever<<endl; 
		cout<<endl;
		
		if(s=="exit"){
			cout<<"종료합니다.";
			break;
		}
		
	}
	
	
	return 0;
}
