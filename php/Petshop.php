<?php
class Petshop {
    protected $ID;
    protected $nama;
    protected $kategori;
    protected $harga;
    protected $gambar_produk;

    public function __construct($ID, $nama, $kategori, $harga, $gambar_produk) {
        $this->ID = $ID;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->harga = $harga;
        $this->gambar_produk = $gambar_produk;
    }

    public function getID() {
        return $this->ID;
    }

    public function getNama() {
        return $this->nama;
    }

    public function getKategori() {
        return $this->kategori;
    }

    public function getHarga() {
        return $this->harga;
    }

    public function getGambarProduk() {
        return $this->gambar_produk;
    }
}
?>
