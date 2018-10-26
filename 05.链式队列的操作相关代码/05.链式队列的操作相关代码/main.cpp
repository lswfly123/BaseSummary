//
//  main.cpp
//  05.链式队列的操作相关代码
//
//  Created by 李善武 on 2018/10/14.
//  Copyright © 2018年 李善武. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    
    LinkNode *front,*rear;//链表头，链表尾
}LinkQueue;// 先进先出

void InitQueue(LinkQueue &Q){
    
    Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
    
    if (Q.front==Q.rear) {
        return true;
    }else{
        return false;
    }
}

void EnQueue(LinkQueue &Q,ElemType x){
    
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

// 出队 头部删除法
bool DeQueue(LinkQueue &Q,ElemType &x){
    
    if (Q.front == Q.rear) {
        return false;
    }
    LinkNode *p=Q.front->next;//头节点什么都没存，所以头节点的下一个节点才有数据
    x=p->data;
    Q.front->next=p->next;// 断链
    if (Q.rear==p) {// 删除的是最后一个元素
        Q.rear = Q.front;// 队列置为空
    }
    // 修改了部分
    free(p);
    return true;
}

int main(int argc, const char * argv[]) {
    
    LinkQueue Q;
    bool ret;
    ElemType element;//存储出队元素
    InitQueue(Q);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);
    ret = DeQueue(Q, element);
    if (ret) {
        printf("出队成功，元素值为%d\n",element);
    }else{
        printf("出队失败\n");
    }
    system("pause");
}
