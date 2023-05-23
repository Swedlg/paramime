// HashTable.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
typedef struct hash_node {
    char* key;
    int value;
    struct hash_node* next;
} hash_node;

typedef struct {
    hash_node** buckets;
} hash_table;

unsigned int hash(char* key) {
    unsigned int hashval = 0;
    for (; *key != '\0'; key++) {
        hashval = *key + 31 * hashval;
    }
    return hashval % TABLE_SIZE;
}

hash_table* create_hash_table() {
    hash_table* table = (hash_table*)malloc(sizeof(hash_table));
    table->buckets = calloc(TABLE_SIZE, sizeof(hash_node*));
    return table;
}

void insert(hash_table* table, char* key, int value) {
    unsigned int bucket = hash(key);
    hash_node* node = table->buckets[bucket];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    hash_node* new_node = malloc(sizeof(hash_node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = table->buckets[bucket];
    table->buckets[bucket] = new_node;
}

int lookup(hash_table* table, char* key) {
    unsigned int bucket = hash(key);
    hash_node* node = table->buckets[bucket];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void delete(hash_table* table, char* key) {
    unsigned int bucket = hash(key);
    hash_node* node = table->buckets[bucket];
    hash_node* prev = NULL;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[bucket] = node->next;
            }
            else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void print_table(hash_table* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_node* node = table->buckets[i];
        printf("[%d]: ", i);
        while (node != NULL) {
            printf("(%s, %d) ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    hash_table* table = create_hash_table();

    insert(table, "apple", 10);
    insert(table, "banana", 20);
    insert(table, "cherry", 30);
    insert(table, "date", 40);

    printf("Lookup(cherry): %d\n", lookup(table, "cherry"));
    printf("Lookup(grape): %d\n", lookup(table, "grape"));

    delete(table, "banana");

    print_table(table);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
