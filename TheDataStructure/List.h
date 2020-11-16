//
//  List.h
//  TheDataStructure
//
//  Created by madongdong on 2020/11/9.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;        //    定义数据类型,可根据需要进行其他类型定义
                                //    链表节点的定义
typedef struct ListNode {
    struct ListNode* Next;        //    指向下一个链表节点
    ElementType  Element;        //    数据域，存放数据
}Node, *PNode;

//    函数声明
PNode CreateList(void);    //    声明创建链表函数
void TraverseList(PNode List);    //    声明遍历链表函数
void InsertList(PNode List, int pos, int val);        //    声明链表插入函数
void DeleteTheList(PNode List);    //    声明删除整个链表函数
void DeleteList(PNode List, int pos);    //    声明删除链表元素函数
PNode FindList(PNode List);    //    声明链表查询函数

PNode ReverseList(PNode List);    //    反转链表
bool CircleList(PNode List);    //    环状链表
PNode MergeList(PNode List1,PNode List2); //两个有序的链表合并
PNode MergeList2(PNode List1,PNode List2);
PNode deleteNodeAtIndex(PNode List1);

PNode middleNode(PNode head);

#endif /* List_h */
