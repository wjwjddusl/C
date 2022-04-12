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

int Person::top=100; //제일 큰값 
int Person::bottom=0; //제일 작은값 


void Person::run(){

	srand(time(NULL));
	int an = rand() %100; //0-99사이

	
	Person player[2]; //배열 생성
	
	//입력받기. 
	string p1,p2;
	
	cout<<"플레이어1: ";
	cin>>p1;
	player[0].setPlayer(p1);
	 
	cout<<"플레이어2: ";
	cin>>p2;
	player[1].setPlayer(p2);


	int myan;

	int i=0;  

	while(true){
		cout<<player[i].getPlayer()<<"> ";
		cin>>myan;

		if(an==myan){
			cout<<"정답."<<player[i].getPlayer()<<"(이)가 이겼습니다."<<endl;
			break;

		}else if(myan>an){
			Person::top=myan; 
			cout<<Person::bottom<<"과 "<<Person::top<<"사이에 있습니다."<<endl;
			i=1; // 플레이어 전환 

		}else if(myan<an){
			Person::bottom=myan;
			cout<<Person::bottom<<"과 "<<Person::top<<"사이에 있습니다."<<endl;
			i=1; //플레이어 전환			

		}else if(myan>100){ //범위를 벗어났을때. 
			cout<<"100이하의 수를 입력해주세요."<<endl;
		}else if(myan<0){
			cout<<"0이상의 수를 입력해주세요."<<endl;
		} 
			
	}		

}

int main(){

	//Up & Down 게임 
	Person p;
	p.run();

	return 0;

}
