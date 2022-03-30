#include "CTable.h"
#include <iostream>


const string CTable::DEFAULT_NAME = "default";
const int CTable::DEFAULT_LENGTH = 3;


CTable::CTable() {
	s_name = DEFAULT_NAME;
	cout << "bezp: '" << s_name << "'" << endl;
	tableLength = DEFAULT_LENGTH;
	piTable = new int[tableLength];
}
CTable::CTable(string sName, int iTableLength) {
	tableLength = iTableLength;
	piTable = new int[iTableLength];
	s_name = sName;
	cout << "parametr: '" << s_name << "'" << endl;
}

CTable::CTable(CTable& pcOther) {
	tableLength = pcOther.tableLength;
	piTable = new int[tableLength];
	memcpy(piTable, pcOther.piTable, tableLength * sizeof(int));
	s_name = pcOther.s_name + "_copy";
	cout << "kopiuj: '" << s_name << "'" << endl;
}
CTable::CTable(CTable&& pcOther) : CTable() {
   swap(*this, pcOther);
   std::cout << "MOVED" << std::endl;
}
CTable::~CTable() {

	cout << "usuwam: " << s_name << endl;
	delete piTable;
}

void CTable::vSetName(string sName) {
	s_name = sName;
}
string CTable::getName() {
	return s_name;
}
bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen < 0) return false;
	else {
		tableLength = iTableLen;
		int* piTableTemp = new int[tableLength];
		memcpy(piTableTemp, piTable, tableLength * 4);
		delete piTable;
		piTable = piTableTemp;
		return true;
	}
}
int CTable::getSize() {
	return tableLength;
}
void CTable::vSetValueAt(int iOffset, int iNewVal) {
	if (0 <= iOffset && iOffset < tableLength) {
		piTable[iOffset] = iNewVal;
	}
}
void CTable::PrintTable()
{
	cout << endl;
	for (int i = 0; i < tableLength; i++)
	{
		cout << piTable[i] << " ";
	}
	cout << endl;
}
CTable* CTable::pcClone() {
	CTable* tableTemp = new CTable(s_name, tableLength);
	tableTemp->piTable = new int[tableLength];
	memcpy(tableTemp->piTable, piTable, tableLength * 4);
	return tableTemp;
}
void v_mod_table(CTable* pcTab, int iNewSize)
{
	(*pcTab).bSetNewSize(iNewSize);
}

void v_mod_table(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);

}
void swap(CTable& cFirst, CTable& cSecond) {
	using std::swap;

	swap(cFirst.s_name, cSecond.s_name);
	swap(cFirst.tableLength, cSecond.tableLength);
	swap(cFirst.piTable, cSecond.piTable);
}
CTable CTable::operator=(CTable pcOther) {
	swap(*this, pcOther);
	return *this;
}

CTable CTable::operator+(CTable pcOther) {

	CTable cTableConcat(s_name + "+" + pcOther.s_name, tableLength + pcOther.tableLength);
	memcpy(cTableConcat.piTable, piTable, tableLength * sizeof(int));
	memcpy(cTableConcat.piTable + tableLength, pcOther.piTable, pcOther.tableLength * sizeof(int));
	return cTableConcat;
}

CTable CTable::operator++(int) {
	bSetNewSize(tableLength + 1);
	vSetValueAt(tableLength - 1, PP_ADDED_VALUE);
	return *this;
}