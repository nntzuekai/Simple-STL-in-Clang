#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#undef DEBUG
#include<stdbool.h>
#include<stddef.h>
#include "item_def.h"

typedef int (*Comparer)(const Item*, const Item*);
typedef void (*Unary_func)(Item *);
typedef void (*Binary_func)(Item *, Item *);
typedef bool (*Pred)(const Item *);
typedef bool (*Binary_pred)(const Item *, const Item *);

struct _node {
    struct _node *prev, *next;
    Item item;
};
typedef struct _node Node;
typedef Node *Iterator;

struct _list {
    Iterator this;
    Iterator head, tail;
    unsigned int count;
    Comparer comp;
};
typedef struct _list List;

List* list_create(List *plist, Comparer comp) ;

Iterator list_iter_incrs(Iterator pt);

Iterator list_iter_decrs(Iterator pt);

Iterator list_riter_incrs(Iterator pt);

Iterator list_riter_decrs(Iterator pt);

bool list_empty(const List *plist);

unsigned int list_size(const List *plist);

Iterator list_begin(const List *plist);

Iterator list_end(const List *plist);

Iterator list_rbegin(const List *plist);

Iterator list_rend(const List *plist);

Item list_front(const List *plist);

Item list_back(const List *plist);

Iterator list_assign(List *Dst, const List *Src);

Iterator list_insert(List *Dst, Iterator pos, const Item item);

Iterator list_erase(List *Dst, Iterator pos);

int list_clear(List *plist);

List* list_destroy(List *plist);

Iterator list_push_front(List *Dst, const Item item);

Iterator list_push_back(List *Dst, const Item item);

Item list_pop_front(List *Src);

Item list_pop_back(List *Src);

int list_swap(List *plist1, List *plist2);

Iterator list_insert2(List *Dst, Iterator pos, Iterator first, Iterator last);

Iterator list_erase2(List *Dst, Iterator first, Iterator last);

bool list_equal(const List *plist1, const List *plist2);

bool list_less(const List *plist1, const List *plist2);

int list_for_each(Iterator first, Iterator last, Unary_func pf);

int list_for_each_reverse(Iterator first, Iterator last, Unary_func pf);

int list_for_all(const List *plist, Unary_func pf);

int list_for_all_reverse(const List *plist, Unary_func pf);

Iterator list_find(const List *plist, const Item *pitem);

Iterator list_find_if(const List *plist, Pred pred);

Item *list_get_item_ptr(Iterator pt);

Item list_get_item(Iterator pt);

Iterator list_resize(List *plist, unsigned int n);

Iterator list_splice(List *Dst, Iterator pos, List *Src);

Iterator list_splice1(List *Dst, Iterator pos, List *Src, Iterator x);

Iterator list_splice2(List *Dst, Iterator pos, List *Src, Iterator first, Iterator last);

Iterator list_remove(List *plist, const Item item);

Iterator list_unique(List *plist);

Iterator list_merge(List *Dst, List *Src);

Iterator list_sort(List *plist);

bool list_is_sorted(List *plist);

#endif // LIST_H_INCLUDED
