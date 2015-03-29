#ifndef CLIENT_H
#define CLIENT_H
#include <cstring>


class Client
{
private:
	char* firstName; // ��� �� �������
	char* lastName; // ������� �� �������
	double money; // ���� �� �������
	double * product , * quantity , * price; // ������� �� �������
	int number; // ������� �� �������
public:
	Client(char* name, char* last_name , double _money) 
	{
		firstName = name;
		lastName = last_name;
	    money = _money;
		product = quantity = price = NULL;
		number = 0;
	}
	char* getFirstName() const{return firstName;}
	char* getLastName() const{return lastName;}
	double getClientMoney() const {return money;}
	double* getProduct() const {return product;} // ������ �� ���������� �� ���������
	double* getQuantity() const {return quantity;}
	double* getPrice() const {return price;}
	int getNumber() const {return number;} 

	void remove() // �������� ������� ��������
	{
		delete[] firstName;
		delete[] lastName;
	}

	void addToCart(Product& ); // �������� �� ������� � ��������� �� �������
	void pay(); // ������� �� ���������� 

};

Client newClient(); // ��������� �� ��� ������ �.�. ������ ����� � ��������


#endif