// memanggil file header utils.h
#include "utils.h"
int main(){
    char nameTicket[10];
    int total = 0, sell=0, menu;

    printf("================================\n");
    printf("==  Program Tiket Management  ==\n");
    printf("================================\n");
    
    //memasukan nama tiket
    printf("Masukan Nama Tiket : ");
    // getchar();
    gets(nameTicket);
    // memasukan total tiket yang ingin dibuat
    printf("Masukan Total Tiket : ");
    scanf("%d", &total);

    // membuat array TicketData dengan tipe data struct Tiket
    struct Ticket TicketData[total];

    //memanggil fungsi untuk membuat tiket secara otomatis
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
        //memanggil fungsi untuk menampilkan tiket yang tersedia
        CheckTicket(TicketData, total);
        getchar(); getchar();
        goto menu;
        break;
    case 2:
        //memanggil fungsi untuk menjual tiket
        printf("\nMau jual berapa tiket? : ");
        scanf("%d", &sell);
        SellTicket(TicketData, sold, total, sell);
        getchar(); getchar();
        goto menu;
        break;
    case 3:
    // memanggil fungsi untuk melakukan validasi tiket
        TicketValidation(TicketData, sold, nameTicket[0]);
        getchar(); getchar();
        goto menu;
    case 4:
        return 0;
    }
    
    return 0;
}

// fungsi untuk membuat tiket secara otomatis
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

// fungsi untuk menampilkan tiket yang masih tersedia
void CheckTicket(struct Ticket *Data, int total){
    printf("\nDAFTAR TIKET TERSEDIA :");
    for (int i = 0; i < total; i++)
    {
        if(Data[i].status == 0){
            printf("\nTiket %c%.3d", Data[i].code, Data[i].number);
        }
    }
    
    printf("\nTekan enter untuk kembali ke menu program!!");
}


// fungsi untuk menjual tiket
void SellTicket(struct Ticket *Data, int sold,int total, int sell){
    if (sold == total) //menegecek apakah total tiket yang sudah terjual sama dengan jumlah tiket yang terbuat
    {
        printf("Tiket Sudah Habis!\n");
        printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
    }else if((sold+sell) > total){ //mengecek jumlah tiket yang ingin dijual lebih dari jumlah tiket yang tersedia
        printf("Penjualan Gagal!\nJumlah Tiket Yang Tersedia : %d", total-sold);
        printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
    }else{
        for (int i = sold-1; i < sold+sell; i++) //melakukan penjualan tiket dengan merubah status dari 0 menjadi 1
    {
        Data[i].status = 1;
    }
    *soldHandler = *soldHandler+sell;
    printf("\nProses Penjualan Tiket Sukses");
    printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
    }
    
}

// fungsi untuk melakukan validadi tiket
void TicketValidation(struct Ticket *Data, int sold, char code){
    char huruf;
    int number;
    getchar();
    // menerima inputan huruf / code tiket
    printf("\nMasukan huruf tiket : ");
    scanf("%c", &huruf);
    // menerima masukan nomor tiket
    printf("Masukan nomor tiket : ");
    scanf("%d", &number);
    int condition = 0;
    // melakukan validasi tiket dengan membandingkan code tiket dan nomor tiket.
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
    // mencetak status tiket valid atau tidak.
    condition == 1 ? printf("Tiket Valid!") : printf("Tiket Tidak Valid!");
    printf("\nTekan Enter Untuk Kembali Ke Menu Program!!");
   
    
}