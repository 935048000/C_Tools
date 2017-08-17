#ifndef	MAP_H
#define	MAP_H

#define MAXMEAN 11

extern struct record;
extern struct lnode;

//数据结构
typedef struct record {
    int KEY;
    char VALUE[MAXMEAN+1];
}record;

//结点结构
typedef struct lnode {
    struct record data;
    struct lnode *next;
}lnode;


//extern struct lnode *map;

/*申请内存*/
#ifndef Malloc
#define Malloc(type,obj) type* obj = (type*)malloc(sizeof(type))
#endif // Malloc

/* 函数声明 */
extern  int Insert(lnode *list,int *K,char *V);/* 添加 */
extern  int Find(lnode *list,int *INDEX);/* 查找 */
extern  int Update(lnode *list,int *FALSE,char *TRUE);/* 修改 */
extern  int Delete(lnode *list,int *INDEX);/* 删除 */
extern  int Display(lnode *list);/* 显示所有记录 */
extern  lnode *FindPrimarykey(lnode *list, int *key);/* 主键查找方法 */
extern  int InsertList(lnode *list,lnode *n);/* 插入链表 */
extern  int Clear(lnode *list);/* 释放整个链表空间 */
extern  int DisplayRecord(lnode *r);/* 显示一条记录 */
extern  lnode* Create_List();/* 创建链表 */
extern  int Empty(lnode *list);/*判断链表是否为空*/

#endif // MAP_H
