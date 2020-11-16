//
//  List.c
//  TheDataStructure
//
//  Created by madongdong on 2020/11/9.
//

#include "List.h"

//    创建链表函数定义
PNode CreateList(void) {
    int len ;    //    用于定义链表长度
    int val ;    //    用于存放节点数值
    PNode PHead = (PNode)malloc(sizeof(Node));    //    创建分配一个头节点内存空间
    if (PHead == NULL)    //    判断是否分配成功
    {
        printf("空间分配失败 \n");
        exit(-1);
    }

    PNode PTail = PHead;    //    链表的末尾节点，初始指向头节点
    PTail->Next = NULL;    //    最后一个节点指针置为空
    printf("请输入节点个数：");
    scanf("%d", &len);        //    输入节点个数
    for (int i = 0; i < len; i++) {

        PNode PNew = (PNode)malloc(sizeof(Node));    //    分配一个新节点
        if (PNew == NULL) {
            printf("分配新节点失败\n");
            exit(-1);
        }
        printf("请输入第 %d 个节点的数据：", i + 1);
        scanf("%d", &val);    //    输入链表节点的数据

        PNew->Element = val;    //    把数据赋值给节点数据域
        PTail->Next = PNew;    //    末尾节点指针指向下一个新节点
        PNew->Next = NULL;        //    新节点指针指向为空
        PTail = PNew;    //    将新节点复制给末尾节点
    }
    printf("创建链表成功\n");
    return PHead->Next;    //    返回头节点
}

//    定义链表遍历函数
void TraverseList(PNode List) {
    PNode P = List;    //    首节点赋值给临时节点P
    printf("遍历链表的值为：");
    if (P == NULL)
        printf("链表为空");
    while (P != NULL)        //当临时节点P不为尾节点时，输出当前节点值
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

//    定义链表查询函数
PNode FindList(PNode List) {
    PNode P = List->Next;    //    定义临时指针P指向首节点的地址
    int num = 0;    //    用于记录链表节点位置
    int val = 0;    //    用于存放要查询的值
    printf("请输入要查询的数：");
    scanf("%d", &val);    //    输入要查询的数值
    while (P != NULL&&P->Element != val) {
        P = P->Next;
        ++num;
    }
    if (P != NULL)
        printf("找到的节点为：%d", num + 1);
    else
        printf("找不到该节点");
    printf("\n");
    return P;
}
//     定义链表插入函数
//    在链表位置第pos节点前插入包含数据val的节点
void InsertList(PNode List, int pos, int val) {
    int position = 0;
    PNode P = List;    //    定义节点p指向头节点
                    //    寻找pos节点的前驱结点
    while (P != NULL&&position<pos - 1)
    {
        P = P->Next;
        ++position;
    }
    if(NULL == P) {
    printf("no node on pos\n");
    return;
    }
    PNode Tmp = (PNode)malloc(sizeof(Node));    //    分配一个临时节点用来存储要插入的数据
    if (Tmp == NULL)
    {
        printf("内存分配失败！");
        exit(-1);
    }
    //    插入节点
    Tmp->Element = val;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}

//定义删除整个链表函数
void DeleteTheList(PNode List) {
    PNode P, Tmp;
    P = List->Next;    //定义指针P指向链表要删除的链表List的第一个点节点
    List->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;        //临时Tmp指向要删除的节点的下个节点
        free(P);    //释放指针P指向的节点
        P = Tmp;    //重新赋值
    }
    printf("删除链表成功！\n");
}
//    定义删除链表元素函数
//    删除链表中的第pos节点
void DeleteList(PNode List, int pos) {
    int position = 0;
    PNode P = List;    //    定义一个指针p指向链表头节点
                    //    寻找pos节点位置的前驱节点
    while (P != NULL&&position < pos - 1) {
        P = P->Next;
        ++position;
    }

    //    删除节点
    if(NULL == P) {
        printf("No node on pos\n");
        return;
    }
    PNode Tmp = P->Next;    //    定义临时指针Tmp指向要删除的节点
    P->Next = Tmp->Next;    //    使要删除节点的前驱结点指向其后驱节点
    free(Tmp);    //    释放删除节点的内存空间，防止内存泄漏
    Tmp = NULL;    //    使q指向空指针，防止产生野指针
}

PNode ReverseList(PNode List) {
    if (List == NULL) return NULL;
    
    PNode headerNode = (PNode)malloc(sizeof(PNode));
    PNode preNode = NULL;
    PNode curNode = List->Next;
    while (curNode != NULL) {
        PNode nextNode = curNode->Next;
        if (nextNode == NULL) {
            headerNode->Next = curNode;
        }
        curNode->Next = preNode;
        preNode = curNode;
        curNode = nextNode;
    }
    return headerNode;
}

//    环状链表
bool CircleList(PNode List) {
    if (List == NULL) return false;
    PNode fast,slow;
    fast = slow = List->Next;
    while(slow != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
        
        if (fast == NULL) {
            return false;
        }
        
        if(slow == fast){
            return true;
        }
    }
    return false;
}
//两个有序的链表合并
PNode MergeList(PNode List1,PNode List2) {
    PNode header = (PNode)malloc(sizeof(PNode));
    PNode last = header;
    PNode temp1 = List1->Next;
    PNode temp2 = List2->Next;
    
    while (temp1 != NULL && temp2 != NULL) {
        
        if (temp1->Element < temp2->Element) {
            last->Next = temp1;
            last = temp1;
            temp1 = temp1->Next;
        }else {
            last->Next = temp2;
            last = temp2;
            temp2 = temp2->Next;
        }
    }
    last->Next = temp1?temp1:temp2;
    return header;
    
//    struct ListNode head;
//        struct ListNode* pre = &head;
//
//        while (l1 && l2 ) {
//            if (l1->val < l2->val) {
//                pre->next = l1;
//                pre = l1;
//                l1 = l1->next;
//            }else {
//                pre->next = l2;
//                pre = l2;
//                l2 = l2->next;
//            }
//        }
//        pre->next = l1 ? l1 : l2;
//        return head.next;
}

PNode MergeList2(PNode List1,PNode List2) {
    if (List1 == NULL) {
        return List2;
    }
    if (List2 == NULL) {
        return List1;
    }
    if (List1->Element < List2->Element) {
        List1->Next = MergeList2(List1->Next, List2);
        return List1;
    }else{
        List2->Next = MergeList2(List1, List2->Next);
        return List2;
    }
}

PNode deleteNodeAtIndex(PNode List1) {
    int n ;
    printf("请输入要删除倒数第几位：");
    scanf("%d",&n);
    int i = 1;
    Node HeaderNode ;
    PNode pre = &HeaderNode;
    pre->Next = List1;
    PNode last = List1;
    while (last) {
        if (last->Next == NULL) {
            PNode nd = pre->Next;
            pre->Next = pre->Next->Next;
            free(nd);
            return HeaderNode.Next;
        }
        if (i >= n) {
            pre = pre->Next;
            last = last->Next;
        }else{
            last = last->Next;
        }
        ++i;
    }
    return HeaderNode.Next;
    
//    int n ;
//    printf("请输入要删除倒数第几位：");
//    scanf("%d",&n);
//    PNode L = (PNode)malloc(sizeof(PNode));
//    L->Next = List1;
//        //求长度
//        int len=0;
//    PNode temp=List1;
//    while(temp){
//        len++;
//        temp=temp->Next;
//    }
//    //
//    if(n>len){return NULL;}
//    else{
//        temp=L;
//        int i;
//        for(i=1;i<len-n+1;i++){
//            temp=temp->Next;
//        }
//        PNode p=temp->Next;
//        temp->Next=temp->Next->Next;
//        free(p);
//        return L->Next;
//    }
}

PNode middleNode(PNode head){
    PNode fast;
    PNode slow;
    fast =  head;
    slow = head;
    while (slow != NULL&&fast->Next != NULL){
        slow = slow->Next;
        fast = fast->Next->Next;
        
        if (fast == NULL||slow == NULL) {
            return slow->Next;
        }
    }
    return slow;
}
