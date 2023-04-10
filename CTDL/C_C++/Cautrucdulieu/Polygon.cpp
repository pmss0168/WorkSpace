#include <stdio.h>
#define Maxlength 100
typedef struct{
    int x,y;
}Point;
typedef Point ElementType;
typedef int Position;
typedef struct{
    ElementType Elements[Maxlength];
    Position Last;
}List;

