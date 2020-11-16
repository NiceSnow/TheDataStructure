//
//  main.c
//  TheDataStructure
//
//  Created by madongdong on 2020/11/8.
//

#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "struct.h"
#include "sort.h"

//    主函数
int main() {
    int a[5] = {6,5,12,3,5};
//    bubbleSort(a, 5);
    selectSort(a, 5);
    return 0;
}


