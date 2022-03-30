#include "CNodeStatic.h"

CNodeStatic::~CNodeStatic() {

}

CNodeStatic::CNodeStatic(int iNewVal)
{
	pc_parent_node = NULL;
	this->i_val = iNewVal;
}

CNodeStatic::CNodeStatic(int iNewVAl, CNodeStatic* parent)
{
	this->pc_parent_node = parent;
	this->i_val = iNewVAl;
}

void CNodeStatic::vAddNewChild() {
	CNodeStatic NewChild = CNodeStatic();
	NewChild.pc_parent_node = this;
	v_children.push_back(NewChild);

}

void CNodeStatic::addNewChild(int childValue)
{
	CNodeStatic NewChild(childValue, this);
	v_children.emplace_back(NewChild);
}

void CNodeStatic::addNewChild(CNodeStatic* NewChild)
{
	v_children.emplace_back(*NewChild);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if ((0 <= iChildOffset) && (iChildOffset < v_children.size())) {
		return &v_children.at(iChildOffset);
	}

	return NULL;
}

void CNodeStatic::vPrintAllBelow() {
	vPrint();

	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i).vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}

bool CNodeStatic::moveSubtree(CNodeStatic* parentNode, CNodeStatic* newChildNode)
{
	if (parentNode == NULL || newChildNode == NULL)
	{
		return false;
	}

	parentNode->addNewChild(newChildNode);

	if (newChildNode->pc_parent_node != NULL)
	{
		int index;
		for (int i = 0; i < newChildNode->pc_parent_node->iGetChildrenNumber(); i++)
		{
			if (&(newChildNode->pc_parent_node->v_children.at(i)) == newChildNode)
			{
				index = i;
				break;
			}
		}
		newChildNode->pc_parent_node->v_children.erase(newChildNode->pc_parent_node->v_children.begin() + index);
	}

	newChildNode->pc_parent_node = parentNode;
	return true;
}

void v_tree_test()
{
	CNodeStatic cRoot;
	cRoot.vAddNewChild();
	cRoot.vAddNewChild();
	cRoot.pcGetChild(0)->vSetValue(1);
	cRoot.pcGetChild(1)->vSetValue(2);
	cRoot.pcGetChild(0)->vAddNewChild();
	cRoot.pcGetChild(0)->vAddNewChild();
	cRoot.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	cRoot.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	cRoot.pcGetChild(1)->vAddNewChild();
	cRoot.pcGetChild(1)->vAddNewChild();
	cRoot.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	cRoot.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	cRoot.vPrintAllBelow();
	std::cout << "\n";
	cRoot.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	std::cout << "\n";
}