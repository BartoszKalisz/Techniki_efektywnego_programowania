#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
	c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}

void CTreeStatic::moveSubtree(CNodeStatic* parentNode, CNodeStatic* newChildNode)
{
	c_root.moveSubtree(parentNode, newChildNode);
}