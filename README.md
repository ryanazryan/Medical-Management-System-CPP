# Implementasi Multi Linked List - Sistem Data Berobat

[cite_start]Project ini adalah implementasi struktur data **Multi Linked List** dengan relasi **Many-to-Many (M:N)** untuk memodelkan sistem administrasi antara Dokter dan Pasien[cite: 34, 37]. [cite_start]Dibuat untuk memenuhi Tugas Besar mata kuliah Struktur Data Program Studi S1 Informatika, Universitas Telkom[cite: 33].

## 👥 Tim Pengembang
**Naufal Faiq Azryan** - 103042400047 
**Nadila Zari Fani** - 103042400053 

## 📋 Deskripsi Project
[cite_start]Sistem ini memungkinkan pengelolaan data dokter dan pasien, di mana seorang dokter dapat menangani banyak pasien, dan seorang pasien dapat ditangani oleh beberapa dokter dengan batasan **maksimal 5 dokter** per pasien[cite: 35]. [cite_start]Hubungan ini dikelola menggunakan **List Relasi** terpisah untuk menjaga independensi data induk[cite: 37, 38].



## 🛠️ Fitur Utama (Requirement a-i)
Program ini mencakup fungsionalitas lengkap sesuai spesifikasi tugas:
* **Manajemen Entitas:** Menambah dan menghapus data Dokter (Parent) serta Pasien (Child).
* [cite_start]**Manajemen Relasi:** Menghubungkan Dokter dengan Pasien dengan batasan validasi maksimal 5 dokter per pasien[cite: 35].
* **Pencarian Lanjut:** * Mencari pasien berdasarkan spesialisasi dokter.
    * Mencari daftar dokter yang menangani pasien tertentu.
* **Pelaporan & Statistik:** * Menampilkan seluruh data pasien beserta dokter yang menanganinya.
    * Mengurutkan data dokter berdasarkan tingkat kesibukan (jumlah pasien terbanyak).

## 🏗️ Struktur Data
Proyek ini menggunakan dua jenis Linked List yang berbeda untuk memenuhi kriteria teknis:
* **List Dokter:** Implementasi menggunakan Double Linked List.
* [cite_start]**List Pasien:** Implementasi menggunakan Double Linked List[cite: 60, 68].
* [cite_start]**List Relasi:** List perantara yang menghubungkan elemen Parent ke Child[cite: 37].

## 📂 Struktur File
* [cite_start]**tubes.h**: Definisi Abstract Data Type (ADT) dan prototipe fungsi[cite: 218, 224].
* [cite_start]**tubes.cpp**: Implementasi logika fungsional sistem[cite: 36].
* **main.cpp**: Program utama dengan menu interaktif untuk pengguna.

## 🚀 Cara Menjalankan
1. Clone repository ini.
2. Buka project menggunakan **Code::Blocks**.
3. *Build and Run* `main.cpp`.
