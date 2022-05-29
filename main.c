#include "utils.h"
int main(){
    char nameTicket[10];
    int total = 0, sell=0, menu;

    printf("================================\n");
    printf("==  Program Tiket Management  ==\n");
    printf("================================\n");
    
    //user define ticket
    printf("Masukan Nama Tiket : ");
    // getchar();
    gets(nameTicket);
    printf("Masukan Total Tiket : ");
    scanf("%d", &total);

    //storage ticket
    struct Ticket TicketData[total];

    //generate ticket
    TicketGenerator(nameTicket[0],total,TicketData);
    getchar();getchar();

    menu:
    system("clear");
    printf("================================\n");
    printf("==  Program Tiket Management  ==\n");
    printf("================================\n");
    printf("Menu:\n1. Cek Tiket\n2. Jual Tiket\n3. Validasi Tiket\n4. Keluar\n");
    printf("Masukan Pilihan Menu: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        //show availble ticket
        CheckTicket(TicketData, total);
        getchar(); getchar();
        goto menu;
        break;
    case 2:
        //sell ticket
        printf("\nMau jual berapa tiket? : ");
        scanf("%d", &sell);
        SellTicket(TicketData, sold, total, sell);
        getchar(); getchar();
        goto menu;
        break;
    case 3:
        TicketValidation(TicketData, sold, nameTicket[0]);
        getchar(); getchar();
        goto menu;
    case 4:
        return 0;
    }
    
    return 0;
}

void TicketGenerator(char code,int total,struct Ticket *Data){
    for (int i = 1; i <= total; i++)
    {
        Data[i-1].code = code;
        Data[i-1].number = i;
        Data[i-1].status = 0;
    }
    printf("Tiket Telah Dibuat.\n");
    printf("Tekan enter untuk melanjutkan program!!\n");
}

void CheckTicket(struct Ticket *Data, int total){
    printf("\nDAFTAR TIKET :");
    for (int i = 0; i < total; i++)
    {
        if(Data[i].status == 0){
            printf("\nTiket %c%.3d", Data[i].code, Data[i].number);
        }
    }
    
    printf("\nTekan enter untuk kembali ke menu program!!");
}


void SellTicket(struct Ticket *Data, int sold,int total, int sell){
    if (sold == total)
    {
        printf("Tiket Sudah Habis!\n");
        printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
    }else if((sold+sell) > total){
        printf("Penjualan Gagal!\nJumlah Tiket Yang Tersedia : %d", total-sold);
        printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
    }else{
        for (int i = sold-1; i < sold+sell; i++)
    {
        Data[i].status = 1;
    }
    *soldHandler = *soldHandler+sell;
    printf("%d", *soldHandler);
    printf("\nProses Penjualan Tiket Sukses");
    printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
    }
    
}

void TicketValidation(struct Ticket *Data, int sold, char code){
    char huruf;
    int number;
    getchar();
    printf("\nMasukan huruf tiket : ");
    scanf("%c", &huruf);
    printf("Masukan nomor tiket : ");
    scanf("%d", &number);
    int condition = 0;
     if(toupper(huruf) == toupper(code)){
         for (int i = 0; i < *soldHandler; i++)
         {
            if(number == Data[i].number){
             if(Data[i].status == 1){
                 condition = 1;
                 break;
             }
         }
         }
         
    }
    condition == 1 ? printf("Tiket Valid!") : printf("Tiket Tidak Valid!");
    printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
   
    
}