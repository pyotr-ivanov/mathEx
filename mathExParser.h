
#include "mathExCommon.h"
#include "structs/ptrStdTree.h"
#include "structs/mathExNode.h"
#include "structs/mathExTree.h"


typedef struct __mathExAgent{
    ptrStdTreeNode_t* tree;
    ptrStdTreeNode_t* pos;
    char* expression;
    size_t expLen;
    bool opFlag;
    bool clean;
    char vars[255];
    uint8_t varLen;
    uint8_t depth;
}mathExAgent_t


void mathExPrint(mathExAgent_t* parser);


mathExAgent_t* mathExInit();


ptrStdTreeNode_t* mathExBuildTree(mathExAgent_t* parser, char* expression);


mathExAgent_t* mathExResetAgent(mathExAgent_t* parser);


void mathExClose(mathExAgent_t* target);
