#pragma once
#include "Aksesoris.cpp"

class Baju : public Aksesoris
{
private:
    std::string untuk_hewan;
    std::string ukuran;
    std::string merk;

public:
    Baju(int id, std::string nama, std::string jenis, int harga,
         std::string jenis_aksesoris, std::string bahan, std::string warna,
         std::string untuk_hewan, std::string ukuran, std::string merk)
        : Aksesoris(id, nama, jenis, harga, jenis_aksesoris, bahan, warna)
    {
        this->untuk_hewan = untuk_hewan;
        this->ukuran = ukuran;
        this->merk = merk;
    }

    // Getters
    std::string getUntukHewan() { return untuk_hewan; }
    std::string getUkuran() { return ukuran; }
    std::string getMerk() { return merk; }
};