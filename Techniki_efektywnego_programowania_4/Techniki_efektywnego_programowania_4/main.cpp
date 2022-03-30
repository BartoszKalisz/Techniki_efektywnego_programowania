#include "CTreeStatic.h"
#include "CTreeDynamic.h"

int main() {
	//Testy dzewa statycznego z listy 3
	/*
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
	 */

	CTreeDynamic<int> dynamicTree(0);
	
	dynamicTree.pcGetRoot()->addNewChild(1);
	dynamicTree.pcGetRoot()->addNewChild(2);
	dynamicTree.pcGetRoot()->getChild(0)->addNewChild(11);
	dynamicTree.pcGetRoot()->getChild(0)->getChild(0)->addNewChild(111);

	CTreeDynamic<int> dynamicTree2(0);
	dynamicTree2.pcGetRoot()->addNewChild(1);
	dynamicTree2.pcGetRoot()->addNewChild(2);
	dynamicTree2.pcGetRoot()->getChild(0)->addNewChild(11);
	dynamicTree2.pcGetRoot()->getChild(0)->getChild(0)->addNewChild(111);

	std::cout << "\nTest moveSubstree-DYNAMIC\n" << std::endl;
	std::cout << " BEFORE:" << std::endl;
	dynamicTree.vPrintTree();
	std::cout << "\n";
	dynamicTree2.vPrintTree();
	std::cout << "\n";

	dynamicTree.moveSubtree(dynamicTree.pcGetRoot()->getChild(0), dynamicTree2.pcGetRoot()->getChild(0));

	std::cout << "AFTER:" << std::endl;
	dynamicTree.vPrintTree();
	std::cout << "\n";
	dynamicTree2.vPrintTree();

	std::cout << "\n";
	std::cout << "\nTest DYNAMICTREE-STRING\n";

	CTreeDynamic<std::string> stringTree("ROOT");
	stringTree.pcGetRoot()->addNewChild("FIRST_NODE");
	stringTree.pcGetRoot()->addNewChild("SECEND_NODE");
	stringTree.vPrintTree();

	std::cout << "\n";
	std::cout << "\nTest DYNAMICTREE-DOUBLE\n";

	double d_my_doub = 5;
	CTreeDynamic<double*> doubleTree(&d_my_doub);
	doubleTree.vPrintTree();

	return 0;
}
