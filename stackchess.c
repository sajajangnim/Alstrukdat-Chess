#include "stackchess.h"

void CreateEmpty(Stack *S)
{
    (*S).TOP = Nil;
}
bool IsEmpty(Stack S)
{
    return ((S).TOP == Nil);
}
bool IsFull(Stack S)
{
    return ((S).TOP==MaxEl);
}
void Push(Stack *S, chessturn X)
{
    (*S).TOP++;
    (*S).T[(*S).TOP-1] = X;
}
void Pop (Stack *S, chessturn *X)
{
    *X = (*S).T[(*S).TOP-1];
    (*S).TOP--;
}