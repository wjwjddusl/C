#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	//���� ���߱� ����
	//string list [] = {"bnana", "strobarry","melon","apple","orange"}; //�迭 ����
	
	int n;
	cout<<"��� �Է��Ͻðڽ��ϱ�? ";
	cin >>n;
	
	string *list = new string [n]; //���� �迭���� 
	
	cout<<"�ܾ� "<<n<<"���� �Է��ϼ���."<<endl;
	for (int i=0; i<n; i++){ //�迭 �Է¹ޱ� 
		cout<<i+1<<"��° �ܾ� �Է�: ";
		cin>>list[i]; 
	}
	
	srand(time(NULL)); //���ට���� ���� ����
	int r = rand()%n; 
	
	string str = list[r]; //str ���ڿ��� �������� ���� ���ڿ� �ֱ�
	string q(str.length(),'_'); //���� ���ڿ���ŭ _�� ä���, �ֵ���ǥ �ȵ�. 
	
	char ans; //���� �Է��� ��. 
	cout<<"=============================="<<endl;	
	cout<<"���ڿ� ����: "<<q<<endl;

	while(true){
		
		cout<<"�Է�: ";
		cin >> ans;
		
		for(int i=0; i<str.length(); i++){
			if(ans==str[i]){
				q[i] = ans; //������� ���� �Է��� �� ����. 
				cout<<q<<endl;
			}		
		
		}
		
		if(str==q){ //��ĭ�� �� ä������. 
			cout<<"����";
			break;
		}
	}
	 
	
	
	return 0;
}
