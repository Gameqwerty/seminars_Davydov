#pragma once
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void* list_ecmalloc(size_t n) {
    void* p = malloc(n);
    if (!p) { fprintf(stderr, "Memory allocation error.\n"); exit(1); }
    return p;
}

#define DECLARE_LIST(type) \
typedef struct node_##type { \
    type value; \
    struct node_##type* next; \
    struct node_##type* prev; \
} Node_##type; \
 \
typedef struct list_##type { \
    Node_##type* head; \
    Node_##type* tail; \
    size_t size; \
} List_##type; \
 \
static Node_##type* list_##type##_make_node(type v) { \
    Node_##type* nd = (Node_##type*)list_ecmalloc(sizeof(Node_##type)); \
    nd->value = v; nd->next = NULL; nd->prev = NULL; \
    return nd; \
} \
 \
void list_##type##_init(List_##type* pl) { \
    pl->head = pl->tail = NULL; \
    pl->size = 0; \
} \
 \
void list_##type##_destroy(List_##type* pl) { \
    Node_##type* cur = pl->head; \
    while (cur) { \
        Node_##type* nxt = cur->next; \
        free(cur); \
        cur = nxt; \
    } \
    pl->head = pl->tail = NULL; \
    pl->size = 0; \
} \
 \
void list_##type##_push_back(List_##type* pl, type value) { \
    Node_##type* nd = list_##type##_make_node(value); \
    if (pl->tail == NULL) { \
        pl->head = pl->tail = nd; \
    } else { \
        nd->prev = pl->tail; \
        pl->tail->next = nd; \
        pl->tail = nd; \
    } \
    pl->size += 1; \
} \
 \
type list_##type##_pop_back(List_##type* pl) { \
    if (pl->tail == NULL) { \
        fprintf(stderr, "pop_back error: list is empty.\n"); \
        exit(1); \
    } \
    Node_##type* last = pl->tail; \
    type value = last->value; \
    pl->tail = last->prev; \
    if (pl->tail) pl->tail->next = NULL; else pl->head = NULL; \
    free(last); \
    pl->size -= 1; \
    return value; \
} \
 \
void list_##type##_push_front(List_##type* pl, type value) { \
    Node_##type* nd = list_##type##_make_node(value); \
    if (pl->head == NULL) { \
        pl->head = pl->tail = nd; \
    } else { \
        nd->next = pl->head; \
        pl->head->prev = nd; \
        pl->head = nd; \
    } \
    pl->size += 1; \
} \
 \
type list_##type##_pop_front(List_##type* pl) { \
    if (pl->head == NULL) { \
        fprintf(stderr, "pop_front error: list is empty.\n"); \
        exit(1); \
    } \
    Node_##type* first = pl->head; \
    type value = first->value; \
    pl->head = first->next; \
    if (pl->head) pl->head->prev = NULL; else pl->tail = NULL; \
    free(first); \
    pl->size -= 1; \
    return value; \
} \
 \
Node_##type* list_##type##_erase(List_##type* pl, Node_##type* p) { \
    if (p == NULL) return NULL; \
    Node_##type* next = p->next; \
    if (p->prev) p->prev->next = p->next; else pl->head = p->next; \
    if (p->next) p->next->prev = p->prev; else pl->tail = p->prev; \
    free(p); \
    pl->size -= 1; \
    return next; \
} \
 \
void list_##type##_splice(List_##type* dst, Node_##type* pos, List_##type* src) { \
    if (src->size == 0) return; \
    Node_##type* first = src->head; \
    Node_##type* last  = src->tail; \
    size_t moved = src->size; \
    if (pos == NULL) { \
        if (dst->tail) { \
            dst->tail->next = first; \
            first->prev = dst->tail; \
            dst->tail = last; \
        } else { \
            dst->head = first; \
            dst->tail = last; \
            first->prev = NULL; \
        } \
    } else { \
        Node_##type* before = pos->prev; \
        if (before) { \
            before->next = first; \
            first->prev = before; \
        } else { \
            dst->head = first; \
            first->prev = NULL; \
        } \
        last->next = pos; \
        pos->prev = last; \
    } \
    dst->size += moved; \
    src->head = src->tail = NULL; \
    src->size = 0; \
} \
 \
void list_##type##_advance(Node_##type** pp, size_t n) { \
    if (!pp) return; \
    Node_##type* cur = *pp; \
    for (size_t i = 0; i < n && cur; ++i) cur = cur->next; \
    *pp = cur; \
} \
 \
void list_##type##_print(const List_##type* pl, void (*print_elem)(type)) { \
    for (Node_##type* cur = pl->head; cur; cur = cur->next) print_elem(cur->value); \
    putchar('\n'); \
}

