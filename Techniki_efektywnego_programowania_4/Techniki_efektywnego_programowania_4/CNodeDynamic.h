#pragma once
#include <iostream>
#include <vector>
 template< typename T >class CNodeDynamic {
public:

	CNodeDynamic() { pc_parent_node = NULL; i_val = new T ; } ; 
	CNodeDynamic(T nodeValue) { pc_parent_node = NULL; i_val = nodeValue; }; 
	CNodeDynamic(T nodeValue, CNodeDynamic<T>* parent) { this->pc_parent_node = parent; i_val = nodeValue; }; 

	~CNodeDynamic(); 

	void vSetValue(T iNewVal) { i_val = iNewVal; }; 

	int iGetChildrenNumber() { return(v_children.size()); }; 

	void addNewChild(T childValue); 
	void addNewChild(CNodeDynamic<T>* child); 

	CNodeDynamic<T>* getChild(int iChildOffset); 
	
	void deleteChildren();
	
	void vPrint() { std::cout << " " << i_val; }; 
	void vPrintAllBelow(); 

	bool moveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode);

private:
	std::vector<CNodeDynamic<T>*> v_children; 
	CNodeDynamic<T>* pc_parent_node; 
	T i_val; 
};

 template <typename T>
 CNodeDynamic<T>::~CNodeDynamic()
 {
	 for (int i = 0; i < iGetChildrenNumber(); i++)  
	 {
		 v_children.at(i)->deleteChildren();
	 }
 }

 template <typename T>
 void CNodeDynamic<T>::addNewChild(T childValue)
 {
	
	 v_children.emplace_back(new CNodeDynamic<T>(childValue, this)); 
	 
 }

 template <typename T>
 void CNodeDynamic<T>::addNewChild(CNodeDynamic<T>* NewChild) 
 {
	 v_children.emplace_back(NewChild);
 }

 template <typename T>
 CNodeDynamic<T>* CNodeDynamic<T>::getChild(int offset)
 {
     if (offset >= iGetChildrenNumber() || offset < 0)   
     {
         return NULL;
     }
     return v_children[offset];
 }

 template <typename T>
 void CNodeDynamic<T>::deleteChildren()
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

 template <typename T>
 void CNodeDynamic<T>::vPrintAllBelow() {
	 vPrint();
	 for (int i = 0; i < v_children.size(); i++) {
		 v_children.at(i)->vPrintAllBelow();
	 }
 }

 template <typename T>
 bool CNodeDynamic<T>::moveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode)
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