
#ifndef MATHEX_COMMON
#define MATHEX_COMMON 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#endif // !MATEX_COMMON
       //

#ifndef MATHEX_ELEMENT
#define MATHEX_ELEMENT 1
typedef enum __mathEx_element_t {
    NUM,
    OP,
    VAR,
    INVALID
}mathEx_element_t;

typedef struct __mathEx_ele {
    
};
#endif // !MATHEX_ELEMENT
