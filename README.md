# FINAL PROJECT STRUKDAT MODUL 6
## Kelompok IT07
### Anggota Kelompok :
|             Nama              |     NRP    |
|-------------------------------|------------|
| Furqon Aryadana               | 5027231024 |
| Gallant Damas Hayuaji         | 5027231037 |
| M. Fadhil Saifullah           | 5027231068 |

# BookStore Management System

Sistem ini adalah implementasi sederhana dari sistem manajemen toko buku dengan menggunakan C++. Sistem ini memungkinkan pengguna untuk mengelola item-item yang ada di dalam toko buku, menambahkannya ke receipt, mengubah jumlah item dalam receipt, menampilkan receipt saat ini, serta menghapus item dari receipt.

## Fitur Utama
- **Tambahkan Item ke Receipt**: Menambahkan item yang tersedia di toko buku ke receipt dengan jumlah yang diinginkan.
- **Tampilkan Receipt Saat Ini**: Menampilkan semua item yang telah ditambahkan ke receipt beserta jumlah dan total harga.
- **Ubah Jumlah Item dari Receipt**: Memungkinkan pengguna untuk mengubah jumlah item yang sudah ada di receipt.
- **Hapus Item dari Receipt**: Menghapus item tertentu dari receipt.
- **Keluar**: Mengakhiri program.

## Kelas Utama
### 1. Item
Merepresentasikan item di toko buku dengan atribut:
- `id` (int): ID unik untuk setiap item.
- `name` (string): Nama item.
- `price` (double): Harga item.

### 2. ReceiptItem
Merepresentasikan item dalam receipt dengan atribut:
- `item` (Item): Objek item.
- `jumlah` (int): Jumlah item dalam receipt.

### 3. Receipt
Merepresentasikan receipt dengan atribut:
- `items` (vector<ReceiptItem>): Vektor yang menyimpan semua item dalam receipt.

## Metode Utama
### Item
- **Konstruktor**: `Item(string name, double price)`

### ReceiptItem
- **Konstruktor**: `ReceiptItem(const Item& item, int jumlah)`

### Receipt
- **addItem**: Menambahkan item ke dalam receipt.
- **displayReceipt**: Menampilkan semua item dalam receipt.
- **updateItemJumlah**: Mengubah jumlah item dalam receipt.
- **removeItem**: Menghapus item dari receipt.

## Cara Penggunaan
1. Kompilasi dan jalankan program.
2. Pilih opsi dari menu yang ditampilkan:
   - `1`: Tambahkan item ke receipt.
   - `2`: Tampilkan receipt saat ini.
   - `3`: Ubah jumlah item dari receipt.
   - `4`: Hapus item dari receipt.
   - `5`: Keluar dari program.
3. Ikuti instruksi yang diberikan untuk setiap opsi.

## Contoh Penggunaan
### Tambahkan Item ke Receipt
- Pilih opsi `1`.
- Lihat daftar item yang tersedia.
- Masukkan ID item yang ingin ditambahkan.
- Masukkan jumlah item yang ingin ditambahkan.

### Tampilkan Receipt Saat Ini
- Pilih opsi `2`.
- Sistem akan menampilkan semua item yang telah ditambahkan ke receipt beserta detailnya.

### Ubah Jumlah Item dari Receipt
- Pilih opsi `3`.
- Masukkan ID item yang jumlahnya ingin diubah.
- Masukkan jumlah baru untuk item tersebut.

### Hapus Item dari Receipt
- Pilih opsi `4`.
- Masukkan ID item yang ingin dihapus dari receipt.

### Keluar
- Pilih opsi `5` untuk keluar dari program.

## Daftar Item yang Tersedia
- Buku (5000)
- Pensil (2500)
- Penghapus (4000)
- Bolpoin (3000)
- Penggaris (10000)
- Lem (8000)
- Klip Kertas (12000)
- Folio (40000)
- Spidol (5000)
- Jangka (20000)

