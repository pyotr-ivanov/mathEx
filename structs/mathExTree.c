

#include "mathExTree.h"


ptrStdTreeNode_t* mathExTreeInsert(ptrStdTreeNode_t* pos, uint8_t type, uint8_t operator, double data, uint8_t depth) {
    ptrStdTreeNode_t* insert;
    mathExNode_t* element = NULL;

    if (insert != NULL) {
        element = (mathExNode_t*) ptrStdTreeGetContent(insert);
    }

    mathExNode_t* new = mathExCreateNode(type, operator, data, depth);
    ptrStdTreeNode_t* branch = ptrStdTreeCreateNode(new);

    if (insert == NULL) {                       // tree is empty
        return branch;
    }

    while (new->depth <= element->depth || !mathExResolvePriority(new, insert)) { // climb up tree until new has precedence over insert or new is root
        if (insert->parent == NULL) {   // insert new as new root
            insert->parent = branch;
            branch->child_l = insert;
            return branch;
        }

        insert = insert->parent;
        element = ptrStdTreeGetContent(insert);
    }

    branch->child_l = insert->child_h;
    if (branch->child_l != NULL) {
        branch->child_l->parent = branch;
    }

    insert->child_h = branch;
    branch->parent = insert;
    return branch;
}
