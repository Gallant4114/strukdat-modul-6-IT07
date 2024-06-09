# FINAL PROJECT STRUKDAT MODUL 6
## Kelompok IT07
### Anggota Kelompok :
|             Nama              |     NRP    |
|-------------------------------|------------|
| Furqon Aryadana               | 5027231024 |
| Gallant Damas Hayuaji         | 5027231037 |
| M. Fadhil Saifullah           | 5027231068 |



# BookStore Management System

Sistem ini adalah implementasi sederhana dari sistem manajemen toko buku menggunakan C++. Sistem ini memungkinkan pengguna untuk mengelola item-item yang tersedia di toko buku, menambahkannya ke dalam receipt, mengubah jumlah item dalam receipt, menampilkan receipt saat ini, serta menghapus item dari receipt.

## Fitur Utama

- **Tambahkan Item ke Receipt**: Menambahkan item yang tersedia di toko buku ke dalam receipt dengan jumlah yang diinginkan.
- **Tampilkan Receipt Saat Ini**: Menampilkan semua item yang ada di receipt, jumlah masing-masing item, harga masing-masing item, dan total harga.
- **Ubah Jumlah Item dalam Receipt**: Mengubah jumlah item tertentu dalam receipt.
- **Hapus Item dari Receipt**: Menghapus item tertentu dari receipt.

## Konsep OOP yang Diterapkan

- **Class & Object**: Kelas `ItemBase`, `Item`, `PaperItem`, `NonPaperItem`, `ReceiptItem`, dan `Receipt` digunakan untuk mendefinisikan item dan receipt.
- **Attribute Property and Method Behavior**: Atribut dan metode disusun secara logis dalam kelas.
- **Constructor**: Konstruktor digunakan untuk inisialisasi objek, seperti dalam kelas `Item` dan `ReceiptItem`.
- **Setter & Getter**: Metode getter (`getId`, `getName`, `getPrice`, `getItem`, `getJumlah`) digunakan untuk mengakses atribut privat. Metode setter (`setJumlah`) digunakan untuk mengubah nilai atribut.
- **Encapsulation**: Atribut privat (`id`, `name`, `price`, `item`, `jumlah`) hanya dapat diakses melalui metode publik.
- **Inheritance**: Kelas `PaperItem` dan `NonPaperItem` mewarisi dari kelas `Item`.
- **Overriding**: Metode `getId`, `getName`, dan `getPrice` di kelas `Item` mengoverride metode abstrak di kelas `ItemBase`.
- **Access Modifier / Visibility**: Penggunaan `private` untuk atribut dan `public` untuk metode untuk mengatur aksesibilitas.
- **Abstraction**: Kelas abstrak `ItemBase` memberikan antarmuka umum untuk kelas `Item`.
- **Polymorphism**: Penggunaan polimorfisme terlihat pada kelas turunan `PaperItem` dan `NonPaperItem` dari kelas `Item`.

## Penggunaan

1. **Kompilasi Kode**:
2. **Jalankan Program**:
3. **Menu Interaktif**:
   - Pilih opsi untuk menambahkan item ke receipt, menampilkan receipt saat ini, mengubah jumlah item dalam receipt, atau menghapus item dari receipt.
   - Ikuti petunjuk di layar untuk memasukkan ID item dan jumlah.

## Contoh Item yang Tersedia

- Buku (Kertas)
- Folio (Kertas)
- Pensil (Non-Kertas)
- Penghapus (Non-Kertas)
- Bolpoin (Non-Kertas)
- Penggaris (Non-Kertas)
- Lem (Non-Kertas)
- Klip Kertas (Non-Kertas)
- Spidol (Non-Kertas)
- Jangka (Non-Kertas)


