#include "mathExParser.h"


void mathExPrint(mathExAgent_t* parser) {

}


mathExAgent_t* mathExInit() {
    mathExAgent_t* new = calloc(1, sizeof(mathExAgent_t));

    if (new == NULL) {
        exit(ENOMEM);
    }

    new->clean = true;
    new->opFlag = true;

    return new;
}



ptrStdTreeNode_t* mathExBuildTree(mathExAgent_t* parser, char* expression, size_t expLen) {
    if (parser == NULL) {
        return NULL;
    }


}


mathExAgent_t* mathExResetAgent(mathExAgent_t* parser) {
    if (parser == NULL) return NULL;

    if (parser->tree != NULL || parser->pos != NULL) {
        ptrStdTreeFree(parser->tree, &mathExDestroyNode);
        ptrStdTreeFree(parser->pos, &mathExDestroyNode);
    }

    memset(parser, '\0', sizeof(mathExAgent_t));

    parser->clean = true;
    parser->opFlag = true;
    return parser;
}


void mathExClose(mathExAgent_t* target) {
    if (target == NULL) {
        return;
    }

    ptrStdTreeFree(target->tree, &mathExDestroyNode);

    free(target);
    return;
}
