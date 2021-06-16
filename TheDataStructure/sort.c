//
//  sort.c
//  TheDataStructure
//
//  Created by madongdong on 2020/11/14.
//

#include "sort.h"

void Swap(int *p, int *q)
{
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}
//打印数组
void PrintArray(int *a, int len)
{
    assert(a);
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void bubbleSort(int* a, int n){
    for (int i = 0; i<n; i++) {
        bool flag = false;
        for (int j = 0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                Swap(&a[j], &a[j+1]);
                flag = true; // 表示有数据交换
            }
        }
        if (!flag) break; // 没有数据交换，提前退出
    }
    PrintArray(a, n);
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
    
    PrintArray(a, n);
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
    
    PrintArray(a, n);
}


//归并排序
void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;

    for(k=0; left_low<=left_high && right_low<=right_high; k++){  // 比较两个指针所指向的元素
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = arr[i];
    }

    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }

    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
    return;
}

//归并排序
void merge_sort(int* arr, int first, int last){
    int mid = 0;
    if(first<last){
        mid = (first+last)/2; /* 注意防止溢出 */
        /*mid = first/2 + last/2;*/
        //mid = (first & last) + ((first ^ last) >> 1);
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
    return;
}

int quick_partition(int* arr,int first,int last){
    PrintArray(arr, 9);
    int pivot = arr[last];
    int i = first;
    for (int j = first; j<last; j++) {
        if (arr[j] < pivot) {
            Swap(&arr[i], &arr[j]);
            PrintArray(arr, 9);
            i++;
        }
    }
    Swap(&arr[i], &arr[last]);
    PrintArray(arr, 9);
    return i;
}

void quick_sort(int* arr, int first, int last) {
    if (first >= last) {
        return;
    }
    int mid = quick_partition(arr, first, last);
    quick_sort(arr, first, mid-1);
    quick_sort(arr, mid+1, last);
}


