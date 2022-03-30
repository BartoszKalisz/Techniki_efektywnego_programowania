#include "CNodeDynamic.h"

CNodeDynamic::CNodeDynamic()
{
    pc_parent_node = NULL;
    i_val = 0;
}

CNodeDynamic::CNodeDynamic(int nodeValue)
{
    pc_parent_node = NULL;
    i_val = nodeValue;
}

CNodeDynamic::CNodeDynamic(int nodeValue, CNodeDynamic* parent)
{
    this->pc_parent_node = parent;
    i_val = nodeValue;
}

CNodeDynamic::~CNodeDynamic()
{
    for (int i = 0; i < iGetChildrenNumber(); i++)
    {
        v_children.at(i)->deleteChildren();
    }
}

void CNodeDynamic::deleteChildren()
{
    for (int i = 0; i < iGetChildrenNumber(); i++)
    {
        if (v_children.at(i)->iGetChildrenNumber() != 0)
        {
            v_children.at(i)->deleteChildren();
        }
        delete v_children.at(i);
    }
}

void CNodeDynamic::addNewChild(int childValue)
{
    v_children.emplace_back(new CNodeDynamic(childValue, this));
}

void CNodeDynamic::addNewChild(CNodeDynamic* NewChild)
{
    v_children.emplace_back(NewChild);
}

CNodeDynamic* CNodeDynamic::getChild(int offset)
{
    if (offset >= iGetChildrenNumber() || offset < 0)
    {
        return NULL;
    }
    return v_children[offset];
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++) {
        v_children.at(i)->vPrintAllBelow();
    }
}

bool CNodeDynamic::moveSubtree(CNodeDynamic* parentNode, CNodeDynamic* newChildNode)
{
    if (parentNode == NULL || newChildNode == NULL)
    {
        return false;
    }

    parentNode->addNewChild(newChildNode);

    if (newChildNode->pc_parent_node != NULL)
    {
        int index;
        for (int i = 0; i < newChildNode->pc_parent_node->v_children.size(); i++)
        {
            if (newChildNode->pc_parent_node->v_children.at(i) == newChildNode)
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