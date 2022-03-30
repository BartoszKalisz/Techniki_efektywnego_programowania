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

CTable::CTable(const CTable& pcOther) {
	tableLength = pcOther.tableLength;
	piTable = new int[tableLength];
	this->copyTable(pcOther.piTable, piTable, pcOther.tableLength);
	s_name = pcOther.s_name + "_copy";
	cout << "kopiuj: '" << s_name << "'" << endl;
}

CTable::CTable(CTable&& pcOther) noexcept : CTable() {
	piTable = pcOther.piTable;
	tableLength = pcOther.tableLength;
    s_name = pcOther.s_name;
    pcOther.piTable = NULL;
	::cout << "MOVED" << std::endl;
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

void CTable::copyTable(const int* copyFromTable, int* copyToTable, int startIndex, int copyFromTableSize)
{
	for (int i = 0; i < copyFromTableSize; i++)
	{
		copyToTable[startIndex + i] = copyFromTable[i];
	}
}

void CTable::copyTable(int* copyFromTable, int* copyToTable, int copyFromTableSize)
{
	copyTable(copyFromTable, copyToTable, 0, copyFromTableSize);
}

CTable CTable::operator=(CTable &pcOther)
{
	if (piTable != NULL) delete piTable;
	piTable = pcOther.piTable;
	tableLength = pcOther.tableLength;
	pcOther.piTable = NULL;
	return *this;
	
}

CTable CTable::operator+(CTable pcOther)
{
	CTable cTableConcat(s_name + "+" + pcOther.s_name, tableLength + pcOther.tableLength);
	memcpy(cTableConcat.piTable, piTable, tableLength * sizeof(int));
	memcpy(cTableConcat.piTable + tableLength, pcOther.piTable, pcOther.tableLength * sizeof(int));
	return cTableConcat;
}


void CTable::setNewValueAt(int offset, int newValue)
{
	if (offset >= tableLength || offset < 0)
	{
		cout << "Wrong offset value";
	}
	else
	{
		piTable[offset] = newValue;
	}
}
