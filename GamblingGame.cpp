#include <iostream>
#include <cstdlib>
#include <ctime> //랜덤 수 생성 


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
	
	cout<<"**** 겜블링 게임을 시작합니다. ****"<<endl; 
	cout<<"첫번째 선수 이름>> ";
	cin>>name;
	p[0].setName(name);
	cout<<"두번째 선수 이름>> ";
	cin>>name;
	p[1].setName(name);
	cout<<endl;	
	
}

void GamblingGame::run(){

	string n; //엔터 
	int start =0; //첫시작 
	
	while(true){
		
		srand(time(NULL)); //랜덤값 생성(실행할때마다) 
		int r[3];
				
		if(start==0){
			cout<<p[0].getName()<<": "; 
			getline(cin,n); //엔터 입력
			cout<<endl;
			
			for(int i=0; i<3; i++){
				r[i]=rand()%3;
				cout<<r[i]<<"\t"; 
			}	 
			if(r[0]==r[1] && r[1]==r[2]){
				cout<<p[0].getName()<<"님 승리!!";
				break;
			}else{
				cout<<"아쉽군요! "<<endl;
			}
			start=1;
			
		}else if(start==1){
			cout<<p[1].getName()<<": "<<endl;
			getline(cin,n); //엔터 입력받기
			
				for(int i=0; i<3; i++){
				r[i]=rand()%3;
				cout<<r[i]<<"\t"; 
			}	 
			if(r[0]==r[1] && r[1]==r[2]){
				cout<<p[1].getName()<<"님 승리!!"<<endl;
				break;
			}else{
				cout<<"아쉽군요! "<<endl;
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
