#pragma once
#include <iostream>
#include <vector>
#include "CNodeDynamic.h"


template<typename T>class CTreeDynamic {
public:
	CTreeDynamic();
	CTreeDynamic(T rootValue);
	~CTreeDynamic();
	
	CNodeDynamic<T>* pcGetRoot() { return(pc_root); }

	bool moveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode);

	void vPrintTree();

private:
	CNodeDynamic<T>* pc_root; 
};

template<typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	pc_root = new CNodeDynamic<T>(); 
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root; 
}

template<typename T>
void CTreeDynamic<T>::vPrintTree()
{
	pc_root->vPrintAllBelow();
}

template<typename T>
bool CTreeDynamic<T>::moveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode)
{
	pc_root->moveSubtree(parentNode, newChildNode);
	return true;
}

template<typename T> CTreeDynamic<T>::CTreeDynamic(T rootValue) {
	pc_root = new CNodeDynamic<T>(rootValue);
}