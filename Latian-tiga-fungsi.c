#include <stdio.h>

int main() {
    char namaPembeli[40];
    char typeRumah;
    char jenisPembayaran;
    int lamaPembayaran;
    double hargaTunai, hargaKredit, pembayaranBulan;
    
    printf("Nama Pembeli: ");
    scanf("%s", namaPembeli);
    
    printf("Type Rumah (A/B/C): ");
    scanf(" %c", &typeRumah);
    
    printf("Jenis Pembayaran (T/K): ");
    scanf(" %c", &jenisPembayaran);
    
    switch (typeRumah) {
        case 'A':
            hargaTunai = 800000000;
            switch (jenisPembayaran) {
                case 'T':
                    pembayaranBulan = hargaTunai;
                    break;
                case 'K':
                    printf("Lama Pembayaran (15/20 thn): ");
                    scanf("%d", &lamaPembayaran);
                    if (lamaPembayaran == 15) {
                        hargaKredit = 7000000;
                    } else if (lamaPembayaran == 20) {
                        hargaKredit = 5000000;
                    } else {
                        printf("Lama pembayaran tidak valid.\n");
                        return 1;
                    }
                    pembayaranBulan = hargaKredit;
                    break;
                default:
                    printf("Jenis pembayaran tidak valid.\n");
                    return 1;
            }
            break;
        case 'B':
            hargaTunai = 1200000000;
            switch (jenisPembayaran) {
                case 'T':
                    pembayaranBulan = hargaTunai;
                    break;
                case 'K':
                    printf("Lama Pembayaran (15/20 thn): ");
                    scanf("%d", &lamaPembayaran);
                    if (lamaPembayaran == 15) {
                        hargaKredit = 9000000;
                    } else if (lamaPembayaran == 20) {
                        hargaKredit = 7000000;
                    } else {
                        printf("Lama pembayaran tidak valid.\n");
                        return 1;
                    }
                    pembayaranBulan = hargaKredit;
                    break;
                default:
                    printf("Jenis pembayaran tidak valid.\n");
                    return 1;
            }
            break;
        case 'C':
            hargaTunai = 1500000000;
            switch (jenisPembayaran) {
                case 'T':
                    pembayaranBulan = hargaTunai;
                    break;
                case 'K':
                    printf("Lama Pembayaran (15/20 thn): ");
                    scanf("%d", &lamaPembayaran);
                    if (lamaPembayaran == 15) {
                        hargaKredit = 10000000;
                    } else if (lamaPembayaran == 20) {
                        hargaKredit = 8000000;
                    } else {
                        printf("Lama pembayaran tidak valid.\n");
                        return 1;
                    }
                    pembayaranBulan = hargaKredit;
                    break;
                default:
                    printf("Jenis pembayaran tidak valid.\n");
                    return 1;
            }
            break;
        default:
            printf("Type rumah tidak valid.\n");
            return 1;
    }
    
    printf("Besar pembayaran: Rp. %.2lf\n", pembayaranBulan);
    
    return 0;
}