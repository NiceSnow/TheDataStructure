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

//第一个值等于给定值的元素。

int bsearch4(int* a, int n, int value) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid =  low + ((high - low) >> 1);
    if (a[mid] > value) {
      high = mid - 1;
    } else if (a[mid] < value) {
      low = mid + 1;
    } else {
      if ((mid == 0) || (a[mid - 1] != value)) return mid;
      else high = mid - 1;
    }
  }
  return -1;
}

//最后一个值等于给定值

int bsearch5(int* a, int n, int value) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid =  low + ((high - low) >> 1);
    if (a[mid] > value) {
      high = mid - 1;
    } else if (a[mid] < value) {
      low = mid + 1;
    } else {
      if ((mid == n - 1) || (a[mid + 1] != value)) return mid;
      else low = mid + 1;
    }
  }
  return -1;
}

//第一个大于等于给定值的元素

int bsearch6(int* a, int n, int value) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid =  low + ((high - low) >> 1);
    if (a[mid] >= value) {
      if ((mid == 0) || (a[mid - 1] < value)) return mid;
      else high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

//最后一个小于等于给定值的元素

int bsearch7(int* a, int n, int value) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid =  low + ((high - low) >> 1);
    if (a[mid] > value) {
      high = mid - 1;
    } else {
      if ((mid == n - 1) || (a[mid + 1] > value)) return mid;
      else low = mid + 1;
    }
  }
  return -1;
}
