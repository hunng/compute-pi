#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct __SIGMA_NODE {
    double stor;
    int confide;
    struct __SIGMA_NODE *NEXT;
} numb;

numb *appendnum(numb *a, double addit);
double sumnum(numb *a);
double avernum(numb *a);
double sigmanum(numb *a);
void confidenum(numb *a);
