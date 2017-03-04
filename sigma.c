#include "sigma.h"

int main()
{
    numb *num = malloc (sizeof(numb));
    numb *start = num;
    num = appendnum(num, 10.22);
    num = appendnum(num, 5.87);
    num = appendnum(num, 0.666);

    double sum = sumnum(start);
    double aver = avernum(start);
    double sig = sigmanum(start);
    confidenum(start);
    sum = sumnum(start);
    aver = avernum(start);
    sig = sigmanum(start);
    return 0;
}

numb *appendnum(numb *a, double addit)
{
    a->stor = addit;
    a->NEXT = (numb *) malloc (sizeof(numb));
    a = a->NEXT;
    a->confide = 0;
    a->NEXT = NULL;
    return a;
}

double sumnum(numb *a)
{
    double sum = 0.0;
    while (a->NEXT != NULL) {
        if (a->confide == 0) {
            sum += a->stor;
        }
        a = a->NEXT;
    }
    return sum;
}

double avernum(numb *a)
{
    double sum = 0.0;
    int count = 0;
    while (a->NEXT != NULL) {
        if (a->confide == 0) {
            sum += a->stor;
        }
        a = a->NEXT;
        count++;
    }
    return sum/count;
}

double sigmanum(numb *a)
{
    double aver = avernum(a);
    double stand = 0;
    double sigma = 0.0;
    int count = 0;
    while (a->NEXT != NULL) {
        stand = aver - a->stor;
        stand *= stand;
        sigma += stand;
        a = a->NEXT;
        count++;
    }
    sigma /= count;
    return sqrt(sigma);
}

void confidenum(numb *a)
{
    double aver = avernum(a);
    double sig = 2 * sigmanum(a);
    double MAX = aver + sig;
    double MIN = aver - sig;
    while (a->NEXT != NULL) {
        if (a->stor < MIN || a->stor > MAX)
            a->confide = 1;
        a = a->NEXT;
    }
}
