// 12S25007 - Tongam Prozona Manurung 


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Struktur data untuk Menu
struct Menu {
    int kode;
    char nama[30];
    int harga;
    int stok;
};

// Struktur data untuk Item yang dipesan
struct Pesanan {
    char nama[30];
    int jumlah;
    int subtotal;
};

int main() {
    // 1. Manajemen Menu (Inisialisasi Data)
    struct Menu daftarMenu[5] = {
        {1, "Nasi Goreng Del", 15000, 20},
        {2, "Ayam Penyet Sitoluama", 18000, 15},
        {3, "Mie Gomak", 12000, 25},
        {4, "Teh Manis (Hot/Ice)", 5000, 50},
        {5, "Kopi ", 8000, 30}
    };

    struct Pesanan keranjang[20];
    int jumlahItem = 0;
    int pilihan, qty;
    int totalBruto = 0;
    char nim[15];
    float ppn, diskon = 0, totalAkhir;

    printf("=== SISTEM KASIR KAFETARIA IT DEL ===\n\n");

    // Menampilkan Menu
    printf("DAFTAR MENU HARI INI:\n");
    printf("------------------------------------------\n");
    printf("Kode | Nama Menu             | Harga  | Stok\n");
    printf("------------------------------------------\n");
    for(int i = 0; i < 5; i++) {
        printf("%-4d | %-20s | %-6d | %d\n", 
                daftarMenu[i].kode, daftarMenu[i].nama, 
                daftarMenu[i].harga, daftarMenu[i].stok);
    }
    printf("------------------------------------------\n");

    // 2. Sistem Pemesanan 
    while(true) {
        printf("\nMasukkan Kode Menu (ketik 0 untuk selesai): ");
        scanf("%d", &pilihan);

        if(pilihan == 0) break;

        // Validasi kode menu
        if(pilihan < 1 || pilihan > 5) {
            printf("Kode tidak valid!\n");
            continue;
        }

        printf("Masukkan Jumlah: ");
        scanf("%d", &qty);

        // Validasi Stok
        int idx = pilihan - 1;
        if(qty > daftarMenu[idx].stok) {
            printf("Maaf, stok tidak mencukupi (Sisa: %d)\n", daftarMenu[idx].stok);
        } else {
            // Masukkan ke keranjang
            strcpy(keranjang[jumlahItem].nama, daftarMenu[idx].nama);
            keranjang[jumlahItem].jumlah = qty;
            keranjang[jumlahItem].subtotal = daftarMenu[idx].harga * qty;
            
            totalBruto += keranjang[jumlahItem].subtotal;
            daftarMenu[idx].stok -= qty; // Kurangi stok
            jumlahItem++;
            
            printf("Berhasil menambahkan %s ke pesanan.\n", daftarMenu[idx].nama);
        }
    }

    // 3. Penghitungan Otomatis & Validasi Mahasiswa
    if(jumlahItem > 0) {
        printf("\nApakah pembeli Mahasiswa IT Del? (Input NIM atau ketik '0' jika bukan): ");
        scanf("%s", nim);

        if(strcmp(nim, "0") != 0) {
            diskon = totalBruto * 0.10; // Diskon 10% untuk mahasiswa
            printf("Validasi NIM %s Berhasil! Anda mendapat diskon 10%%.\n", nim);
        }

        ppn = (totalBruto - diskon) * 0.10; // PPN 10%
        totalAkhir = (totalBruto - diskon) + ppn;

        // Output Struk Belanja
        printf("\n\n==========================================");
        printf("\n          STRUK BELANJA KAFETARIA         ");
        printf("\n                  IT DEL                  ");
        printf("\n==========================================\n");
        for(int i = 0; i < jumlahItem; i++) {
            printf("%-20s x%d   Rp%d\n", keranjang[i].nama, keranjang[i].jumlah, keranjang[i].subtotal);
        }
        printf("------------------------------------------\n");
        printf("Total Harga (Bruto) : Rp%d\n", totalBruto);
        printf("Diskon Mahasiswa    : Rp%.0f\n", diskon);
        printf("PPN (10%%)           : Rp%.0f\n", ppn);
        printf("------------------------------------------\n");
        printf("TOTAL BAYAR         : Rp%.0f\n", totalAkhir);
        printf("==========================================\n");
        printf("       Terima Kasih & MarTuhan, Marroha, Marbisuk!     \n");
    } else {
        printf("\nTidak ada pesanan yang dibuat.\n");
    }

    return 0;
}