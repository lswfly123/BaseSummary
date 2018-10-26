//
//  main.cpp
//  04.栈的操作、循环队列的操作练习
//
//  Created by 李善武 on 2018/10/14.
//  Copyright © 2018年 李善武. All rights reserved.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
    
    ElemType data[MaxSize];// 数组
    int top;
}SqStack;
typedef struct {
    
    ElemType data[MaxSize];// 数组，存储MaxSize-1个元素
    int front,rear;// 队列头，队列尾
}SqQueue;

void InitStack(SqStack &S){
    
    S.top = -1;// 代表栈为空
}

bool StackEmpty(SqStack &S){
    
    if (S.top == -1) {
        
        return true;
    }else{
        
        return false;
    }
}

// 入栈
bool Push(SqStack &S,ElemType x){
    
    if (S.top==MaxSize-1) {// 数组的大小不能改变，避免访问越界
        return false;
    }
    S.data[++S.top]=x;
    return true;
}

// 出栈
bool Pop(SqStack &S,ElemType &x){
    
    if (-1==S.top) {
        return false;
    }
    x=S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack &S,ElemType &x){
    
    if (-1==S.top) {// 空栈
        return false;
    }
    x=S.data[S.top];
    return true;
}




/**************************循环队列练习*********************************/
void InitQueue(SqQueue &Q){
    
    Q.rear=Q.front=0;
}

// 判空
bool isEmpty(SqQueue &Q){
    
    if (Q.rear==Q.front) {// 不需要为零
        
        return true;
    }else{
        
        return false;
    }
}

// 入队
bool EnQueue(SqQueue &Q,ElemType x){
    
    if ((Q.rear+1)%MaxSize==Q.front) {// 判断是否队满
        
        return false;
    }
    Q.data[Q.rear]=x;//
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q,ElemType &x){
    
    if (Q.rear==Q.front) {
        return false;
    }
    x=Q.data[Q.front];// 先进先出
    Q.front = (Q.front+1)%MaxSize;
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    SqStack S;
    bool flag;
    ElemType m;//用来存放拿出的元素
    InitStack(S);// 初始化
    flag=StackEmpty(S);
    if (flag) {
        printf("栈是空的\n");
    }
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    flag=GetTop(S, m);// 获取栈顶元素
    if (flag) {
        printf("获取栈顶元素为%d\n",m);
    }
    printf("************循环队列练习************\n");
    SqQueue Q;
    bool ret;//存储返回值
    ElemType element;//存储出队元素
    InitQueue(Q);
    ret=isEmpty(Q);
    if (ret) {
        
        printf("队列为空\n");
    }else{
        
        printf("队列不为空\n");
    }
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    ret=EnQueue(Q, 6);
    ret=EnQueue(Q, 7);
    if (ret) {
        
        printf("入队成功\n");
    }else{
        
        printf("入队失败\n");
    }
    ret = DeQueue(Q, element);
    if (ret) {
        
        printf("出队成功，元素值为%d\n",element);
    }else{
        
        printf("出队失败\n");
    }
    ret=EnQueue(Q, 8);
    if(ret)
    {
        printf("入队成功\n");
    }else{
        printf("入队失败\n");
    }
    return 0;
}


