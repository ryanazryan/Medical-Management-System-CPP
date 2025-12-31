#include <iostream>
#include <limits>
#include <string>
#include "tubes.h"

using namespace std;

void displayMenu() {
    cout << "\n=============================================" << endl;
    cout << "          MENU SISTEM DATA BEROBAT           " << endl;
    cout << "=============================================" << endl;
    cout << "1.  Tambah Data Dokter" << endl;
    cout << "2.  Tambah Data Pasien" << endl;
    cout << "3.  Hubungkan Dokter & Pasien" << endl;
    cout << "4.  Tampilkan Semua Laporan" << endl;
    cout << "5.  Cari Pasien by Spesialis Dokter" << endl;
    cout << "6.  Cari Dokter by Nama Pasien" << endl;
    cout << "7.  Hapus Data Dokter" << endl;
    cout << "8.  Hapus Data Pasien" << endl;
    cout << "9.  Urutkan Dokter Tersibuk" << endl;
    cout << "10. Tampilkan List Pasien Saja" << endl;
    cout << "11. Tampilkan List Dokter Saja" << endl;
    cout << "0.  Keluar" << endl;
    cout << "=============================================" << endl;
    cout << "Pilih menu: ";
}

int main() {
    List_Dokter LD;
    List_Pasien LP;
    createListDokter(LD);
    createListPasien(LP);

    int pilihan, n, idCari, kodeCari;
    string keyStr;
    char confirm;

    do {
        displayMenu();
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: {
                cout << "Masukkan jumlah dokter: "; cin >> n;
                for(int i = 1; i <= n; i++) {
                    infotype_dokter d;
                    cout << "\n--- Dokter Ke-" << i << " ---" << endl;
                    cout << "Kode Dokter : "; cin >> d.kodeDokter;
                    cin.ignore();
                    cout << "Nama Dokter : "; getline(cin, d.namaDokter);
                    cout << "Spesialisasi: "; getline(cin, d.spesialisasi);
                    insertLastDokter(LD, createElmDokter(d));
                }
                cout << "\nTotal " << n << " dokter berhasil ditambahkan." << endl;
                break;
            }
            case 2: {
                cout << "Masukkan jumlah pasien: "; cin >> n;
                for(int i = 1; i <= n; i++) {
                    infotype_pasien p;
                    cout << "\n--- Pasien Ke-" << i << " ---" << endl;
                    cout << "ID Pasien  : "; cin >> p.idPasien;
                    cin.ignore();
                    cout << "Nama Pasien: "; getline(cin, p.namaPasien);
                    cout << "Umur       : "; cin >> p.umur;
                    insertLastPasien(LP, createElmPasien(p));
                }
                cout << "\nTotal " << n << " pasien berhasil ditambahkan." << endl;
                break;
            }
            case 3: {
                cout << "Masukkan Kode Dokter: "; cin >> kodeCari;
                cout << "Masukkan ID Pasien  : "; cin >> idCari;
                address_dokter D = findDokter(LD, kodeCari);
                address_pasien P = findPasien(LP, idCari);

                if (D != NULL && P != NULL) {
                    connect(LD, D, P);
                } else {
                    cout << "Dokter atau Pasien tidak ditemukan!" << endl;
                }
                break;
            }
            case 4:
                showAllPasienWithDokter(LP, LD);
                break;
            case 5:
                cout << "Masukkan Spesialisasi yang dicari: ";
                getline(cin, keyStr);
                searchPasienBySpesialis(LD, keyStr);
                break;
            case 6:
                cout << "Masukkan Nama Pasien yang dicari: ";
                getline(cin, keyStr);
                showDokterHandlingPasien(LD, keyStr);
                break;
            case 7: {
                cout << "Masukkan Kode Dokter yang dihapus: "; cin >> kodeCari;
                address_dokter D = findDokter(LD, kodeCari);
                if (D != NULL) {
                    cout << "Hapus Dokter " << D->info.namaDokter << "? (y/n): "; cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        deleteDokter(LD, D);
                        cout << "Dokter dan relasinya berhasil dihapus." << endl;
                    }
                } else {
                    cout << "Dokter tidak ditemukan." << endl;
                }
                break;
            }
            case 8: {
                cout << "Masukkan ID Pasien yang dihapus: "; cin >> idCari;
                address_pasien P = findPasien(LP, idCari);
                if (P != NULL) {
                    cout << "Hapus Pasien " << P->info.namaPasien << "? (y/n): "; cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        deletePasien(LD, LP, P);
                        cout << "Pasien dihapus dari sistem." << endl;
                    }
                } else {
                    cout << "Pasien tidak ditemukan." << endl;
                }
                break;
            }
            case 9:
                sortDokterByKesibukan(LD);
                cout << "\n--- Hasil Urutan Kesibukan (Tersibuk di Atas) ---" << endl;
                showDokter(LD);
                break;
            case 10:
                showPasien(LP);
                break;
            case 11:
                showDokter(LD);
                break;
            case 0:
                cout << "Keluar program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
