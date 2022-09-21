/*
��Ʒ����ϵͳ
���ܣ�1.�����Ʒ 2.ɾ����Ʒ 3.��ʾ��Ʒ 4.������Ʒ 0.�˳�
*/
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

#define MAX 1000//��Ʒ�嵥�������

//��Ʒ�ṹ��
struct item {
	string name;//��Ʒ����
	string owner;//��Ʒ����
	string phone_num;//��ϵ�绰
};

//��Ʒ�嵥�ṹ��
struct item_book {
	struct item items[MAX];//�������Ʒ
	int size;//��ǰ��Ʒ����
};

//��ʾ�˵�
void showMenu() {
	cout << "��ӭʹ����Ʒ����ϵͳ�������Ǳ�ϵͳ�Ĺ��ܣ�" << endl;
	cout << "***************1.�����Ʒ***************" << endl;
	cout << "***************2.ɾ����Ʒ***************" << endl;
	cout << "***************3.��ʾ��Ʒ***************" << endl;
	cout << "***************4.������Ʒ***************" << endl;
	cout << "***************0. ��  �� ***************" << endl;
	cout << "����������ѡ��" << endl;
}

//�����Ʒ
void add_item(item_book* abs) {
	if (abs->size == MAX) {
		cout << "��Ʒ�嵥�Ѵ������������ɾ��������Ʒ���ټ�����ӡ�" << endl;
		return;
	}
	else {
		//�����Ʒ����
		string name;
		cout << "��������Ʒ���ƣ�" << endl;
		cin >> name;		
		//�����Ʒ����
		string owner;
		cout << "�������������ƣ�" << endl;
		cin >> owner;		
		//�����ϵ��ʽ
		string phone_num;
		cout << "��������ϵ��ʽ��" << endl;
		cin >> phone_num;
		
		//�ж���Ʒ�Ƿ��Ѿ�����
		int flag = 0;
		for (int i = 0; i < abs->size; i++) {
			if ((abs->items[i].name == name) && (abs->items[i].owner) == owner) {
				flag = 1;
				cout << "��Ʒ�Ѿ����ڣ������ظ�¼�롣" << endl;
				return;
				}
			}
		if (flag == 0) {
			//������Ʒ��Ϣ
			abs->items[abs->size].name = name;
			abs->items[abs->size].owner = owner;
			abs->items[abs->size].phone_num = phone_num;
			//������Ʒ����
			abs->size++;

			cout << "�����ϡ�" << endl;	
			}	
	}
}

//ɾ����Ʒ
void delete_item(item_book* abs) {
	if (abs->size == 0) {
		cout << "��Ʒ�嵥Ϊ�գ������ٽ���ɾ����" << endl;
	}
	else {
		string name, onwer;
		cout << "������Ҫɾ������Ʒ��" << endl;
		cin >> name;
		cout << "��������Ʒ���˵����֣�" << endl;
		cin >> onwer;

		//�ж���Ʒ�Ƿ����
		int flag = 0;
		for (int i = 0; i < abs->size; i++) {
			if ((abs->items[i].name == name) && (abs->items[i].owner)==onwer) {
				//��Ҫɾ������Ʒ��ʼ����һλ����ǰһλ
				//ע�⣺��ʱitems�����һλ��δ�����ǣ�������size-1��ͬ���ӹ�����ʵ����ɾ��
				flag = 1;
				for (int j = i; j < abs->size-1; j++) {
					abs->items[j] = abs->items[j + 1];
				}
				abs->size--;//������Ʒ����
				cout << "ɾ����ϡ�" << endl;
				return;
			}
		
		}
		if (flag == 0) {
			cout << "��Ǹ������ɾ������Ʒ�����ڡ�" << endl;
		}
	}

}

//��ʾ��Ʒ
void show_item(item_book *abs){
	//�ж��嵥�Ƿ�Ϊ��
	if (abs->size == 0) {
		cout << "��Ʒ�嵥Ϊ�գ�" << endl;
	}
	else {
		cout << setw(15)<<"��Ʒ����" ;
		cout << setw(15)<< "��������";
		cout << setw(15)<<"��ϵ��ʽ" << endl;
		for (int i = 0; i < abs->size; i++) {
			cout<< setw(15)<< abs->items[i].name ;
			cout<< setw(15)<<abs->items[i].owner;
			cout<< setw(15)<<abs->items[i].phone_num << endl;
		}
	}
}

//������Ʒ
void find_item(item_book* abs) {
	string name;
	cout << "����������Ҫ���ҵ���Ʒ����" << endl;
	cin >> name;
	//�ж���Ʒ�Ƿ����
	int flag = 0;
	for (int i = 0; i < abs->size; i++) {
		if (abs->items[i].name == name) {
			if (flag == 0) {
				cout << setw(15) << "��Ʒ����";
				cout << setw(15) << "��������";
				cout << setw(15) << "��ϵ��ʽ" << endl;
			}
			flag = 1;
			cout << setw(15) << abs->items[i].name;
			cout << setw(15) << abs->items[i].owner;
			cout << setw(15) << abs->items[i].phone_num << endl;
			}
		}
	if (flag == 0) {
		cout << "��Ǹ��������ҵ���Ʒ�����ڡ�" << endl;
	}
}

//������
int main()
{
	item_book ib;//������Ʒ�嵥
	ib.size = 0;


	string select;
	while (true) {
		showMenu();//��ʾ�˵�
		cin >> select;
		if (select == "1") {//1.�����Ʒ
			add_item(&ib);
			std::system("pause");
			std::system("cls");
		}
		else if (select == "2") {//2.ɾ����Ʒ
			delete_item(&ib);
			system("pause");
			system("cls");
		}
		else if (select == "3") {//3.��ʾ��Ʒ
			show_item(&ib);
			system("pause");
			system("cls");
		}
		else if (select == "4") {//4.������Ʒ
			find_item(&ib);
			system("pause");
			system("cls");
		}
		else if (select == "0") {//0.�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
		}
		else {//�������
			cout << "��Ǹ��������0-4֮��İ��������֡�" << endl;
			system("pause");
			system("cls");
		}
	}
	
	system("pause");
	return 0;
}