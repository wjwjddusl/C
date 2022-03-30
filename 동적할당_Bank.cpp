//�����Ҵ� ���� ���α׷�
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
	Bank(){} //���� �Ҵ� ���� �⺻������ �ʿ� ** 
	string get_acc(); //����
	int get_pwd(); //��й�ȣ 
	int get_money(int put); //�Ա� 
	int exit_money(int out); //���
	int money(); //�ܾ���ȸ

};


string Bank::get_acc(){
	return account; //�Ű������� ���� ���� ��ȯ ( ���� this�� �������༭ ���� �Ű������� ���� �ʿ�x 
}

int Bank::get_pwd(){
	return pwd;  //�Ű������� ���� ��й�ȣ ��ȯ 
}

int Bank::get_money(int put){ //�Ա� 
	r_money=r_money+put; //�ܾ׿� �Է¹��� �� �ֱ� 
}

int Bank::exit_money(int out){ //��� 
			
	if(out>r_money){ //����Ϸ��� �׼��� �ܾ׺��� ������ 
		cout<<"����Ҽ� ����"<<endl;
		r_money = r_money+out;
	}	
	r_money=r_money-out; 
}

int Bank::money(){ //�ܾ� 
	return r_money;
}


int main(){

	//Bank b("111-111-222",1234); //���� ��ȣ, ��й�ȣ (b��� ��ü) 
	//Bank b[3]={Bank("222-222-333",2345),Bank("333-333-444",4567),Bank("444-444-555",6789)}; //��ü�迭 b����,�ʱ�ȭ
	
	string account;
	int pwd;
	
	int n;
	cout<<"��� ���¼�: ";
	cin>>n;
	
	Bank *b=new Bank[n]; //�����Ҵ� 
	
	for(int i=0; i<n; i++){
		cout<<"���¹�ȣ �Է�: ";
		cin>> account;
		cout<<"��й�ȣ �Է�: ";
		cin>> pwd;
		b[i]=Bank(account,pwd); //�迭�� �Է°� ����. 
	}
	
	
	if(!b){
		cout<<"�޸𸮸� �Ҵ��Ҽ� �����ϴ�.";
		return 0; 
	}
	
	 
	int num,put,out; //��ȣ, �Է°�, ���Ⱚ  
	
	string acc_put; //�Է¹��� ���¹�ȣ
	int pwd_put; //�Է¹��� ��й�ȣ   
	
	cout<<"===== �α��� ====="<<endl;
	cout<<"���¹�ȣ: ";
	cin>>acc_put; 
	cout<<"��й�ȣ: ";
	cin>>pwd_put;
	
	 
	int i; //�ۿ��� i�� �������־� �迭�ּҷ� ����Ҽ� �ְ���. 
	int start;
	
	
	for(i=0; i<n; i++){
		if(b[i].get_acc()==acc_put && b[i].get_pwd()==pwd_put){
			//��ġ�ϴ� ��� 
			start=0; 
			break;
		}else{ 
		//��ġ���� ���� ��� 
			start=1;
		}
	}
	
	if(start==1){
		cout <<"���¹�ȣ,��й�ȣ�� Ʋ���ϴ�."<<endl;	
		return 1; //Ʋ����� �ƿ� ����. 
	}

	
	while(true){
				
		cout<<"��ȣ �Է� ";
		cout<<"(1.�Ա� 2.��� 3.�ܾ���ȸ 0. ����): ";
		cin>>num;

		if(num==1){
			cout<<"�Աݾ�: ";
			cin>>put;
			b[i].get_money(put);	
		}else if(num==2){
			cout<<"���: ";
			cin>>out;
			b[i].exit_money(out);
		}else if(num==3){
			cout<<"�ܾ���ȸ: "<<b[i].money()<<endl;; //�Է¹��� �ʿ� ���� 
			
		}else if(num==0){
			cout<<"�����մϴ�."<<endl;
			break;
		}

	} //while�� ���� 
	
	delete [] b;
	
	return 0;	
	
}
