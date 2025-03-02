<?php
require_once 'Petshop.php';

class Aksesoris extends Petshop {
    private $jenis;
    private $bahan;
    private $warna;

    public function __construct($ID, $nama, $kategori, $harga, $gambar_produk, $jenis, $bahan, $warna) {
        parent::__construct($ID, $nama, $kategori, $harga, $gambar_produk);
        $this->jenis = $jenis;
        $this->bahan = $bahan;
        $this->warna = $warna;
    }

    public function getJenis() {
        return $this->jenis;
    }

    public function getBahan() {
        return $this->bahan;
    }

    public function getWarna() {
        return $this->warna;
    }
}
?>
