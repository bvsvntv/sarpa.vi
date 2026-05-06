#include <stdlib.h>
#include "./logic.h"
#include "./game.h"

Sarpa *head = NULL;
Sarpa *tail = NULL;
Food food;

void init_sarpa() {
    Sarpa *sarpa = malloc(sizeof(Sarpa));
    sarpa->x = (rand() % COLS) * CELL_SIZE;
    sarpa->y = (rand() % ROWS) * CELL_SIZE;
    sarpa->direction = RIGHT;
    sarpa->next = NULL;
    head = sarpa;
    tail = sarpa;
}

void add_segment() {
    Sarpa *segment = malloc(sizeof(Sarpa));
    segment->x = tail->x;
    segment->y = tail->y;
    segment->direction = tail->direction;
    segment->next = NULL;
    tail->next = segment;
    tail = segment;
}

void move_sarpa() {
    int prev_x = head->x;
    int prev_y = head->y;

    switch (head->direction) {
        case UP:    head->y -= CELL_SIZE; break;
        case DOWN:  head->y += CELL_SIZE; break;
        case LEFT:  head->x -= CELL_SIZE; break;
        case RIGHT: head->x += CELL_SIZE; break;
    }

    Sarpa *current = head->next;
    while (current != NULL) {
        int temp_x = current->x;
        int temp_y = current->y;
        current->x = prev_x;
        current->y = prev_y;
        prev_x = temp_x;
        prev_y = temp_y;
        current = current->next;
    }
}

void generate_food() {
    bool inside_sarpa;
    do {
        inside_sarpa = false;
        food.x = (rand() % COLS);
        food.y = (rand() % ROWS);
        Sarpa *current = head;
        while (current != NULL) {
            if (current->x == food.x * CELL_SIZE && current->y == food.y * CELL_SIZE) {
                inside_sarpa = true;
                break;
            }
            current = current->next;
        }
    } while (inside_sarpa);
}

void eat_food() {
    if(head->x == food.x * CELL_SIZE && head->y == food.y * CELL_SIZE) {
        generate_food();
        add_segment();
    }
}

bool check_collision() {
    if (head->x < 0 || head->x >= COLS * CELL_SIZE ||
        head->y < 0 || head->y >= ROWS * CELL_SIZE) {
        return true;
    }
    Sarpa *current = head->next;
    while (current != NULL) {
        if (head->x == current->x && head->y == current->y) {
            return true;
        }
        current = current->next;
    }
    return false;
}
