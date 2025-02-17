#include <stdio.h>

// Fungsi untuk menghitung luas balok
float hitungLuas(int panjang, int lebar) {
return (float)panjang * lebar;
}

// Fungsi untuk menghitung isi balok
float hitungIsi(float luas, int tinggi) {
return luas * tinggi;
} 

int main() {
// Deklarasi variabel panjang, lebar, dan tinggi bertipe integer
int panjang, lebar, tinggi;

// Input panjang, lebar, dan tinggi
printf("Masukkan panjang balok: ");
scanf("%d", &panjang);
printf("Masukkan lebar balok: ");
scanf("%d", &lebar);
printf("Masukkan tinggi balok: ");
scanf("%d", &tinggi);

// Menghitung luas dan isi balok menggunakan fungsi
float luas = hitungLuas(panjang, lebar);
float isi = hitungIsi(luas, tinggi);

// Cetak hasil
printf("\nLuas balok adalah: %.2f\n", luas);
printf("Isi balok adalah: %.2f\n", isi);

return 0;
}