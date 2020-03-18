//
// Created by Justin Wang on 19/3/20.
//
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void EmptyTheQueue(Queue* pq){
    QueueItem dummy;
    while (!QueueIsEmpty(pq)){
        DeQueue(&dummy, pq);
    }
}        // 清空队列

bool DeQueue(QueueItem* pItem, Queue* pq){
    if (QueueIsEmpty(pq)){
        return false;
    }

    QueueNode* pt;
    *pItem = pq->front->item;

    pt = pq->front;
    pq->front = pt->next; // 重置队列的头部
    free(pt);
    pq->items--;

    if(pq->items == 0){
        pq->rear = NULL;
    }

    return true;
} // 出列操作: 从队列头部删除项目

bool EnQueue(QueueItem item, Queue* pq){
    if(QueueIsFull(pq)){
        return false;   // 队列已满
    }

    // 1 创建新节点
    QueueNode* newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if(newNode == NULL){
        fprintf(stderr, "内存不足! \n");
        exit(1);
    }

    // 2 把项目复制到新节点
    newNode->item = item;

    // 3 设置节点的next为空, 表明是最后一个
    newNode->next = NULL;

    if(QueueIsEmpty(pq)){
        // 表示队列是新的，所以当前入列的是第一个项目
        pq->front = newNode;
    } else {
        // 4 设置当前的尾节点的next 指向新节点
        pq->rear->next = newNode;
    }

    // 5 把队列中的rear指向新节点
    pq->rear = newNode;

    // 6 项目总个数加一
    pq->items++;

    return true;
}   // 入列操作: 向队列尾添加项目

void InitializeQueue(Queue* pq){
    EmptyTheQueue(pq); // 先把队列清空
    pq->rear = pq->front = NULL;
    pq->items = 0;
}    // 初始化队列

bool QueueIsFull(const Queue* pq){
    return pq->items == MAX_QUEUE;
}  // 是否队列已满

bool QueueIsEmpty(const Queue* pq){
    return pq->items == 0;
} // 队列是否为空

int QueueItemCount(const Queue* pq){
    return pq->items;
}   // 队列中项目的数量
