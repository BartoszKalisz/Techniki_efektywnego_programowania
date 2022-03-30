#pragma once
#include <string>
using namespace std;

class CTable
{
public:
	static const string DEFAULT_NAME;
	static const int DEFAULT_LENGTH;
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& pcOther);
	CTable(CTable&& pcOther) noexcept;
	bool bSetNewSize(int iTableLen);
	int getSize();
	void vSetName(string sName);
	string getName();
	CTable* pcClone();
	void PrintTable();
	CTable operator=(CTable &pcOther);
	CTable operator+(CTable pcOther);
	void setNewValueAt(int offset, int newVal);

private:
	string s_name;
	int* piTable;
	int tableLength;
	void copyTable(int* copyFromTable, int* copyToTable, int copyFromTableSize);
	void copyTable(const int* copyFromTable, int* copyToTable, int startIndex, int copyFromTableSize);
};
void v_mod_table(CTable* pcTab, int iNewSize);
void v_mod_table(CTable cTab, int iNewSize);



