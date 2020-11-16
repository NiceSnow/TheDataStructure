//
//  sort.c
//  TheDataStructure
//
//  Created by madongdong on 2020/11/14.
//

#include "sort.h"

void bubbleSort(int* a, int n){
    for (int i = 0; i<n; i++) {
        bool flag = false;
        for (int j = 0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = true; // 表示有数据交换
            }
        }
        if (!flag) break; // 没有数据交换，提前退出
    }
    for (int i = 0; i<n; i++) {
        printf("index = %d Value = %d\n",i,a[i]);
    }
}

void insertSort(int* a, int n){
    if (n <= 1) return;
    
    for (int i = 1; i<n; i++) {
        int value = a[i];
        int j = i - 1;
        // 查找插入的位置
        for (; j>=0; j--) {
            if (a[j] > value) {
                a[j+1] = a[j]; // 数据移动
            }else { break; }
        }
        a[j+1] = value; // 插入数据
    }
    
    for (int i = 0; i<n; i++) {
        printf("index = %d Value = %d\n",i,a[i]);
    }
}

void selectSort(int* a, int n) {
    for (int i = 0; i<n; i++) {
        int index = i;
        for (int j = i+1; j<n; j++) {
            if (a[j] < a[index]) {
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
    
    for (int i = 0; i<n; i++) {
        printf("index = %d Value = %d\n",i,a[i]);
    }
}
