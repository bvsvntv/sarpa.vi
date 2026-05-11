#ifndef LOGIC_H_
#define LOGIC_H_

#include <stdbool.h>

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

typedef struct Sarpa {
    int x;
    int y;
    Direction direction;
    struct Sarpa *next;
} Sarpa;

typedef struct {
    int x;
    int y;
} Food;

extern Sarpa *head;
extern Sarpa *tail;
extern Food food;

void init_sarpa();
void add_segment();
void move_sarpa();
void generate_food();
bool eat_food();
bool check_collision();

#endif
