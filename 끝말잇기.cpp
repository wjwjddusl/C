#include <iostream>
#include <string>

using namespace std;

class Player { //�÷��̾� ���� 
    string name;
    
public:
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    //�̸��� ���� �ް� �̸� ��ȯ 
};

class WordGame {
	
    Player *p;  //player Ŭ������ ������ ���� p ���� 
    int num; //�÷��̾� �� 
    
public:
    WordGame(int num){ //�Ű����� ������ �ȿ��� ������ ����  �����Ҵ�. 
    	p=new Player[num]; //�̷����ϸ� �⺻������ �ʿ�X 
		this->num = num;	
	}; 
    ~WordGame() { delete[] p; }
    void game(); //��� �Լ� ���� 
};

void WordGame::game() {
	
    string an;
    for (int i = 0; i <num; ++i) {
        cout << "�������� �̸��� �Է��ϼ���. ��ĭ ����>>";
        cin >> an;
        p[i].setName(an); //�迭�� �̸� ���� 
    }
    cout << endl;
    cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�" << endl;
    string first = "�ƹ���";
    string next;
    
    int i = 0;
    for (;;) {
        cout << p[i%num].getName() << ">>"; //��)  i=0, num=3 -- 0 / i=1, num=3 --1 / i=2, num=3 --2 / i=3 num=3 --0 �̷������� �ݺ�. 
        cin >> next;
        int len = first.length();
        if (first.at(len - 2) == next.at(0) && first.at(len - 1) == next.at(1)) {
            first = next;
        }
        else {
            cout << p[i%num].getName() << " Ż��"<<endl;
            break;
        }
        i++;
    }
}
int main() {
    cout << "���� �ձ� ������ �����մϴ�" << endl;
    cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�?";
    
    int num;
    cin >> num;
    
    WordGame wordgame(num); //��ü����, �Ű����� ���� 
    wordgame.game();
}
