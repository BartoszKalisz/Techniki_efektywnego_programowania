#include "functions.h"
#include <iostream>;

//Zadanie 1
void v_alloc_table_add_5(int iSize) {

	int* tab = new int[iSize];
	for (int i = 0; i < iSize; i++) {
		tab[i] = i + 5;
	}
	for (int i = 0; i < iSize; i++) {
		cout << tab[i] << " ";
	}
	delete[] tab;
}
//Zadanie 2
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {

	if (iSizeX <= 0 || iSizeY <= 0) {
		return false;
	}
	*piTable = new int* [iSizeX];
	for (int i = 0; i < iSizeX; i++) {
		(*piTable)[i] = new int[iSizeY];
	}
	return true;
}
//zadanie 3
bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY) {

	if (iSizeX <= 0 || iSizeY <= 0) {
		return false;
	}
	else {

		for (int i = 0; i < iSizeX; i++) {
			delete piTable[i];
		}
		delete piTable;

		return true;
	}


}