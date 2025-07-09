
#include "mathExCommon.h"
#include "structs/ptrStdTree.h"
#include "structs/mathExNode.h"
#include "structs/mathExTree.h"


typedef struct __mathExAgent{
    ptrStdTreeNode_t* tree;
    bool opFlag;
    char vars[255];
    uint8_t vars_len;
}mathExAgent_t

void mathExPrint(mathExAgent_t* parser);

mathExAgent_t* mathExInit();
