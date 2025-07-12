#include "mathExParser.h"


void mathExPrint(mathExAgent_t* parser) {

}


mathExAgent_t* mathExInit() {
    mathExAgent_t* new = calloc(1, sizeof(mathExAgent_t));

    if (new == NULL) {
        exit(ENOMEM);
    }

    new->clean = true;
    new->opFlag = false;

    return new;
}


void mathExAddNode(mathExAgent_t* parser, uint8_t type, uint8_t operation, double data) {
    if (parser == NULL) {
        return;
    }

    parser->pos = mathExTreeInsert(parser->pos, type, operation, data, parser->depth);

    if (parser->tree == NULL || (parser->pos->depth < parser->tree->depth)) {
        parser->tree = parser->pos;
    }

    return;
}


ptrStdTreeNode_t* mathExBuildTree(mathExAgent_t* parser, char* expression, size_t expLen) {
    if (parser == NULL) {
        return NULL;
    } else if (parser->clean == false || expression == NULL) {
        return parser;
    }
    parser->expression = expression;
    parser->expLen = expLen;

    size_t i = 0;
    while (*(parser->expression + i) != '\0' && i < parser->expLen) {   

        if (*(parser->expression + i) == '(') {
            if (parser->opFlag == false && parser->clean == false) {            // add multiplication
                mathExAddNode(parser, MATHEX_NODET_OP, MATHEX_OPT_MUL, 0.0);
            }
            parser->depth = parser->depth + 1;

        } else if (*(parser->expression + i) == ')') {
            parser->depth = parser->depth - 1;

        } else if (*(parser->expression + i) == '+') {
            mathExAddNode(parser, MATHEX_NODET_OP, MATHEX_OPT_ADD, 0.0);

        } else if (*(parser->expression + i) == '-') {
            mathExAddNode(parser, MATHEX_NODET_OP, MATHEX_OPT_SUB, 0.0);

        } else if (*(parser->expression + 1) == '*') {
            if (*(parser->expression + i + 1) == '*') {
                i++;
                mathExAddNode(parser, MATHEX_NODET_OP, MATHEX_OPT_POT, 0.0);
            } else {
                mathExAddNode(parser, MATHEX_NODET_OP, MATHEX_OPT_MUL, 0.0);
            }

        } else if (*(parser->expression + i) == '/') {
            mathExAddNode(parser, MATHEX_NODET_OP, MATHEX_OPT_DIV);

        } else if (isalpha(parser->expression + i) != 0) {
            // TODO:: Add logic for variables

        } else if (isdigit(parser->expression + i) != 0) {
            // TODO:: Add logic for parsing values

        } else {
            i++;
            continue;
        }

        parser->clean = false;
        i++;
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
    parser->opFlag = false;
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
