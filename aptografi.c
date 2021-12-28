#include <stdio.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdlib.h>		//Header yang di gunakan untuk standar input output pada bahasa C
#include <string.h>		//Header yang di gunakan untuk operasi string pada bahasa C
#include <time.h>		//Header yang di gunakan untuk operasi pada bahasa C
time_t waktuserver;	
char namaFile[]="loginRecord.txt";

typedef struct user{
	char nama [50];
	char username [12];
	char password [10];
	char email [50];
}User;
User u;		

typedef struct {
	char *nama[50];
	char *telepon[13];
	char *alamat[70];	
}Identitas;

typedef struct {
	char *tanggal[2];
	char *bulan[9];
	char *tahun[4];
}Date;

void welcome(){
	printf("\n\n\n\n\n\t\t************************************************************\n");
    printf("\t\t  ========================================================\n\n");
    printf("\t\t\t    SELAMAT DATANG DI SISTEM PELAYANAN\n");
    printf("\t\t\t	     APTOGRAFI \n");
    printf("\t\t\t	JL.IMAM BONJOL NO.7 DENPASAR\n");
    printf("\t\t\t      NOMOR TELEPON: (0361) 978 154\n");
    printf("\t\t\t      EMAIL: aptografi@gmail.com\n");
    printf("\t\t\t    AHLI FOTOGRAFI DAN VIDEOGRAFI \n\n");
    printf("\t\t  ========================================================");
	printf("\n\t\t************************************************************");
	printf("\n\n\n\n\n Press any key to continue......");
	getch();
	system("cls");
}

void waktu(){
	time(&waktuserver);
	struct tm*waktu = localtime (&waktuserver);
	printf ("\n\t\t\t||==========Tanggal: %d/%d/%d=========||\n\n", waktu -> tm_mday, waktu ->tm_mon +1, waktu -> tm_year +1900);
}


void masuk(){
	void daftar();
	/*  Variabel username[12] digunakan untuk menyimpan input username
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan username yang sudah terdaftar pada file loginRecord.txt   */
	char username[12];
	
	/*  Variabel password[10] digunakan untuk menyimpan input password
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan password yang sudah terdaftar pada file loginRecord.txt   */
	char password[10];
	
	// Variabel pilihan untuk pilihan user apakah ingin mendaftar, masuk ulang, atau keluar
	int pilihan;
	
	// Membuat pointer record untuk menunjuk pada file "loginRecord.txt"
	FILE *record;
	
	// Membuka file dengan mode "r"
	record = fopen (namaFile, "r");
	if (record == NULL){
		fputs ("Error, tidak terdapat file untuk menyimpan akun\n", stderr);
		exit(1);
	}
	
	// Instruksi untuk login
	printf ("\t\t\t||====================||\n");
	printf ("\t\t\t|| LOGIN\n");
	printf ("\t\t\t||====================||\n");
	printf ("\t\t\t|| Username: ");
	scanf ("%s", username);
	printf ("\t\t\t||====================||\n");
	printf ("\t\t\t|| Password: ");
	scanf ("%s", password);
	printf ("\t\t\t||====================||\n");
	
	// Membersikan layar terminal
	system ("cls");
	
	// Membeaca file "logRecord.txt"
	while (fread(&u, sizeof(u),1,record)){
		 /*  Mengkomparasi username serta password yang diinput user ke dalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
		if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
			printf ("\t\t\t||====================||\n");
			printf ("\t\t\t|| 	Login Berhasil!	 ||\n");
			printf ("\t\t\t||====================||\n");	
		}
		//  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar, masuk ulang, atau keluar
		else {
			printf ("\t\t\t||============================||\n");
			printf ("\t\t\t|| 	Akun Tidak Terdaftar!	 ||\n");
			printf ("\t\t\t||============================||\n");
			
			instruksi:
			printf ("\t\t\t||============================||\n");
			printf ("\n\t\t\t||Ketik 1 untuk Daftar");
			printf ("\n\t\t\t||Ketik 2 untuk Masuk Ulang");
			printf ("\n\t\t\t||Ketik 3 untuk Keluar\n");
			printf ("\n\t\t\t||============================||\n");
			printf ("\n\t\t\t||Pilihan : ");
			scanf ("%d", &pilihan);
			system ("cls");
			if (pilihan == 1){
				daftar();
			}
			else if (pilihan == 2){
				masuk();
			}
			else if (pilihan == 3){
				exit(1);
			}
			else {
				printf ("Error! Silahkan Masukkan Pilihan dengan Benar \n");
				goto instruksi;
			}
		}
	}
	fclose (record);
	return;
}

void daftar(){
	// Membuat pointer regis untuk file "loginRecord.txt"
	FILE *regis;
	// Membuka file "loginRecord.txt" dengan mode "w"
	regis = fopen(namaFile, "w");
	if (regis == NULL){
		fputs ("ERROR, Tidak terdapat file untuk menyimpan data!\n", stderr);
	}
	
	//Instruksi untuk melakukan registrasi akun 
	printf ("\n\t\t\t Silahkan Registrasi Akun Anda! \n\n");
	getchar ();
	printf ("\n\t\t\t Nama Lengkap: ");
	gets (u.nama);
	printf ("\n\t\t\t Email: ");
	scanf ("%s", u.email);
	printf ("\n\t\t\t Hallo %s! \n", u.nama);
	printf ("\n\t\t\t Silahkan membuat username (max 12 karakter), serta password (max 10 karakter) \n");
	
	// Instruksi untuk menginput username serta password
	printf ("\n\t\t\t Masukkan Username : ");
	scanf ("%s", u.username);
	printf ("\n\t\t\t Masukkan Password : ");
	scanf ("%s", u.password);
	
	// Menuliskan nama yang diinput oleh pengguna kedalam file "loginRecord.txt"
	fwrite (&u, sizeof(u),1,regis);
	fclose (regis);
	printf ("\n\t\t\t Registrasi Selesai! ");
	printf ("\n\t\t\t Akun Anda Terdaftar, Silahkan Mencoba!");
	
	// Membersikan layar terminal
	system("cls");
	// Memanggil fungsi masuk()
	masuk ();	
}



void pilmenu(){
	//variabel pilihan untuk menyimpan pilihan yang diinput user pada switch case
	int pilihan;
	
	instruksi:
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t|| 		PILIHAN MENU MASUK	||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||	No	|	Menu Masuk	||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||	1	|	Masuk		||\n");
	printf ("\t\t\t||	2	|	Registrasi	||\n");
	printf ("\t\t\t||	4	|	Keluar		||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &pilihan);
	printf ("\t\t\t||======================================||\n");
	system ("cls");
	
	/* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pilihan untuk menuju ke pilihan menu masuk yang diinput user  */
	switch (pilihan){
		case 1:
			masuk();
			break;
		case 2:
			daftar();
			break;
		case 3:
			exit(1);
			break;
		default:
			printf ("Error! Silahkan Masukkan Plihan dengan Benar \n");
			break;
	}
}


Date InputTanggalPemesanan (Date pemesanan){
	printf ("|===========================================================================|");
	printf ("\n|                               [APTOGRAFI]                                 |");
	printf ("\n|                              Membantu Anda                                |");
	printf ("\n|                   Menentukan Paket Fotografi & Videografi                 |");
	printf ("\n=============================================================================");
	printf ("\n|                           SILAHKAN REGISTRASI                             |");
	printf ("\n=============================================================================");
	
	printf ("\n\nTanggal Pesan		: ");
	scanf ("%s", &pemesanan.tanggal);
	printf ("Bulan Pesan		: ");
	scanf ("%s", &pemesanan.bulan);
	printf ("Tahun Pesan		: ");
	scanf ("%s", &pemesanan.tahun);
	return pemesanan;
}

Identitas InputDataCustomer (Identitas customer){
	printf ("\nNama Customer		: ");
	scanf (" %[^\n]s", &customer.nama);
	printf ("No. Telepon		: ");
	scanf ("%s", &customer.telepon);
	printf ("Alamat			: ");
	scanf ("%s", &customer.alamat);
	return customer;	
}

Date InputTanggalDigunakan (Date digunakan){
	printf ("\nTanggal Digunakan	: ");
	scanf ("%s", &digunakan.tanggal);
	printf ("Bulan Digunakan		: ");
	scanf ("%s", &digunakan.bulan);
	printf ("Tahun Digunakan		: ");
	scanf ("%s", &digunakan.tahun);
	return digunakan;
}

void TampilkanDaftarMenu(){
	printf ("|===========================================================================|");
	printf ("\n|                               [APTOGRAFI]                                 |");
	printf ("\n|                              Membantu Anda                                |");
	printf ("\n|                   Menentukan Paket Fotografi & Videografi                 |");
	printf ("\n=============================================================================");
	printf ("\n|     |                                                                     |");
	printf ("\n| No. |                   SILAHKAN PILIH MENU PAKET                         |");
	printf ("\n|     |                                                                     |");
	printf ("\n|===========================================================================|");
	printf ("\n|     |                                                                     |");
	printf ("\n| 1.  | Prewedding                                                          |");
	printf ("\n|     |                                                                     |");
	printf ("\n| 2.  | Dokumenter                                                          |");
	printf ("\n|     |                                                                     |");
	printf ("\n=============================================================================");
}

void TampilkanExtraOptionPrawedding(){
	printf ("=============================================================================");
	printf ("\n|                          EXTRA OPTION PREWEDDING                          |");
	printf ("\n|===========================================================================|");
	printf ("\n| No. |                     Opsi Tambahan                   |     Harga     |");
	printf ("\n|===========================================================================|");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 1.  | Album Foto                                          | Rp. 330000    |");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 2.  | All Softcopy                                        | Rp. 178000    |");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 3.  | Bingkai 20R                                         | Rp. 120000    |");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 4.  | Bingkai 16R                                         | Rp. 96000     |");
	printf ("\n|     |                                                     |               |");
	printf ("\n=============================================================================");
}

void TampilkanExtraOptionDokumenter(){
	printf ("=============================================================================");
	printf ("\n|                          EXTRA OPTION DOKUMENTER                          |");
	printf ("\n|===========================================================================|");
	printf ("\n| No. |                     Opsi Tambahan                   |     Harga     |");
	printf ("\n|===========================================================================|");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 1.  | Efek Monokrom                                       | Rp. 50000     |");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 2.  | All Softcopy                                        | Rp. 100000    |");
	printf ("\n|     |                                                     |               |");
	printf ("\n| 3.  | Bingkai 16R                                         | Rp. 120000    |");
	printf ("\n|     |                                                     |               |");
	printf ("\n=============================================================================");
}

int HitungHargaFotografer (int sewa_fotografer, int jumlah_fotografer){
	int sub_fotografer = sewa_fotografer * jumlah_fotografer;
	return sub_fotografer;
}

int HitungHargaVideografer (int sewa_videografer, int jumlah_videografer){
	int sub_videografer = sewa_videografer * jumlah_videografer;
	return sub_videografer;
}

int HitungHargaPerorang (int harga_perorang, int jumlah_orang){
	int sub_perorang = harga_perorang * jumlah_orang;
	return sub_perorang;
}

void TampilkanHasilRegistrasi (Identitas customer, Date pesan, Date digunakan){
	system ("cls");
	printf ("=============================================================================");
	printf ("\n|                              DATA REGISTRASI                              |");
	printf ("\n=============================================================================");
	printf ("\n");
	printf ("\n                       Nama Customer	: %s", customer.nama);
	printf ("\n");
	printf ("\n                         No. Telepon	: %s", customer.telepon);
	printf ("\n");
	printf ("\n                              Alamat	: %s", customer.alamat);
	printf ("\n");
	printf ("\n	  	      Pemesanan Pada	: %s - %s - %s", pesan.tanggal, pesan.bulan, pesan.tahun);
	printf ("\n");
	printf ("\n	         Akan Digunakan Pada	: %s - %s - %s", digunakan.tanggal, digunakan.bulan, digunakan.tahun);
	printf ("\n");
	printf ("\n=============================================================================");
}



int main (){
	
	int menu;
	int total;
	char kembali = 'r';
	Identitas customer;
	Date pemesanan, digunakan;
	Identitas input_customer;
	Date input_pemesanan, input_digunakan;
	int sewa_fotografer, sewa_videografer;
	int jumlah_fotografer, jumlah_videografer;
	int price_fotografer, price_videografer;
	char opsi;
	int jumlah_opsi;
	int pilih_opsi;
	int harga_opsi;
	int subtotal_opsi = 0;
	
	welcome();
	waktu();
	pilmenu();
		
	while (kembali == 'r' || kembali == 'R'){
			
		system ("cls");
	
		pemesanan = InputTanggalPemesanan (input_pemesanan);
		
		customer = InputDataCustomer (input_customer);
		
		digunakan = InputTanggalDigunakan (input_digunakan);

		system ("cls");
		TampilkanDaftarMenu();
		
		printf ("\n\n\nSilahkan Masukkan Menu Pilihan : ");
		scanf ("%d", &menu);
		
		system ("cls");
		if (menu == 1){
			sewa_fotografer = 400000;
			sewa_videografer = 500000;
			total = 0;
			harga_opsi = 0;
			
			printf ("=============================================================================");
			printf ("\n|                             PAKET PRAWEDDING                              |");
			printf ("\n|                  Semakin Banyak Kamera, Semakin Estetik                   |");
			printf ("\n=============================================================================");	
			printf ("\n\nSilahkan Masukkan Jumlah Fotografer		: ");
			scanf ("%d", &jumlah_fotografer);
			printf ("\nSilahkan Masukkan Jumlah Videografer		: ");
			scanf ("%d", &jumlah_videografer);
			printf ("\n=============================================================================");	
			
			printf ("\n\nApakah Ingin Membeli Opsi Tambahan	(Y/N)	? ");
			scanf (" %c", &opsi);
			
			if (opsi == 'y' || opsi == 'Y'){
				int i = 1;		
				system ("cls");		
				
				TampilkanExtraOptionPrawedding();
				
				printf ("\n\nMasukkan Jumlah Opsi	: ");
				scanf ("%d", &jumlah_opsi);
				printf ("\n=============================================================================\n");
				
				while (i <= jumlah_opsi){
					printf ("\nSilahkan Pilih Opsi 	: ");
					scanf ("%d", &pilih_opsi);			
					if (pilih_opsi == 1){
						harga_opsi = 330000;
					}
					else if (pilih_opsi == 2){
						harga_opsi = 178000;
					}
					else if (pilih_opsi == 3){
						harga_opsi = 120000;
					}
					else if (pilih_opsi == 4){
						harga_opsi = 96000;
					}
					else {
						printf ("\nMOHON INPUTKAN KODE SESUAI DAFTAR EXTRA OPTION !\n");
						i--;
					}
					subtotal_opsi = subtotal_opsi + harga_opsi;
					i++;
				}	
								
				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);
				
				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);
				
				total = total + price_fotografer + price_videografer + subtotal_opsi;
				
				TampilkanHasilRegistrasi(customer, pemesanan, digunakan);
				
				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);      
				printf ("\n");
				printf ("\n                         Opsi Tambahan	: Rp. %d", subtotal_opsi);
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                  Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
			}
			
			else {
				int total = 0;
				
				TampilkanHasilRegistrasi(customer, pemesanan, digunakan);
				
				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);
				
				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);
				
				total = total + price_fotografer + price_videografer;
				
				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);      
				printf ("\n");
				printf ("\n                         Opsi Tambahan	: -");
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                  Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
			} 
		}
						
		else if (menu == 2){
			sewa_fotografer = 365000;
			sewa_videografer = 488000;
			total = 0;
			harga_opsi = 0;
			int jumlah_orang;
			int harga_perorang = 20000;
			int price_orang;
			
			printf ("=============================================================================");
			printf ("\n|                             PAKET DOKUMENTER                              |");
			printf ("\n|                  Semakin Banyak Kamera, Semakin Estetik                   |");
			printf ("\n=============================================================================");	
			printf ("\n\nSilahkan Masukkan Jumlah Fotografer		: ");
			scanf ("%d", &jumlah_fotografer);
			printf ("\nSilahkan Masukkan Jumlah Videografer		: ");
			scanf ("%d", &jumlah_videografer);
			printf ("\nSilahkan Masukkan Jumlah Orang / Peserta	: ");
			scanf ("%d", &jumlah_orang);
			printf ("\n=============================================================================");	
			
			printf ("\n\nApakah Ingin Membeli Opsi Tambahan	(Y/N)	? ");
			scanf (" %c", &opsi);
		
			if (opsi == 'y' || opsi == 'Y'){
				int i = 1;		
				system ("cls");		
				
				TampilkanExtraOptionDokumenter();
				
				printf ("\n\nMasukkan Jumlah Opsi	: ");
				scanf ("%d", &jumlah_opsi);
				printf ("\n=============================================================================\n");
				
				while (i <= jumlah_opsi){
					printf ("\nSilahkan Pilih Opsi 	: ");
					scanf ("%d", &pilih_opsi);			
					if (pilih_opsi == 1){
						harga_opsi = 50000;
					}
					else if (pilih_opsi == 2){
						harga_opsi = 100000;
					}
					else if (pilih_opsi == 3){
						harga_opsi = 120000;
					}
					else {
						printf ("\nMOHON INPUTKAN KODE SESUAI DAFTAR EXTRA OPTION !\n");
						i--;
					}
					subtotal_opsi = subtotal_opsi + harga_opsi;
					i++;
				}
				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);
				
				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);
				
				price_orang = HitungHargaPerorang (jumlah_orang, harga_perorang);
				
				total = total + price_fotografer + price_videografer + price_orang + subtotal_opsi;
				
				TampilkanHasilRegistrasi(customer, pemesanan, digunakan);
				
				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);      
				printf ("\n");
				printf ("\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);      
				printf ("\n");
				printf ("\n                        Opsi Tambahan	: Rp. %d", subtotal_opsi);
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                  Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
			}
			
			else {
				int total = 0;
				
				TampilkanHasilRegistrasi(customer, pemesanan, digunakan);
				
				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);
				
				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);
				
				price_orang = HitungHargaPerorang (jumlah_orang, harga_perorang);
				
				total = total + price_fotografer + price_videografer + price_orang;
				
				printf ("\n|                              RINCIAN BIAYA                                |");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n              Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				printf ("\n");
				printf ("\n             Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);      
				printf ("\n");
				printf ("\n                       Harga %d Orang	: Rp. %d",jumlah_orang, price_orang);      
				printf ("\n");
				printf ("\n                        Opsi Tambahan	: -");
				printf ("\n");
				printf ("\n=============================================================================");
				printf ("\n");
				printf ("\n	                  Total Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
			} 
		}
		
		else {
			printf ("! MOHON MASUKKAN KODE YANG SESUAI DENGAN NOMOR MENU !");
		}
		
		printf ("\n\nReturn (R) or Quit (Q) : ");
		scanf (" %c", &kembali);	
	}
	return 0;
}

