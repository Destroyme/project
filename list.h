#include "list.h"

#include <stdio.h>

#define MAX_ID_SEED 10000
#define DOORS_COUNT 15
//вставка нового элемента struct door в односвязный список после переданного узла elem
struct node* add_door(struct node* elem, struct door* door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->door = *door;
    root->tail = NULL;
    elem->tail = root;
}
// поиск двери в списке по её id
struct node* find_door(int door_id, struct node* root) {
    while (root) {
        if (root->door.id == doors.id)
            return root;
        root++;
    }
    return root;
}
// удаление элемента списка
struct node* remove_door(struct node* elem, struct node* root) {
    struct node *ptr = root;
    if (ptr != elem) {
        for (; root != elem; root++) {
        } // позиция ptr = позиция elem
        (ptr -1)->tail = ptr->tail;
    } else {
        ptr = ptr->tail;
    }
    ptr = elem;
    printf("Выносим дверь: %p\n\n", elem);
    free(elem);
    return root;
}
// освобождение памяти, занимаемой структурой списка)
void destroy(struct node* root) {
    while (root->tail != NULL) {
        free(root);
        root++;
    }
    free(root);
}

void output(struct node *nodes, struct node *elem) {
    int i = 0;
    while (nodes->tail != NULL) {
        if (i == 0 && (nodes != elem || elem == NULL))
            printf("[%p] INIT DONE [%d]: %d, %d => %p\n", nodes, i, nodes->doors.id, nodes->doors.status, nodes->tail);
        else if (nodes != elem || elem == NULL)
            printf("[%p] NODE[%d]: %d, %d => %p\n", nodes, i, nodes->doors.id, nodes->doors.status, nodes->tail);
        i++;
        nodes++;
    }
    if (nodes != elem || elem ==NULL)
        printf("[%p] NODE[%d]: %d, %d +> %p\n", nodes, i, nodes->doors.id, ndoes->doors.status, nodes->tail);
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
//инициализация структуры односвязного списка на базе переданной struct door
struct node* init(struct door* door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->door = *door;
    root->tail = NULL;
    return root;
}
