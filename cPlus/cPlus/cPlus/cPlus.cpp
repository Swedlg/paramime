// cPlus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "cPlus.h"
#include <string> 


typedef struct _Node {
    std::string value;
    struct _Node* next;
    struct _Node* prev;
} Node;

struct MyLinkedList {
    size_t size;
    Node* head;
    Node* tail; 
};

MyLinkedList* create() {
    MyLinkedList* result = new MyLinkedList;
    result->head = NULL;
    result->tail = NULL;
    result->size = 0;

    return result;
}

void SortedInsert(MyLinkedList* list, std::string value) {
    Node* node = new Node;
    node->next = NULL;
    node->prev = NULL;
    node->value = value;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->size = 1;
    }
    else {
        list->size += 1;
        Node* current = list->head;
        while (current != NULL) {
            if (value.compare(current->value) < 0) {
                // втсавляем node перед current
                node->next = current;
                node->prev = current->prev;
                if (current->prev != NULL) {
                    current->prev->next = node;
                }
                current->prev = node;
                // если вставили вместо head
                if (node->next == list->head) {
                    list->head = node;
                }
                break;
            }
            current = current->next;
        }
        if (current == NULL) {
            // вставляем в конец
            node->prev = list->tail;
            list->tail->next = node;
            list->tail = node;
        }
    }
}

void printList(MyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    MyLinkedList* list = create();
    SortedInsert(list, "я");
    SortedInsert(list, "бы");
    SortedInsert(list, "хотел");
    SortedInsert(list, "чтобы");
    SortedInsert(list, "меня");
    SortedInsert(list, "называли");
    SortedInsert(list, "все");
    SortedInsert(list, "талант");
    SortedInsert(list, "но");

    printList(list);
}
