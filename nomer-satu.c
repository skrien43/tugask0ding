#include <stdio.h>
#define MAX_SIZE 15

// Fungsi untuk menghitung jumlah elemen dalam array
int hitungJumlah(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int angka[MAX_SIZE];
    int input, count = 0;

    printf("Masukkan angka (hingga 15 angka, 0 untuk berhenti):\n");

    // Membaca angka dari inputan
    do {
        scanf("%d", &input);
        if (input != 0) {
            angka[count] = input;
            count++;
        }
    } while (input != 0 && count < MAX_SIZE);

    // Menghitung jumlah angka yang dimasukkan
    int jumlah = hitungJumlah(angka, count);

    printf("Jumlah dari angka yang dimasukkan: %d\n", jumlah);

    return 0;
}
