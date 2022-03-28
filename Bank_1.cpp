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
	int get_money(int put); //입금 
	int exit_money(int out); //출금
	int money(); //잔액조회

};

int Bank::get_money(int put){ //입금 

	if(account=="111-111-222" && pwd==1234){
		r_money=r_money+put; //잔액에 입력받은 돈 넣기 
	}else{
		cout<<"계좌번호, 비밀번호가 다릅니다."<<endl;
	}

}

int Bank::exit_money(int out){ //출금 
	if(account=="111-111-222" && pwd==1234){		
		if(out>r_money){ //출금하려는 액수가 잔액보다 많을때 
			cout<<"출금할수 없음"<<endl;
			r_money = r_money+out;
		}
		
		r_money=r_money-out; 
		 
	}else{
		cout<<"계좌번호, 비밀번호가 다릅니다."<<endl;
	}
	
}

int Bank::money(){ //잔액 
	return r_money;
}

int main(){

	Bank b("111-111-222",1234); //계좌 번호, 비밀번호 (b라는 객체) 

	int num,put,out; //번호, 입력값, 빼기값  

	while(true){

		cout<<"번호 입력 ";
		cout<<"(1.입금 2.출금 3.잔액조회 0. 종료): ";
		cin>>num;

		if(num==1){
			cout<<"입금액: ";
			cin>>put;
			b.get_money(put);	
		}else if(num==2){
			cout<<"출금: ";
			cin>>out;
			b.exit_money(out);
		}else if(num==3){
			cout<<"잔액조회: "<<b.money()<<endl;; //입력받을 필요 없음 
			
		}else if(num==0){
			cout<<"종료"<<endl;
			break;
		}

	}

}
