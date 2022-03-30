#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic()
{
    pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic()
{
    delete pc_root;
}

void CTreeDynamic::vPrintTree()
{
    pc_root->vPrintAllBelow();
}

bool CTreeDynamic::moveSubtree(CNodeDynamic* parentNode, CNodeDynamic* newChildNode)
{
    pc_root->moveSubtree(parentNode, newChildNode);
    return true;
}
