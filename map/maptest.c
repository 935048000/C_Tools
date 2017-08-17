#include <stdio.h>
#include <malloc.h>
#include "map.h"

lnode *map;

/* 主程序 */
int main(lnode *list)
{
    if(Empty(map) == 1)
    map=Create_List();


    Insert(map,111,"aaaa");
    Insert(map,222,"bbbb");
    Insert(map,333,"cccc");

    Display(map);

    printf("\n-------find key------------\n");
    Find(map,111);

    printf("\n--------delete key------------\n");
    //delete(map,222);
    //Display(map);

    printf("\n--------update key------------\n");
    Update(map,111,"AAAAAAAAAA");
    Display(map);

    Clear(map);
    return 0;
}
