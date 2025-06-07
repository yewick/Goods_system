#include "Good.h"
void coutgood(Goods a[], int n);
void coutbook(Goods a[], int n);
tm Time() {
	time_t t = time(0);
	tm p;
	localtime_s(&p, &t);
	p.tm_year += 1900;
	p.tm_mon++;
	return p;
}

Goods::Goods()
{
	g_name = "0";
	kind = "0";
	inprice = 0;
	cost = 0;
	sellprice = 0;
	amount = 0;
	all_sell_amount = 0;
	intime.tm_year = 1970; intime.tm_mon = 1;	intime.tm_mday = 1;
	sell_time.tm_year = 1970; sell_time.tm_mon = 1;	sell_time.tm_mday = 1;
	sell_amount = 0;
	code = 10000;
}
Goods::Goods(const Goods& p)
{
	g_name = p.g_name;
	kind = p.kind;
	inprice = p.inprice;
	cost = p.cost;
	sellprice = p.sellprice;
	amount = p.amount;
	intime = p.intime;
	all_sell_amount = p.all_sell_amount;
	sell_time = p.sell_time;
	sell_amount = p.sell_amount;
	code = p.code;
	Situation = p.Situation;
}

int Manager_count::getIntegerInput() {
	int input;
	while (true) 
	{
		//cout << "请输入一个整数: ";
		cin >> input;

		if (cin.fail()) {
			// 清除错误状态
			cin.clear();
			// 忽略剩余的输入
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入无效，请输入一个整数。" << endl;
		}
		else {
			// 清除输入缓冲区
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}

double Manager_count::getDoubleInput ()
{
	double input;
	while (true) {
		//std::cout << "请输入一个浮点数: ";
		cin >> input;

		if (cin.fail()) {
			// 清除错误状态
			cin.clear();
			// 忽略剩余的输入
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入无效，请输入一个浮点数。" << endl;
		}
		else {
			// 清除输入缓冲区
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}


void Manager_count::Creat_GoodsDataBase()
{
	ifstream Data_Base("Goods.txt", ios::in | ios::out);
	if (Data_Base.is_open())
	{
		cout << "数据库已创建!" << endl;
	}
	char Dstr[200] = { 0 };
	//int m_Num;
	//Data_Base.getline(Dstr, sizeof(char));
	int C_i = 0;
	Data_Base >> Dstr;
	//cout << Dstr << ' ';
	//while (C_i != 5)
	//{
	//	Data_Base >> Dstr;
	//	//cout<<Dstr<<' ';
	//	C_i++;
	//}

	Data_Base >> all_amount;
	//cout << all_amount << endl;
	C_i = 0;
	while (C_i != 9)
	{
		Data_Base >> Dstr;
		//cout << Dstr << ' ';
		C_i++;
	}
	//cout << endl;
	char Dch;
	for (int i = 0; i < all_amount; i++)
	{
		Data_Base /*>> setw(12) */ >> m_goods[i].code;
		Data_Base/* >> setw(12)*/ >> m_goods[i].g_name;
		Data_Base/* >> setw(12)*/ >> m_goods[i].kind;
		Data_Base/* >> setw(12)*/ >> m_goods[i].inprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].cost;
		Data_Base/* >> setw(12)*/ >> m_goods[i].sellprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].all_sell_amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].intime.tm_year >> Dch >> m_goods[i].intime.tm_mon >> Dch >> m_goods[i].intime.tm_mday;

		//cout << m_goods[i].code << ' '
		//	<< m_goods[i].g_name << ' '
		//	<< m_goods[i].kind << ' '
		//	<< m_goods[i].inprice << ' '
		//	<< m_goods[i].cost << ' '
		//	<< m_goods[i].sellprice << ' '
		//	<< m_goods[i].amount << ' '
		//	<< m_goods[i].all_sell_amount
		//	<< " Time: " << m_goods[i].intime.tm_year << '.' << m_goods[i].intime.tm_mon << '.' << m_goods[i].intime.tm_wday << endl;
		//	
		remind(m_goods[i]);
	}
	Data_Base.close();

	fstream fs;
	fs.open("Book.txt", ios::in);
	fs >> bs_record; string str; char ch;
	for (int i = 0; i < 5; i++)
		fs >> str;
	for (int i = 0; i < bs_record; i++) {
		fs >> m_books[i].code
			>> m_books[i].g_name
			>> m_books[i].sellprice
			>> m_books[i].sell_amount
			>> m_books[i].sell_time.tm_year >> ch
			>> m_books[i].sell_time.tm_mon >> ch
			>> m_books[i].sell_time.tm_mday >> ch
			>> m_books[i].sell_time.tm_hour >> ch
			>> m_books[i].sell_time.tm_min;
	}
	fs.close();
	//coutgood(m_goods, all_amount);
}

void Manager_count::OutputInfo()
{
	cout << "请输入想添加的商品数目: ";
	int size;
	bool op1 = 1;
	//cin >> size;
	size=getIntegerInput();
	while (op1)
	{
		if (size <= 100 && size > 0)
		{
			all_amount += size;
			op1 = 0;
			for (int i = 0; i < all_amount; i++)
			{
				cout << "商品编码: " << endl;
				//cin >> m_goods[i].code;
				m_goods[i].code = getIntegerInput();
				cout << "商品名称: ";
				cin >> m_goods[i].g_name;
				cout << "种类: ";
				cin >> m_goods[i].kind;
				cout << "进价: ";
				//cin >> m_goods[i].inprice;
				m_goods[i].inprice = getDoubleInput();
				m_goods[i].cost = m_goods[i].inprice * 1.02;
				cout << "售价: ";
				//cin >> m_goods[i].sellprice;
				m_goods[i].sellprice = getDoubleInput();
				cout << "数量: ";
				//cin >> m_goods[i].amount;
				m_goods[i].amount = getIntegerInput();
				cout << "进价日期(年): ";
				//cin >> m_goods[i].intime.tm_year;
				m_goods[i].intime.tm_year = getIntegerInput();
				cout << "进价日期(月): ";
				//cin >> m_goods[i].intime.tm_mon;
				m_goods[i].intime.tm_mon = getIntegerInput();
				cout << "进价日期(日): ";
				m_goods[i].intime.tm_mday = getIntegerInput();
				//cin >> m_goods[i].intime.tm_wday;
			}
		}
		else if (size > 100 || size <= 0)
		{
			cout << "非法增量，请重新输入: ";
			size = getIntegerInput();
		}
	}
	//this->Save();
}

Goods Manager_count::InputInfo()
{
	cout << "Choose the goods you need" << endl;
	int pre_code;
	cout << "The code of the goods: ";
	cin >> pre_code;
	int pre = Find(pre_code);
	if (pre == -1)
	{
		cout << "The goods doesn't exist!" << endl;
		return Goods();
	}
	else
	{
		cout << "Name: " << m_goods[pre].g_name << endl;
		cout << "Sellprice: " << m_goods[pre].sellprice << endl;
		cout << "Amount: " << m_goods[pre].amount << endl;
		return m_goods[pre];
	}
}

void Manager_count::ReAdd()
{
	int size1=0;
	cout << "请输入想继续添加的商品数目:";
	//cin >> size1;
	size1 = getIntegerInput();

	bool Rop = 1;
	while (Rop)
	{
		if (size1 <= 100 - all_amount && size1 > 0)
		{
			all_amount += size1;
			Rop = 0;
			for (int i = all_amount-size1; i < all_amount; i++)
			{
				cout << "商品编码: " << endl;
				//cin >> m_goods[i].code;
				m_goods[i].code = getIntegerInput();
				cout << "商品名称: ";
				cin >> m_goods[i].g_name;
				cout << "种类: ";
				cin >> m_goods[i].kind;
				cout << "进价: ";
				//cin >> m_goods[i].inprice;
				m_goods[i].inprice = getDoubleInput();
				m_goods[i].cost = m_goods[i].inprice * 1.02;
				cout << "售价: ";
				//cin >> m_goods[i].sellprice;
				m_goods[i].sellprice = getDoubleInput();
				cout << "数量: ";
				//cin >> m_goods[i].amount;
				m_goods[i].amount = getIntegerInput();
				cout << "进价日期(年): ";
				//cin >> m_goods[i].intime.tm_year;
				m_goods[i].intime.tm_year = getIntegerInput();
				cout << "进价日期(月): ";
				//cin >> m_goods[i].intime.tm_mon;
				m_goods[i].intime.tm_mon = getIntegerInput();
				cout << "进价日期(日): ";
				m_goods[i].intime.tm_mday = getIntegerInput();
				//cin >> m_goods[i].intime.tm_wday;
			}
		}
		else if (size1 > 100 - all_amount || size1 <= 0)
		{
			cout << "非法增量，请重新输入: ";
			//cin >> size1;
			size1 = getIntegerInput();
		}
	}
	/*for (int i = all_amount - size1; i < all_amount; i++)
	{
		m_goods[i].code = i + 10001;
		cout << "code: " << m_goods[i].code << endl;
		cout << "name: ";
		cin >> m_goods[i].g_name;
		cout << "kind: ";
		cin >> m_goods[i].kind;
		cout << "inprice: ";
		cin >> m_goods[i].inprice;
		m_goods[i].cost = m_goods[i].inprice * 1.02;
		cout << "sellprice: ";
		cin >> m_goods[i].sellprice;
		cout << "amount: ";
		cin >> m_goods[i].amount;
		cout << "intime.year: ";
		cin >> m_goods[i].intime.tm_year;
		cout << "intime.month: ";
		cin >> m_goods[i].intime.tm_mon;
		cout << "intime.day: ";
		cin >> m_goods[i].intime.tm_wday;
	}*/
	//this->Save();
}

void Manager_count::Replenish()
{
	int size2;
	cout << "请输入需要补货的商品数: ";
	size2 = getIntegerInput();
	int replenishamount;
	int* replenishCode = new int[size2];
	bool rp_s = 1;
	for (int i = 0; i < size2; i++)
	{
		cout << "输入需补货商品的编码: ";
		replenishCode[i] = getIntegerInput();
		int rp = Find(replenishCode[i]);
		if (rp == -1)
		{
			cout << "该编码商品不存在!" << endl;
			return;
		}
		else
		{
			for (int j = 0; j < size2; j++)
			{
				if (j != i && replenishCode[i] == replenishCode[j])
				{
					cout << "重复补货!" << endl;
					rp_s = 0;
				}
			}
			if (rp_s == 0)
				continue;
			else
			{
				cout << "商品: " << m_goods[rp].g_name << " 现有 " << m_goods[rp].amount << endl;
				cout << "输入补货数量: ";
				replenishamount = getIntegerInput();
				bool rp_state = 1;
				while (rp_state)
				{
					if (replenishamount > 0)
					{
						rp_state = 0;
						m_goods[rp].amount += replenishamount;
						this->Save();
					}
					else
					{
						cout << "非法操作!" << endl;
						cout << "请重新输入补货数量: ";
						replenishamount = getIntegerInput();
					}
				}
			}
		}
	}
	delete[] replenishCode;
}

int Manager_count::Find(int code)
{
	int m_index = -1;
	//cout << "alam" << all_amount << endl;
	for (int i = 0; i < all_amount; i++)
	{
		if (m_goods[i].code == code)
		{
			m_index = i;
			break;
		}
	}
	return m_index;
}

void Manager_count::Save()
{
	ofstream ofs("Goods.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "Goods.txt打开失败!" << endl;
		return;
	}
	ofs << "商品总数:  " << all_amount << endl;
	ofs << left << setw(12) << "商品编码";
	ofs << left << setw(12) << "商品名称";
	ofs << left << setw(12) << "种类";
	ofs << left << setw(12) << "进价";
	ofs << left << setw(12) << "成本";
	ofs << left << setw(12) << "售价";
	ofs << left << setw(12) << "数量";
	ofs << left << setw(12) << "销售总数";
	ofs << left << setw(12) << "进货时间" << endl;
	for (int i = 0; i < all_amount; i++)
	{
		ofs << left << setw(12) << m_goods[i].code;
		ofs << left << setw(12) << m_goods[i].g_name;
		ofs << left << setw(12) << m_goods[i].kind;
		ofs << left << setw(12) << m_goods[i].inprice;
		ofs << left << setw(12) << m_goods[i].cost;
		ofs << left << setw(12) << m_goods[i].sellprice;
		ofs << left << setw(12) << m_goods[i].amount;
		ofs << left << setw(12) << m_goods[i].all_sell_amount;
		ofs <</* left << setw(12) <<*/ m_goods[i].intime.tm_year << "." << m_goods[i].intime.tm_mon << "." << m_goods[i].intime.tm_mday << endl;
	}
	ofs.close();
	cout << "商品信息已保存" << endl;

}

Manager_count::~Manager_count()
{
	delete[]m_books;
	delete[]m_book;
	delete[]m_goods;
}

void Manager_count::DeleteGoods()
{
	int DelNum = 0;
	for (int i = 0; i < all_amount; i++)
	{
		if (m_goods[i].Situation == 0 && m_goods[i].amount == 0)
		{
			DelNum++;
			cout << "商品: " << m_goods[i].g_name << " 将被删除!" << endl;
			for (int j = i; j < all_amount - 1; j++)
			{
				//m_goods[j + 1].code = m_goods[j].code;
				m_goods[j] = m_goods[j + 1];
				
			}
		}
	}
	all_amount -= DelNum;
	//this->Save();
	cout << "删除完成!" << endl;
}

void Manager_count::InfoChange()
{
	int ic_code;
	cout << "输入需修改商品的编码: ";
	ic_code = getIntegerInput();
	int ic = Find(ic_code);
	if (ic == -1)
	{
		cout << "该商品不存在!" << endl;
		return;
	}
	else
	{
		cout << "商品名: " << m_goods[ic].g_name << endl;
		cout << "输入该商品的新售价: ";
		int newSellprice;
		bool ic_s = 1;
		newSellprice = getDoubleInput();
		while (ic_s)
		{
			if (newSellprice <= m_goods[ic].inprice || newSellprice <= m_goods[ic].cost)
			{
				cout << "警告:该新售价低于商品成本!" << endl;
				cout << "输入合适售价: ";
				newSellprice = getDoubleInput();
			}
			else if (newSellprice > m_goods[ic].cost)
			{
				ic_s = 0;
				cout << "商品原售价 : " << m_goods[ic].sellprice << endl;
				m_goods[ic].sellprice = newSellprice;
				cout << "商品 " << m_goods[ic].g_name << " 新售价为: " << m_goods[ic].sellprice << endl;
				this->Save();
			}
		}
	}
}

double Manager_count::ProfitCaculate()
{
	int p_code = 10001;
	int pc = 0;
	double profitsum = 0;
	for (int i = 0; i < all_amount; i++)
	{
		m_find(p_code + i, m_book, b_record);
		double nowprofit = 0;
		for (int j = 0; j < b_record; j++)
		{
			pc = Find(m_book[j].code);
			/*cout << m_goods[pc].code << endl;
			cout << "Sell: " << m_book[j].sellprice * m_book[j].sell_amount << endl;
			cout << "Cost: " << m_book[j].sell_amount * m_goods[pc].cost << endl;*/
			nowprofit += m_book[j].sellprice * m_book[j].sell_amount - (m_book[j].sell_amount) * m_goods[pc].cost;
			//cout << "NowProfit: " << nowprofit << endl;
		}
		profitsum += nowprofit;
		//cout << "SumProfit: " << profitsum << endl;
	}
	return profitsum;
}

void Manager_count::ProfitStatistic()
{
	double profit = 0;
	cout << "选择统计利润的方式" << endl;
	cout << "1:日利润 ; 2:商品利润 ; 3:总利润 ; 4:亏损情况 ;" << endl;
	/*int ps_i;
	ps_i = getIntegerInput();*/
	string ps_i;
	cin>>ps_i;
	int ps = 0;
	if (ps_i == "1")
	{
		double profit1 = 0;
		Inquire(ps_i);
		//cout << "b_record" << b_record << endl;
		for (int i = 0; i < b_record; i++)
		{
			//cout << m_book[i].code << endl;
			ps = Find(m_book[i].code);
			/*cout << m_goods[ps].code << endl;
			cout << "Sell: " << m_book[i].sellprice * m_book[i].sell_amount << endl;
			cout << "Cost: " << m_book[i].sell_amount * m_goods[ps].cost << endl;*/
			profit1 += m_book[i].sellprice * m_book[i].sell_amount - (m_book[i].sell_amount) * m_goods[ps].cost;
			//cout << "Profit1: " << profit1 << endl;
		}
		cout << "日利润: " << profit1 << endl;
	}
	else if (ps_i == "2")
	{
		double profit2 = 0;
		Inquire(ps_i);
		for (int i = 0; i < b_record; i++)
		{
			//cout << m_book[i].code << endl;
			ps = Find(m_book[i].code);
			/*cout << m_goods[ps].code << endl;
			cout << "Sell: " << m_book[i].sellprice * m_book[i].sell_amount << endl;
			cout << "Cost: " << m_book[i].sell_amount * m_goods[ps].cost << endl;*/
			profit2 += m_book[i].sellprice * m_book[i].sell_amount - (m_book[i].sell_amount) * m_goods[ps].cost;
			//cout << "Profit2: " << profit2 << endl;
		}
		cout << "商品 " << m_book[0].g_name << " 的利润为: " << profit2 << endl;
	}
	else if (ps_i ==  "3")
	{
		double profit3 = ProfitCaculate();
		cout << "总利润: " << profit3 << endl;
	}
	else if (ps_i == "4")
	{
		double profit4 = 0;
		int p_code = 10001;
		int pc = 0, ppc = 0;
		string pstr;
		for (int i = 0; i < all_amount; i++)
		{
			m_find(p_code + i, m_book, b_record);
			for (int j = 0; j < b_record; j++)
			{
				pc = Find(m_book[j].code);
				profit4 += m_book[j].sellprice * m_book[j].sell_amount - (m_book[j].sell_amount) * m_goods[ps].cost;
				if (profit4 < 0)
				{
					ppc++;
					cout << m_goods[pc].g_name << " 正在亏损!" << endl;
					cout << "选择是否继续进货: ";
					cin >> pstr;
					if (pstr.compare("否") == 0)
						m_goods[pc].Situation = 0;
					else if (pstr.compare("是") == 0)
						m_goods[pc].Situation = 1;
				}
			}
		}
		if (ppc == 0)
		{
			cout << "没有商品出现亏损情况! " << endl;
		}
	}
}

void Manager_count::Inquire(string n)
{
	while (1) {
		cout << "选择您的查询方式：" << endl;
		cout << "1.时间     2.商品     3.退出" << endl;
		string n;
		cin >> n;
		if (n == "1") {
			cout << "您要查询1.某日     2.某时段" << endl;
			string q; cin >> q;
			if (q == "1") {
				tm s; char ch;
				cout << "时间：（2024/7/3）" << endl;
				cin >> s.tm_year >> ch >> s.tm_mon >> ch >> s.tm_mday;
				m_find(s, m_book, b_record);
				break;
				//coutbook(m_book, b_record);
			}
			else if (q == "2") {
				tm s1, s2; char ch;
				cout << "起始时间：";
				cin >> s1.tm_year >> ch >> s1.tm_mon >> ch >> s1.tm_mday;
				cout << "终止时间：";
				cin >> s2.tm_year >> ch >> s2.tm_mon >> ch >> s2.tm_mday;
				m_find(s1, s2, m_book, b_record);
				break;
				//coutbook(m_book, b_record);
			}
			else cout << "输入错误" << endl;

		}
		else if (n == "2") {
			cout << "您要查询1.商品编号  2.商品名称" << endl;
			string s; cin >> s;
			if (s == "1") {
				cout << "输入商品编号: ";
				int a; cin >> a;
				m_find(a, m_book, b_record);
				break;
				//coutbook(m_book, b_record);
			}
			else if (s == "2") {
				cout << "输入商品名称: ";
				string a; cin >> a;
				m_find(a, m_book, b_record);
				break;
				//coutbook(m_book, b_record);
			}
			else cout << "输入错误" << endl;
		}
		else if (n == "3")break;
		else cout << "输入错误" << endl;
		system("pause");
		system("cls");
	}
}

      

void Manager_count::CreatGoodsDataBase(){
	ifstream Data_Base("Goods.txt", ios::in | ios::out);
	char Dstr[200] = { 0 };
	//int m_Num;
	//Data_Base.getline(Dstr, sizeof(char));
	int C_i = 0;
	//while (C_i != 5)
	//{
	//	Data_Base >> Dstr;
	//	//cout<<Dstr<<' ';
	//	C_i++;
	//}
	Data_Base >> Dstr;
	Data_Base >> all_amount;
	//cout << all_amount << endl;
	C_i = 0;
	while (C_i != 9)
	{
		Data_Base >> Dstr;
		//cout << Dstr << ' ';
		C_i++;
	}
	//cout << endl;
	char Dch;
	for (int i = 0; i < all_amount; i++)
	{
		Data_Base /*>> setw(12) */ >> m_goods[i].code;
		Data_Base/* >> setw(12)*/ >> m_goods[i].g_name;
		Data_Base/* >> setw(12)*/ >> m_goods[i].kind;
		Data_Base/* >> setw(12)*/ >> m_goods[i].inprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].cost;
		Data_Base/* >> setw(12)*/ >> m_goods[i].sellprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].all_sell_amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].intime.tm_year >> Dch >> m_goods[i].intime.tm_mon >> Dch >> m_goods[i].intime.tm_mday;

		/*cout << m_goods[i].code << ' '
			<< m_goods[i].g_name << ' '
			<< m_goods[i].kind << ' '
			<< m_goods[i].inprice << ' '
			<< m_goods[i].cost << ' '
			<< m_goods[i].sellprice << ' '
			<< m_goods[i].amount << ' '
			<< m_goods[i].all_sell_amount
			<< " Time: " << m_goods[i].intime.tm_year << '.' << m_goods[i].intime.tm_mon << '.' << m_goods[i].intime.tm_wday << endl;
			*/
		
	}
	Data_Base.close();
}
void Manager_count::Replenishone(int n) {
	tm a = Time();
	int code = Find(n);
	/*cout << m_goods[code].code << " "
		<< m_goods[code].g_name << ' '
		<< m_goods[code].kind << ' '
		<< m_goods[code].inprice << ' '
		<< m_goods[code].cost << ' '
		<< m_goods[code].sellprice << ' '
		<< m_goods[code].amount << ' '
		<< m_goods[code].intime.tm_year << '/' << m_goods[code].intime.tm_mon << "/" << m_goods[code].intime.tm_wday << endl;*/
	cout << "商品" << m_goods[code].g_name << " 现有 " << m_goods[code].amount << endl;
	cout << "输入进货数量:";
		int number; //cin >> number;
		number = getIntegerInput();
		m_goods[code].amount += number;
		m_goods[code].intime = a;
		if (m_goods[code].amount > 2)
			m_goods[code].Situation = 1;
}
void coutgood(Goods a[],int n) {


	cout << left << setw(12) << "编码";
	cout << left << setw(12) << "名称";
	cout << left << setw(12) << "种类";
	cout << left << setw(12) << "进价";
	cout << left << setw(12) << "成本";
	cout << left << setw(12) << "售价";
	cout << left << setw(12) << "数量";
	cout << left << setw(12) << "销售额";
	cout << left << setw(12) << "进货日期" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << left << setw(12) << a[i].code;
		cout << left << setw(12) << a[i].g_name;
		cout << left << setw(12) << a[i].kind;
		cout << left << setw(12) << a[i].inprice;
		cout << left << setw(12) << a[i].cost;
		cout << left << setw(12) << a[i].sellprice;
		cout << left << setw(12) << a[i].amount;
		cout << left << setw(12) << a[i].all_sell_amount;
		cout <</* left << setw(12) <<*/ a[i].intime.tm_year << "." << a[i].intime.tm_mon << "." << a[i].intime.tm_mday << endl;
	}
}
void coutbook(Goods a[], int n)  {

	cout << left << setw(12) << "编码";
	cout << left << setw(12) << "名称";
	cout << left << setw(12) << "售价";
	cout << left << setw(12) << "销售数量";
	cout << left << setw(12) << "销售时间" << endl;
	for (int i = 0; i < n; i++)
		/*cout << a[i].code << ' '
		<< a[i].g_name << ' '
		<< a[i].sellprice << ' '
		<< a[i].sell_amount << ' '
		<< a[i].sell_time.tm_year << '/'
		<< a[i].sell_time.tm_mon << '/'
		<< a[i].sell_time.tm_wday << '.'
		<< a[i].sell_time.tm_hour << ':'
		<< a[i].sell_time.tm_min << endl;*/
	{
		cout << left << setw(12) << a[i].code;
		cout << left << setw(12) << a[i].g_name;
		cout << left << setw(12) << a[i].sellprice;
		cout << left << setw(12) << a[i].sell_amount;
		cout << a[i].sell_time.tm_year << "." << a[i].sell_time.tm_mon << "." << a[i].sell_time.tm_mday << "," << a[i].sell_time.tm_hour << ":" << a[i].sell_time.tm_min << endl;
	}
} 
void Manager_count::Inquire() {
	while (1) {
		cout << "选择您的查询方式：" << endl;
		cout << "1.时间     2.商品     3.退出" << endl;
		string n;
		cin >> n;
		if (n == "1") {
			cout << "您要查询1.某日     2.某时段" << endl;
			string q; cin >> q;
			if (q == "1") {
				tm s; char ch;
				cout << "时间：（2024/7/3）" << endl;
				cin >> s.tm_year >> ch >> s.tm_mon >> ch >> s.tm_mday;
				m_find(s, m_book, b_record);
				coutbook(m_book, b_record);
			}
			else if (q == "2") {
				tm s1, s2; char ch;
				cout << "起始时间：";
				cin >> s1.tm_year >> ch >> s1.tm_mon >> ch >> s1.tm_mday;
				cout << "终止时间：";
				cin >> s2.tm_year >> ch >> s2.tm_mon >> ch >> s2.tm_mday;
				m_find(s1, s2, m_book, b_record);
				coutbook(m_book, b_record);
			}
			else cout << "输入错误" << endl;

		}
		else if (n == "2") {
			cout << "您要查询1.商品编号  2.商品名称" << endl;
			string s; cin >> s;
			if (s == "1") {
				cout << "输入商品编号: ";
				int a; cin >> a;
				m_find(a, m_book, b_record);
				coutbook(m_book, b_record);
			}
			else if (s == "2") {
				cout << "输入商品名称: ";
				string a; cin >> a;
				m_find(a, m_book, b_record);
				coutbook(m_book, b_record);
			}
			else cout << "输入错误" << endl;
		}
		else if (n == "3")break;
		else cout << "输入错误" << endl;
		system("pause");
		system("cls");
	}
}
void Manager_count::m_find(int s, Goods b[], int& sellamount) {
	if (sellamount != 0)
		sellamount = 0;
	for (int i = 0; i < bs_record; i++)
		if (m_books[i].code==s) {
			b[sellamount].code = m_books[i].code;
			b[sellamount].g_name = m_books[i].g_name;
			b[sellamount].sellprice = m_books[i].sellprice;
			b[sellamount].sell_amount = m_books[i].sell_amount;
			b[sellamount].sell_time.tm_year = m_books[i].sell_time.tm_year;
			b[sellamount].sell_time.tm_mon = m_books[i].sell_time.tm_mon;
			b[sellamount].sell_time.tm_mday = m_books[i].sell_time.tm_mday;
			b[sellamount].sell_time.tm_hour = m_books[i].sell_time.tm_hour;
			b[sellamount].sell_time.tm_min = m_books[i].sell_time.tm_min;
			sellamount++;
		}
}
void Manager_count::m_find(string s, Goods b[], int& sellamount) {
	if (sellamount != 0)
		sellamount = 0;
	for (int i = 0; i < bs_record; i++)
		if (m_books[i].g_name==s) {
			b[sellamount].code = m_books[i].code;
			b[sellamount].g_name = m_books[i].g_name;
			b[sellamount].sellprice = m_books[i].sellprice;
			b[sellamount].sell_amount = m_books[i].sell_amount;
			b[sellamount].sell_time.tm_year = m_books[i].sell_time.tm_year;
			b[sellamount].sell_time.tm_mon = m_books[i].sell_time.tm_mon;
			b[sellamount].sell_time.tm_mday = m_books[i].sell_time.tm_mday;
			b[sellamount].sell_time.tm_hour = m_books[i].sell_time.tm_hour;
			b[sellamount].sell_time.tm_min = m_books[i].sell_time.tm_min;
			sellamount++;
		}
}
void Manager_count::m_find(tm s, Goods b[], int &sellamount) {
	if (sellamount != 0)
		sellamount = 0;
	for (int i = 0; i < bs_record; i++) {
		if (m_books[i].sell_time.tm_year == s.tm_year && m_books[i].sell_time.tm_mon == s.tm_mon && m_books[i].sell_time.tm_mday == s.tm_mday)
		{
			b[sellamount].code = m_books[i].code;
			b[sellamount].g_name = m_books[i].g_name;
			b[sellamount].sellprice = m_books[i].sellprice;
			b[sellamount].sell_amount = m_books[i].sell_amount;
			b[sellamount].sell_time.tm_year = m_books[i].sell_time.tm_year;
			b[sellamount].sell_time.tm_mon = m_books[i].sell_time.tm_mon;
			b[sellamount].sell_time.tm_mday = m_books[i].sell_time.tm_mday;
			b[sellamount].sell_time.tm_hour = m_books[i].sell_time.tm_hour;
			b[sellamount].sell_time.tm_min = m_books[i].sell_time.tm_min;
			sellamount++;
		}
	}
}
void Manager_count::m_find(tm s1,tm s2, Goods b[], int &sellamount) {
	if (sellamount != 0)
		sellamount = 0;
	for (int i = 0; i < bs_record; i++) {
		if (m_books[i].sell_time.tm_year >= s1.tm_year && m_books[i].sell_time.tm_mon >= s1.tm_mon && m_books[i].sell_time.tm_mday >= s1.tm_mday&&
			m_books[i].sell_time.tm_year <= s2.tm_year && m_books[i].sell_time.tm_mon <= s2.tm_mon && m_books[i].sell_time.tm_mday <= s2.tm_mday
			)
		{
			b[sellamount].code = m_books[i].code;
			b[sellamount].g_name = m_books[i].g_name;
			b[sellamount].sellprice = m_books[i].sellprice;
			b[sellamount].sell_amount = m_books[i].sell_amount;
			b[sellamount].sell_time.tm_year = m_books[i].sell_time.tm_year;
			b[sellamount].sell_time.tm_mon = m_books[i].sell_time.tm_mon;
			b[sellamount].sell_time.tm_mday = m_books[i].sell_time.tm_mday;
			b[sellamount].sell_time.tm_hour = m_books[i].sell_time.tm_hour;
			b[sellamount].sell_time.tm_min = m_books[i].sell_time.tm_min;
			sellamount++;
		}
	}
}
void Manager_count::sort() {
	while (1) {
		cout << "1.对库存商品排序  2.对销售商品排序  3.退出" << endl;
		string n; cin >> n;
		if (n == "1") {
			cout << "按 1.编码  2.进货日期  3.库存量 进行排序" << endl;
			string nn; cin >> nn;
			if (nn == "1") {
				for (int i = 0; i < all_amount; i++)
					for (int j = 0; j < all_amount - i - 1; j++)
						if (m_goods[j].code > m_goods[j + 1].code)
							swap(m_goods[j], m_goods[j + 1]);
				coutgood(m_goods, all_amount);
			}
			else if (nn == "2") {
				for (int i = 0; i < all_amount; i++)
					for (int j = 0; j < all_amount - i - 1; j++) {
						if (m_goods[j].intime.tm_year > m_goods[j + 1].intime.tm_year)
							swap(m_goods[j], m_goods[j + 1]);
						else if (m_goods[j].intime.tm_year == m_goods[j + 1].intime.tm_year)
						{
							if (m_goods[j].intime.tm_mon > m_goods[j + 1].intime.tm_mon)
								swap(m_goods[j], m_goods[j + 1]);
							else if (m_goods[j].intime.tm_mon == m_goods[j + 1].intime.tm_mon)
							{
								if (m_goods[j].intime.tm_mday > m_goods[j + 1].intime.tm_mday)
									swap(m_goods[j], m_goods[j + 1]);
							}
						}
					}
				coutgood(m_goods, all_amount);
			}
			else if (nn == "3") {
				for (int i = 0; i < all_amount; i++)
					for (int j = 0; j < all_amount - i - 1; j++)
						if (m_goods[j].amount < m_goods[j + 1].amount)
							swap(m_goods[j], m_goods[j + 1]);
				coutgood(m_goods, all_amount);
			}
			else cout << "输入错误" << endl;
		}
		else if (n == "2") {
			cout << "按 1.编码  2.销售量  3.利润 进行排序" << endl;
			string nn; cin >> nn;
			if (nn == "1") {
				for (int i = 0; i < bs_record; i++)
					for (int j = 0; j < bs_record - i - 1; j++)
						if (m_books[j].code > m_books[j + 1].code)
							swap(m_books[j], m_books[j + 1]);
				coutbook(m_books, bs_record);
			}
			else if (nn == "2") {
				for (int i = 0; i < all_amount; i++)
					for (int j = 0; j < all_amount - i - 1; j++)
						if (m_goods[j].all_sell_amount < m_goods[j + 1].all_sell_amount)
							swap(m_goods[j], m_goods[j + 1]);
				cout << left << setw(12) << "编码";
				cout << left << setw(12) << "名称";
				cout << left << setw(12) << "种类";
				cout << left << setw(12) << "进价";
				cout << left << setw(12) << "成本";
				cout << left << setw(12) << "售价";
				cout << left << setw(12) << "数量";
				cout << left << setw(12) << "销售总额" << endl;
				for (int i = 0; i < all_amount; i++)
				{
					if (m_goods[i].all_sell_amount != 0)
					{
						cout << left << setw(12) << m_goods[i].code;
						cout << left << setw(12) << m_goods[i].g_name;
						cout << left << setw(12) << m_goods[i].kind;
						cout << left << setw(12) << m_goods[i].inprice;
						cout << left << setw(12) << m_goods[i].cost;
						cout << left << setw(12) << m_goods[i].sellprice;
						cout << left << setw(12) << m_goods[i].amount;
						cout << left << setw(12) << m_goods[i].all_sell_amount << endl;
					}
				}
			}
			else if (nn == "3") {
				for (int i = 0; i < all_amount; i++)
					for (int j = 0; j < all_amount - i - 1; j++)
					{
						if (m_goods[j].all_sell_amount * (m_goods[j].sellprice - m_goods[j].cost) < m_goods[j + 1].all_sell_amount * (m_goods[j + 1].sellprice - m_goods[j + 1].cost))
							swap(m_goods[j], m_goods[j + 1]);
					}
				cout << left << setw(12) << "编码";
				cout << left << setw(12) << "名称";
				cout << left << setw(12) << "种类";
				cout << left << setw(12) << "进价";
				cout << left << setw(12) << "成本";
				cout << left << setw(12) << "售价";
				cout << left << setw(12) << "数量";
				cout << left << setw(12) << "销售总额";
				cout << left << setw(12) << "利润" << endl;
				for (int i = 0; i < all_amount; i++)
				{
					if (m_goods[i].all_sell_amount != 0)
					{
						cout << left << setw(12) << m_goods[i].code;
						cout << left << setw(12) << m_goods[i].g_name;
						cout << left << setw(12) << m_goods[i].kind;
						cout << left << setw(12) << m_goods[i].inprice;
						cout << left << setw(12) << m_goods[i].cost;
						cout << left << setw(12) << m_goods[i].sellprice;
						cout << left << setw(12) << m_goods[i].amount;
						cout << left << setw(12) << m_goods[i].all_sell_amount;
						cout << left << setw(12) << m_goods[i].all_sell_amount * (m_goods[i].sellprice - m_goods[i].cost) << endl;
					}
				}
			}
			else cout << "输入错误" << endl;
		}
		else if (n == "3") break;
		else cout << "输入错误" << endl;
		system("pause");
		system("cls");
	}
}
void swap(Goods &a, Goods &b) {
	Goods s;
	s = a, a = b, b = s;
}
void Manager_count::remind(Goods& g) {
	if (g.amount < 2)
	{
		g.Situation = 0;
		cout << g.code << "商品库存不足，需补货" << endl;
		cout << "是否补货1.是   2.否  " << endl;
		int n;// cin >> n;
		n = getIntegerInput();
		if (n==1)
			Replenishone(g.code);
	}
}
void Manager_count::m_exit() {
	Manager_count one;
	one.CreatGoodsDataBase();
	bool s = 0,ss;
	if (all_amount == one.all_amount)
	{
		for (int i = 0; i < all_amount; i++)
			if (m_goods[i].code != one.m_goods[i].code || m_goods[i].g_name != one.m_goods[i].g_name ||
				m_goods[i].cost != one.m_goods[i].cost || m_goods[i].amount != one.m_goods[i].amount
				|| m_goods[i].intime.tm_year != one.m_goods[i].intime.tm_year || m_goods[i].intime.tm_mon != one.m_goods[i].intime.tm_mon
				|| m_goods[i].intime.tm_mday != one.m_goods[i].intime.tm_mday)
			{
				s = 1; break;
			}
	}
	else
		s = 1;
	if (s) {
		cout << "信息未保存，是否保存1.是   0.否" << endl;
		//cin >> ss;
		ss = getIntegerInput();
		if (ss)
			Save();
	}
}

int Salesperson::getIntegerInput() {
	int input;
	while (true)
	{
		//cout << "请输入一个整数: ";
		cin >> input;

		if (cin.fail()) {
			// 清除错误状态
			cin.clear();
			// 忽略剩余的输入
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入无效，请输入一个整数。" << endl;
		}
		else {
			// 清除输入缓冲区
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
	}
}


void Salesperson::OpenFile()
{
	ifstream Data_Base("Goods.txt", ios::in);
	if (Data_Base.is_open())
	{
		//cout << "DataBase has been created!" << endl;
	}
	char Dstr[200] = { 0 };
	//int m_Num;
	//Data_Base.getline(Dstr, sizeof(char));
	int C_i = 0;
	Data_Base >> Dstr;
	//cout<<Dstr<<endl;
	Data_Base >> all_amount;
	//cout << all_amount << endl;
	C_i = 0;
	while (C_i != 9)
	{
		Data_Base >> Dstr;
		//cout << Dstr << endl;
		C_i++;
	}
	char Dch;
	for (int i = 0; i < all_amount; i++)
	{
		Data_Base /*>> setw(12) */ >> m_goods[i].code;
		Data_Base/* >> setw(12)*/ >> m_goods[i].g_name;
		Data_Base/* >> setw(12)*/ >> m_goods[i].kind;
		Data_Base/* >> setw(12)*/ >> m_goods[i].inprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].cost;
		Data_Base/* >> setw(12)*/ >> m_goods[i].sellprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].all_sell_amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].intime.tm_year >> Dch >> m_goods[i].intime.tm_mon >> Dch >> m_goods[i].intime.tm_mday;
	}
	Data_Base.close();

	ifstream ifs;
	ifs.open("Goods.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	//cout << "The information of goods:" << endl;
	char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))
	{
		cout << buf << endl;
	}
	ifs.close();
}

void Salesperson::SetBooks()
{
	ifstream Data_Base("Goods.txt", ios::in);
	if (Data_Base.is_open())
	{
		//cout << "DataBase has been created!" << endl;
	}
	char Dstr[200] = { 0 };
	//int m_Num;
	//Data_Base.getline(Dstr, sizeof(char));
	int C_i = 0;
	Data_Base >> Dstr;
	//cout<<Dstr<<endl;
	Data_Base >> all_amount;
	//cout << all_amount << endl;
	C_i = 0;
	while (C_i != 9)
	{
		Data_Base >> Dstr;
		//cout << Dstr << endl;
		C_i++;
	}
	char Dch;
	for (int i = 0; i < all_amount; i++)
	{
		Data_Base /*>> setw(12) */ >> m_goods[i].code;
		Data_Base/* >> setw(12)*/ >> m_goods[i].g_name;
		Data_Base/* >> setw(12)*/ >> m_goods[i].kind;
		Data_Base/* >> setw(12)*/ >> m_goods[i].inprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].cost;
		Data_Base/* >> setw(12)*/ >> m_goods[i].sellprice;
		Data_Base/* >> setw(12)*/ >> m_goods[i].amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].all_sell_amount;
		Data_Base/* >> setw(12)*/ >> m_goods[i].intime.tm_year >> Dch >> m_goods[i].intime.tm_mon >> Dch >> m_goods[i].intime.tm_mday;
	}
	Data_Base.close();


}

void Salesperson::Sell()
{
	int choose = -1;
	int sell_num = 0;
	int m_code;
	string m_name;
	bool isFound = 1;
	int all_price = 0;
	int N = 0;
	ifstream ifs("Book.txt", ios::in);
	ifs >> N;

	if (N != 0 && sell_record == 0)
	{
		sell_record += N;
		char Str[100] = { 0 };
		int S_i = 0;
		while (S_i != 5)
		{
			ifs >> Str;
			S_i++;
		}
		char Sstr;
		for (int i = 0; i < N; i++)
		{
			ifs >> m_books[i].code;
			ifs >> m_books[i].g_name;
			ifs >> m_books[i].sellprice;
			ifs >> m_books[i].sell_amount;
			ifs >> m_books[i].sell_time.tm_year >> Sstr >> m_books[i].sell_time.tm_mon >> Sstr >> m_books[i].sell_time.tm_mday >> Sstr >> m_books[i].sell_time.tm_hour >> Sstr >> m_books[i].sell_time.tm_min;
		}
	}
	ifs.close();
	while (1)
	{
		cout << "选择输入形式 ( 1. 编码  2. 名称 3. 退出 ) : ";
		cin >> choose;
		if (choose == 1)
		{
			cout << "输入所需售卖商品的的编码 :";
			cin >> m_code;
			int i = Find(m_code);
			if (i == -1)
			{
				cout << "该商品不存在!" << endl;
				continue;
			}
			cout << "商品 " << m_code << " 数量:" << m_goods[i].amount << endl;
			cout << "输入销售数量:";
			cin >> sell_num;

			if (m_goods[i].amount - sell_num < 0)
			{
				cout << "商品数量不足 ! " << endl;
				continue;
			}
			sell_record++;
			m_goods[i].amount -= sell_num;
			m_goods[i].all_sell_amount += sell_num;
			m_goods[i].sell_time = Time();
			//cout << "zong:" << m_goods[i].all_sell_amount << endl;
			cout << "所需支付:" << sell_num * m_goods[i].sellprice << endl;
			all_price += sell_num * m_goods[i].sellprice;
			if (m_goods[i].amount == 0)
			{
				m_goods[i].Situation = 0;
				cout << "该商品售罄,提醒经理补货!" << endl;
			}
			m_books[sell_record - 1].all_sell_amount = m_goods[i].all_sell_amount;
			m_books[sell_record - 1].code = m_goods[i].code;
			m_books[sell_record - 1].g_name = m_goods[i].g_name;
			m_books[sell_record - 1].sellprice = m_goods[i].sellprice;
			m_books[sell_record - 1].sell_amount = sell_num;
			m_books[sell_record - 1].sell_time = Time();

		}
		if (choose == 2)
		{

			cout << "输入所需售卖商品的的名称:";
			cin >> m_name;
			int i = Find(m_name);

			if (i == -1)
			{
				cout << "该商品不存在!" << endl;
				continue;
			}
			cout << "商品 " << m_name << " 数量:" << m_goods[i].amount << endl;
			cout << "输入销售数量:";
			cin >> sell_num;
			if (m_goods[i].amount - sell_num < 0)
			{
				cout << "商品数量不足 ! " << endl;
				continue;
			}
			sell_record++;
			m_goods[i].amount -= sell_num;
			m_goods[i].all_sell_amount += sell_num;
			m_goods[i].sell_time = Time();
			//cout << "The amount that should be paid:" << sell_num * m_goods[i].sellprice << endl;
			all_price += sell_num * m_goods[i].sellprice;
			if (m_goods[i].amount == 0)
			{
				m_goods[i].Situation = 0;
				cout << "该商品售罄,提醒经理补货 ! " << endl;
			}
			m_books[sell_record - 1].all_sell_amount = m_goods[i].all_sell_amount;
			m_books[sell_record - 1].code = m_goods[i].code;
			m_books[sell_record - 1].g_name = m_goods[i].g_name;
			m_books[sell_record - 1].sellprice = m_goods[i].sellprice;
			m_books[sell_record - 1].sell_amount = sell_num;
			m_books[sell_record - 1].sell_time = Time();
		}
		if (choose == 3)
		{
			cout << "需支付 : " << all_price << endl;
			break;
		}
	}
	ofstream ofs("Goods.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "Goods.txt打开失败!" << endl;
		return;
	}
	ofs << "商品:  " << all_amount << endl;
	ofs << left << setw(12) << "编码";
	ofs << left << setw(12) << "名称";
	ofs << left << setw(12) << "种类";
	ofs << left << setw(12) << "进价";
	ofs << left << setw(12) << "成本";
	ofs << left << setw(12) << "售价";
	ofs << left << setw(12) << "数量";
	ofs << left << setw(12) << "总销售额";
	ofs << left << setw(12) << "进货时间" << endl;
	for (int i = 0; i < all_amount; i++)
	{
		ofs << left << setw(12) << m_goods[i].code;
		ofs << left << setw(12) << m_goods[i].g_name;
		ofs << left << setw(12) << m_goods[i].kind;
		ofs << left << setw(12) << m_goods[i].inprice;
		ofs << left << setw(12) << m_goods[i].cost;
		ofs << left << setw(12) << m_goods[i].sellprice;
		ofs << left << setw(12) << m_goods[i].amount;
		ofs << left << setw(12) << m_goods[i].all_sell_amount;
		ofs <</* left << setw(12) <<*/ m_goods[i].intime.tm_year << "." << m_goods[i].intime.tm_mon << "." << m_goods[i].intime.tm_mday << endl;
	}
	ofs.close();
	//ofstream ofs;
	ofs.open("Book.txt", ios::out);
	ofs << sell_record << endl;
	ofs << left << setw(12) << "编码";
	ofs << left << setw(12) << "名称";
	ofs << left << setw(12) << "售价";
	ofs << left << setw(12) << "销售数量";
	ofs << left << setw(12) << "销售时间" << endl;
	for (int i = 0; i < sell_record; i++)
	{
		ofs << left << setw(12) << m_books[i].code;
		ofs << left << setw(12) << m_books[i].g_name;
		ofs << left << setw(12) << m_books[i].sellprice;
		ofs << left << setw(12) << m_books[i].sell_amount;
		ofs << m_books[i].sell_time.tm_year << "." << m_books[i].sell_time.tm_mon << "." << m_books[i].sell_time.tm_mday << "," << m_books[i].sell_time.tm_hour << ":" << m_books[i].sell_time.tm_min << endl;
	}
	ofs.close();


}

void Salesperson::SellStatistic()
{

	//ofstream ofs;
	//ofs.open("Book.txt", ios::out);
	//ofs << sell_record << endl;
	//ofs << left << setw(12) << "Code";
	//ofs << left << setw(12) << "Name";
	//ofs << left << setw(12) << "Sellprice";
	//ofs << left << setw(12) << "Amount";
	//ofs << left << setw(12) << "SellTime" << endl;
	//for (int i = 0; i < sell_record; i++)
	//{
	//	ofs << left << setw(12) << m_books[i].code;
	//	ofs << left << setw(12) << m_books[i].g_name;
	//	ofs << left << setw(12) << m_books[i].sellprice;
	//	ofs << left << setw(12) << m_books[i].sell_amount;
	//	ofs << m_books[i].sell_time.tm_year << "." << m_books[i].sell_time.tm_mon << "." << m_books[i].sell_time.tm_wday << "," << m_books[i].sell_time.tm_hour << ":" << m_books[i].sell_time.tm_min << endl;
	//}
	//ofs.close();

	ifstream ifs;
	ifs.open("Book.txt", ios::in);
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	ifs.close();
}
void Salesperson::FindInfo_good()
{
	int choose = 0;
	cout << "选择查找方式(1. 编码;2. 种类):";
	cin >> choose;
	if (choose == 1)
	{
		int code;
		cout << "输入所需查找商品的编码:";
		cin >> code;
		bool IsFind = 1;
		cout << "结果:" << endl;
		for (int i = 0; i < all_amount; i++)
		{
			if (m_goods[i].code == code)
			{
				IsFind = 0;
				cout << left << setw(12) << m_goods[i].code;
				cout << left << setw(12) << m_goods[i].g_name;
				cout << left << setw(12) << m_goods[i].kind;
				cout << left << setw(12) << m_goods[i].inprice;
				cout << left << setw(12) << m_goods[i].cost;
				cout << left << setw(12) << m_goods[i].sellprice;
				cout << left << setw(12) << m_goods[i].amount;
				cout << left << setw(12) << m_goods[i].all_sell_amount;
				cout <</* left << setw(12) <<*/ m_goods[i].intime.tm_year << "." << m_goods[i].intime.tm_mon << "." << m_goods[i].intime.tm_mday << endl;
			}
		}
		if (IsFind)
		{
			cout << "无法找到商品 ! " << endl;
		}

	}
	if (choose == 2)
	{
		string Kind;
		cout << "请输入所需查找种类:";
		cin >> Kind;
		bool IsFind = 1;
		cout << "结果:" << endl;
		cout << left << setw(12) << "编码";
		cout << left << setw(12) << "名称";
		cout << left << setw(12) << "种类";
		cout << left << setw(12) << "进价";
		cout << left << setw(12) << "成本";
		cout << left << setw(12) << "售价";
		cout << left << setw(12) << "数量";
		cout << left << setw(12) << "总销售额";
		cout << left << setw(12) << "进货时间" << endl;
		for (int i = 0; i < all_amount; i++)
		{
			if (m_goods[i].kind == Kind)
			{
				IsFind = 0;
				cout << left << setw(12) << m_goods[i].code;
				cout << left << setw(12) << m_goods[i].g_name;
				cout << left << setw(12) << m_goods[i].kind;
				cout << left << setw(12) << m_goods[i].inprice;
				cout << left << setw(12) << m_goods[i].cost;
				cout << left << setw(12) << m_goods[i].sellprice;
				cout << left << setw(12) << m_goods[i].amount;
				cout << left << setw(12) << m_goods[i].all_sell_amount;
				cout <</* left << setw(12) <<*/ m_goods[i].intime.tm_year << "." << m_goods[i].intime.tm_mon << "." << m_goods[i].intime.tm_mday << endl;
			}
			if (IsFind)
			{
				cout << "无法找到商品 ! " << endl;
			}
		}
	}


}
//6
void Salesperson::FindInfo_book()
{
	fstream fs;
	fs.open("Book.txt", ios::in);
	fs >> sell_record; string str; char ch;
	for (int i = 0; i < 5; i++)
		fs >> str;
	for (int i = 0; i < sell_record; i++) {
		fs >> m_books[i].code
			>> m_books[i].g_name
			>> m_books[i].sellprice
			>> m_books[i].sell_amount
			>> m_books[i].sell_time.tm_year >> ch
			>> m_books[i].sell_time.tm_mon >> ch
			>> m_books[i].sell_time.tm_mday >> ch
			>> m_books[i].sell_time.tm_hour >> ch
			>> m_books[i].sell_time.tm_min;
	}
	fs.close();
	int choose = 0;
	cout << "选择查找销售记录模式(1. 编码;2. 日期):";
	cin >> choose;
	if (choose == 1)
	{
		int code;
		cout << "输入所需查找商品编码:";
		cin >> code;
		bool IsFind = 1;
		cout << "结果:" << endl;
		cout << left << setw(12) << "编码";
		cout << left << setw(12) << "名称";
		cout << left << setw(12) << "售价";
		cout << left << setw(12) << "销售数量";
		cout << left << setw(12) << "销售时间" << endl;
		for (int i = 0; i < sell_record; i++)
		{
			if (m_books[i].code == code)
			{
				IsFind = 0;
				cout << left << setw(12) << m_books[i].code;
				cout << left << setw(12) << m_books[i].g_name;
				cout << left << setw(12) << m_books[i].sellprice;
				cout << left << setw(12) << m_books[i].sell_amount;
				cout << m_books[i].sell_time.tm_year << "." << m_books[i].sell_time.tm_mon << "." << m_books[i].sell_time.tm_mday << "," << m_books[i].sell_time.tm_hour << ":" << m_books[i].sell_time.tm_min << endl;
			}
		}
		if (IsFind)
		{
			cout << "未发现销售记录 ! " << endl;
		}
	}
	if (choose == 2)
	{
		int y, m, d;
		cout << "输入查找时间年限:";
		cin >> y;
		cout << "输入查找时间月份:";
		cin >> m;
		cout << "输入查找时间日期:";
		cin >> d;
		bool IsFind = 1;
		cout << "结果:" << endl;
		cout << left << setw(12) << "编码";
		cout << left << setw(12) << "名称";
		cout << left << setw(12) << "售价";
		cout << left << setw(12) << "销售数量";
		cout << left << setw(12) << "销售时间" << endl;
		for (int i = 0; i < sell_record; i++)
		{

			if (m_books[i].sell_time.tm_year == y || m_books[i].sell_time.tm_mon == m || m_books[i].sell_time.tm_mday == d)
			{
				IsFind = 0;
				cout << left << setw(12) << m_books[i].code;
				cout << left << setw(12) << m_books[i].g_name;
				cout << left << setw(12) << m_books[i].sellprice;
				cout << left << setw(12) << m_books[i].sell_amount;
				cout << m_books[i].sell_time.tm_year << "." << m_books[i].sell_time.tm_mon << "." << m_books[i].sell_time.tm_mday << "," << m_books[i].sell_time.tm_hour << ":" << m_books[i].sell_time.tm_min << endl;

			}
		}
		if (IsFind)
		{
			cout << "未发现销售记录 !" << endl;
		}
	}

}
//7
int Salesperson::Find(int code)
{
	int m_index = -1;

	for (int i = 0; i < all_amount; i++)
	{
		if (m_goods[i].code == code)
		{
			m_index = i;
			break;
		}
	}
	return m_index;
}

int Salesperson::Find(string name)
{
	int m_index = -1;
	for (int i = 0; i < all_amount; i++)
	{
		if (m_goods[i].g_name == name)
		{
			m_index = i;
			break;
		}
	}
	return m_index;
}

Salesperson::~Salesperson()
{
	delete[]m_goods;
	delete[]m_books;
}

void Salesperson::sort() {
	cout << "1.对库存商品排序  2.对销售商品排序" << endl;
	int n; 
	while(1) 
	{
		n = getIntegerInput();
	if(n==1)
	{
		cout << "按 1.编码  2.进货日期  3.库存量 进行排序" << endl;
		int nn; 
		while(1)
		{
			nn= getIntegerInput();
		
		if(nn==1)
		{
			for (int i = 0; i < all_amount; i++)
				for (int j = 0; j < all_amount - i - 1; j++)
					if (m_goods[j].code > m_goods[j + 1].code)
						swap(m_goods[j], m_goods[j + 1]);
			coutgood(m_goods, all_amount);
			break;
		}
		if(nn==2) 
		{
			for (int i = 0; i < all_amount; i++)
				for (int j = 0; j < all_amount - i - 1; j++) {
					if (m_goods[j].intime.tm_year > m_goods[j + 1].intime.tm_year)
						swap(m_goods[j], m_goods[j + 1]);
					else if (m_goods[j].intime.tm_year == m_goods[j + 1].intime.tm_year)
					{
						if (m_goods[j].intime.tm_mon > m_goods[j + 1].intime.tm_mon)
							swap(m_goods[j], m_goods[j + 1]);
						else if (m_goods[j].intime.tm_mon == m_goods[j + 1].intime.tm_mon)
						{
							if (m_goods[j].intime.tm_mday > m_goods[j + 1].intime.tm_mday)
								swap(m_goods[j], m_goods[j + 1]);
						}
					}
				}
			coutgood(m_goods, all_amount);
			break;
		}
		if(nn==3)
		{
			for (int i = 0; i < all_amount; i++)
				for (int j = 0; j < all_amount - i - 1; j++)
					if (m_goods[j].amount < m_goods[j + 1].amount)
						swap(m_goods[j], m_goods[j + 1]);
			coutgood(m_goods, all_amount);
			break;
		}
		cout << "输入错误！重新输入：";
		}break;
	}
	if(n==2)
	{
		cout << "按 1.编码  2.销售量  3.利润 进行排序" << endl;
		//cout << all_amount << endl;
		int nn; 
		while(1)
		{
			nn = getIntegerInput();
		if(nn==1)
		{
			for (int i = 0; i < sell_record; i++)
				for (int j = 0; j < sell_record - i - 1; j++)
					if (m_books[j].code > m_books[j + 1].code)
						swap(m_books[j], m_books[j + 1]);
			coutbook(m_books, sell_record);
			break;
		}
		if(nn==2)
		{
			for (int i = 0; i < all_amount; i++)
				for (int j = 0; j < all_amount - i - 1; j++)
					if (m_goods[j].all_sell_amount < m_goods[j + 1].all_sell_amount)
						swap(m_goods[j], m_goods[j + 1]);
			cout << left << setw(12) << "编码";
			cout << left << setw(12) << "名称";
			cout << left << setw(12) << "种类";
			cout << left << setw(12) << "进价";
			cout << left << setw(12) << "成本";
			cout << left << setw(12) << "售价";
			cout << left << setw(12) << "数量";
			cout << left << setw(12) << "总销售额" << endl;
			for (int i = 0; i < all_amount; i++)
			{
				//cout << m_goods[i].all_sell_amount << endl;
				if (m_goods[i].all_sell_amount != 0)
				{

					cout << left << setw(12) << m_goods[i].code;
					cout << left << setw(12) << m_goods[i].g_name;
					cout << left << setw(12) << m_goods[i].kind;
					cout << left << setw(12) << m_goods[i].inprice;
					cout << left << setw(12) << m_goods[i].cost;
					cout << left << setw(12) << m_goods[i].sellprice;
					cout << left << setw(12) << m_goods[i].amount;
					cout << left << setw(12) << m_goods[i].all_sell_amount << endl;

					//cout << m_goods[i].code << ' '
					//	<< m_goods[i].g_name << ' '
					//	<< m_goods[i].sellprice << ' '
					//	<< m_goods[i].amount << ' '
					//	/*<< m_goods[i].sell_time.tm_year << '/'
					//	<< m_goods[i].sell_time.tm_mon << '/'
					//	<< m_goods[i].sell_time.tm_wday << '.'
					//	<< m_goods[i].sell_time.tm_hour << ':'
					//	<< m_goods[i].sell_time.tm_min << " "*/ << m_goods[i].all_sell_amount << " " << m_goods[i].all_sell_amount * (m_goods[i].sellprice - m_goods[i].cost) << endl;
				}
			}
			break;
		}
		if(nn==3)
		{
			for (int i = 0; i < all_amount; i++)
				for (int j = 0; j < all_amount - i - 1; j++)
				{
					if (m_goods[j].all_sell_amount * (m_goods[j].sellprice - m_goods[j].cost) < m_goods[j + 1].all_sell_amount * (m_goods[j + 1].sellprice - m_goods[j + 1].cost))
						swap(m_goods[j], m_goods[j + 1]);
				}
			/*		cout << left << setw(12) << "Code";
					cout << left << setw(12) << "Name";
					cout << left << setw(12) << "Kind";
					cout << left << setw(12) << "Inprice";
					cout << left << setw(12) << "Cost";
					cout << left << setw(12) << "Sellprice";
					cout << left << setw(12) << "Amount";
					cout << left << setw(12) << "AllSellNum";
					*/
			cout << left << setw(12) << "编码";
			cout << left << setw(12) << "名称";
			cout << left << setw(12) << "种类";
			cout << left << setw(12) << "进价";
			cout << left << setw(12) << "成本";
			cout << left << setw(12) << "售价";
			cout << left << setw(12) << "数量";
			cout << left << setw(12) << "总销售额";
			cout << left << setw(12) << "利润" << endl;
			for (int i = 0; i < all_amount; i++)
			{
				if (m_goods[i].all_sell_amount != 0)
				{
					cout << left << setw(12) << m_goods[i].code;
					cout << left << setw(12) << m_goods[i].g_name;
					cout << left << setw(12) << m_goods[i].kind;
					cout << left << setw(12) << m_goods[i].inprice;
					cout << left << setw(12) << m_goods[i].cost;
					cout << left << setw(12) << m_goods[i].sellprice;
					cout << left << setw(12) << m_goods[i].amount;
					cout << left << setw(12) << m_goods[i].all_sell_amount;
					cout << left << setw(12) << m_goods[i].all_sell_amount * (m_goods[i].sellprice - m_goods[i].cost) << endl;
				}
			}
			break;
		}
		cout << "输入错误！重新输入：";
		}
		break;
	}
	cout << "输入错误！重新输入：";
	}
}