
#ifndef _stackchess_H__
#define _stackchess_H__


#include "listchess.h"

#define MaxEl 100

typedef struct {
    Piece T[MaxEl];
    int TOP;
} Stack;

void CreateEmptyS(Stack *S);
boolean IsEmptyS(Stack S);
boolean IsFullS(Stack S);
void Push(Stack *S, Piece X);
void Pop (Stack *S, Piece *X);

#endif