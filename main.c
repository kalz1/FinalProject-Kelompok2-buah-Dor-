#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PLTS_Data {
    int tahun;
    float energiHarian;
    float totalEnergi;
    int lokasi; // 1: Rumah, 2: Gedung, 3: Lahan
};

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

int main(){
    

    return 0;
}