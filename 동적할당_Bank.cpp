//동적할당 은행 프로그램
#include <iostream>

using namespace std;

class Bank{

private:
	string account; //계좌
	int pwd; //비밀번호 

public:
	int r_money=0; //잔액 
	
	Bank(string account,int pwd){
		this->account=account;
		this->pwd = pwd;
	} 
	Bank(){} //동적 할당 사용시 기본생성자 필요 ** 
	string get_acc(); //계좌
	int get_pwd(); //비밀번호 
	int get_money(int put); //입금 
	int exit_money(int out); //출금
	int money(); //잔액조회

};


string Bank::get_acc(){
	return account; //매개변수로 받은 계좌 반환 ( 위에 this로 선언해줘서 따로 매개변수로 받을 필요x 
}

int Bank::get_pwd(){
	return pwd;  //매개변수로 받은 비밀번호 반환 
}

int Bank::get_money(int put){ //입금 
	r_money=r_money+put; //잔액에 입력받은 돈 넣기 
}

int Bank::exit_money(int out){ //출금 
			
	if(out>r_money){ //출금하려는 액수가 잔액보다 많을때 
		cout<<"출금할수 없음"<<endl;
		r_money = r_money+out;
	}	
	r_money=r_money-out; 
}

int Bank::money(){ //잔액 
	return r_money;
}


int main(){

	//Bank b("111-111-222",1234); //계좌 번호, 비밀번호 (b라는 객체) 
	//Bank b[3]={Bank("222-222-333",2345),Bank("333-333-444",4567),Bank("444-444-555",6789)}; //객체배열 b생성,초기화
	
	string account;
	int pwd;
	
	int n;
	cout<<"등록 계좌수: ";
	cin>>n;
	
	Bank *b=new Bank[n]; //동적할당 
	
	for(int i=0; i<n; i++){
		cout<<"계좌번호 입력: ";
		cin>> account;
		cout<<"비밀번호 입력: ";
		cin>> pwd;
		b[i]=Bank(account,pwd); //배열에 입력값 삽입. 
	}
	
	
	if(!b){
		cout<<"메모리를 할당할수 없습니다.";
		return 0; 
	}
	
	 
	int num,put,out; //번호, 입력값, 빼기값  
	
	string acc_put; //입력받은 게좌번호
	int pwd_put; //입력받은 비밀번호   
	
	cout<<"===== 로그인 ====="<<endl;
	cout<<"계좌번호: ";
	cin>>acc_put; 
	cout<<"비밀번호: ";
	cin>>pwd_put;
	
	 
	int i; //밖에서 i를 선언해주어 배열주소로 사용할수 있게함. 
	int start;
	
	
	for(i=0; i<n; i++){
		if(b[i].get_acc()==acc_put && b[i].get_pwd()==pwd_put){
			//일치하는 경우 
			start=0; 
			break;
		}else{ 
		//일치하지 않은 경우 
			start=1;
		}
	}
	
	if(start==1){
		cout <<"계좌번호,비밀번호가 틀립니다."<<endl;	
		return 1; //틀릴경우 아예 종료. 
	}

	
	while(true){
				
		cout<<"번호 입력 ";
		cout<<"(1.입금 2.출금 3.잔액조회 0. 종료): ";
		cin>>num;

		if(num==1){
			cout<<"입금액: ";
			cin>>put;
			b[i].get_money(put);	
		}else if(num==2){
			cout<<"출금: ";
			cin>>out;
			b[i].exit_money(out);
		}else if(num==3){
			cout<<"잔액조회: "<<b[i].money()<<endl;; //입력받을 필요 없음 
			
		}else if(num==0){
			cout<<"감사합니다."<<endl;
			break;
		}

	} //while문 종료 
	
	delete [] b;
	
	return 0;	
	
}
