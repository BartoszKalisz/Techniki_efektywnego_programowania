#pragma once
#include <iostream>
#include <vector>
class CNodeDynamic {
public:

	CNodeDynamic();
	CNodeDynamic(int nodeValue);
	CNodeDynamic(int nodeValue, CNodeDynamic* parent);

	~CNodeDynamic();

	void vSetValue(int iNewVal) { i_val = iNewVal; };

	int iGetChildrenNumber() { return(v_children.size()); };

	void addNewChild(int childValue);
	void addNewChild(CNodeDynamic* child);

	CNodeDynamic* getChild(int iChildOffset);

	void deleteChildren();

	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();

	bool moveSubtree(CNodeDynamic* parentNode, CNodeDynamic* newChildNode);


private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
};
