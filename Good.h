#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include <limits>
using namespace std;
class Goods
{
public:
	int code;				//商品编码		从10001开始
	string g_name;
	string kind;	//类别
	double inprice;		//进价
	double cost = 1.02 * inprice;	//成本
	double sellprice;		//售价
	int amount;		//库存量
	tm intime;		//进货日期  以XX.XX.XX为例
	tm sell_time;		//销售日期  以XX.XX.XX为例
	int sell_amount;		//销售记录（件）
	int all_sell_amount;
	bool Situation = 1;			//状态(是否补货：1->Yes/0->No)
	Goods();
	Goods(const Goods& p);
};
class Manager_count
{
public:
	Goods* m_goods = new Goods[100];
	int all_amount = 0;		//库存种类总额


	int bs_record = 0;
	Goods* m_books = new Goods[1024];
	int b_record = 0;
	Goods* m_book = new Goods[1024];


	void Creat_GoodsDataBase();		//创建数据库
	void OutputInfo();			//导入信息
	Goods InputInfo();			//打开，读入商品信息供销售员销售
	void ReAdd();
	void Replenish();					//商品信息进货
	int Find(int code);		//查找商品
	void Save();			//保存文件
	void DeleteGoods();			//删除商品
	void InfoChange();			//商品信息修改(售价)
	double ProfitCaculate();		//利润计算
	void ProfitStatistic();			//利润统计
	void Inquire(string n);
	int getIntegerInput();
	double getDoubleInput();
	~Manager_count();


	void CreatGoodsDataBase();
	void Replenishone(int n);    //对一件商品进货
	friend void coutgood(Goods a[],int n);     //输出Goods[]
	friend void coutbook(Goods a[], int n);
	void Inquire();              //查找
	void m_find(int s, Goods b[], int& sellamount);
	void m_find(string s, Goods b[], int& sellamount);
	void m_find(tm s, Goods a[], int& sellampunt);
	void m_find(tm s1, tm s2, Goods b[], int& sellamount);
	void sort();                   //排序
	friend void swap(Goods& a, Goods &b);
	void remind(Goods& g);    //提醒补货
	void m_exit();        //退出系统
};
class Salesperson// :public Goods
{
public:
	Goods* m_goods = new Goods[100];
	Goods* m_books = new Goods[1024];
	int all_amount = 0;		//库存种类总额
	int sell_record = 0;    //销售条数
	int getIntegerInput();
	void OpenFile();               //打开商品数据库
	void SetBooks();             //建立台账
	void Sell();                        //动态销售
	void SellStatistic();         //销售统计
	void sort();                       //当日销售商品排序
	void FindInfo_book();                //商品信息查询（按编码）
	void FindInfo_good();
	int Find(int code);
	int Find(string name);
	~Salesperson();
};






