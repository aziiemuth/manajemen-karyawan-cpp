#include "../include/Karyawan.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Karyawan::Karyawan() : id(0), gaji(0.0) {}

Karyawan::Karyawan(int id, const string& nama, const string& jabatan, double gaji)
    : id(id), nama(nama), jabatan(jabatan), gaji(gaji) {}

void Karyawan::tampilkan() const {
    cout << "ID: " << id
         << " | Nama: " << nama
         << " | Jabatan: " << jabatan
         << " | Gaji: " << gaji << endl;
}

int Karyawan::getId() const {
    return id;
}

void Karyawan::simpanData(const vector<Karyawan>& data) {
    ofstream file("../data/data_karyawan.txt");
    for (const auto& k : data) {
        file << k.id << ";" << k.nama << ";" << k.jabatan << ";" << k.gaji << "\n";
    }
    file.close();
}

void Karyawan::muatData(vector<Karyawan>& data) {
    data.clear();
    ifstream file("../data/data_karyawan.txt");
    string line;
    while (getline(file, line)) {
        int id;
        string nama, jabatan;
        double gaji;

        size_t p1 = line.find(";");
        size_t p2 = line.find(";", p1 + 1);
        size_t p3 = line.find(";", p2 + 1);

        id = stoi(line.substr(0, p1));
        nama = line.substr(p1 + 1, p2 - p1 - 1);
        jabatan = line.substr(p2 + 1, p3 - p2 - 1);
        gaji = stod(line.substr(p3 + 1));

        data.emplace_back(id, nama, jabatan, gaji);
    }
    file.close();
}
