

#ifndef MATHEX_COMMON
#define MATHEX_COMMON 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#endif // !MATHEX_COMMON


#ifndef MATHEX_NODE
#define MATHEX_NODE 1

typedef struct __mathExNode_t {
    uint8_t nodeType;               // object type (operation, variable, data)
    uint8_t opType;                 // operation flag (multe, add, etc.)
    double data;                    // constant value
} mathExNode_t;

mathExNode_t* mathExCreateNode();

void mathExDestroyNode(mathExNode_t* target);

#endif // !MATHEX_NODE

