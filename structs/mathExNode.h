

#ifndef MATHEX_COMMON
#define MATHEX_COMMON 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#endif // !MATHEX_COMMON


//#ifndef MATHEX_NODE
#define MATHEX_NODE 1


// types on nodes
#define MATHEX_NODET_NUM 0
#define MATHEX_NODET_OP 1
#define MATHEX_NODET_VAR 2

// operators
#define MATHEX_OPT_ADD 0
#define MATHEX_OPT_MULT 2


typedef struct __mathExNode_t {
    uint8_t nodeType;               // object type (operation, variable, data)
    uint8_t opType;                 // operation flag (mult, add, etc.)
    double data;                    // constant value
}mathExNode_t;

void mathExPrintNode(void* element);

mathExNode_t* mathExCreateNode(uint8_t nodeType, uint8_t operation, double data);

void mathExDestroyNode(mathExNode_t* target);

//#endif // !MATHEX_NODE

