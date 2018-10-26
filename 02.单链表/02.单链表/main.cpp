//
//  main.cpp
//  02.单链表
//
//  Created by 51pgzs on 2018/10/15.
//  Copyright © 2018年 xuehuaqi. All rights reserved.
//

#include <iostream>
typedef int ElemType;
typedef struct LNode{
    
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
// 头插法新建链表
LinkList CreateList1(LinkList &L){
    
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while (x!=9999) {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        
    }
}
int main(int argc, const char * argv[]) {
    
    
    return 0;
}
