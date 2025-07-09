

#ifndef MATHEX_COMMON
#define MATHEX_COMMON 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>

#endif // !MATHEX_COMMON

//#ifndef MATHEX_NODE
#define MATHEX_NODE 1


// types on nodes
#define MATHEX_NODET_NUM 0
#define MATHEX_NODET_OP 1
#define MATHEX_NODET_VAR 2

// operators
#define MATHEX_OPT_ADD 0
#define MATHEX_OPT_SUB 1
#define MATHEX_OPT_MUL 2
#define MATHEX_OPT_DIV 3
#define MATHEX_OPT_POT 4


typedef struct __mathExNode_t {
    uint8_t nodeType;               // object type (operation, variable, data)
    uint8_t opType;                 // operation flag (mult, add, etc.)
    double data;                    // constant value
    uint8_t depth;                  // priority of operation
}mathExNode_t;


// print node type to stderr
void mathExPrintNode(void* element);

// resolve presedence conflicts between two nodes (returns ture when new has priority over comp)
bool mathExResolvePriority(mathExNode_t* new, mathExNode_t*comp);

// create a basic mathExNode
mathExNode_t* mathExCreateNode(uint8_t nodeType, uint8_t operation, double data, uint8_t depth);

// free allocated space
void mathExDestroyNode(mathExNode_t* target);

//#endif // !MATHEX_NODE

