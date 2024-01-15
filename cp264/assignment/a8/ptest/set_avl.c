/*--------------------------------------------------
Project: cp264-a7q2
File:    set_avl.c
Author:  Shawn Phung
Version: 2023-03-02
--------------------------------------------------
*/
#include "avl.h"
#include "set_avl.h"

int size(SET *s) {
    return s->size;
}

int contains_element(SET *s, char *e){
    return (search_avl(s->root, e))? 1:0;
}

void add_element(SET *s, char *e)
{
    if(contains_element(s, e) == 0){
        insert_avl(&s->root, e, 0);
        s->size++;
    }
}

void remove_element(SET *s, char *e)
{
    if(contains_element(s, e) == 1){
        delete_avl(&s->root, e);
        s->size--;
    }
}

void clear_set(SET *s){
    if(s != NULL) clear_tree(&s->root);
    s->size = 0;
}   
