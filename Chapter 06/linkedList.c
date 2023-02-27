#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void print_listNode(ListNode *head) {
    while (1) {
        printf("%d -> ", head->data);
        if(head->link == NULL) {
            break;
        }
        head = head->link;
    }
}

ListNode* insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p->data = value;
    p->link = head;
    head = p;
    
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    p->link = pre->link;
    pre->link = p;

    return p;
}

ListNode* delete_front(ListNode* head) {
    ListNode* removed;
    if (head->link == NULL) {
        return NULL;
    }
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

int main(void) {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 11;
    head->link = NULL;

    ListNode *a = insert(head->link, head, 12);
    ListNode *b = insert(head->link, a, 13);
    ListNode *newHead = insert_first(head, 10);
    ListNode *c = delete(newHead, head);

    print_listNode(c);

}