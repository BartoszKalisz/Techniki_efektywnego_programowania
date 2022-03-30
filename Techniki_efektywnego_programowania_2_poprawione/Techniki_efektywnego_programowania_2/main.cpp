//Bartosz Kalisz
#include "CTable.h"
#include "functions.h"
#include <iostream>

int main() {
    CTable tab_0, tab_1;
    tab_0.bSetNewSize(4);
    tab_1.bSetNewSize(4);
   
    tab_0.setNewValueAt(0, 1);
    tab_0.setNewValueAt(1, 2);
    tab_0.setNewValueAt(2, 3);
    tab_0.setNewValueAt(3, 4);
    tab_1.setNewValueAt(0, 51);
    tab_1.setNewValueAt(1, 52);
    tab_1.setNewValueAt(2, 53);
    tab_1.setNewValueAt(3, 54);
   
    tab_1.setNewValueAt(2, 123);

    cout << "tab00 table size: " << tab_0.getSize() <<endl;
    cout << "tab01 table size: " << tab_1.getSize() << "\n\n";
    cout << "Ours tables" << endl;
    tab_0.PrintTable();
    tab_1.PrintTable();

    
    CTable concatenation = (tab_0 +tab_1);
    cout << "\nconcatenation: " <<endl;
    concatenation.PrintTable();
    cout << endl;
    
}

