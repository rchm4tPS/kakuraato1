# Kakuraato

## Deskripsi
`Kakuraato` merupakan aplikasi kalkulator sederhana yang menerapkan konsep struktur data binary tree serta stack untuk melakukan proses perhitungan matematis, disamping struktur data linked list untuk menyimpan seluruh data penggunaan kalkulator standar.
<br/><br/>
Terdapat dua buah fitur utama di dalam aplikasi `Kakuraato` ini, yakni :

- Kalkulator Standar
  <br>Merupakan kalkulator standar yang berguna untuk melakukan proses perhitungan aritmetika yang menggunakan operator seperti :
  - penambahan dengan simbol `+` (_plus_)
  - pengurangan dengan simbol `-` (_minus_)
  - perkalian dengan simbol `*` (_asterisk_)
  - pembagian dengan simbol `/` (_slash_)
  - perpangkatan dengan simbol `^` (_caret_)
  - perakar-kuadratan dengan simbol `#` (_hash_), dan
  - kurung dengan simbol `(` dan `)` (_parentheses_)
  
  dengan menerapkan aturan <i>precedence</i> diantara seluruh operator tersebut. Secara umum, dapat dituliskan :
  ```
  Precedence dinyatakan sebagai P() untuk menyebut nilai precedence suatu operator.
  
     P(()) > P(^) && P(#) > P(*) && P(/) > P(+) && P(-)
  ```
  
  Penulisan antar suku pada inputan ekspresi matematika di dalam fitur kalkulator standar hendaknya tidak diberi spasi apapun.
- Kalkulator Akar Kuadrat
  <br>Merupakan kalkulator yang disediakan untuk mencari 2 (dua) buah akar-akar riil dari suatu persamaan kuadrat yang berakhiran dengan sintaks sama dengan 0. Penulisan antar suku-suku di dalam persamaan akar kuadrat harus diberi satu spasi.

## Cara Penggunaan
### Kalkulator Standar

- Masukkan ekspresi matematika yang ingin diketahui hasilnya pada kotak input pertama. Misalkan :
  ```
  #((11^3-(3*111-2))*10
  ```
- Tekan `Enter` pada keyboard. Maka hasil perhitungan `100.00` akan langsung ditampilkan pada kotak output di bawah kotak input ekspresi matematika tadi.
- Jika ingin melakukan perhitungan lain, ketik tombol apapun pada keyboard.
- Namun, jika ingin keluar dari fitur kalkulator standar, tekan tombol huruf `Q` (kyu besar, akronim untuk kata "QUIT") pada keyboard.
  - Tampilan pesan 
    ```
    Successfully record previous data to the file!
    ```
    setelah menekan huruf `Q` menunjukkan bahwa segala ekspresi matematika dan data terkait telah dituliskan dalam file bernama `calc_history.csv`. Tekan saja tombol apapun pada keyboard untuk melanjutkan.
<br>

### Kalkulator Akar Kuadrat

- Masukkan persamaan akar kuadrat yang memenuhi syarat berikut :
  - Memiliki variabel yang sama untuk seluruh sukunya
  - Variabel yang dimaksud haruslah berupa huruf alphabet latin `A-Z` atau `a-z`.
  - Memiliki akhiran `= 0`
    Contoh masukan yang benar sehingga dapat dilakukan perhitungan padanya :
    ```
    -5x^2 + 15x - 10 = 0
    ```
    Dan berikut merupakan masukan yang tidak dapat dilakukan perhitungan padanya :
    ```
    x^2 + 10x
    ```
    ... yang kemudian akan memunculkan pesan kesalahan seperti berikut :
    ```
    Persamaan Kuadrat tidak valid! Harus sama variabelnya dan berakhiran '= 0'
    ```
    Adapun jika persamaan tidak memiliki akar-akar yang riil (akar-akar imajiner), akan muncul pesan seperti berikut :
    ```
    PERHATIAN! Akar-akar tidak real / imajiner
    ```
- Setelah selesai memasukkan persamaan kuadrat tadi, tekan `Enter` pada keyboard.
- Jika menggunakan inputan persamaan kuadrat pada contoh di atas yang valid, maka hasil akar ke-1 dan akar ke-2 akan ditampilkan pada dua buah kotak output di bawah kotak input persamaan kuadrat tadi. Pada contoh di atas, akan muncul bilangan `1.00` dan `2.00` sebagai dua buah akar riil dari persamaan kuadrat yang diinputkan.
- Jika ingin melakukan perhitungan lain, ketik tombol apapun pada keyboard.
- Namun, jika ingin keluar dari fitur kalkulator standar, tekan tombol huruf `Q` (kyu besar, akronim untuk kata "QUIT") pada keyboard.

## Credit
Aplikasi `Kakuraato` ini dibuat oleh Kelompok 1 - Kelas 1B Progam Studi D4-Teknik Informatika dari Politeknik Negeri Bandung. Versi awal dari aplikasi `Kakuraato` dirilis pertama kali pada hari Minggu, tanggal 5 Juni tahun 2022. 
<br>Tiga orang kontributor di kelompok 1 tersebut adalah :
- **Danu Mahesa**, NIM : 211524037
- **Husna Maulana**, NIM : 211524045
- **Rachmat Purwa Saputra**, NIM : 211524054
