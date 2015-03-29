#ifndef SHOP_H
#define SHOP_H

class Shop
{
    public:
        Shop(char* ="" , int = 0 );
        virtual ~Shop();

        void setName(char*);
        void receiveMoney(int);
        void addProduct(const Product&);//�������� �� ���� ��������� ��� �� ��� �������
        void getProduct(Product&)//������� �� ������� �� ������ �� �������� � ��������� ��� ��������� �� ������

        char* getName()const {return name;}
        double getMoney()const {return money;}


    private:
        char *name;//����� �� ��������
        int money;// ��������� � ����� �������� ���������
        int numberProducts;//����� �������� ����� � �������;
        int capacity;//������������ ���� �������� - ������ �� �� �� ���� ���� �� ���������� �������
        Product* products;
        void destroy();
        void resize();
        bool empty();
        bool isProductContainerFull();
};

#endif // SHOP_H
