
#ifndef stackchess_H
#define stackchess_H

#include "boolean.h"

#define Nil 0
#define MaxEl 100

typedef int address;
typedef struct {
    koordinat k;
    piece z;
} chessturn;


typedef struct {
    infotype T[MaxEl];
    address TOP;
} Stack;

void CreateEmpty(Stack *S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack *S, infotype X);
void Pop (Stack *S, infotype *X);