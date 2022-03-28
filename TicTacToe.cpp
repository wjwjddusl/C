#include <iostream> 

using namespace std; 

char a[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
 //배열선언, 초기화 , 전역배열로 선언해줘야 win에서 사용가능. 
 //틀 제대로 잡아줘야함. a[3][3] ={' '} 하면 제대로 안돌아감.  

//게임판 
void board(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << "|" << a[i][j];  //표형식 출력
		} 
		cout<<endl; 
	} 
} 

//승패 결정 
bool win() 
{	//세로줄이 같을때 
	for (int i = 0; i < 3; i++) {
		if (a[i][0] != ' ' && a[i][0] == a[i][1] && a[i][1] == a[i][2]) {
			return true; 
		} 
	} 
	//가로줄이 같을때 
	for (int j = 0; j < 3; j++) {
		if (a[0][j] != ' ' && a[0][j] == a[1][j] && a[1][j] == a[2][j]) {
			return true; 
		} 
	} 
	//대각선이 같을때 
	if (a[0][0] != ' ' && a[0][0] == a[1][1] && a[1][1] == a[2][2]) {
		return true; 
	} 
	if (a[0][2] != ' ' && a[0][2] == a[1][1] && a[1][1] == a[2][0]) {
		return true; 
	} 
	
	return false; //어느곳에도 해당안되면 false 
}



int main(){

int x;
int y; 
int player=0; //플레이어 설정 
cout<<"Tic Tac Toe Game Start!"<<endl;
cout<<"======================="<<endl;
//board(); //게임판 출력 

for(int i=0; i<9; i++){ //9칸 동안 반복. 
	//cout<<"======================="<<endl; 
	cout<<"x,y 입력: ";
	cin >> x>>y; 
	
	if(player==0){ //플레이어0 일때. 
		a[x][y]='X'; //x와 y에 'O' 삽입. 
		player=1; //플레이어 전환 
		board(); //보드 출력. 
		if(win()==true){ //플레이어가 0일때 이기는 조건(win함수)가 true라면 플레이어0이 승. 
			cout<< "player0 승!"<<endl; 
			exit(1); //for반복문 빠져나가기. 
		} 
	}else{ //player1일때 
		a[x][y]='O'; 
		player=0; //플레이어 전환 
		board(); 
		if(win()==true){
			cout<< "player1 승!"<<endl; 
			exit(1); 
		} 
	} 
} 

cout<< "무승부입니다."<<endl;  //9칸을 다 채웠는데도 승패가 안나면 무승부. 

return 0; 

}




