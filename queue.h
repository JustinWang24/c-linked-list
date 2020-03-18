//
// Created by Justin Wang on 18/3/20.
//

#ifndef ADT_FILMS_QUEUE_H
#define ADT_FILMS_QUEUE_H

#include <stdbool.h>

#define HASH_LEN 48
#define MAX_QUEUE 100

struct queue_item {   // 其实可以是任意的数据结构
    char uuid[HASH_LEN];    // UUID
    char* value;            // 序列话的值
};
typedef struct queue_item QueueItem;

typedef struct queue_node
{
    QueueItem item;
    struct node* next;
} QueueNode;

typedef struct queue
{
    QueueNode* front;    // 队列头
    QueueNode* rear;     // 队列尾
    int items;      // 元素的个数
} Queue;

void InitializeQueue(Queue* pq);    // 初始化队列
bool QueueIsFull(const Queue* pq);  // 是否队列已满
bool QueueIsEmpty(const Queue* pq); // 队列是否为空
int QueueItemCount(const Queue* pq);// 队列中项目的数量
bool EnQueue(QueueItem item, Queue* pq); // 入列操作: 向队列尾添加项目
bool DeQueue(QueueItem* pItem, Queue* pq); // 出列操作: 从队列头部删除项目
void EmptyTheQueue(Queue* pq);        // 清空队列

#endif //ADT_FILMS_QUEUE_H
