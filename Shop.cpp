#include "Shop.h"
#include<iostream>
#include<cstring>
#include "Product.h"
#include "client.h"

using namespace std;

int const DEFAULT_CAPACITY = 10;

Shop::Shop(char* _name ,int _money ):name(NULL), money(_money){
    setName(_name);
    numberProducts = 0;
    capacity = DEFAULT_CAPACITY;
    products = new Product[capacity];
    cout<<"Shop created ! \n";
}
Shop::empty(){
    return numberProducts == 0;
}
Shop::isProductContainerFull(){
    return numberProducts == capacity  - 1;
}
Shop::resize(){
    int oldCapacity = capacity;
    capacity +=10;
    Product* newProducts = new Product[capacity];
    for(int i = 0 ; i < oldCapacity ; i++){
        newProducts[i] = products[i];
    }
    delete[] products;
    products = newProducts;
}
Shop::receiveMoney(int _money){
    money +=_money;
}
Shop::addProduct(const Product &product){
    for(int i = 0 ; i < numberProducts ; i++){
        if(products[i].id == product.id){
            products[i].quantity+=product.quantity ; // �������� ����������� �� ������� ������� ��� ������ , ��� ���� ������� � ������ id  ��������� ���
            return;
        }
    }
    if(isProductContainerFull()){
        resize();
    }
    products[++numberProducts] = Product(product); // �������� �� �������� �� �������� ����� � ������ �� ������ ��������
}
Shop::~Shop()
{
    destroy();
    cout<<"Shop destroyed ! \n";
}
Shop::getProduct(Product &product){// ��� �������� �� ������� � ��������� �� ������� ������ �������� ��� getProduct == 1 ����� ������ � �����, � �������� ������ ������ ����� �������
    for(int i = 0 ; i < numberProducts ; i++){
        if(products[i].id == product.id){
            if(products[i].quantity >= product.quantity){//���� ��� ��� ���������� ����������
                products[i].quantity-=product.quantity//���������� �� �������� � ��������
                cout<<"��������� � �������� � ��������� \n";
            }
            else{
                cout<<"���� ������ ����������, �������� �� �������� ���������� ! \n";
                product.quantity = products[i].quantity; //���������� �� �������� � ��������� �� �������
                products[i].quantity = 0;
            }
            return 1;
        }
    }
    cout<<"� ������� ������ ����� �������, ���������� ! \n";
    return 0;
}
Shop::destroy(){
    if(name != NULL){
        delete[] name;
    }
    if(products !=NULL){
        delete[] products;
    }
}

Shop::setName(char *_name){
    if(name != NULL){
        delete[] name;
    }
    name = new char[strlen(_name) + 1];
    strcpy(name , _name);
}
