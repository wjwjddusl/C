#include <iostream>
#include <string>

using namespace std;

class Player { //플레이어 관리 
    string name;
    
public:
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    //이름을 전달 받고 이름 반환 
};

class WordGame {
	
    Player *p;  //player 클래스의 포인터 변수 p 선언 
    int num; //플레이어 수 
    
public:
    WordGame(int num){ //매개변수 생성자 안에서 포인터 변수  동적할당. 
    	p=new Player[num]; //이렇게하면 기본생성자 필요X 
		this->num = num;	
	}; 
    ~WordGame() { delete[] p; }
    void game(); //멤버 함수 선언 
};

void WordGame::game() {
	
    string an;
    for (int i = 0; i <num; ++i) {
        cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
        cin >> an;
        p[i].setName(an); //배열에 이름 저장 
    }
    cout << endl;
    cout << "시작하는 단어는 아버지입니다" << endl;
    string first = "아버지";
    string next;
    
    int i = 0;
    for (;;) {
        cout << p[i%num].getName() << ">>"; //예)  i=0, num=3 -- 0 / i=1, num=3 --1 / i=2, num=3 --2 / i=3 num=3 --0 이런식으로 반복. 
        cin >> next;
        int len = first.length();
        if (first.at(len - 2) == next.at(0) && first.at(len - 1) == next.at(1)) {
            first = next;
        }
        else {
            cout << p[i%num].getName() << " 탈락"<<endl;
            break;
        }
        i++;
    }
}
int main() {
    cout << "끝말 잇기 게임을 시작합니다" << endl;
    cout << "게임에 참가하는 인원은 몇명입니까?";
    
    int num;
    cin >> num;
    
    WordGame wordgame(num); //객체선언, 매개변수 전달 
    wordgame.game();
}
