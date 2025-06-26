

#include "mathExNode.h"


void mathExPrintNode(void* element) {
    if (element == NULL) {
        fprintf(stderr, "NULL");
        return;
    }

    mathExNode_t* target = element;

    else {
        if (target->nodeType == MATHEX_NODET_NUM) {         // target holds double
            fprintf(stderr, "NUM");
        } else if (target->nodeType == MATHEX_NODET_OP){    // target is operator
            if (target->opType == MATHEX_OPT_ADD) {
                fprintf(stderr, "ADD");
            } else if (target->opType == MATHEX_OPT_MULT){
                fprintf(stderr, "MUL");
            } else {
                fprintf(stderr, "INV");
            }
        } else {                                            // target is variable
            fprintf(stderr, "v_%d", target->opType);
        }
    }
}

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
