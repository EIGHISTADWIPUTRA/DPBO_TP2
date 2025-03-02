class Baju extends Aksesoris {
    private String untuk;
    private String size;
    private String merk;

    public Baju(Integer ID, String nama, String kategori, Integer harga, String jenis, String bahan, String warna, String untuk, String size, String merk) {
        super(ID, nama, kategori, harga, jenis, bahan, warna);
        this.untuk = untuk;
        this.size = size;
        this.merk = merk;
    }

    public String getUntuk() {
        return untuk;
    }

    public void setUntuk(String untuk) {
        this.untuk = untuk;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public String getMerk() {
        return merk;
    }

    public void setMerk(String merk) {
        this.merk = merk;
    }
}