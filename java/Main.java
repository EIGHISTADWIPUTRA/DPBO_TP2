import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Petshop> data = new ArrayList<>();
        
        // Data Dummy
        data.add(new Petshop(1, "Whiskas", "Makanan_Kucing", 50000));
        data.add(new Aksesoris(2, "Collar Bell", "Aksesoris", 45000, "Kalung", "Kulit", "Hitam"));
        data.add(new Aksesoris(3, "Pet Bow", "Aksesoris", 25000, "Pita", "Kain", "Pink"));
        data.add(new Baju(4, "Sweater Dog", "Pakaian", 125000, "Sweater", "Wol", "Merah", "Anjing", "M", "PawStyle"));
        data.add(new Baju(5, "Cat Hoodie", "Pakaian", 99000, "Hoodie", "Katun", "Biru", "Kucing", "S", "MeowFashion"));

        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("\nSelamat Datang di Database Petshop");
            System.out.println("Pilih Aksi yang Ingin Anda Lakukan");
            System.out.println("1. Tambah Data Petshop");
            System.out.println("2. Lihat Data Petshop");
            System.out.println("3. Keluar");

            try {
                System.out.print("Opsi yang Dipilih (1-3): ");
                int pilihan = scanner.nextInt();
                scanner.nextLine(); // Clear buffer

                if (pilihan == 1) {
                    System.out.println("\nPilih Jenis Produk:");
                    System.out.println("1. Produk Umum");
                    System.out.println("2. Aksesoris");
                    System.out.println("3. Baju");
                    
                    System.out.print("Pilih jenis produk (1-3): ");
                    int jenisProduk = scanner.nextInt();
                    scanner.nextLine(); // Clear buffer
                    
                    // Input data umum
                    System.out.print("Masukkan ID Produk: ");
                    int tmpId = scanner.nextInt();
                    scanner.nextLine(); // Clear buffer
                    
                    System.out.print("Masukkan Nama Produk: ");
                    String tmpNama = scanner.nextLine();
                    
                    System.out.print("Masukkan Kategori Produk: ");
                    String tmpKategori = scanner.nextLine();
                    
                    System.out.print("Masukkan Harga Produk: ");
                    int tmpHarga = scanner.nextInt();
                    scanner.nextLine(); // Clear buffer

                    if (jenisProduk == 1) {
                        data.add(new Petshop(tmpId, tmpNama, tmpKategori, tmpHarga));
                    } 
                    else if (jenisProduk == 2) {
                        System.out.print("Masukkan Jenis Aksesoris: ");
                        String tmpJenis = scanner.nextLine();
                        
                        System.out.print("Masukkan Bahan Aksesoris: ");
                        String tmpBahan = scanner.nextLine();
                        
                        System.out.print("Masukkan Warna Aksesoris: ");
                        String tmpWarna = scanner.nextLine();
                        
                        data.add(new Aksesoris(tmpId, tmpNama, tmpKategori, tmpHarga,
                                             tmpJenis, tmpBahan, tmpWarna));
                    } 
                    else if (jenisProduk == 3) {
                        System.out.print("Masukkan Jenis Baju: ");
                        String tmpJenis = scanner.nextLine();
                        
                        System.out.print("Masukkan Bahan Baju: ");
                        String tmpBahan = scanner.nextLine();
                        
                        System.out.print("Masukkan Warna Baju: ");
                        String tmpWarna = scanner.nextLine();
                        
                        System.out.print("Masukkan Target Pengguna Baju: ");
                        String tmpUntuk = scanner.nextLine();
                        
                        System.out.print("Masukkan Ukuran Baju: ");
                        String tmpSize = scanner.nextLine();
                        
                        System.out.print("Masukkan Merk Baju: ");
                        String tmpMerk = scanner.nextLine();
                        
                        data.add(new Baju(tmpId, tmpNama, tmpKategori, tmpHarga,
                                        tmpJenis, tmpBahan, tmpWarna,
                                        tmpUntuk, tmpSize, tmpMerk));
                    }
                    
                    System.out.println("Data berhasil ditambahkan");
                } 
                else if (pilihan == 2) {
                    if (data.isEmpty()) {
                        System.out.println("Data kosong");
                    } else {
                        // Print table header
                        System.out.println("---------------------------------------------------------------------------------------------------------------------------------------------------------");
                        System.out.printf("| %-3s | %-20s | %-15s | %-10s | %-15s | %-15s | %-15s | %-15s | %-6s | %-15s |\n",
                                "ID", "Nama", "Kategori", "Harga", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk");
                        System.out.println("---------------------------------------------------------------------------------------------------------------------------------------------------------");

                        // Print data rows
                        for (Petshop item : data) {
                            String jenis = "-", bahan = "-", warna = "-", untuk = "-", size = "-", merk = "-";
                            
                            if (item instanceof Baju) {
                                Baju baju = (Baju) item;
                                jenis = baju.getJenis();
                                bahan = baju.getBahan();
                                warna = baju.getWarna();
                                untuk = baju.getUntuk();
                                size = baju.getSize();
                                merk = baju.getMerk();
                            } 
                            else if (item instanceof Aksesoris) {
                                Aksesoris aksesoris = (Aksesoris) item;
                                jenis = aksesoris.getJenis();
                                bahan = aksesoris.getBahan();
                                warna = aksesoris.getWarna();
                            }
                            
                            System.out.printf("| %-3d | %-20s | %-15s | %-10d | %-15s | %-15s | %-15s | %-15s | %-6s | %-15s|\n",
                                    item.getID(), item.getNama(), item.getKategori(), item.getHarga(),
                                    jenis, bahan, warna, untuk, size, merk);
                        }

                        System.out.println("---------------------------------------------------------------------------------------------------------------------------------------------------------");
                    }
                } 
                else if (pilihan == 3) {
                    System.out.println("Terimakasih Telah Menggunakan Aplikasi ini");
                    break;
                } 
                else {
                    System.out.println("Pilihan Tidak Valid, harap pilih angka 1-3");
                }
            } catch (Exception e) {
                System.out.println("Input tidak valid. Masukkan angka.");
                scanner.nextLine(); // Clear buffer
            }
        }
        scanner.close();
    }
}