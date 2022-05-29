#include "utils.c"
void TicketGenerator(char code,int total,struct Ticket *Data);
void TicketValidation(struct Ticket *Data, int sold, char code);
void SellTicket(struct Ticket *Data, int sold,int total, int sell);
void CheckTicket(struct Ticket *Data, int total);