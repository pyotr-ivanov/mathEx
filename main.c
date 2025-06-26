// just some basic testing
//
//

#include "mathExCommon.h"
#include "structs/ptrStdTree.h"
#include "structs/mathExNode.h"

bool addLow (void* a, void* b) {
    return false;
}

bool addHigh (void*, void* b) {
    return true;
}


int main(int argc, char *argv[]) {

    // create test nodes
    mathExNode_t* root = mathExCreateNode(MATHEX_NODET_OP, MATHEX_OPT_ADD, 0);
    mathExNode_t* child_l = mathExCreateNode(MATHEX_NODET_NUM, 0, 1.0);
    mathExNode_t* child_h = mathExCreateNode(MATHEX_NODET_NUM, 0, 2.0);

    // insert nodes into tree 
    ptrStdTreeNode_t* tree = ptrStdTreeCreateNode(root);
    ptrStdTreeAppend(tree, &addLow, child_l);
    ptrStdTreeAppend(tree, &addHigh, child_h);

    ptrStdTreePrintTree(tree, &mathExPrintNode);
    return EXIT_SUCCESS;
}
