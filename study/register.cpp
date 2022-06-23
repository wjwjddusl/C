#include <iostream>
#include <vector>
using namespace std;

class Bank{
	string name, phone;
	int age, balance; //잔액 
	int secret_num; //비밀번호 
public:
	Bank(){
		balance = 0; 
	}
	Bank(string name, int age, string phone,int secret_num){
		this->name=name;
		this->age=age;
		this->phone=phone;
		this->secret_num=secret_num; 
	}
	string getName(){
		return name;
	}
	int getAge(){
		return age;
	}
	string getPhone(){
		return phone;
	}
	int getSnum(){
		return secret_num;
	} 
	// 입,출금 
	void AddMoney(int money){
		balance +=money;
	}
	void MinusMoney(int money){
		balance -=money;
	}
	int getBalance(){
		return balance;
	}
	
};

int main(){
	
	// 신한은행에 회원등록하고 돈 입,출금하기
	vector<Bank> v; //vector 이용하기
	vector<Bank>::iterator it;
	
	char an; //회원등록 여부 
	string name, phone;
	int age, snum;//비밀번호 
	
	while(true){
		
		cout<<"회원등록을 하시겠습니까? (y/n) ";
		cin>>an;
		
		if(an=='y'){
			cout<<"<<정보를 입력해주세요>>"<<endl;
			cout<<"이름,나이,휴대폰 번호, 비밀번호를 입력해주세요: ";
			cin>>name>>age>>phone>>snum;
			v.push_back(Bank(name,age,phone,snum)); //값 넣기 
			cout<<"등록이 완료되었습니다."<<endl;
			
		}else if(an=='n'){
			break;
		}else{
			cout<<"다시 입력해주세요>> ";
			continue;
		}
	} 
	cout<<"<<등록된 회원 목록>>"<<endl;
	for(it = v.begin(); it != v.end(); it++){
		cout<<it->getName()<<endl;
	}
	
	int num, money; 
	while(true){
		cout<<"1.회원조회 2.입금 3.출금 4.잔액조회 (0.종료) >>";
		cin>>num;
		
		cout<<"비밀번호를 입력해주세요>> ";
		cin>>snum;
		
		if(num==1){
			for(int i=0; i<v.size(); i++){
				if(snum == v[i].getSnum()){
					cout<<v[i].getName()<<", "<<v[i].getAge()<<", "<<v[i].getPhone()<<endl;
					break;
				}
			}
			
		}else if(num==2){
			for(int i=0; i<v.size(); i++){
				if(snum == v[i].getSnum()){
					cout<<"입금할 금액을 입력하세요>>";
					cin>>money;
					v[i].AddMoney(money);
					break;
				}
			}
			
		}else if(num==3){
			for(int i=0; i<v.size(); i++){
				if(snum == v[i].getSnum()){
					cout<<"출금할 금액을 입력하세요>>";
					cin>>money;
					
					if(money>v[i].getBalance()){
						cout<<"출금이 불가능합니다"<<endl;
						break;
					}else{
						v[i].MinusMoney(money);
						break;
					} 
					
				}
			}
			
		}else if(num==4){
			for(int i=0; i<v.size(); i++){
				if(snum == v[i].getSnum()){
					cout<<"잔액>> "<<v[i].getBalance()<<endl;
					break;
				}
			}
			
		}else{
			cout<<"종료합니다."<<endl;
			break;
		}
	}
	
	return 0;
	
}
