#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showMovies(Item item);

void test_list();

int main() {

    test_list();
    return 0;
}

void showMovies(Item item){
    printf("电影名: %s, 评分: %d\n", item.title, item.rating);
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