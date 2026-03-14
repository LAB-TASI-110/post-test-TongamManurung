// 12S25007 - Tongam Prozona Manurung 


#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    float beratButet, beratUcok, totalBerat, ongkosPerKg, totalOngkos, diskon;
    char namaKota[20], keterangan[20], promo[100];

    printf("=== Program Pengiriman Barang Del Expres ===\n");

    while (1) {
        printf("\nMasukkan Kode Kota (MDN/BLG/JKT/SBY) atau 'END' untuk keluar: ");
        scanf("%s", kode);

        // Cek kondisi berhenti
        if (strcmp(kode, "END") == 0 || strcmp(kode, "end") == 0) {
            break;
        }

        printf("Masukkan Berat Paket Butet (kg): ");
        scanf("%f", &beratButet);

        // Logika penentuan kota dan ongkos
        if (strcmp(kode, "MDN") == 0) {
            strcpy(namaKota, "Medan");
            ongkosPerKg = 8000;
            strcpy(keterangan, "Dalam Pulau");
        } else if (strcmp(kode, "BLG") == 0) {
            strcpy(namaKota, "Balige");
            ongkosPerKg = 5000;
            strcpy(keterangan, "Dalam Pulau");
        } else if (strcmp(kode, "JKT") == 0) {
            strcpy(namaKota, "Jakarta");
            ongkosPerKg = 12000;
            strcpy(keterangan, "Luar Pulau");
        } else if (strcmp(kode, "SBY") == 0) {
            strcpy(namaKota, "Surabaya");
            ongkosPerKg = 13000;
            strcpy(keterangan, "Luar Pulau");
        } else {
            printf("Kode kota tidak valid!\n");
            continue;
        }

        // Hitung berat Ucok dan Total
        beratUcok = 1.5 * beratButet;
        totalBerat = beratButet + beratUcok;
        totalOngkos = totalBerat * ongkosPerKg;
        
        // Logika Promo
        strcpy(promo, "");
        diskon = 0;

        if (totalBerat > 10) {
            diskon = 0.1 * totalOngkos;
            totalOngkos -= diskon;
            strcat(promo, "Diskon 10% ");
        }
        
        if (strcmp(keterangan, "Luar Pulau") == 0) {
            strcat(promo, "+ Asuransi Gratis");
        }

        if (strlen(promo) == 0) {
            strcpy(promo, "Tidak ada promo");
        }

        // Output Struk 
        printf("\n======================================\n");
        printf("         STRUK PEMBAYARAN DEL EXPRES    \n");
        printf("======================================\n");
        printf("Kota Tujuan          : %s (%s)\n", namaKota, keterangan);
        printf("Berat Paket Butet    : %.2f kg\n", beratButet);
        printf("Berat Paket Ucok     : %.2f kg\n", beratUcok);
        printf("Total Berat          : %.2f kg\n", totalBerat);
        printf("Informasi Promo      : %s\n", promo);
        printf("--------------------------------------\n");
        printf("TOTAL ONGKOS KIRIM   : Rp %.2f\n", totalOngkos);
        printf("======================================\n");
    }

    printf("\nTerima kasih telah menggunakan layanan Del Expres!\n");
    return 0;
}