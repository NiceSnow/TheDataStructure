//
//  sort.h
//  TheDataStructure
//
//  Created by madongdong on 2020/11/14.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

void PrintArray(int *a, int len);

void bubbleSort(int* a, int n);//冒泡
void insertSort(int* a, int n);//插入
void selectSort(int* a, int n);//选择
void merge_sort(int* arr, int first, int last);//归并排序
#endif /* sort_h */
