#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"



/* 插入 */
int Insert(lnode *list,int *K,char *V)
{
    int i;
    struct record t;
    struct lnode *n, *r;

    /* 录入记录 */
    /* 判断记录是否已存在，若存在则显示记录，若不存在则添加记录 */
    if((r = FindPrimarykey(list,K)) == NULL)
    {
        /* 申请lnode空间并初始化 */
        Malloc(lnode,n);
        if(n != NULL)
        {
            /* 复制记录 */
            (n->data).KEY=K;
            strcpy((n->data).VALUE,V);
            /* 插入链表 */
            InsertList(list, n);
        }
    }
    else
    {
        DisplayRecord(r);
        return 1;
    }
    return 0;
}

/* 更新 */
int Update(lnode *list,int *FALSE,char *TRUE)
{

    struct record t;
    struct lnode *r, *p;
    p = list;

    if((r = FindPrimarykey(list, FALSE)) != NULL)
    {
        /* 复制记录 */
        strcpy((r->data).VALUE,TRUE);
        printf("update ok!\n");
    }
    else
    {
        printf("Record cann't find!\n");
    }
}

/* 查询 */
int Find(lnode *list,int *INDEX)
{
    struct lnode *r;

    if((r = FindPrimarykey(list, INDEX)) != NULL)
    {
        DisplayRecord(r);
    }
    else
    {
        return 2;
    }
    return 0;
}

/* 删除 */
int Delete(lnode *list,int *INDEX)
{
    struct lnode *q, *p;
    q = list;//q是链表
    p = list->next;//p是链表的下一个

    if(FindPrimarykey(list,INDEX) == NULL)//判断是否存在需要删除的主键
        return 3;
    while(p != NULL)
    {
        if( (p->data).KEY == INDEX) {
            q->next = p->next;
            free(p);    /* 释放空间 */
            return ;    /* 函数返回 */
        }
        q = p;
        p = p->next;
    }
    return 0;
}

/* 显示所有记录 */
int Display(lnode *list)
{
    int c = 0;
    struct lnode *p = list->next;

    printf("\nReaderMessage Display\n");
    while(p != NULL)
    {
        DisplayRecord(p);
        c++;    /* 记录条数 */
        p = p->next;
    }
    printf("\nTotal:  %d  Record(s)\n",c);
}

/* 按主键查找的方法 */
struct lnode *FindPrimarykey(lnode *list, int *key)
{
    struct lnode *p = list->next;


    while (p != NULL)
    {
        if( (p->data).KEY == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/* 插入链表的方法 */
int InsertList(lnode *list,lnode *n)
{
    struct lnode *p = list;

    while (p->next != NULL)
    {
        p = p->next;
    }
    n->next = p->next;
    p->next = n;
}

/* 释放整个链表空间 */
int Clear(lnode *list)
{
    struct lnode *p = list;
    while(p->next != NULL)
    {
        p = p->next;
        free(list);
        list = p;
    }
    free(p);
}

/* 显示一条记录 */
int DisplayRecord(lnode *r)
{
    printf("[%d,\"%s\"]\n", (r->data).KEY, (r->data).VALUE);
}


/* 创建链表 */
lnode* Create_List()
{
    Malloc(lnode,map);
    map->next=NULL;
    return map;
}

/*判断链表是否为空，空返回1，非空返回0*/
inline int Empty(lnode *list)
{
    return list == NULL;
}