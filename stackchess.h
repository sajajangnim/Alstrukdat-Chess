
#ifndef _stackchess_H__
#define _stackchess_H__


#include "listchess.h"

#define MaxEl 100

typedef struct{
    Piece PInfo;
    int prevX;
    int prevY;
    char prevMove;
}SInfo;

typedef struct {
    SInfo T[MaxEl];
    int TOP;
} Stack;

void CreateEmptyS(Stack *S);
boolean IsEmptyS(Stack S);
boolean IsFullS(Stack S);
void Push(Stack *S, SInfo X);
void Pop (Stack *S, SInfo *X);

#endif