#include <iostream>
#include <string.h>
#include <algorithm> //reverse�� ����ϱ� ���� �ʿ��� ��� ����. 

using namespace std;

int main(){
	
	
	while(true){
		
		string s;
		
		cout<<"<���� �Ųٷ� ����ϱ�>"<<endl; 
		cout<<endl;
		cout<<"���� �Է�: ";
		cin>>s;
		cout<<"�Է�: "<<s<<endl;
		
		string s_rever(s); //���ڿ� ����
		reverse(s_rever.begin(), s_rever.end()); //���ڿ� ������
		cout<<"���: "<<s_rever<<endl; 
		cout<<endl;
		
		if(s=="exit"){
			cout<<"�����մϴ�.";
			break;
		}
		
	}
	
	
	return 0;
}
