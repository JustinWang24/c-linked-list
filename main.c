#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

void showMovies(Item item);

void test_list();
void test_queue();

int main() {

//    test_list();
    test_queue();
    return 0;
}

void showMovies(Item item){
    printf("电影名: %s, 评分: %d\n", item.title, item.rating);
}

/**
 * 测试队列
 */
void test_queue(){
    Queue line;
    QueueItem temp, temp2, temp3;
    QueueItem currentItem;

    InitializeQueue(&line);
    temp.uuid[0] = 'a';
    temp.value = "json 1";
    temp2.uuid[0] = 'b';
    temp2.value = "json 2";
    temp3.uuid[0] = 'b';
    temp3.value = "json 3";

    // 测试入列
    printf("队列是否为空? %s\n", QueueIsEmpty(&line) ? "Yes" : "No");

    EnQueue(temp, &line);
    printf("队列是否为空? %s\n", QueueIsEmpty(&line) ? "Yes" : "No");
    printf("队列元素数: %d\n", QueueItemCount(&line));

    EnQueue(temp2, &line);
    EnQueue(temp3, &line);
    printf("队列元素数: %d\n", QueueItemCount(&line));

    DeQueue(&currentItem, &line);
    printf("出列元素: %s\n", currentItem.value);
    printf("队列元素数: %d\n", QueueItemCount(&line));

    DeQueue(&currentItem, &line);
    printf("出列元素: %s\n", currentItem.value);
    printf("队列元素数: %d\n", QueueItemCount(&line));

    DeQueue(&currentItem, &line);
    printf("出列元素: %s\n", currentItem.value);
    printf("队列元素数: %d\n", QueueItemCount(&line));

    EmptyTheQueue(&line);
}

void test_list(){
    List movies; // Node* movies
    Item temp;   // struct film temp

    InitializeList(&movies);

    if(ListIsFull(&movies)){
        fprintf(stderr, "没有足够内存了");
        exit(1);
    }

    /**
     * 通过命令行收集数据
     */
    puts("请输入第一步电影的名称: ");
    while (gets(temp.title) != NULL && temp.title[0] != '\0'){
        puts("请输入您的评级 <0 - 10>: ");
        scanf("%d", &temp.rating);

        while (getchar() != '\n'){
            continue;
        }

        if(AddItem(temp, &movies) == false){
            fprintf(stderr, "添加新记录失败");
            break;
        }

        if(ListIsFull(&movies)){
            puts("列表已经没有空间");
            break;
        }

        puts("请输入下一部电影名称: ");
    }

    if(ListIsEmpty(&movies)){
        printf("没有输入任何数据. \n");
    } else {
        printf("影片列表: \n");
        Traverse(&movies, showMovies);
    }

    printf("您输入了%d部电影\n", ListItemCount(&movies));

    /**
     * 清除
     */
    EmptyTheList(&movies);
    printf("再见\n");
}