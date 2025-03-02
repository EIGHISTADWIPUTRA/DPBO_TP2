<?php
// Start the session if not already started
if (session_status() === PHP_SESSION_NONE) {
    session_start();
}


// Include required classes
require_once 'Petshop.php';
require_once 'Aksesoris.php';
require_once 'Baju.php';

// Create dummy data
$data = [];

// 1 Petshop data
$data[] = new Petshop(1, "Dog Food Premium Gacor", "Makanan", 150000, "dogfood.jpg");

// 2 Aksesoris data
$data[] = new Aksesoris(2, "Kalung Gugug", "Aksesoris", 75000, "kalung.jpg", "Kalung", "Kulit", "Coklat");
$data[] = new Aksesoris(3, "Mangkuk Anabul", "Aksesoris", 45000, "mangkok.jpg", "Mangkok", "Stainless", "Silver");

// 2 Baju data
$data[] = new Baju(4, "Outfit Ronda", "Pakaian", 120000, "ronda.jpg", "ngeronda", "Kain", "Hijau", "Kucing", "M", "MengFashion");
$data[] = new Baju(5, "Outfit Sekolah", "Pakaian", 180000, "sekolah.jpg", "seragam", "kain", "Putih", "Kucing", "S", "MengFashion");


// Store data in session
$_SESSION['data'] = $data;

// Initialize session data if not set
if (!isset($_SESSION['data'])) {
    $_SESSION['data'] = []; // Initialize as an empty array
}

// Pagination logic
$itemsPerPage = 10;
$totalItems = count($_SESSION['data']);
$totalPages = ceil($totalItems / $itemsPerPage);
$currentPage = isset($_GET['page']) ? (int)$_GET['page'] : 1;
$currentPage = max(1, min($currentPage, $totalPages)); // Ensure current page is within bounds

// Calculate the offset for the current page
$offset = ($currentPage - 1) * $itemsPerPage;
$currentItems = array_slice($_SESSION['data'], $offset, $itemsPerPage);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Petshop</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
</head>
<body>
<div class="container mt-5">
    <h2 class="text-center">Data Produk Petshop</h2>
    
    <table class="table table-bordered mt-4">
        <thead>
            <tr>
                <th>ID</th>
                <th>Nama</th>
                <th>Kategori</th>
                <th>Harga</th>
                <th>Gambar</th>
                <th>Jenis</th>
                <th>Bahan</th>
                <th>Warna</th>
                <th>Untuk</th>
                <th>Size</th>
                <th>Merk</th>
                
            </tr>
        </thead>
        <tbody>
            <?php if (empty($currentItems)): ?>
                <tr>
                    <td colspan="11" class="text-center">Data kosong</td>
                </tr>
            <?php else: ?>
                <?php foreach ($currentItems as $item): ?>
                    <tr>
                        <td><?php echo htmlspecialchars($item->getID()); ?></td>
                        <td><?php echo htmlspecialchars($item->getNama()); ?></td>
                        <td><?php echo htmlspecialchars($item->getKategori()); ?></td>
                        <td><?php echo htmlspecialchars($item->getHarga()); ?></td>
                        <td><img src="img/<?php echo htmlspecialchars($item->getGambarProduk()); ?>" alt="Product Image" style="width: 100px;"></td>
                        <td><?php echo htmlspecialchars($item instanceof Aksesoris ? $item->getJenis() : ($item instanceof Baju ? $item->getJenis() : '-')); ?></td>
                        <td><?php echo htmlspecialchars($item instanceof Aksesoris ? $item->getBahan() : ($item instanceof Baju ? $item->getBahan() : '-')); ?></td>
                        <td><?php echo htmlspecialchars($item instanceof Aksesoris ? $item->getWarna() : ($item instanceof Baju ? $item->getWarna() : '-')); ?></td>
                        <td><?php echo htmlspecialchars($item instanceof Baju ? $item->getUntuk() : '-'); ?></td>
                        <td><?php echo htmlspecialchars($item instanceof Baju ? $item->getSize() : '-'); ?></td>
                        <td><?php echo htmlspecialchars($item instanceof Baju ? $item->getMerk() : '-'); ?></td>
                    </tr>
                <?php endforeach; ?>
            <?php endif; ?>
        </tbody>
    </table>
    
    <nav aria-label="Page navigation" class="mt-4">
        <ul class="pagination justify-content-center">
            <?php for ($i = 1; $i <= $totalPages; $i++): ?>
                <li class="page-item <?php echo $i === $currentPage ? 'active' : ''; ?>">
                    <a class="page-link" href="?page=<?php echo $i; ?>"><?php echo $i; ?></a>
                </li>
            <?php endfor; ?>
        </ul>
    </nav>
</div>

<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
