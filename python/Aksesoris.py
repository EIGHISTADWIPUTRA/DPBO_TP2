from Petshop import Petshop

class Aksesoris(Petshop):
    def __init__(self, ID=None, nama=None, kategori=None, harga=None, jenis=None, bahan=None, warna=None):
        # Panggil parent class constructor
        super().__init__(ID, nama, kategori, harga)
        # Atribut Baru
        self._jenis = jenis
        self._bahan = bahan
        self._warna = warna

    def getJenis(self):
        """Fungsi untuk mendapatkan jenis aksesoris"""
        return self._jenis

    def getBahan(self):
        """Fungsi untuk mendapatkan bahan aksesoris"""
        return self._bahan

    def getWarna(self):
        """Fungsi untuk mendapatkan warna aksesoris"""
        return self._warna

    def setJenis(self, jenis):
        """Fungsi untuk menetapkan jenis aksesoris"""
        self._jenis = jenis

    def setBahan(self, bahan):
        """Fungsi untuk menetapkan bahan aksesoris"""
        self._bahan = bahan

    def setWarna(self, warna):
        """Fungsi untuk menetapkan warna aksesoris"""
        self._warna = warna


