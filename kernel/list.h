#ifndef _LIST_H_
#define _LIST_H_

struct list_node {
    struct list_node* next;
    struct list_node* prev;
};

static inline void list_init(struct list_node* head)
{
  head->next = head;
  head->prev = head;
}

static inline void list_add_end(struct list_node* node, struct list_node* head)
{
  node->prev = head->prev;
  node->next = head;
  head->prev->next = node;
  head->prev = node;
}

static inline void list_add_start(struct list_node* node, struct list_node* head)
{
  node->prev = head;
  node->next = head->next;
  head->next->prev = node;
  head->next = node;
}

static inline void list_del(struct list_node* node)
{
  node->prev->next = node->next;
  node->next->prev = node->prev;
}
#endif // _LIST_H_
