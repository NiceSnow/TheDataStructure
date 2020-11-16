//
//  struct.c
//  TheDataStructure
//
//  Created by madongdong on 2020/11/15.
//

#include "struct.h"
int a[5];

pastruct createArrayStruct(void){
    pastruct myStruct = (pastruct)malloc(sizeof(pastruct));
    myStruct->count = 0;
    myStruct->array = a;
    return myStruct;
}

pastruct push(pastruct s,int n){
    s->array[s->count] = n;
    s->count ++;
    printf("count = %d,top = %d\n",s->count,s->array[s->count -1]);
    return s;
}
pastruct pop(pastruct s){
    s->array[s->count-1] = 0;
    s->count --;
    printf("count = %d,top = %d\n",s->count,s->array[s->count-1]);
    return s;
}




