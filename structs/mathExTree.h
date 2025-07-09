

#ifndef MATHEX_COMMON
#define MATHEX_COMMON 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#endif // !MATHEX_COMMON

#ifndef PTRSTD_COMMON
#include "ptrStdTree.h"
#endif // !


#include "mathExNode.h"
// insert a mathExNode inot the parsing tree
ptrStdTreeNode_t* mathExTreeInsert(ptrStdTreeNode_t* pos, uint8_t type, uint8_t operator, double data, uint8_t depth);
