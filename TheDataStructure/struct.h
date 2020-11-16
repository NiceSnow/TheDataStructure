//
//  struct.h
//  TheDataStructure
//
//  Created by madongdong on 2020/11/15.
//

#ifndef struct_h
#define struct_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayStruct {
    int count;
    int* array;
}astruct, *pastruct;

pastruct createArrayStruct(void);
pastruct push(pastruct s,int n);
pastruct pop(pastruct s);

#endif /* struct_h */
