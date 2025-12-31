#ifndef TUBES_H
#define TUBES_H

#include <iostream>
#include <string>

using namespace std;

struct infotype_pasien {
    string namaPasien;
    int idPasien;
    int umur;
};

typedef struct elm_pasien *address_pasien;

struct elm_pasien {
    infotype_pasien info;
    address_pasien next;
    address_pasien prev;
};

struct List_Pasien {
    address_pasien first;
    address_pasien last;
};

typedef struct elm_relasi *address_relasi;

struct elm_relasi {
    address_relasi next;
    address_pasien info; // pointer ke arah pasien (child)
};

struct List_Relasi {
    address_relasi first;
};

struct infotype_dokter {
    string namaDokter;
    string spesialisasi;
    int kodeDokter;
};

typedef struct elm_dokter *address_dokter;

struct elm_dokter {
    infotype_dokter info;
    address_dokter next;
    address_dokter prev;

    List_Relasi childs;
};

struct List_Dokter {
    address_dokter first;
    address_dokter last;
};

void createListDokter(List_Dokter &L);
address_dokter createElmDokter(infotype_dokter data);
void insertLastDokter(List_Dokter &L, address_dokter P);
void showDokter(List_Dokter L);

void createListPasien(List_Pasien &L);
address_pasien createElmPasien(infotype_pasien data);
void insertLastPasien(List_Pasien &L, address_pasien P);
void showPasien(List_Pasien L);

address_dokter findDokter(List_Dokter L, int kode);
address_pasien findPasien(List_Pasien L, int id);


address_relasi createElmRelasi(address_pasien P);
void insertLastRelasi(List_Relasi &L, address_relasi R);
void connect(address_dokter D, address_pasien P);

void showDokterSpesifik(address_dokter D);

int countDokterByPasien(List_Dokter LD, address_pasien P);
void showDokterByPasien(List_Dokter LD, address_pasien P);

void deleteFirstRelasi(List_Relasi &L, address_relasi &R);
void deleteDokter(List_Dokter &L, address_dokter &D);

void deleteRelationByPasien(List_Relasi &L, address_pasien P);
void deletePasien(List_Dokter &LD, List_Pasien &LP, address_pasien &P);

void showAllPasienWithDokter(List_Pasien LP, List_Dokter LD);
void showPasienBySpesialis(List_Dokter LD, string spesialis);
void showDokterHandlingPasien(List_Dokter LD, string namaPasien);

void searchPasienBySpesialis(List_Dokter LD, string keywordSpesialis);

int hitungJumlahPasien(address_dokter D);
void sortDokterByKesibukan(List_Dokter &LD);

int countDoctorsOfPatient(List_Dokter LD, address_pasien P);
void connect(List_Dokter &LD, address_dokter D, address_pasien P);
#endif
