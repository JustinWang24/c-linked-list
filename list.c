//
// Created by Justin Wang on 15/3/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/* 局部函数原型, 作为私有函数使用 */
static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist){
    *plist = NULL;
}

bool ListIsEmpty(const List *plist){
    if(*plist == NULL){
        return true;
    }
    return false;
}

bool ListIsFull(const List *plist){
    Node *pt;
    bool full = false;

    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL){
        // 分配失败
        full = true;
    }

    free(pt);
    return full;
}

unsigned int ListItemCount(const List *plist){
    unsigned int count = 0;
    Node *pnode = *plist;
    while (pnode != NULL){
        ++count;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item, List *plist){
    Node *pnew;
    Node *scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL){
        return false;
    }

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if(scan == NULL){
        *plist = pnew;
    }
    else{
        while (scan->next != NULL){
            scan = scan->next;
        }
        scan->next = pnew;
    }
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item)){
    Node *pnode = *plist;
    int i = 0;
    while (pnode != NULL){
        i++;
        (*pfun)(pnode->item); // 执行回调函数
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist){
    Node *psave;
    while (*plist != NULL){
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(Item item, Node *pnode){
    pnode->item = item;
}