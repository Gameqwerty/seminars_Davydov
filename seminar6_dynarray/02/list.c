#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (!p) { fprintf(stderr, "Memory allocation error.\n"); exit(1); }
    return p;
}

static Node* make_node(int value)
{
    Node* nd = (Node*)ecmalloc(sizeof(Node));
    nd->value = value;
    nd->next = NULL;
    nd->prev = NULL;
    return nd;
}

List init(size_t n)
{
    List l;
    l.head = l.tail = NULL;
    l.size = 0;
    for (size_t i = 0; i < n; ++i)
        push_back(&l, 0);
    return l;
}

void print(const List* pl)
{
    for (Node* cur = pl->head; cur != NULL; cur = cur->next)
    {
        printf("%d ", cur->value);
    }
    printf("\n");
}

void push_back(List* pl, int value)
{
    Node* nd = make_node(value);
    if (pl->tail == NULL)
    {
        pl->head = pl->tail = nd;
    }
    else
    {
        nd->prev = pl->tail;
        pl->tail->next = nd;
        pl->tail = nd;
    }
    pl->size += 1;
}

int pop_back(List* pl)
{
    if (pl->tail == NULL)
    {
        fprintf(stderr, "pop_back error: list is empty.\n");
        exit(1);
    }
    Node* last = pl->tail;
    int value = last->value;

    pl->tail = last->prev;
    if (pl->tail)
        pl->tail->next = NULL;
    else
        pl->head = NULL;

    free(last);
    pl->size -= 1;
    return value;
}

void push_front(const List* pl_const, int value)
{
    List* pl = (List*)pl_const;
    Node* nd = make_node(value);
    if (pl->head == NULL)
    {
        pl->head = pl->tail = nd;
    }
    else
    {
        nd->next = pl->head;
        pl->head->prev = nd;
        pl->head = nd;
    }
    pl->size += 1;
}

int pop_front(List* pl)
{
    if (pl->head == NULL)
    {
        fprintf(stderr, "pop_front error: list is empty.\n");
        exit(1);
    }
    Node* first = pl->head;
    int value = first->value;

    pl->head = first->next;
    if (pl->head)
        pl->head->prev = NULL;
    else
        pl->tail = NULL;

    free(first);
    pl->size -= 1;
    return value;
}

Node* erase(List* pl, Node* p)
{
    if (p == NULL) return NULL;

    Node* next = p->next;
    if (p->prev) p->prev->next = p->next;
    else         pl->head = p->next;
    if (p->next) p->next->prev = p->prev;
    else         pl->tail = p->prev;

    free(p);
    pl->size -= 1;
    return next;
}

void splice(List* plist, Node* p, List* pother)
{
    if (pother->size == 0) return;

    Node* first = pother->head;
    Node* last  = pother->tail;
    size_t moved = pother->size;

    if (p == NULL)
    {
        if (plist->tail)
        {
            plist->tail->next = first;
            first->prev = plist->tail;
            plist->tail = last;
        }
        else
        {
            plist->head = first;
            plist->tail = last;
            first->prev = NULL;
        }
    }
    else
    {
        Node* before = p->prev;
        if (before)
        {
            before->next = first;
            first->prev = before;
        }
        else
        {
            plist->head = first;
            first->prev = NULL;
        }
        // connect last <-> p
        last->next = p;
        p->prev = last;
    }

    plist->size += moved;

    pother->head = pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl)
{
    Node* cur = pl->head;
    while (cur)
    {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    pl->head = pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n)
{
    if (pp == NULL) return;
    Node* cur = *pp;
    for (size_t i = 0; i < n; ++i)
    {
        if (cur == NULL) break;
        cur = cur->next;
    }
    *pp = cur;
}
