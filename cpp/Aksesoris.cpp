#pragma once
#include "Petshop.cpp"

class Aksesoris : public Petshop
{
private:
    std::string jenis_aksesoris;
    std::string bahan;
    std::string warna;

public:
    Aksesoris(int id, std::string nama, std::string jenis, int harga,
              std::string jenis_aksesoris, std::string bahan, std::string warna)
        : Petshop(id, nama, jenis, harga)
    {
        this->jenis_aksesoris = jenis_aksesoris;
        this->bahan = bahan;
        this->warna = warna;
    }

    // Getters
    std::string getJenisAksesoris() { return jenis_aksesoris; }
    std::string getBahan() { return bahan; }
    std::string getWarna() { return warna; }

    ~Aksesoris() // Destruktor
    {
    }
};