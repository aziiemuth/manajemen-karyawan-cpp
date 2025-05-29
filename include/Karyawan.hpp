#ifndef KARYAWAN_HPP
#define KARYAWAN_HPP

#include <string>
#include <vector>

class Karyawan {
private:
    int id;
    std::string nama;
    std::string jabatan;
    double gaji;

public:
    Karyawan();
    Karyawan(int id, const std::string& nama, const std::string& jabatan, double gaji);

    void tampilkan() const;
    int getId() const;

    static void simpanData(const std::vector<Karyawan>& data);
    static void muatData(std::vector<Karyawan>& data);
};

#endif
