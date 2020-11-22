//
//  binarySearch.c
//  TheDataStructure
//
//  Created by madongdong on 2020/11/22.
//

#include "binarySearch.h"


// 二分查找的递归实现

int binarySearch (int* arr,int low, int high ,int val) {
    
    if (low >high) return -1;
    int mid = low +(high - low)/2;
    if (arr[mid] == val) {
        return mid;
    }else if (arr[mid] < val){
        return binarySearch(arr, mid+1, high,val);
    }else {
        return binarySearch(arr, low, mid - 1,val);
    }
}
