#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Ticket
{
    char code;
    int number, status;
};
int sold=0;
int *soldHandler = &sold;
char nameTicket[10];
