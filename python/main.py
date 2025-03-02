from Petshop import Petshop
from Aksesoris import Aksesoris
from Baju import Baju

def main():
    data = []
    
    # Data Dummy
    data.append(Petshop(1, "Whiskas", "Makanan_Kucing", 50000))
    data.append(Aksesoris(2, "Collar Bell", "Aksesoris", 45000, "Kalung", "Kulit", "Hitam"))
    data.append(Aksesoris(3, "Pet Bow", "Aksesoris", 25000, "Pita", "Kain", "Pink"))
    data.append(Baju(4, "Sweater Dog", "Baju", 125000, "Sweater", "Wol", "Merah", "Anjing", "M", "PawStyle"))
    data.append(Baju(5, "Cat Hoodie", "Baju", 99000, "Hoodie", "Katun", "Biru", "Kucing", "S", "MeowFashion"))

    while True: 
        print("\nSelamat Datang di Database Petshop")
        print("Pilih Aksi yang Ingin Anda Lakukan")
        print("1. Tambah Data Petshop")
        print("2. Lihat Data Petshop")
        print("3. Keluar")

        try:
            pilihan = int(input("Opsi yang Dipilih (1-3): "))
            
            if pilihan == 1:  # Tambah Data
                print("\nPilih Jenis Produk:")
                print("1. Produk Umum")
                print("2. Aksesoris")
                print("3. Baju")
                
                jenis_produk = int(input("Pilih jenis produk (1-3): "))
                
                # Input data umum
                tmp_id = int(input("Masukkan ID Produk: "))
                tmp_nama = input("Masukkan Nama Produk: ")
                tmp_kategori = input("Masukkan Kategori Produk: ")
                tmp_harga = int(input("Masukkan Harga Produk: "))
                
                if jenis_produk == 1:
                    tmp = Petshop(tmp_id, tmp_nama, tmp_kategori, tmp_harga)
                    
                elif jenis_produk == 2:
                    # Input data khusus Aksesoris
                    tmp_jenis = input("Masukkan Jenis Aksesoris: ")
                    tmp_bahan = input("Masukkan Bahan Aksesoris: ")
                    tmp_warna = input("Masukkan Warna Aksesoris: ")
                    
                    tmp = Aksesoris(tmp_id, tmp_nama, tmp_kategori, tmp_harga, 
                                tmp_jenis, tmp_bahan, tmp_warna)
                    
                elif jenis_produk == 3:
                    # Input data khusus Aksesoris
                    tmp_jenis = input("Masukkan Jenis Baju: ")
                    tmp_bahan = input("Masukkan Bahan Baju: ")
                    tmp_warna = input("Masukkan Warna Baju: ")
                    # Input data khusus Baju
                    tmp_untuk = input("Masukkan Target Pengguna Baju: ")
                    tmp_size = input("Masukkan Ukuran Baju: ")
                    tmp_merk = input("Masukkan Merk Baju: ")
                    
                    tmp = Baju(tmp_id, tmp_nama, tmp_kategori, tmp_harga,
                            tmp_jenis, tmp_bahan, tmp_warna,
                            tmp_untuk, tmp_size, tmp_merk)
                
                data.append(tmp)
                print("Data berhasil ditambahkan")

            elif pilihan == 2:  # Lihat Data
                if len(data) == 0:
                    print("Data kosong")
                else:
                    # Define all possible attributes
                    headers = ["ID", "Nama", "Kategori", "Harga", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"]
                    
                    # Get maximum lengths for each column including headers
                    max_lengths = {header: len(header) for header in headers}
                    
                    # Update max lengths based on data
                    for item in data:
                        max_lengths["ID"] = max(max_lengths["ID"], len(str(item.getID())))
                        max_lengths["Nama"] = max(max_lengths["Nama"], len(item.getNama()))
                        max_lengths["Kategori"] = max(max_lengths["Kategori"], len(item.getKategori()))
                        max_lengths["Harga"] = max(max_lengths["Harga"], len(str(item.getHarga())))
                        
                        if isinstance(item, (Aksesoris, Baju)):
                            max_lengths["Jenis"] = max(max_lengths["Jenis"], len(item.getJenis()))
                            max_lengths["Bahan"] = max(max_lengths["Bahan"], len(item.getBahan()))
                            max_lengths["Warna"] = max(max_lengths["Warna"], len(item.getWarna()))
                            
                        if isinstance(item, Baju):
                            max_lengths["Untuk"] = max(max_lengths["Untuk"], len(item.getUntuk()))
                            max_lengths["Size"] = max(max_lengths["Size"], len(item.getSize()))
                            max_lengths["Merk"] = max(max_lengths["Merk"], len(item.getMerk()))

                    # Create format string for table
                    format_str = "| " + " | ".join("{:<" + str(max_lengths[header]) + "}" for header in headers) + " |"
                    
                    # Calculate total width
                    total_width = sum(max_lengths.values()) + (len(headers) * 3) + 1
                    
                    # Print header
                    print("-" * total_width)
                    print(format_str.format(*headers))
                    print("-" * total_width)
                    
                    # Print data
                    for item in data:
                        row_data = [
                            str(item.getID()),
                            item.getNama(),
                            item.getKategori(),
                            str(item.getHarga()),
                            item.getJenis() if isinstance(item, (Aksesoris, Baju)) else "-",
                            item.getBahan() if isinstance(item, (Aksesoris, Baju)) else "-",
                            item.getWarna() if isinstance(item, (Aksesoris, Baju)) else "-",
                            item.getUntuk() if isinstance(item, Baju) else "-",
                            item.getSize() if isinstance(item, Baju) else "-",
                            item.getMerk() if isinstance(item, Baju) else "-"
                        ]
                        print(format_str.format(*row_data))
                    print("-" * total_width)


            elif pilihan == 3:  # Keluar
                print("Terimakasih Telah Menggunakan Aplikasi ini")
                break

            else:
                print("Pilihan Tidak Valid, harap pilih angka 1-6")

        except ValueError:
            print("Input tidak valid. Masukkan angka.")

if __name__ == "__main__":
    main()