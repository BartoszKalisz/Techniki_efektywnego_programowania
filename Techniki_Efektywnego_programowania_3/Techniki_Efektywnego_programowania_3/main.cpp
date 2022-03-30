#include "CTreeStatic.h"
#include "CTreeDynamic.h"

int main() {
	std::cout << "Test v_tree_test\n";
	v_tree_test();

	CTreeStatic staticTree;
	staticTree.pcGetRoot()->addNewChild(1);
	staticTree.pcGetRoot()->addNewChild(2);

	CTreeStatic staticTree2;
	staticTree2.pcGetRoot()->addNewChild(1);
	staticTree2.pcGetRoot()->addNewChild(2);
	staticTree2.pcGetRoot()->pcGetChild(0)->addNewChild(11);
	staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->addNewChild(12);

	std::cout << "Test moveSubstree-STATIC\n" << std::endl;
	std::cout << "BEFORE:" << std::endl;
	staticTree.vPrintTree();
	std::cout << "\n";
	staticTree2.vPrintTree();
	std::cout << "\n";

	staticTree.moveSubtree(staticTree.pcGetRoot()->pcGetChild(0), staticTree2.pcGetRoot()->pcGetChild(0));

	std::cout << "AFTER:" << std::endl;
	staticTree.vPrintTree();
	std::cout << "\n";
	staticTree2.vPrintTree();

	CTreeDynamic* dynamicTree = new CTreeDynamic();
	dynamicTree->pcGetRoot()->vSetValue(0);
	dynamicTree->pcGetRoot()->addNewChild(1);
	dynamicTree->pcGetRoot()->addNewChild(2);

	CTreeDynamic* dynamicTree2 = new CTreeDynamic();
	dynamicTree2->pcGetRoot()->vSetValue(0);
	dynamicTree2->pcGetRoot()->addNewChild(1);
	dynamicTree2->pcGetRoot()->addNewChild(2);
	dynamicTree2->pcGetRoot()->getChild(0)->addNewChild(11);

	std::cout << "\nTest moveSubstree-DYNAMIC\n" << std::endl;
	std::cout << " BEFORE:" << std::endl;
	dynamicTree->vPrintTree();
	std::cout << "\n";
	dynamicTree2->vPrintTree();
	std::cout << "\n";

	dynamicTree->moveSubtree(dynamicTree->pcGetRoot()->getChild(0), dynamicTree2->pcGetRoot()->getChild(0));

	std::cout << "AFTER:" << std::endl;
	dynamicTree->vPrintTree();
	std::cout << "\n";
	dynamicTree2->vPrintTree();

	delete dynamicTree;
	delete dynamicTree2;

	return 0;
}
