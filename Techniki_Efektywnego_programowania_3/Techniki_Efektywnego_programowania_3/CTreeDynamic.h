#pragma once
#include <iostream>
#include <vector>
#include "CNodeDynamic.h"


class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic* pcGetRoot() { return(pc_root); }

	bool moveSubtree(CNodeDynamic* parentNode, CNodeDynamic* newChildNode);

	void vPrintTree();

private:
	CNodeDynamic* pc_root;
};