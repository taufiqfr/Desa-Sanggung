#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Penduduk {
    string Nama;
    int Umur;
    string KepalaKeluarga;
    Penduduk* next;
};

void tambahDepan(Penduduk** head, string Nama, int Umur, string KepalaKeluarga) {
    Penduduk* newNode = new Penduduk;
    newNode->Nama = Nama;
    newNode->Umur = Umur;
    newNode->KepalaKeluarga = KepalaKeluarga;
    newNode->next = *head;
    *head = newNode;
}

void tambahBelakang(Penduduk** head, string Nama, int Umur, string KepalaKeluarga) {
    Penduduk* newNode = new Penduduk;
    newNode->Nama = Nama;
    newNode->Umur = Umur;
    newNode->KepalaKeluarga = KepalaKeluarga;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Penduduk* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void hapusDepan(Penduduk** head) {
    if (*head == NULL) {
        cout << "Linked list kosong!" << endl;
    } else {
        Penduduk* temp = *head;
        *head = (*head)->next;
        delete temp;
        cout << "Data dihapus dari depan linked list" << endl;
    }
}

void hapusBelakang(Penduduk** head) {
    if (*head == NULL) {
        cout << "Linked list kosong!" << endl;
    } else if ((*head)->next == NULL) {
        delete *head;
        *head = NULL;
        cout << "Data dihapus dari belakang linked list" << endl;
    } else {
        Penduduk* temp1 = *head;
        Penduduk* temp2 = NULL;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        delete temp1;
        cout << "Data dihapus dari belakang linked list" << endl;
    }
}

bool cariSequential(Penduduk* head, string Nama) {
    Penduduk* temp = head;
    while (temp != NULL) {
        if (temp->Nama == Nama) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void swapData(Penduduk* a, Penduduk* b) {
    string tempNama = a->Nama;
    int tempUmur = a->Umur;
    string tempKepalaKeluarga = a->KepalaKeluarga;
    a->Nama= b->Nama;
    a->Umur = b->Umur;
    a->KepalaKeluarga = b->KepalaKeluarga;
    b->Nama = tempNama;
    b->Umur = tempUmur;
    b->KepalaKeluarga = tempKepalaKeluarga;
}

void selectionSort(Penduduk* head) {
    Penduduk* temp1 = head;
    while (temp1 != NULL) {
        Penduduk* temp2 = temp1;
        Penduduk* minNode = temp1;
        while (temp2 != NULL) {
            if (temp2->Nama.compare(minNode->Nama) < 0) {
                minNode = temp2;
            }
            temp2 = temp2->next;
        }
        swapData(temp1, minNode);
        temp1 = temp1->next;
    }
    cout << "Data diurutkan menggunakan Selection Sort" << endl;
}

void tampilkanData(Penduduk* head) {
    if (head == NULL) {
        cout << "Linked list kosong!" << endl;
    } else {
        Penduduk* temp = head;
        while (temp != NULL) {
            cout << "Nama     : " << temp->Nama << endl;
            cout << "Umur             : " << temp->Umur << endl;
            cout << "Kepala Keluarga  : " << temp->KepalaKeluarga << endl;
            cout << "--------------------------" << endl;
            temp = temp->next;
        }
    }
}

void tambahAntrian(queue<int>& antrian) {
    int nilai;
    cout << "Masukkan nilai: ";
    cin >> nilai;
    antrian.push(nilai);
    cout << "Nilai " << nilai << " ditambahkan ke dalam antrian." << endl;
}

void prosesAntrian(queue<int>& antrian) {
    if (!antrian.empty()) {
        cout << "Nilai " << antrian.front() << " diproses." << endl;
        antrian.pop();
    } else {
        cout << "Antrian kosong." << endl;
    }
}

void jumlahAntrian(queue<int>& antrian) {
    cout << "Jumlah antrian: " << antrian.size() << endl;
}

int main() {
    Penduduk* head = NULL;
    int pilihan;
    string Nama;
    int Umur;
    string KepalaKeluarga;
    queue<int> antrian;

    do {
        system("cls");
        cout << "-----Sensus Penduduk-----" << endl;
        cout << "Menu Data Penduduk" << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data depan" << endl;
        cout << "3. Cari data (Sequential Search)" << endl;
        cout << "4. Urutkan data (Selection Sort)" << endl;
        cout << "5. Tampilkan data" << endl;
        cout << "6. Tambah data antrian" << endl;
        cout << "7. Proses antrian" << endl;
        cout << "8. Jumlah antrian" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama          : ";
                cin.ignore();
                getline(cin, Nama);
                cout << "Masukkan Umur: ";
                cin >> Umur;
                cout << "Masukkan KepalaKeluarga  : ";
                cin.ignore();
                getline(cin, KepalaKeluarga);
                tambahDepan(&head, Nama, Umur, KepalaKeluarga);
                cout << "Data ditambahkan di awal linked list" << endl;
                break;

