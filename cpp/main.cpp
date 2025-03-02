
#include "Petshop.cpp"
#include "Aksesoris.cpp"
#include "Baju.cpp"
#include <iostream>
#include <vector>
#include <string>
// #include <iomanip>
#include <cstring>
#include <algorithm>

int main()
{
    std::vector<Petshop *> data;

    // Data Dummy
    data.push_back(new Petshop(1, "Whiskas", "Makanan_Kucing", 50000));
    data.push_back(new Aksesoris(2, "Collar Bell", "Aksesoris", 45000, "Kalung", "Kulit", "Hitam"));
    data.push_back(new Aksesoris(3, "Pet Bow", "Aksesoris", 25000, "Pita", "Kain", "Pink"));
    data.push_back(new Baju(4, "Sweater Dog", "Baju", 125000, "Jaket", "Wol", "Merah", "Anjing", "M", "PawStyle"));
    data.push_back(new Baju(5, "Cat Hoodie", "Baju", 99000, "Hoodie", "Katun", "Biru", "Kucing", "S", "MeowFashion"));

    while (true)
    {
        std::cout << "\nSelamat Datang di Database Petshop" << std::endl;
        std::cout << "Pilih Aksi yang Ingin Anda Lakukan" << std::endl;
        std::cout << "1. Tambah Data Petshop" << std::endl;
        std::cout << "2. Lihat Data Petshop" << std::endl;
        std::cout << "3. Keluar" << std::endl;

        int pilihan;
        std::cout << "Opsi yang Dipilih (1-3): ";

        std::cin >> pilihan;

        if (pilihan == 1)
        { // Tambah Data
            std::cout << "\nPilih Jenis Produk:" << std::endl;
            std::cout << "1. Produk Umum" << std::endl;
            std::cout << "2. Aksesoris" << std::endl;
            std::cout << "3. Baju" << std::endl;

            int jenis_produk;
            std::cout << "Pilih jenis produk (1-3): ";
            std::cin >> jenis_produk;

            // Clear input buffer
            std::cin.ignore();

            // Input data umum
            int tmp_id;
            std::cout << "Masukkan ID Produk: ";
            std::cin >> tmp_id;

            std::string tmp_nama;
            std::cout << "Masukkan Nama Produk: ";
            std::cin >> tmp_nama;

            std::string tmp_kategori;
            std::cout << "Masukkan Kategori Produk: ";
            std::cin >> tmp_kategori;

            int tmp_harga;
            std::cout << "Masukkan Harga Produk: ";
            std::cin >> tmp_harga;

            if (jenis_produk == 1)
            {
                data.push_back(new Petshop(tmp_id, tmp_nama, tmp_kategori, tmp_harga));
            }
            else if (jenis_produk == 2)
            {
                // Input data khusus Aksesoris
                std::string tmp_jenis, tmp_bahan, tmp_warna;

                std::cout << "Masukkan Jenis Aksesoris: ";
                std::cin >> tmp_jenis;

                std::cout << "Masukkan Bahan Aksesoris: ";
                std::cin >> tmp_bahan;

                std::cout << "Masukkan Warna Aksesoris: ";
                std::cin >> tmp_warna;

                data.push_back(new Aksesoris(tmp_id, tmp_nama, tmp_kategori, tmp_harga,
                                             tmp_jenis, tmp_bahan, tmp_warna));
            }
            else if (jenis_produk == 3)
            {
                // Input data khusus Aksesoris dan Baju
                std::string tmp_jenis, tmp_bahan, tmp_warna, tmp_untuk, tmp_size, tmp_merk;

                std::cout << "Masukkan Jenis Baju: ";
                std::cin >> tmp_jenis;

                std::cout << "Masukkan Bahan Baju: ";
                std::cin >> tmp_bahan;

                std::cout << "Masukkan Warna Baju: ";
                std::cin >> tmp_warna;

                // Input data khusus Baju
                std::cout << "Masukkan Target Pengguna Baju: ";
                std::cin >> tmp_untuk;

                std::cout << "Masukkan Ukuran Baju: ";
                std::cin >> tmp_size;

                std::cout << "Masukkan Merk Baju: ";
                std::cin >> tmp_merk;

                data.push_back(new Baju(tmp_id, tmp_nama, tmp_kategori, tmp_harga,
                                        tmp_jenis, tmp_bahan, tmp_warna,
                                        tmp_untuk, tmp_size, tmp_merk));
            }

            std::cout << "Data berhasil ditambahkan" << std::endl;
        }
        else if (pilihan == 2)
        {
            if (data.empty())
            {
                std::cout << "Data kosong" << std::endl;
            }
            else
            {
                // Define all possible headers
                std::vector<std::string> headers = {"ID", "Nama", "Kategori", "Harga", "Jenis", "Bahan", "Warna", "Untuk Hewan", "Ukuran", "Merk"};
                std::vector<int> max_lengths(headers.size());

                // Initialize max_lengths with header lengths
                for (size_t i = 0; i < headers.size(); i++)
                {
                    max_lengths[i] = headers[i].length();
                }

                // Update max lengths based on data
                for (Petshop *item : data)
                {
                    max_lengths[0] = std::max<size_t>(max_lengths[0], std::to_string(item->getID()).length());
                    max_lengths[1] = std::max<size_t>(max_lengths[1], item->getNama().length());
                    max_lengths[2] = std::max<size_t>(max_lengths[2], item->getKategori().length());
                    max_lengths[3] = std::max<size_t>(max_lengths[3], std::to_string(item->getHarga()).length());

                    if (item->getKategori() == "Aksesoris" || item->getKategori() == "Pakaian")
                    {
                        Aksesoris *aks = (Aksesoris *)item;
                        max_lengths[4] = std::max<size_t>(max_lengths[4], aks->getJenisAksesoris().length());
                        max_lengths[5] = std::max<size_t>(max_lengths[5], aks->getBahan().length());
                        max_lengths[6] = std::max<size_t>(max_lengths[6], aks->getWarna().length());

                        if (item->getKategori() == "Pakaian")
                        {
                            Baju *baju = (Baju *)item;
                            max_lengths[7] = std::max<size_t>(max_lengths[7], baju->getUntukHewan().length());
                            max_lengths[8] = std::max<size_t>(max_lengths[8], baju->getUkuran().length());
                            max_lengths[9] = std::max<size_t>(max_lengths[9], baju->getMerk().length());
                        }
                    }
                }

                // Calculate total width
                int total_width = 1;
                for (int width : max_lengths)
                {
                    total_width += width + 3; // +3 untuk spasi dan border
                }

                // Print top border and headers
                std::cout << std::string(total_width, '-') << std::endl;
                std::cout << "|";
                for (size_t i = 0; i < headers.size(); i++)
                {
                    std::cout << " " << std::setw(max_lengths[i]) << std::left << headers[i] << " |";
                }
                std::cout << std::endl;
                std::cout << std::string(total_width, '-') << std::endl;

                // Print data rows
                for (Petshop *item : data)
                {
                    std::cout << "|";
                    std::cout << " " << std::setw(max_lengths[0]) << std::left << item->getID() << " |";
                    std::cout << " " << std::setw(max_lengths[1]) << std::left << item->getNama() << " |";
                    std::cout << " " << std::setw(max_lengths[2]) << std::left << item->getKategori() << " |";
                    std::cout << " " << std::setw(max_lengths[3]) << std::right << item->getHarga() << " |"; // Right-align harga

                    if (item->getKategori() == "Aksesoris" || item->getKategori() == "Baju")
                    {
                        Aksesoris *aks = (Aksesoris *)item;
                        std::cout << " " << std::setw(max_lengths[4]) << std::left << aks->getJenisAksesoris() << " |";
                        std::cout << " " << std::setw(max_lengths[5]) << std::left << aks->getBahan() << " |";
                        std::cout << " " << std::setw(max_lengths[6]) << std::left << aks->getWarna() << " |";
                    }
                    else
                    {
                        std::cout << " " << std::setw(max_lengths[4]) << std::left << "-" << " |";
                        std::cout << " " << std::setw(max_lengths[5]) << std::left << "-" << " |";
                        std::cout << " " << std::setw(max_lengths[6]) << std::left << "-" << " |";
                    }

                    if (item->getKategori() == "Pakaian")
                    {
                        Baju *baju = (Baju *)item;
                        std::cout << " " << std::setw(max_lengths[7]) << std::left << baju->getUntukHewan() << " |";
                        std::cout << " " << std::setw(max_lengths[8]) << std::left << baju->getUkuran() << " |";
                        std::cout << " " << std::setw(max_lengths[9]) << std::left << baju->getMerk() << " |";
                    }
                    else
                    {
                        std::cout << " " << std::setw(max_lengths[7]) << std::left << "-" << " |";
                        std::cout << " " << std::setw(max_lengths[8]) << std::left << "-" << " |";
                        std::cout << " " << std::setw(max_lengths[9]) << std::left << "-" << " |";
                    }
                    std::cout << std::endl;
                }

                // Print bottom border
                std::cout << std::string(total_width, '-') << std::endl;
            }
        }

        else if (pilihan == 3)
        { // Keluar
            std::cout << "Terimakasih Telah Menggunakan Aplikasi ini" << std::endl;

            // Free allocated memory
            for (Petshop *item : data)
            {
                delete item;
            }

            break;
        }
        else
        {
            std::cout << "Pilihan Tidak Valid, harap pilih angka 1-3" << std::endl;
        }
    }

    return 0;
}