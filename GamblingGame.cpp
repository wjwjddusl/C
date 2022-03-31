#include <iostream>
#include <cstdlib>
#include <ctime> //���� �� ���� 


using namespace std;

class Player{
	string name;

public:
	void setName(string name){
		this->name =name;
	}	

	string getName(){
		return name;
	}

};

class GamblingGame{
	string name;
	Player *p;
	
public:
	
	GamblingGame(){
		p= new Player[2];
	}
	~ GamblingGame(){
		delete []p;
	}
	void player_set();
	void run();
		
};

void GamblingGame::player_set(){
	
	cout<<"**** �׺� ������ �����մϴ�. ****"<<endl; 
	cout<<"ù��° ���� �̸�>> ";
	cin>>name;
	p[0].setName(name);
	cout<<"�ι�° ���� �̸�>> ";
	cin>>name;
	p[1].setName(name);
	cout<<endl;	
	
}

void GamblingGame::run(){

	string n; //���� 
	int start =0; //ù���� 
	
	while(true){
		
		srand(time(NULL)); //������ ����(�����Ҷ�����) 
		int r[3];
				
		if(start==0){
			cout<<p[0].getName()<<": "; 
			getline(cin,n); //���� �Է�
			cout<<endl;
			
			for(int i=0; i<3; i++){
				r[i]=rand()%3;
				cout<<r[i]<<"\t"; 
			}	 
			if(r[0]==r[1] && r[1]==r[2]){
				cout<<p[0].getName()<<"�� �¸�!!";
				break;
			}else{
				cout<<"�ƽ�����! "<<endl;
			}
			start=1;
			
		}else if(start==1){
			cout<<p[1].getName()<<": "<<endl;
			getline(cin,n); //���� �Է¹ޱ�
			
				for(int i=0; i<3; i++){
				r[i]=rand()%3;
				cout<<r[i]<<"\t"; 
			}	 
			if(r[0]==r[1] && r[1]==r[2]){
				cout<<p[1].getName()<<"�� �¸�!!"<<endl;
				break;
			}else{
				cout<<"�ƽ�����! "<<endl;
			}
			start=0;
		}
		
		
	}	
	
}

int main(){
	
	GamblingGame g;
	g.player_set();
	g.run();
	
	return 0;
}
