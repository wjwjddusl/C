#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


class Person{
	string player;

public:
	static int top;
	static int bottom;

	void setPlayer(string player){
		this->player=player;

	}

	string getPlayer(){
		return player;
	}
 
	void run();

};

int Person::top=100; //���� ū�� 
int Person::bottom=0; //���� ������ 


void Person::run(){

	srand(time(NULL));
	int an = rand() %100; //0-99����

	
	Person player[2]; //�迭 ����
	
	//�Է¹ޱ�. 
	string p1,p2;
	
	cout<<"�÷��̾�1: ";
	cin>>p1;
	player[0].setPlayer(p1);
	 
	cout<<"�÷��̾�2: ";
	cin>>p2;
	player[1].setPlayer(p2);


	int myan;

	int i=0;  

	while(true){
		cout<<player[i].getPlayer()<<"> ";
		cin>>myan;

		if(an==myan){
			cout<<"����."<<player[i].getPlayer()<<"(��)�� �̰���ϴ�."<<endl;
			break;

		}else if(myan>an){
			Person::top=myan; 
			cout<<Person::bottom<<"�� "<<Person::top<<"���̿� �ֽ��ϴ�."<<endl;
			i=1; // �÷��̾� ��ȯ 

		}else if(myan<an){
			Person::bottom=myan;
			cout<<Person::bottom<<"�� "<<Person::top<<"���̿� �ֽ��ϴ�."<<endl;
			i=1; //�÷��̾� ��ȯ			

		}else if(myan>100){ //������ �������. 
			cout<<"100������ ���� �Է����ּ���."<<endl;
		}else if(myan<0){
			cout<<"0�̻��� ���� �Է����ּ���."<<endl;
		} 
			
	}		

}

int main(){

	//Up & Down ���� 
	Person p;
	p.run();

	return 0;

}
