#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	
	map<string, int> m;
	cout<<"**** �������� ���α׷� HIGH SCORE�� �����մϴ�. ****"<<endl;
	
	int num, score;
	string name;
	
	while(true){
		cout<<"�Է�:1, ��ȸ:2, ����:3 >> ";
		cin>>num;
		if(num==1){
			cout<<"�̸��� ����>> ";
			cin>>name>>score;
			m[name]=score;
		}else if(num==2){
			cout<<"�̸� >> ";
			cin>>name;
			cout<<name<<"�� ������ "<<m[name]<<endl;;
			
		}else if(num==3){
			cout<<"�����մϴ�."<<endl;
			break;
		}
	}
	
	return 0;
	
}
