#include "Good.h"
using namespace std;
#include<fstream>
void coutgood(Goods a[], int n);
struct Account {
	char username[16];
	char key[16];
};

// 写入账户信息到二进制文件
void CountRead() {
	Account manager = { "经理", "12345" };
	Account salesman = { "销售", "w-2024.12.12" };

	ofstream ofs("Count.dat", ios::binary);
	if (!ofs.is_open()) {
		cout << "账户文件打开失败!" << endl;
		return;
	}
	ofs.write(reinterpret_cast<char*>(&manager), sizeof(Account));
	ofs.write(reinterpret_cast<char*>(&salesman), sizeof(Account));
	ofs.close();
}

// 从二进制文件中读取账户信息并验证
int CountWrite() {
	string user;
	string key;
	cout << "请输入账户和密码" << endl;

	while (true) {
		cout << "用户名: ";
		cin >> user;
		cout << "密码: ";
		cin >> key;

		ifstream ifs("Count.dat", ios::binary);
		if (!ifs.is_open()) {
			cout << "账户文件打开失败!" << endl;
			return -1; // Return an error code if the file cannot be opened
		}

		Account account;
		bool found = false;

		while (ifs.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
			if (user == account.username && key == account.key) {
				found = true;
				break;
			}
		}

		ifs.close();

		if (found) {
			if (user == "经理") {
				cout << "正确，进入经理账户" << endl;
				return 1;
			}
			else if (user == "销售") {
				cout << "正确，进入销售账户" << endl;
				return 2;
			}
		}
		else {
			cout << "用户名或密码有误,请重新输入." << endl;
		}
	}
}
int main() {
	CountRead();
	int n = CountWrite();
	//cout << "您的身份是1.经理     2.销售员" << endl;
	//int n; cin >> n;
	system("cls");
	switch (n) {
	case 1: {

		Manager_count m; int p = 1;
		while (1) {
			cout << "         ************************************************************************************************" << endl;
			cout << "         ************************************************************************************************" << endl;
			cout << "         *************                                                                      *************" << endl;
			cout << "         *************                        欢迎使用商品销售管理系统                      *************" << endl;
			cout << "         *************                        1.商品信息数据库创建                          *************" << endl;
			cout << "         *************                        2.商品信息查看                                *************" << endl;
			cout << "         *************                        3.商品信息保存                                *************" << endl;
			cout << "         *************                        4.商品信息添加                                *************" << endl;
			cout << "         *************                        5.商品信息进货                                *************" << endl;
			cout << "         *************                        6.商品信息删除                                *************" << endl;
			cout << "         *************                        7.商品信息修改                                *************" << endl;
			cout << "         *************                        8.利润统计与查询                              *************" << endl;
			cout << "         *************                        9.销售台账查询与输出                          *************" << endl;
			cout << "         *************                        10.排序                                       *************" << endl;
			cout << "         *************                        11.提醒补货                                   *************" << endl;
			cout << "         *************                        12.系统退出                                   *************" << endl;
			cout << "         *************                                                                      *************" << endl;
			cout << "         ************************************************************************************************" << endl;
			cout << "         ************************************************************************************************" << endl;
			string nn;
			cout << "                              请选择您需要的服务类型: ";
			cin >> nn;
			system("cls");
			if (nn == "1") { m.Creat_GoodsDataBase(); }
			else if (nn == "2") { coutgood(m.m_goods, m.all_amount); }
			else if (nn == "3") { m.Save(); }
			else if (nn == "4") { if (m.all_amount == 0) m.OutputInfo(), p--; else { m.ReAdd(); } }
			else if (nn == "5") { m.Replenish(); }
			else if (nn == "6") { m.DeleteGoods(); }
			else if (nn == "7") { m.InfoChange(); }
			else if (nn == "8") { m.ProfitStatistic(); }
			else if (nn == "9") { m.Inquire(); }
			else if (nn == "10") { m.sort(); }
			else if (nn == "11") { for (int i = 0; i < m.all_amount; i++) m.remind(m.m_goods[i]); }
			else if (nn == "12") { m.m_exit(); cout << "欢迎再次使用!"; exit(0); }
			else cout << "输入错误" << endl;
			system("pause");
			system("cls");
		}
		break;
	}
	case 2: {
		Salesperson mm;
		while (1) {
			cout << "         ************************************************************************************************" << endl;
			cout << "         ************************************************************************************************" << endl;
			cout << "         *************                                                                      *************" << endl;
			cout << "         *************          欢迎使用商品销售管理系统,请选择您需要的服务类型             *************" << endl;
			cout << "         *************                    1.打开商品数据库,开始销售                         *************" << endl;
			cout << "         *************                    2.销售统计                                        *************" << endl;
			cout << "         *************                    3.排序                                            *************" << endl;
			cout << "         *************                    4.商品信息查询                                    *************" << endl;
			cout << "         *************                    5.销售台账查询与输出                              *************" << endl;
			cout << "         *************                    6.系统退出                                        *************" << endl;
			cout << "         *************                                                                      *************" << endl;
			cout << "         ************************************************************************************************" << endl;
			cout << "         ************************************************************************************************" << endl;
			cout << "                              请选择您需要的服务类型: ";
			string nn; cin >> nn;
			system("cls");
			if (nn == "1") { mm.OpenFile(); mm.Sell(); }
			else if (nn == "2") { mm.SellStatistic(); }
			else if (nn == "3") { mm.SetBooks(); mm.sort(); }
			else if (nn == "4") { mm.SetBooks(); mm.FindInfo_good(); }
			else if (nn == "5") { mm.SetBooks(); mm.FindInfo_book(); }
			else if (nn == "6") { cout << "欢迎再次使用!"; exit(0); }
			else cout << "输入错误" << endl;
			system("pause");
			system("cls");
		}
		break;
	}
		  return 0;
	}
}