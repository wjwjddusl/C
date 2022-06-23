#include <iostream>
#include <vector>
using namespace std;

class Bank{
	string name, phone;
	int age, balance; //�ܾ� 
	int secret_num; //��й�ȣ 
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
	// ��,��� 
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
	
	// �������࿡ ȸ������ϰ� �� ��,����ϱ�
	vector<Bank> v; //vector �̿��ϱ�
	vector<Bank>::iterator it;
	
	char an; //ȸ����� ���� 
	string name, phone;
	int age, snum;//��й�ȣ 
	
	while(true){
		
		cout<<"ȸ������� �Ͻðڽ��ϱ�? (y/n) ";
		cin>>an;
		
		if(an=='y'){
			cout<<"<<������ �Է����ּ���>>"<<endl;
			cout<<"�̸�,����,�޴��� ��ȣ, ��й�ȣ�� �Է����ּ���: ";
			cin>>name>>age>>phone>>snum;
			v.push_back(Bank(name,age,phone,snum)); //�� �ֱ� 
			cout<<"����� �Ϸ�Ǿ����ϴ�."<<endl;
			
		}else if(an=='n'){
			break;
		}else{
			cout<<"�ٽ� �Է����ּ���>> ";
			continue;
		}
	} 
	cout<<"<<��ϵ� ȸ�� ���>>"<<endl;
	for(it = v.begin(); it != v.end(); it++){
		cout<<it->getName()<<endl;
	}
	
	int num, money; 
	while(true){
		cout<<"1.ȸ����ȸ 2.�Ա� 3.��� 4.�ܾ���ȸ (0.����) >>";
		cin>>num;
		
		cout<<"��й�ȣ�� �Է����ּ���>> ";
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
					cout<<"�Ա��� �ݾ��� �Է��ϼ���>>";
					cin>>money;
					v[i].AddMoney(money);
					break;
				}
			}
			
		}else if(num==3){
			for(int i=0; i<v.size(); i++){
				if(snum == v[i].getSnum()){
					cout<<"����� �ݾ��� �Է��ϼ���>>";
					cin>>money;
					
					if(money>v[i].getBalance()){
						cout<<"����� �Ұ����մϴ�"<<endl;
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
					cout<<"�ܾ�>> "<<v[i].getBalance()<<endl;
					break;
				}
			}
			
		}else{
			cout<<"�����մϴ�."<<endl;
			break;
		}
	}
	
	return 0;
	
}
