#include "tubes.h"

void createListDokter(List_Dokter &L) {
    L.first = NULL;
    L.last = NULL;
}

address_dokter createElmDokter(infotype_dokter data) {
    address_dokter P = new elm_dokter;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;

    P->childs.first = NULL;

    return P;
}

void insertLastDokter(List_Dokter &L, address_dokter P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void showDokter(List_Dokter L) {
    address_dokter P = L.first;
    if (P == NULL) {
        cout << "Data Dokter kosong." << endl;
    } else {
        cout << "=== DATA DOKTER ===" << endl;
        while (P != NULL) {
            cout << "Kode: " << P->info.kodeDokter << endl;
            cout << "Nama: " << P->info.namaDokter << endl;
            cout << "Spesialis: " << P->info.spesialisasi << endl;
            cout << "-------------------" << endl;
            P = P->next;
        }
    }
}

// Membuat List Pasien Kosong
void createListPasien(List_Pasien &L) {
    L.first = NULL;
    L.last = NULL;
}

// Membuat Element Pasien Baru
address_pasien createElmPasien(infotype_pasien data) {
    address_pasien P = new elm_pasien;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Insert Pasien ke Belakang
void insertLastPasien(List_Pasien &L, address_pasien P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// Menampilkan Data Pasien
void showPasien(List_Pasien L) {
    address_pasien P = L.first;
    if (P == NULL) {
        cout << "Data Pasien kosong." << endl;
    } else {
        cout << "=== DATA PASIEN ===" << endl;
        while (P != NULL) {
            cout << "ID  : " << P->info.idPasien << endl;
            cout << "Nama: " << P->info.namaPasien << endl;
            cout << "Umur: " << P->info.umur << endl;
            cout << "-------------------" << endl;
            P = P->next;
        }
    }
}

address_dokter findDokter(List_Dokter L, int kode) {
    address_dokter P = L.first;
    while (P != NULL) {
        if (P->info.kodeDokter == kode) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

address_pasien findPasien(List_Pasien L, int id) {
    address_pasien P = L.first;
    while (P != NULL) {
        if (P->info.idPasien == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int countDoctorsOfPatient(List_Dokter LD, address_pasien P) {
    int count = 0;
    address_dokter D = LD.first;
    while (D != NULL) {
        address_relasi R = D->childs.first;
        while (R != NULL) {
            if (R->info == P) {
                count++;
                break;
            }
            R = R->next;
        }
        D = D->next;
    }
    return count;
}

void connect(List_Dokter &LD, address_dokter D, address_pasien P) {
    if (D != NULL && P != NULL) {
        if (countDoctorsOfPatient(LD, P) >= 5) {
            cout << "Gagal: Pasien " << P->info.namaPasien << " sudah memiliki maksimal 5 dokter!" << endl;
            return;
        }
        address_relasi R = D->childs.first;
        bool found = false;
        while (R != NULL) {
            if (R->info == P) {
                found = true;
                break;
            }
            R = R->next;
        }

        if (!found) {
            address_relasi newR = createElmRelasi(P);
            insertLastRelasi(D->childs, newR);
            cout << "Berhasil menghubungkan " << D->info.namaDokter
                 << " dengan Pasien " << P->info.namaPasien << endl;
        } else {
            cout << "Pasien sudah terdaftar di dokter ini!" << endl;
        }
    }
}


address_relasi createElmRelasi(address_pasien P) {
    address_relasi R = new elm_relasi;
    R->info = P;
    R->next = NULL;
    return R;
}

void insertLastRelasi(List_Relasi &L, address_relasi R) {
    if (L.first == NULL) {
        L.first = R;
    } else {
        address_relasi Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

void connect(address_dokter D, address_pasien P) {
    if (D != NULL && P != NULL) {
        address_relasi R = D->childs.first;
        bool found = false;
        while (R != NULL) {
            if (R->info == P) {
                found = true;
                break;
            }
            R = R->next;
        }

        if (!found) {
            address_relasi newR = createElmRelasi(P);
            insertLastRelasi(D->childs, newR);
            cout << "Berhasil menghubungkan " << D->info.namaDokter
                 << " dengan Pasien " << P->info.namaPasien << endl;
        } else {
            cout << "Pasien sudah terdaftar di dokter ini!" << endl;
        }
    }
}

void showDokterSpesifik(address_dokter D) {
    if (D == NULL) return;
    cout << "\n>>> Data Dokter: " << D->info.namaDokter << " (" << D->info.spesialisasi << ")" << endl;
    cout << "    Daftar Pasien:" << endl;

    address_relasi R = D->childs.first;
    if (R == NULL) {
        cout << "    - (Belum ada pasien)" << endl;
    } else {
        while (R != NULL) {
            cout << "    - " << R->info->info.namaPasien
                 << " (ID: " << R->info->info.idPasien << ")" << endl;
            R = R->next;
        }
    }
}

// Menghitung jumlah dokter yang menangani seorang pasien
int countDokterByPasien(List_Dokter LD, address_pasien P) {
    int jumlah = 0;
    address_dokter D = LD.first;

    while (D != NULL) {
        address_relasi R = D->childs.first;

        while (R != NULL) {
            if (R->info == P) {
                jumlah++;
                break;
            }
            R = R->next;
        }
        D = D->next;
    }
    return jumlah;
}

// Menampilkan daftar dokter yang menangani pasien tertentu
void showDokterByPasien(List_Dokter LD, address_pasien P) {
    if (P == NULL) return;

    cout << "\n>>> Pasien: " << P->info.namaPasien << " (ID: " << P->info.idPasien << ")" << endl;
    cout << "    Ditangani oleh Dokter:" << endl;

    bool adaDokter = false;
    address_dokter D = LD.first;

    while (D != NULL) {
        address_relasi R = D->childs.first;
        while (R != NULL) {
            if (R->info == P) {
                cout << "    - " << D->info.namaDokter
                     << " (Spesialis: " << D->info.spesialisasi << ")" << endl;
                adaDokter = true;
                break;
            }
            R = R->next;
        }
        D = D->next;
    }

    if (!adaDokter) {
        cout << "    - (Belum ada dokter yang menangani)" << endl;
    }
}

// Menghapus 1 elemen relasi
void deleteFirstRelasi(List_Relasi &L, address_relasi &R) {
    if (L.first != NULL) {
        R = L.first;
        if (R->next == NULL) {
            L.first = NULL;
        } else {
            L.first = R->next;
            R->next = NULL;
        }
    }
}

// Menghapus Dokter beserta relasinya
void deleteDokter(List_Dokter &L, address_dokter &D) {
    if (D != NULL) {
        //Hapus Semua relasi (Anak) dari dokter ini
        address_relasi R;
        while (D->childs.first != NULL) {
            deleteFirstRelasi(D->childs, R);
            delete R; // Deallocate memori relasi
        }

        // Hapus dokter dari list induk
        if (D == L.first && D == L.last) {
            // Dokter cuma satu-satunya
            L.first = NULL;
            L.last = NULL;
        } else if (D == L.first) {
            // Dokter di depan
            L.first = D->next;
            L.first->prev = NULL;
            D->next = NULL;
        } else if (D == L.last) {
            // Dokter di belakang
            L.last = D->prev;
            L.last->next = NULL;
            D->prev = NULL;
        } else {
            // Dokter di tengah
            D->prev->next = D->next;
            D->next->prev = D->prev;
            D->next = NULL;
            D->prev = NULL;
        }

        // Buang memori dokter
        delete D;
        D = NULL;
    }
}

// Menghapus relasi tertentu dari satu dokter
void deleteRelationByPasien(List_Relasi &L, address_pasien P) {
    address_relasi R = L.first;
    address_relasi prev = NULL;

    while (R != NULL) {
        if (R->info == P) {
            if (prev == NULL) {

                L.first = R->next;
            } else {
                prev->next = R->next;
            }
            address_relasi temp = R;
            R = R->next;
            delete temp;
            return;
        } else {
            prev = R;
            R = R->next;
        }
    }
}

// Menghapus Pasien Secara Global
void deletePasien(List_Dokter &LD, List_Pasien &LP, address_pasien &P) {
    if (P != NULL) {
        address_dokter D = LD.first;
        while (D != NULL) {
            // Cek 'kantong' relasi setiap dokter, hapus jika ada hubungan ke P
            deleteRelationByPasien(D->childs, P);
            D = D->next;
        }

        // Hapus pasien dari list induk
        if (P == LP.first && P == LP.last) {
            LP.first = NULL;
            LP.last = NULL;
        } else if (P == LP.first) {
            LP.first = P->next;
            LP.first->prev = NULL;
            P->next = NULL;
        } else if (P == LP.last) {
            LP.last = P->prev;
            LP.last->next = NULL;
            P->prev = NULL;
        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
            P->next = NULL;
            P->prev = NULL;
        }

        delete P;
        P = NULL;
    }
}

// show all pasien & dokter
void showAllPasienWithDokter(List_Pasien LP, List_Dokter LD) {
    cout << "\n=============================================" << endl;
    cout << "   LAPORAN DATA PASIEN DAN DOKTERNYA" << endl;
    cout << "=============================================" << endl;

    address_pasien P = LP.first;

    if (P == NULL) {
        cout << "Data Pasien masih kosong." << endl;
    } else {
        while (P != NULL) {
            showDokterByPasien(LD, P);

            cout << "---------------------------------------------" << endl;
            P = P->next;
        }
    }
}

// search dokter yang spesialisnya cocok, lalu menampilkan relasinya
void showPasienBySpesialis(List_Dokter LD, string spesialis) {
    address_dokter D = LD.first;
    bool foundDokter = false;

    cout << "\n>>> HASIL PENCARIAN UNTUK SPESIALIS: " << spesialis << " <<<" << endl;

    while (D != NULL) {
        if (D->info.spesialisasi == spesialis) {
            foundDokter = true;
            cout << "\n[Dokter]: " << D->info.namaDokter << " (Kode: " << D->info.kodeDokter << ")" << endl;

            address_relasi R = D->childs.first;
            if (R == NULL) {
                cout << "   - Belum ada pasien." << endl;
            } else {
                while (R != NULL) {
                    cout << "   - Pasien: " << R->info->info.namaPasien
                         << " (ID: " << R->info->info.idPasien << ")" << endl;
                    R = R->next;
                }
            }
        }
        D = D->next;
    }

    if (!foundDokter) {
        cout << "Tidak ditemukan dokter dengan spesialisasi tersebut." << endl;
    }
    cout << "==============================================" << endl;
}

// search dokter by pasien

void showDokterHandlingPasien(List_Dokter LD, string namaPasien) {
    cout << "\n>>> MENCARI DOKTER YANG MERAWAT PASIEN: " << namaPasien << " <<<" << endl;

    address_dokter D = LD.first;
    bool foundAny = false;

    while (D != NULL) {
        bool isHandling = false;

        address_relasi R = D->childs.first;
        while (R != NULL) {
            if (R->info->info.namaPasien == namaPasien) {
                isHandling = true;
                break;
            }
            R = R->next;
        }

        if (isHandling) {
            cout << "- Dokter: " << D->info.namaDokter
                 << " (Spesialis: " << D->info.spesialisasi << ")" << endl;
            foundAny = true;
        }

        D = D->next;
    }

    if (!foundAny) {
        cout << "Tidak ada dokter yang menangani pasien bernama " << namaPasien << "." << endl;
    }
    cout << "===================================================" << endl;
}
// Cari Pasien berdasarkan Keyword Spesialis Dokter

void searchPasienBySpesialis(List_Dokter LD, string keywordSpesialis) {
    address_dokter D = LD.first;
    bool foundDokter = false;

    cout << "\n>>> HASIL PENCARIAN UNTUK SPESIALIS: " << keywordSpesialis << " <<<" << endl;

    while (D != NULL) {
        if (D->info.spesialisasi == keywordSpesialis) {
            foundDokter = true;
            cout << "----------------------------------------------" << endl;
            cout << "Dokter Ditemukan: " << D->info.namaDokter
                 << " (Spesialis: " << D->info.spesialisasi << ")" << endl;

            address_relasi R = D->childs.first;
            if (R == NULL) {
                cout << "   -> Belum ada pasien yang dirawat." << endl;
            } else {
                cout << "   -> Daftar Pasien:" << endl;
                while (R != NULL) {
                    cout << "      * Nama: " << R->info->info.namaPasien
                         << " | ID: " << R->info->info.idPasien
                         << " | Umur: " << R->info->info.umur << endl;
                    R = R->next;
                }
            }
        }
        D = D->next;
    }

    if (!foundDokter) {
        cout << "Tidak ditemukan dokter dengan spesialisasi '" << keywordSpesialis << "'." << endl;
    }
    cout << "==============================================" << endl;
}

// Mengurutkan pasien dari terbanyak hingga paling sedikit
int hitungJumlahPasien(address_dokter D) {
    int count = 0;
    if (D != NULL) {
        address_relasi R = D->childs.first;
        while (R != NULL) {
            count++;
            R = R->next;
        }
    }
    return count;
}

void sortDokterByKesibukan(List_Dokter &LD) {
    if (LD.first == NULL || LD.first->next == NULL) {
        return;
    }

    bool swapped;
    address_dokter ptr1;
    address_dokter lptr = NULL;

    do {
        swapped = false;
        ptr1 = LD.first;

        while (ptr1->next != lptr) {
            int countNow = hitungJumlahPasien(ptr1);
            int countNext = hitungJumlahPasien(ptr1->next);

            if (countNow < countNext) {

                infotype_dokter tempInfo = ptr1->info;
                ptr1->info = ptr1->next->info;
                ptr1->next->info = tempInfo;

                List_Relasi tempChilds = ptr1->childs;
                ptr1->childs = ptr1->next->childs;
                ptr1->next->childs = tempChilds;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    cout << "\n>>> PROSES SORTING SELESAI." << endl;
    cout << ">>> Dokter tersibuk sekarang ada di urutan teratas." << endl;
}
