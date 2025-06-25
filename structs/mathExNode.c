

#include "mathExNode.h"


mathExNode_t* mathExCreateNode(uint8_t nodeType, uint8_t operation, double data) {
    mathExNode_t* new = calloc(1, sizeof(mathExNode_t));
    if (new == NULL) {
        exit(ENOMEM);
    }

    new->nodeType = nodeType;
    new->opType = operation;
    new->data = data;
    return new;
}

void mathExDestroyNode(mathExNode_t* target) {
    free(target);
}
