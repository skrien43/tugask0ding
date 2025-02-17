#include <stdio.h>

#define MAX_INPUT 20

// Fungsi untuk menentukan keterangan dari nilai psikotes
char* tentukanKeterangan(int nilai) {
    if (nilai < 70) {
        return "Bad";
    } else if (nilai >= 70 && nilai <= 100) {
        return "Under average";
    } else if (nilai >= 101 && nilai <= 200) {
        return "Default average";
    } else if (nilai >= 201 && nilai <= 400) {
        return "Upper average";
    } else if (nilai >= 401 && nilai <= 500) {
        return "Good";
    } else {
        return "Excellence";
    }
}

int main() {
    char nama[MAX_INPUT][50];
    int nilai[MAX_INPUT];
    int totalBad = 0, totalUnderAverage = 0, totalDefaultAverage = 0, totalUpperAverage = 0, totalGood = 0, totalExcellence = 0;

    printf("Laporan Psikotest\n");
    printf("No\tNama\t\t\tNilai\t\tKeterangan\n");

    // Memasukkan nilai psikotes
    for (int i = 0; i < MAX_INPUT; i++) {
        printf("%d\t", i + 1);
        scanf("%s %d", nama[i], &nilai[i]);
        printf("\t%s\t\t", nama[i]);
        printf("%d\t\t", nilai[i]);
        char* keterangan = tentukanKeterangan(nilai[i]);
        printf("%s\n", keterangan);

        // Menghitung total kategori nilai
        if (nilai[i] < 70) {
            totalBad++;
        } else if (nilai[i] >= 70 && nilai[i] <= 100) {
            totalUnderAverage++;
        } else if (nilai[i] >= 101 && nilai[i] <= 200) {
            totalDefaultAverage++;
        } else if (nilai[i] >= 201 && nilai[i] <= 400) {
            totalUpperAverage++;
        } else if (nilai[i] >= 401 && nilai[i] <= 500) {
            totalGood++;
        } else {
            totalExcellence++;
        }
    }

    // Menampilkan total dari setiap kategori
    printf("\nTotal :\n");
    printf("Bad\t\t\t: %d\n", totalBad);
    printf("Under average\t: %d\n", totalUnderAverage);
    printf("Default average\t: %d\n", totalDefaultAverage);
    printf("Upper average\t: %d\n", totalUpperAverage);
    printf("Good\t\t: %d\n", totalGood);
    printf("Excellence\t: %d\n", totalExcellence);

    return 0;
}
