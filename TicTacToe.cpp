#include <iostream> 

using namespace std; 

char a[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
 //�迭����, �ʱ�ȭ , �����迭�� ��������� win���� ��밡��. 
 //Ʋ ����� ��������. a[3][3] ={' '} �ϸ� ����� �ȵ��ư�.  

//������ 
void board(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << "|" << a[i][j];  //ǥ���� ���
		} 
		cout<<endl; 
	} 
} 

//���� ���� 
bool win() 
{	//�������� ������ 
	for (int i = 0; i < 3; i++) {
		if (a[i][0] != ' ' && a[i][0] == a[i][1] && a[i][1] == a[i][2]) {
			return true; 
		} 
	} 
	//�������� ������ 
	for (int j = 0; j < 3; j++) {
		if (a[0][j] != ' ' && a[0][j] == a[1][j] && a[1][j] == a[2][j]) {
			return true; 
		} 
	} 
	//�밢���� ������ 
	if (a[0][0] != ' ' && a[0][0] == a[1][1] && a[1][1] == a[2][2]) {
		return true; 
	} 
	if (a[0][2] != ' ' && a[0][2] == a[1][1] && a[1][1] == a[2][0]) {
		return true; 
	} 
	
	return false; //��������� �ش�ȵǸ� false 
}



int main(){

int x;
int y; 
int player=0; //�÷��̾� ���� 
cout<<"Tic Tac Toe Game Start!"<<endl;
cout<<"======================="<<endl;
//board(); //������ ��� 

for(int i=0; i<9; i++){ //9ĭ ���� �ݺ�. 
	//cout<<"======================="<<endl; 
	cout<<"x,y �Է�: ";
	cin >> x>>y; 
	
	if(player==0){ //�÷��̾�0 �϶�. 
		a[x][y]='X'; //x�� y�� 'O' ����. 
		player=1; //�÷��̾� ��ȯ 
		board(); //���� ���. 
		if(win()==true){ //�÷��̾ 0�϶� �̱�� ����(win�Լ�)�� true��� �÷��̾�0�� ��. 
			cout<< "player0 ��!"<<endl; 
			exit(1); //for�ݺ��� ����������. 
		} 
	}else{ //player1�϶� 
		a[x][y]='O'; 
		player=0; //�÷��̾� ��ȯ 
		board(); 
		if(win()==true){
			cout<< "player1 ��!"<<endl; 
			exit(1); 
		} 
	} 
} 

cout<< "���º��Դϴ�."<<endl;  //9ĭ�� �� ä���µ��� ���а� �ȳ��� ���º�. 

return 0; 

}




