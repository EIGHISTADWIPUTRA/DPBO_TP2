from Aksesoris import Aksesoris

class Baju(Aksesoris):
    def __init__(self, ID=None, nama=None, kategori=None, harga=None, jenis=None, 
                 bahan=None, warna=None, untuk=None, size=None, merk=None):
        # Panggil parent class constructor
        super().__init__(ID, nama, kategori, harga, jenis, bahan, warna)
        # Atribut Baru
        self._untuk = untuk
        self._size = size
        self._merk = merk

    def getUntuk(self):
        """Fungsi untuk mendapatkan target pengguna baju"""
        return self._untuk

    def getSize(self):
        """Fungsi untuk mendapatkan ukuran baju"""
        return self._size

    def getMerk(self):
        """Fungsi untuk mendapatkan merk baju"""
        return self._merk

    def setUntuk(self, untuk):
        """Fungsi untuk menetapkan target pengguna baju"""
        self._untuk = untuk

    def setSize(self, size):
        """Fungsi untuk menetapkan ukuran baju"""
        self._size = size

    def setMerk(self, merk):
        """Fungsi untuk menetapkan merk baju"""
        self._merk = merk