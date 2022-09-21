/*
物品交换系统
功能：1.添加物品 2.删除物品 3.显示物品 4.查找物品 0.退出
*/
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

#define MAX 1000//物品清单最大容量

//物品结构体
struct item {
	string name;//物品名称
	string owner;//物品主人
	string phone_num;//联系电话
};

//物品清单结构体
struct item_book {
	struct item items[MAX];//保存的物品
	int size;//当前物品数量
};

//显示菜单
void showMenu() {
	cout << "欢迎使用物品交换系统！以下是本系统的功能：" << endl;
	cout << "***************1.添加物品***************" << endl;
	cout << "***************2.删除物品***************" << endl;
	cout << "***************3.显示物品***************" << endl;
	cout << "***************4.查找物品***************" << endl;
	cout << "***************0. 退  出 ***************" << endl;
	cout << "请输入您的选择：" << endl;
}

//添加物品
void add_item(item_book* abs) {
	if (abs->size == MAX) {
		cout << "物品清单已达最大容量，请删除部分物品后，再继续添加。" << endl;
		return;
	}
	else {
		//添加物品名称
		string name;
		cout << "请输入物品名称：" << endl;
		cin >> name;		
		//添加物品主人
		string owner;
		cout << "请输入主人名称：" << endl;
		cin >> owner;		
		//添加联系方式
		string phone_num;
		cout << "请输入联系方式：" << endl;
		cin >> phone_num;
		
		//判断物品是否已经存在
		int flag = 0;
		for (int i = 0; i < abs->size; i++) {
			if ((abs->items[i].name == name) && (abs->items[i].owner) == owner) {
				flag = 1;
				cout << "物品已经存在，无需重复录入。" << endl;
				return;
				}
			}
		if (flag == 0) {
			//更新物品信息
			abs->items[abs->size].name = name;
			abs->items[abs->size].owner = owner;
			abs->items[abs->size].phone_num = phone_num;
			//更新物品数量
			abs->size++;

			cout << "添加完毕。" << endl;	
			}	
	}
}

//删除物品
void delete_item(item_book* abs) {
	if (abs->size == 0) {
		cout << "物品清单为空！不可再进行删除。" << endl;
	}
	else {
		string name, onwer;
		cout << "请输入要删除的物品：" << endl;
		cin >> name;
		cout << "请输入物品主人的名字：" << endl;
		cin >> onwer;

		//判断物品是否存在
		int flag = 0;
		for (int i = 0; i < abs->size; i++) {
			if ((abs->items[i].name == name) && (abs->items[i].owner)==onwer) {
				//从要删除的物品开始，后一位覆盖前一位
				//注意：此时items中最后一位并未被覆盖，但由于size-1，同样从功能上实现了删除
				flag = 1;
				for (int j = i; j < abs->size-1; j++) {
					abs->items[j] = abs->items[j + 1];
				}
				abs->size--;//更新物品数量
				cout << "删除完毕。" << endl;
				return;
			}
		
		}
		if (flag == 0) {
			cout << "抱歉！您想删除的物品不存在。" << endl;
		}
	}

}

//显示物品
void show_item(item_book *abs){
	//判断清单是否为空
	if (abs->size == 0) {
		cout << "物品清单为空！" << endl;
	}
	else {
		cout << setw(15)<<"物品名称" ;
		cout << setw(15)<< "主人名称";
		cout << setw(15)<<"联系方式" << endl;
		for (int i = 0; i < abs->size; i++) {
			cout<< setw(15)<< abs->items[i].name ;
			cout<< setw(15)<<abs->items[i].owner;
			cout<< setw(15)<<abs->items[i].phone_num << endl;
		}
	}
}

//查找物品
void find_item(item_book* abs) {
	string name;
	cout << "请输入您想要查找的物品名：" << endl;
	cin >> name;
	//判断物品是否存在
	int flag = 0;
	for (int i = 0; i < abs->size; i++) {
		if (abs->items[i].name == name) {
			if (flag == 0) {
				cout << setw(15) << "物品名称";
				cout << setw(15) << "主人名称";
				cout << setw(15) << "联系方式" << endl;
			}
			flag = 1;
			cout << setw(15) << abs->items[i].name;
			cout << setw(15) << abs->items[i].owner;
			cout << setw(15) << abs->items[i].phone_num << endl;
			}
		}
	if (flag == 0) {
		cout << "抱歉！您想查找的物品不存在。" << endl;
	}
}

//主程序
int main()
{
	item_book ib;//创建物品清单
	ib.size = 0;


	string select;
	while (true) {
		showMenu();//显示菜单
		cin >> select;
		if (select == "1") {//1.添加物品
			add_item(&ib);
			std::system("pause");
			std::system("cls");
		}
		else if (select == "2") {//2.删除物品
			delete_item(&ib);
			system("pause");
			system("cls");
		}
		else if (select == "3") {//3.显示物品
			show_item(&ib);
			system("pause");
			system("cls");
		}
		else if (select == "4") {//4.查找物品
			find_item(&ib);
			system("pause");
			system("cls");
		}
		else if (select == "0") {//0.退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			exit(0);
		}
		else {//输入错误
			cout << "抱歉，请输入0-4之间的阿拉伯数字。" << endl;
			system("pause");
			system("cls");
		}
	}
	
	system("pause");
	return 0;
}