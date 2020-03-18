//
// Created by Justin Wang on 19/3/20.
//

#ifndef ADT_FILMS_TREE_H
#define ADT_FILMS_TREE_H

#include <stdbool.h>

struct tree_item {
    long id;
    char name[30];
};
typedef struct tree_item TreeItem;

typedef struct tree_node
{
    TreeItem item;
    struct tree_node* left;
    struct tree_node* right;
} TreeNode;

typedef struct tree
{
    TreeNode* root;
    int size;
} Tree;

void InitializeQueue(Tree* pTree);      // 初始化树
bool TreeIsFull(const Tree* pTree);     // 是否树已满
bool TreeIsEmpty(const Tree* pTree);    // 树是否为空
int TreeItemCount(const Tree* pTree);
bool AddItem(const TreeItem* item, Tree* pTree);
bool InTree(const TreeItem* item, const Tree* pTree);
bool DeleteItem(const TreeItem* item, const Tree* pTree);
bool TreeTraverse(const Tree* pTree, void (* pFunc)(TreeItem item));
void DeleteTree(Tree* pTree);

#endif //ADT_FILMS_TREE_H
