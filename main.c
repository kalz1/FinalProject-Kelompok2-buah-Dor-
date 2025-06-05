#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PLTS_Data {
    int tahun;
    float energiHarian;
    float totalEnergi;
    int lokasi; // 1: Rumah, 2: Gedung, 3: Lahan
};

const char* namaLokasi(int lokasi) {
    switch (lokasi) {
        case 1: return "Atap Rumah";
        case 2: return "Gedung Pemerintah";
        case 3: return "Lahan Terbuka";
        default: return "Tidak diketahui";
    }
}

float faktorLokasi(int lokasi) {
    switch (lokasi) {
        case 1: return 1.0;
        case 2: return 1.1;
        case 3: return 0.95;
        default: return 1.0;
    }
}

void inputData(struct PLTS_Data *data, int tahun, float efisiensi, float luasPanel, int lokasi) {
    for (int i = 0; i < tahun; i++) {
        data[i].tahun = i + 1;
        data[i].lokasi = lokasi;
        printf("Masukkan rata-rata energi harian (kWh/m²) untuk tahun ke-%d: ", i + 1);
        scanf("%f", &data[i].energiHarian);
        data[i].totalEnergi = data[i].energiHarian * 365 * efisiensi * luasPanel;
    }
}

void tampilkanData(struct PLTS_Data *data, int tahun) {
    float total = 0;

    printf("+--------+--------------------------+----------------------+---------------------+\n");
    printf("| Tahun  | Energi Harian (kWh/m²)  | Total Energi (kWh)   | Lokasi              |\n");
    printf("+--------+--------------------------+----------------------+---------------------+\n");

    for (int i = 0; i < tahun; i++) {
        printf("| %-6d | %-24.2f | %-20.2f | %-19s |\n",
            data[i].tahun, data[i].energiHarian, data[i].totalEnergi, namaLokasi(data[i].lokasi));
        total += data[i].totalEnergi;
    }

    printf("+--------+--------------------------+----------------------+---------------------+\n");
    printf("Total energi dalam %d tahun: %.2f kWh\n\n", tahun, total);
}

void tampilkanRangkuman(struct PLTS_Data *data, int totalInput) {
    float total = 0;

    printf("\n=============== RANGKUMAN SELURUH SIMULASI ===============\n");
    printf("+--------+--------------------------+----------------------+---------------------+\n");
    printf("| Tahun  | Energi Harian (kWh/m²)  | Total Energi (kWh)   | Lokasi              |\n");
    printf("+--------+--------------------------+----------------------+---------------------+\n");

    for (int i = 0; i < totalInput; i++) {
        printf("| %-6d | %-24.2f | %-20.2f | %-19s |\n",
            data[i].tahun, data[i].energiHarian, data[i].totalEnergi, namaLokasi(data[i].lokasi));
        total += data[i].totalEnergi;
    }

    printf("+--------+--------------------------+----------------------+---------------------+\n");
    printf("Total energi dari seluruh simulasi: %.2f kWh\n", total);
}

int main() {
    int tahunSimulasi, lokasi;
    float efisiensiPanel = 0.18, luasPanel = 50.0;
    int indexRangkuman = 0;

    struct PLTS_Data *data = (struct PLTS_Data*) calloc(100, sizeof(struct PLTS_Data));
    struct PLTS_Data *rangkuman = (struct PLTS_Data*) calloc(1000, sizeof(struct PLTS_Data));

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
