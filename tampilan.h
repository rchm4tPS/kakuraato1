/**
 *  Program file name   : tampilan.h
 *  Description         : deklarasi prototipe modul-modul behavior untuk tampilan pada Kakuraato.
 *  Author              : Danu Mahesa, 211524037
 *  Compiler            : GCC
 *
 */

#ifndef tampilan_h
#define tampilan_h

/**
 * Mendapatkan lebar screen monitor user dalam bilangan integer.
 */
int getScreenWidth();

/**
 * Mendapatkan tinggi screen monitor user dalam bilangan integer.
 */
int getScreenHeight();

/** 
 * Mengarahkan kursor untuk tampilan output ataupun kursor 
 * untuk proses inputan ke koordinat yang diinginkan di dalam
 * tampilan jendela konsol.
 * 
 * I.S. : Kursor masih berada di posisi default (sebelah kiri jendela konsol)
 * F.S. : Kursor sudah berada pada posisi yang diejawantahkan.
 */
void gotoxy(int x, int y);

/**
 * Menampilkan tampilan main menu.
 *  
 * I.S. : Tampilan main menu belum tampil di layar.
 * F.S. : Tampilan main menu tampil di layar.
 */
void tampilMainMenu();

/**
 * Menampilkan tampilan kalkulator standar.
 *  
 * I.S. : Tampilan kalkulator standar belum tampil di layar
 * F.S. : Tampilan kalkulator standar tampil di layar.
 */
void tampilKalkStandar();

/**
 * Menampilkan tampilan kalkulator akar kuadrat.
 * 
 * I.S. : Tampilan kalkulator akar kuadrat belum tampil di layar.
 * F.S. : Tampilan kalkulator akar kuadrat tampil di layar.
 */
void tampilKalkAkur();

/**
 * Membaca lalu menampilkan file yang berisi fitur help
 * 
 * I.S. : Isi file yang berisi fitur help belum tampil di layar. 
 * F.S. : Isi file yang berisi fitur help tampil di layar. 
 */
void tampilHelp();

/**
 * Menampilkan tampilan history penggunaan kalkulator
 *  
 * I.S. : Tampilan history belum tampil di layar.
 * F.S. : Tampilan history tampil di layar.
 */
void tampilHistory();

/**
 * Menampilkan tampilan credit ataupun author.
 * 
 * I.S. : tampilan credit belum tampil di layar.
 * F.S. : tampilan credit tampil di layar.
 */
void tampilCredit();

/**
 * Menampilkan teks banner “Kakurato” pada saat tampilan main menu dimuat di dalam jendela konsol aplikasi.
 * 
 * I.S. : tampilan teks banner belum muncul.
 * F.S. : tampilan teks banner sudah muncul.
 */
void printBanner();

/**
 * Mengubah karakter-karakter pada array teks banner di dalam method printBanner agar menjadi character blok yang diperindah.
 * 
 * I.S. : Array banner masih berupa karakter standar
 * F.S. : Array banner sudah dikonversi menjadi bentuk blok-blok pada karakter ASCII extended.
 */
void printASCII(char ch);

#endif
