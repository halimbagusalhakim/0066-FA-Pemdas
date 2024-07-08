/**
 * @file UASPEMDAS_0066.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
using namespace std;
/**
 * @brief class mata kuliah
 * @class mata kuliah
 */
class MataKuliah
{
private: // isi dengan access modifier yang dibutuhkan
 float presensi;///> untuk menyimpan nilai presensi
 float activity;///> untuk menyimpan nilai activty
 float exercise;///> untuk menyimpan nilai exercise
 float tugasakhir;///> untuk menyinmpan nilai tugas akhri
 // tambahkan dengan variabel lain yang dibutuhkan dibawah ini
public:
MataKuliah()
{
 presensi = 0.0;
 // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini
 activity = 0.0;
 exercise = 0.0;
 tugasakhir = 0.0;

}
// tambahkan virtual fungsi lain yang dibutuhkan dibawah ini
virtual void namaMataKuliah() { return; }
virtual void inputNilai() {return;}
virtual int hitungNilaiAkhir(){return 0;}
virtual void cekKelulusan() {return;}

// tambahkan setter dan getter lain yang dibutuhkan dibawah ini
void setPresensi(float nilai)
{
 this->presensi = nilai;
}
float getPresensi()
{
 return presensi;
}
void setActivity(float nilai)
{
 this->activity = nilai;
}
float getActivity()
{
 return activity;
}
void setExercise(float nilai)
{
 this->exercise = nilai;
}
float getExercise()
{
 return exercise;
}
void setTugasAkhir(float nilai)
{
 this->tugasakhir = nilai;
}
float getTugasAkhir()
{
 return tugasakhir;
}


};
/**
 * @brief 
 * 
 */
 // isi disini untuk mengisi kelas pemrograman
class Pemrograman : public MataKuliah
{
    private:
    float temp;
    public:
    Pemrograman(){}//construct
    void inputNilai(){//polymorph
        cout << "berapa presensinya: ";
        cin >> temp;
        setPresensi(temp);

        cout << "berapa activitynya: ";
        cin >> temp;
        setActivity(temp);

        cout << "berapa exercise nya: ";
        cin >> temp;
        setExercise(temp);

        cout << "berapa tugas akhirnya :";
        cin >> temp;
        setTugasAkhir(temp);
    }

    int hitungNilaiAkhir(){//polymorph
        return (getPresensi() + getActivity() + getExercise() + getTugasAkhir())/ 4;
        
    }
    //kurang cek kellusan
    void cekKelulusan() {
       if (hitungNilaiAkhir() >= 75){
        cout << "anda dinyatakan lulus";
       }
       else {
        cout << " anda tidak lulus";
       }
    }

    
    

};
 // isi disini untuk mengisi kelas jaringan
class Jaringan : public MataKuliah
{
    private:
    float temp;

    void inputNilai(){
        cout << "berapa activitynya: ";
        cin >> temp;
        setActivity(temp);

        cout << "berapa exercise nya: ";
        cin >> temp;
        setExercise(temp);
    }
    int hitungNilaiAkhir(){//polymorph
        return (getActivity() + getExercise() )/ 2;
        
    }
    void cekKelulusan() {
       if (hitungNilaiAkhir() >= 75){
        cout << "anda dinyatakan lulus";
       }
       else {
        cout << " anda tidak lulus";
       }
    }




};
int main()
{
    while (true)
    {
        cout << "\nPilih mata kuliah" << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "pilih: ";
        char pilih;
        cin >> pilih;
        MataKuliah *mataKuliah = nullptr;

        switch (pilih)
        {
        case '1':
        {
            mataKuliah = new Pemrograman();
            mataKuliah->inputNilai();
            cout << "Nilai akhir: " << mataKuliah->hitungNilaiAkhir() << endl;
            mataKuliah->cekKelulusan();
            delete mataKuliah;
            break;
        }
        case '2':
        {
            mataKuliah = new Jaringan();
            mataKuliah->inputNilai();
            cout << "Nilai akhir: " << mataKuliah->hitungNilaiAkhir() << endl;
            mataKuliah->cekKelulusan();
            delete mataKuliah;
            break;
        }
        case '3':
        {
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    }

    return 0;
}