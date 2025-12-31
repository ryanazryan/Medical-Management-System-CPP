# Implementasi Multi Linked List - Sistem Data Berobat

Project ini adalah implementasi struktur data **Multi Linked List** dengan relasi **Many-to-Many (M:N)** untuk memodelkan sistem administrasi antara Dokter dan Pasien. Dibuat untuk memenuhi Tugas Besar mata kuliah Struktur Data Program Studi S1 Informatika, Universitas Telkom.

## 👥 Tim Pengembang
* **Naufal Faiq Azryan** - 103042400047 
* **Nadila Zari Fani** - 103042400053
* **Kelas:** IF-48-01 PJJ
* **Fakultas:** Fakultas Informatika, Universitas Telkom

## 📋 Deskripsi Project
Sistem ini memungkinkan pengelolaan data dokter dan pasien, di mana seorang dokter dapat menangani banyak pasien, dan seorang pasien dapat ditangani oleh beberapa dokter dengan batasan **maksimal 5 dokter** per pasien. Hubungan ini dikelola menggunakan **List Relasi** terpisah untuk menjaga independensi data induk.



## 🛠️ Fitur Utama (Requirement a-i)
Program ini mencakup fungsionalitas lengkap sesuai spesifikasi tugas:
* **Manajemen Entitas:** Menambah dan menghapus data Dokter (Parent) serta Pasien (Child).
* **Manajemen Relasi:** Menghubungkan Dokter dengan Pasien dengan batasan validasi maksimal 5 dokter per pasien.
* **Pencarian Lanjut:** * Mencari pasien berdasarkan spesialisasi dokter.
    * Mencari daftar dokter yang menangani pasien tertentu.
* **Pelaporan & Statistik:** * Menampilkan seluruh data pasien beserta dokter yang menanganinya.
    * Mengurutkan data dokter berdasarkan tingkat kesibukan (jumlah pasien terbanyak).

## 🏗️ Struktur Data
Proyek ini menggunakan dua jenis Linked List yang berbeda untuk memenuhi kriteria teknis:
* **List Dokter:** Implementasi menggunakan Double Linked List.
* **List Pasien:** Implementasi menggunakan Double Linked List.
* **List Relasi:** List perantara yang menghubungkan elemen Parent ke Child.

## 📂 Struktur File
* **tubes.h**: Definisi Abstract Data Type (ADT) dan prototipe fungsi.
* **tubes.cpp**: Implementasi logika fungsional sistem.
* **main.cpp**: Program utama dengan menu interaktif untuk pengguna.

## 🚀 Cara Menjalankan
1. Clone repository ini.
2. Buka project menggunakan **Code::Blocks**.
3. *Build and Run* `main.cpp`.
