// 12S25007 - Tongam Prozona Manurung 


#include <stdio.h>

int main() {
    int n, kategori, totalStok = 0;

    printf("=== Program Penghitung Stok Gudang ===\n");

    // 1. Input jumlah total data
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &n);

    int stok[n];

    // 2. Input deret stok
    printf("Masukkan %d deret stok barang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Stok ke-%d: ", i + 1);
        scanf("%d", &stok[i]);
    }

    // 3. Pilih Kategori
    printf("\nPilih Kode Kategori (1 untuk Ganjil, 2 untuk Genap): ");
    scanf("%d", &kategori);

    // Proses Perhitungan
    for (int i = 0; i < n; i++) {
        int nomorUrut = i + 1; // Karena array mulai dari 0, kita tambah 1

        if (kategori == 1) {
            // Kategori 1: Ambil nomor urut ganjil (1, 3, 5...)
            if (nomorUrut % 2 != 0) {
                totalStok += stok[i];
            }
        } else if (kategori == 2) {
            // Kategori 2: Ambil nomor urut genap (2, 4, 6...)
            if (nomorUrut % 2 == 0) {
                totalStok += stok[i];
            }
        }
    }

    // Output Hasil
    printf("---------------------------------------\n");
    printf("Total stok untuk Kategori %d adalah: %d\n", kategori, totalStok);

    return 0;
}