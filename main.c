#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PLTS_Data {
    int tahun;
    float energiHarian;
    float totalEnergi;
    int lokasi; // 1: Rumah, 2: Gedung, 3: Lahan
};

int main() {
    int tahunSimulasi, lokasi;
    float efisiensiPanel = 0.18, luasPanel = 50.0;
    int indexRangkuman = 0;

    struct PLTS_Data data = (struct PLTS_Data) calloc(100, sizeof(struct PLTS_Data));
    struct PLTS_Data rangkuman = (struct PLTS_Data) calloc(1000, sizeof(struct PLTS_Data));

    do {
        printf("=== SIMULASI PEMBANGKIT LISTRIK TENAGA SURYA ===\n");
        printf("Pilih Lokasi Pemasangan Panel:\n");
        printf("1. Atap Rumah\n2. Gedung Pemerintah\n3. Lahan Terbuka\n4. Keluar \n");
        printf("Masukkan pilihan: ");
        scanf("%d", &lokasi);

        if (lokasi >= 1 && lokasi <= 3) {
            printf("Masukkan jumlah tahun simulasi: ");
            scanf("%d", &tahunSimulasi);
            float faktor = faktorLokasi(lokasi);
            inputData(data, tahunSimulasi, efisiensiPanel * faktor, luasPanel, lokasi);
            tampilkanData(data, tahunSimulasi);

            // Salin data ke rangkuman
            for (int i = 0; i < tahunSimulasi; i++) {
                rangkuman[indexRangkuman++] = data[i];
            }

        } else if (lokasi != 4) {
            printf("Pilihan tidak valid.\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while (lokasi != 4);

    tampilkanRangkuman(rangkuman, indexRangkuman);

    free(data);
    free(rangkuman);

    printf("\nKeluar Program\n");
    return 0;
}