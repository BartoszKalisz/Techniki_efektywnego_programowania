#pragma once
#include <string>
#define PP_ADDED_VALUE 48
using namespace std;

class CTable
{
public:
	static const string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;
	CTable();
	CTable(string sName, int iTableLn);
	CTable(CTable& pcOther);
	CTable(CTable&& pcOther);
	~CTable();
	bool bSetNewSize(int iTableLen);
	int getSize();
	void vSetName(string sName);
	string getName();
	CTable* pcClone();
	void PrintTable();
	void vSetValueAt(int iOffset, int iNewVal);
	friend void swap(CTable& cFirst, CTable& cSecond);
	CTable operator=(CTable cOther);
	CTable operator+(CTable cOther);
	CTable operator++(int);

private:
	string s_name;
	int* piTable;
	int tableLength;
};
void v_mod_table(CTable* pcTab, int iNewSize);
void v_mod_table(CTable cTab, int iNewSize);
