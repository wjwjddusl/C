#include <iostream>

using namespace std;

class Bank{
private:
	string account; //����
	int pwd; //��й�ȣ 

public:
	int r_money=0; //�ܾ� 
	
	Bank(string account,int pwd){
		this->account=account;
		this->pwd = pwd;
	}
	int get_money(int put); //�Ա� 
	int exit_money(int out); //���
	int money(); //�ܾ���ȸ

};

int Bank::get_money(int put){ //�Ա� 

	if(account=="111-111-222" && pwd==1234){
		r_money=r_money+put; //�ܾ׿� �Է¹��� �� �ֱ� 
	}else{
		cout<<"���¹�ȣ, ��й�ȣ�� �ٸ��ϴ�."<<endl;
	}

}

int Bank::exit_money(int out){ //��� 
	if(account=="111-111-222" && pwd==1234){		
		if(out>r_money){ //����Ϸ��� �׼��� �ܾ׺��� ������ 
			cout<<"����Ҽ� ����"<<endl;
			r_money = r_money+out;
		}
		
		r_money=r_money-out; 
		 
	}else{
		cout<<"���¹�ȣ, ��й�ȣ�� �ٸ��ϴ�."<<endl;
	}
	
}

int Bank::money(){ //�ܾ� 
	return r_money;
}

int main(){

	Bank b("111-111-222",1234); //���� ��ȣ, ��й�ȣ (b��� ��ü) 

	int num,put,out; //��ȣ, �Է°�, ���Ⱚ  

	while(true){

		cout<<"��ȣ �Է� ";
		cout<<"(1.�Ա� 2.��� 3.�ܾ���ȸ 0. ����): ";
		cin>>num;

		if(num==1){
			cout<<"�Աݾ�: ";
			cin>>put;
			b.get_money(put);	
		}else if(num==2){
			cout<<"���: ";
			cin>>out;
			b.exit_money(out);
		}else if(num==3){
			cout<<"�ܾ���ȸ: "<<b.money()<<endl;; //�Է¹��� �ʿ� ���� 
			
		}else if(num==0){
			cout<<"����"<<endl;
			break;
		}

	}

}
