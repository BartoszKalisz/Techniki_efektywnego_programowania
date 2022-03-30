//Bartosz Kalisz
#include "CTable.h"
#include "functions.h"
#include <iostream>

int main() {
	/*
		//zad 1
	int array_size;
	cout << "Put array size";
	cin >> array_size;
	while (array_size < 0)
	{
		cout << "Wrong array size, try again";
	    cin >> array_size;

	}
	v_alloc_table_add_5(array_size);
	cout << endl;
	 
	//zad2
	int** piTable;
	cout << b_alloc_table_2_dim(&piTable, 5, 3)<<endl;

	//zad3
	cout << b_dealloc_table_2_dim(*&piTable, 5, 3)<<endl;

	//zad4
	CTable table_with_parameters("not default table", 5);
	
    CTable c_tab;
	CTable* pc_new_tab;
	pc_new_tab = c_tab.pcClone();

	cout << endl << "v_mod_table(CTable cTab, int iNewSize)" << endl;
	v_mod_table(c_tab, 5);
	c_tab.PrintTable();

	cout << endl << "v_mod_table(CTable* pcTab, int iNewSize)" << endl;
	v_mod_table(&c_tab, 5);
	c_tab.PrintTable();
	
	CTable static_table[3];
	static_table[0].vSetName("tab1");
	static_table[1].vSetName("tab2");
	static_table[2].vSetName("tab3");

	
	CTable* dynamic_pc_tab = new CTable[3];
	delete[] dynamic_pc_tab;
	*/
	

	CTable c_tab_0("table 0", 8), c_tab_1("table 1", 8);
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);

	for (int ii = 0; ii < 6; ii++) {
		c_tab_0.vSetValueAt(ii, ii + 1);
	}

	for (int ii = 0; ii < 4; ii++) {
		c_tab_1.vSetValueAt(ii, ii + 51);
	}

	c_tab_0 = c_tab_1;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.PrintTable();
	c_tab_1.PrintTable();

	(c_tab_0 + c_tab_1).PrintTable();

	CTable c_tab_2("table 2", 6);
	
	c_tab_2 = c_tab_0 + c_tab_1;

	c_tab_2 = c_tab_2++;
	c_tab_2.PrintTable();
	
}
