#include <stdio.h>

struct Mahasiswa {
    int npm;
    char nama[50];
    float nilai_tugas;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    char nilai_huruf;
};

char konversiNilaiHuruf(float nilai) {
    if (nilai >= 80)
        return 'A';
    else if (nilai >= 65)
        return 'B';
    else if (nilai >= 56)
        return 'C';
    else if (nilai >= 50)
        return 'D';
    else
        return 'E';
}

int main() {
    struct Mahasiswa daftar_mahasiswa[20];
    int jumlah_mahasiswa, i;

    printf("Masukkan jumlah mahasiswa (maksimal 20): ");
    scanf("%d", &jumlah_mahasiswa);

    for (i = 0; i < jumlah_mahasiswa; ++i) {
        printf("\nMasukkan data untuk Mahasiswa %d:\n" ,i+1);
        printf("Nomor Pokok Mahasiswa: ");
        scanf("%d", &daftar_mahasiswa[i].npm);
        printf("Nama Mahasiswa: ");
        scanf("%s", daftar_mahasiswa[i].nama);
        printf("Nilai Tugas: ");
        scanf("%f", &daftar_mahasiswa[i].nilai_tugas);
        printf("Nilai Ujian Tengah Semester: ");
        scanf("%f", &daftar_mahasiswa[i].nilai_uts);
        printf("Nilai Ujian Akhir Semester: ");
        scanf("%f", &daftar_mahasiswa[i].nilai_uas);

        daftar_mahasiswa[i].nilai_akhir = 0.2 * daftar_mahasiswa[i].nilai_tugas +
                                           0.3 * daftar_mahasiswa[i].nilai_uts +
                                           0.5 * daftar_mahasiswa[i].nilai_uas;

        daftar_mahasiswa[i].nilai_huruf = konversiNilaiHuruf(daftar_mahasiswa[i].nilai_akhir);
    }

    printf("\nNPM\tNAMA\tNILAI AKHIR\tNILAI HURUF\n");
    for (i = 0; i < jumlah_mahasiswa; ++i) {
        printf("%d\t%s\t%.2f\t\t%c\n", daftar_mahasiswa[i].npm, daftar_mahasiswa[i].nama,
               daftar_mahasiswa[i].nilai_akhir, daftar_mahasiswa[i].nilai_huruf);
    }

    return 0;
}