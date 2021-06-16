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
#include "binarySearch.h"
#include "tree.h"
#include "test.h"

//    主函数
int main() {
//    int a[5] = {6,5,12,3,5};
//    bubbleSort(a, 5);
//    selectSort(a, 5);
    
    int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 ,5};
//    merge_sort(a, 0, sizeof(a) / sizeof(int)-1);
    quick_sort(a, 0, sizeof(a) / sizeof(int)-1);
//    PrintArray(a, sizeof(a) / sizeof(int));
//    int a[] = { 1,2,4,5,6,7,9};
//    int index = binarySearch(a, 0, sizeof(a) / sizeof(int), 10);
//    printf("index = %d\n",index);
//    int x = pos_num(9, 2);
//    printf("x = %d\n",x);
//    int y = pos_num1(9,2);
//    printf("y = %d\n",y);
//    int z = bottlesOfDrinks(6, 0, 0, 0);
//    printf("z = %d\n",z);
    return 0;
}


