#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long generateRandomLong() {
long result = 0;
for (int i = 0; i < 6; i++) {
    result = result * 10 + rand() % 9 + 1;
}
return result;
}

int main(){
    char namaPemesan[50];
    char kendaraan[30];
    char noTNKB[20];
    char tglBook[20];
    char jenisPaket, mtdBayar, pilihan;
    int jmlInap;
    long kdBook, kdBookGenerated = 0;
    float jmlBayar;
    float hrgSatuan = 120000;

    srand(time(NULL));
    time_t t;
    struct tm *info;
    time(&t);
    info = localtime(&t);
    
    char time_str[80];
    strftime(time_str, sizeof(time_str), "%d %b %Y  --  %H:%M:%S", info);

    printf("\n\tPARKIR MOBIL INAP PURNAMA\n");
    printf("Jl. Raya Bandara No.110, Jakarta, Indonesia\n");
    printf("\t%s\n", &time_str);
    printf("\nSelamat datang di pemesanan Parkir Inap Purnama\nKami menyediakan penginapan mulai dari per malam, paket 3 malam, dan paket 7 malam.\n\n");
    
    do {
        printf("Menu\n");
        printf("1. Book sekarang\n");
        printf("2. Cek status pemesanan\n");
        printf("3. Keluar\n");
        printf("Pilih menu (1/2/3): ");
            scanf(" %c", &pilihan);

// hal. 1 ------------------------------------------------------------------------------------------------------------------------------------------------

        switch(pilihan){
            case '1':
                kdBookGenerated = generateRandomLong();
                printf("\nSilakan ketik Nama, Kendaraan, dan Nomor TNKB Anda\n");
                printf("1. Nama: ");
                    scanf("%s", namaPemesan);
                printf("2. Kendaraan (kapital): ");
                    scanf("%s", kendaraan);
                printf("3. No TNKB (tanpa spasi): ");
                    scanf("%s", noTNKB);

                printf("\nSilakan memilih paket menginap kendaraan Anda:\n1. Per Malam (n)\n2. 3 Malam   (3)\n3. 7 Malam   (7)\n");
                printf("Pilih paket (n/3/7): ");
                    scanf(" %c", &jenisPaket);

                switch(jenisPaket){
                    case 'n':
                        printf("Lama menginap: ");
                        scanf("%d", &jmlInap);
                        if (jmlInap == 1) {
                            printf("\nLama menginap Anda, %d Malam\n", jmlInap);
                            printf("Total yang dibayarkan: Rp %.2f", jmlBayar = hrgSatuan);
                        } else if (jmlInap == 2){
                            printf("\nLama menginap Anda, %d Malam\n", jmlInap);
                            printf("Total yang dibayarkan: Rp %.2f", jmlBayar = hrgSatuan * 2);
                        } else if (jmlInap >= 4 && jmlInap <= 6){
                            printf("\nLama menginap Anda, %d Malam\n", jmlInap);
                            printf("Total yang dibayarkan: Rp %.2f", jmlBayar = hrgSatuan * jmlInap);
                        } else if (jmlInap > 6){
                            printf("\nMaaf, kami tidak menyediakan layanan penginapan lebih dari 7 malam.\n\n");
                            return 0;
                        }
                        break;
                    case '3':
                        printf("\nLama menginap Anda, 3 Malam\n");
                        printf("Total yang dibayarkan: Rp %.2f", jmlBayar = hrgSatuan * 3 * (1 - 0.10));
                        break;
                    case '7':
                        printf("\nLama menginap Anda, 7 Malam\n");
                        printf("Total yang dibayarkan: Rp %.2f", jmlBayar = hrgSatuan * 7 * (1 - 0.35));
                        break;
                    default:
                        printf("\nMaaf, kami tidak menyediakan layanan penginapan lebih dari 7 malam.\n\n");
                        return 0;
                }

// hal. 2 ------------------------------------------------------------------------------------------------------

                printf("\n\nSilakan ketik tanggal check-in Anda, dengan format DD-MM-YYYY: ");
                    scanf("%s", tglBook);

                printf("\nSilakan memilih metode pembayaran Anda:\n1. QRIS\t\t\t (Q)\n2. Transfer Bank\t (T)\n3. Kartu Uang Elektronik (E)\n");
                printf("Pilih metode pembayaran (Q/T/E): ");
                    scanf(" %c", &mtdBayar);

                switch(mtdBayar){
                    case 'Q':
                        printf("\nAnda memilih metode pembayaran QRIS.\n");
                        printf("Scan QR Code dibawah ini untuk membayar\n\n");
                        printf("\t\t\t\t\n/QR Code/\n\n");
                        break;
                    case 'T':
                        printf("\nAnda memilih metode pembayaran Transfer Bank.\n");
                        printf("Silakan membayar melalui rekening Bank Koox 0123 4567 89 a/n Parkir Inap Purnama.\nMohon tunjukkan bukti transfer pada saat check-in!\n");
                        break;
                    case 'E':
                        printf("\nAnda memilih metode pembayaran dengan Kartu Uang Elektronik.\n");
                        printf("Silakan melakukan Tap KUE pada saat check-in dan check-out!\n");
                        break;
                    default:
                        printf("\nMetode pembayaran tidak sesuai!\n\n");
                        return 0;
                }

                printf("\nBooking atas nama %s-%s-%s selama %d malam BERHASIL, silakan melakukan check-in pada tanggal %s.\n",
                        namaPemesan, kendaraan, noTNKB, ((jenisPaket == 'n') ? jmlInap : ((jenisPaket == '3') ? 3 : 7)), tglBook);
                printf("Total yang harus dibayarkan Rp %.2f dengan metode pembayaran %c.\n", jmlBayar, mtdBayar);
                printf("\nTerima Kasih telah melakukan booking penginapan di Parkir Inap Purnama!\n");
                printf("\nKode Booking anda adalah: %ld\n", kdBookGenerated);
                printf("TUNJUKKAN KODE BOOKING ANDA PADA SAAT CHECK-IN\n");
                printf("\nJika Anda mengalami kendala, mohon hubungi Customer Service yang tertera dibawah ini\nCustomer Service: 08212531947111\n\n");
                break;
            case '2':
                if (kdBookGenerated){
                printf("\nMasukkan kode pemesanan: ");
                    scanf("%ld", &kdBook);
                    if (kdBook == kdBookGenerated){
                        printf("\nBooking atas nama %s-%s-%s selama %d malam.\nCheck-in pada tanggal %s.\n\n",
                        namaPemesan, kendaraan, noTNKB, ((jenisPaket == 'n') ? jmlInap : ((jenisPaket == '3') ? 3 : 7)), tglBook);
                    } else {
                        printf("\nKode Booking tidak Valid!\n\n");
                    }
                } else {
                    printf("\nBelum ada booking yang dilakukan!\n\n");
                }
                break;
            case '3':
                printf("\nTerima Kasih! Program Selesai.\n\n");
                break;
            default :
                printf("\nInput tidak valid! Coba lagi!\n\n");
        }
    } while (pilihan != '3');
        
    return 0;
}
// hal. 3 ------------------------------------------------------------------------------------------------------------------------
