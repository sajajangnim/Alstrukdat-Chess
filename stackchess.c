#include "stackchess.h"

void CreateEmptyS(Stack *S)
{
    (*S).TOP = 0;
}
boolean IsEmptyS(Stack S)
{
    return ((S).TOP == 0);
}
boolean IsFullS(Stack S)
{
    return ((S).TOP==MaxEl);
}
void Push(Stack *S, Piece X)
{
    (*S).TOP++;
    (*S).T[((*S).TOP)-1] = X;
}
void Pop (Stack *S, Piece *X)
{
    *X = (*S).T[((*S).TOP)-1];
    (*S).TOP--;
}