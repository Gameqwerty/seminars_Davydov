#pragma once
#include <stddef.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list
{
    Node* head;
    Node* tail;
    size_t size;
} List;

List  init(size_t n);
void  destroy(List* pl);

void  print(const List* pl);
void  push_back(List* pl, int value);
int   pop_back(List* pl);
void  push_front(const List* pl, int value);
int   pop_front(List* pl);

Node* erase(List* pl, Node* p);
void  splice(List* plist, Node* p, List* pother);
void  advance(Node** pp, size_t n);
