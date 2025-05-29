#include "../include/Karyawan.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<Karyawan> dataKaryawan;

void tambahKaryawan() {
    int id;
    string nama, jabatan;
    double gaji;

    cout << "Masukkan ID: "; cin >> id;
    cin.ignore();
    cout << "Nama: "; getline(cin, nama);
    cout << "Jabatan: "; getline(cin, jabatan);
    cout << "Gaji: "; cin >> gaji;

    dataKaryawan.emplace_back(id, nama, jabatan, gaji);
    cout << "Karyawan berhasil ditambahkan.\n";
}

void tampilkanSemua() {
    cout << "\n=== Data Karyawan ===\n";
    for (const auto& k : dataKaryawan) {
        k.tampilkan();
    }
}

void cariKaryawan() {
    int id;
    cout << "Masukkan ID yang dicari: ";
    cin >> id;
    for (const auto& k : dataKaryawan) {
        if (k.getId() == id) {
            k.tampilkan();
            return;
        }
    }
    cout << "Karyawan tidak ditemukan.\n";
}

void hapusKaryawan() {
    int id;
    cout << "Masukkan ID yang ingin dihapus: ";
    cin >> id;
    for (auto it = dataKaryawan.begin(); it != dataKaryawan.end(); ++it) {
        if (it->getId() == id) {
            dataKaryawan.erase(it);
            cout << "Data berhasil dihapus.\n";
            return;
        }
    }
    cout << "Karyawan tidak ditemukan.\n";
}

int main() {
    int pilihan;

    Karyawan::muatData(dataKaryawan);

    do {
        cout << "\n=== MENU MANAJEMEN KARYAWAN ===\n";
        cout << "1. Tambah Karyawan\n";
        cout << "2. Tampilkan Semua\n";
        cout << "3. Cari Karyawan\n";
        cout << "4. Hapus Karyawan\n";
        cout << "5. Simpan dan Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahKaryawan(); break;
            case 2: tampilkanSemua(); break;
            case 3: cariKaryawan(); break;
            case 4: hapusKaryawan(); break;
            case 5: Karyawan::simpanData(dataKaryawan); cout << "Data disimpan. Keluar...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
