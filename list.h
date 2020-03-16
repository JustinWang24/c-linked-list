//
// Created by Justin Wang on 15/3/20.
//

#ifndef ADT_FILMS_LIST_H
#define ADT_FILMS_LIST_H

#include <stdbool.h> /* C99特性 */

#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef Node* List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);

void Traverse(const List *plist, void (* pfun)(Item item));

void EmptyTheList(List *plist);

#endif //ADT_FILMS_LIST_H
