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

void waktu(){
	time(&waktuserver);
	struct tm* waktu = localtime(&waktuserver);
	FILE *hasil;
	hasil = fopen("transaksi.txt", "w");
	printf (" Waktu Pemesanan : %s", asctime (waktu));
	fprintf (hasil, " Waktu Pemesanan : %s", asctime (waktu));
	fclose(hasil);
}

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
	printf ("\t\t\t||	3	|	Keluar		||\n");
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
		goto instruksi;
	}
}

void tentangPembuat(){
	char buff[100];
	FILE*pembuat;
	if((pembuat=fopen("tentangPembuat.txt", "r"))==NULL){
		printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), pembuat)){
		printf("%s",buff);
	}
	fclose(pembuat);
}

void tentangAptografi(){
	char buff[100];
	FILE*aptografi;
	if((aptografi=fopen("tentangAptografi.txt", "r"))==NULL){
	printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), aptografi)){
	printf("%s",buff);
	}
	fclose(aptografi);
}

void informasiPaket(){
	char buff[100];
	FILE*informasiPaket;
	if((informasiPaket=fopen("informasiPaket.txt", "r"))==NULL){
	printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), informasiPaket)){
	printf("%s",buff);
	}
	fclose(informasiPaket);
}

void menu1(){
	//variabel pilihan untuk menyimpan pilihan yang diinput user pada switch case
	int pilihan;
	
	menu:
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t|| 	 	MENU 		||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||	No	|	Pilihan 	||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||	1	|Tentang Pembuat||\n");
	printf ("\t\t\t||	2	|Tentang Aptografi	||\n");
	printf ("\t\t\t||	3	|Informasi Paket, Harga,||\n"); 
	printf ("\t\t\t||		|dan Diskon||\n");
	printf ("\t\t\t||	4	|Keluar			||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\t||======================================||\n");
	printf ("\t\t\tTekan karakter acak untuk lanjut ke Registrasi Pemesanan...\n");
	printf ("\t\t\t|| Masukkan pilihan anda : ");
	scanf ("%d", &pilihan);
	printf ("\t\t\t||======================================||\n");
	system ("cls");
	if (pilihan == 1){
		tentangPembuat();
		goto menu;
	}
	else if (pilihan == 2){
		tentangAptografi();
		goto menu;
	}
	else if (pilihan == 3){
		informasiPaket();
		goto menu;
	}
	else if (pilihan == 4){
		exit(1);
	}		
}

Date InputTanggalPemesanan (){
	printf ("|===========================================================================|");
	printf ("\n|                               [APTOGRAFI]                                 |");
	printf ("\n|                              Membantu Anda                                |");
	printf ("\n|                   Menentukan Paket Fotografi & Videografi                 |");
	printf ("\n=============================================================================");
	printf ("\n|                           SILAHKAN REGISTRASI                             |");
	printf ("\n=============================================================================");

	printf ("\n"); waktu();
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
	scanf ("%s", &digunakan.tanggal );
	return digunakan;
}

void TampilkanDaftarMenu(){
char buff[100];
	FILE*in;
	if((in=fopen("pilMenuPaket.txt", "r"))==NULL){
		printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), in)){
		printf("%s",buff);
	}
	fclose(in);
}

void TampilkanExtraOptionPrawedding(){
	char buff[100];
	FILE*extraPrewed;
	if((extraPrewed=fopen("ExtraOptionalPrewedding.txt", "r"))==NULL){
		printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), extraPrewed)){
		printf("%s",buff);
	}
	fclose(extraPrewed);
}

void TampilkanExtraOptionDokumenter(){
	char buff[100];
	FILE*extraDokumen;
	if((extraDokumen=fopen("ExtraOptionDokumenter.txt", "r"))==NULL){
		printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), extraDokumen)){
		printf("%s",buff);
	}
	fclose(extraDokumen);
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
	printf ("\n");  waktu();
	printf ("\n");
	printf ("\n	         Akan Digunakan Pada	: %s", digunakan.tanggal);
	printf ("\n");
	printf ("\n=============================================================================");
}

	
int main (){

	int menu;
	int total, total1, total2;
	int diskon1, diskon2;
	int bayar;
	int kembalian;
	int kembaliandisc1, kembaliandisc2;
	Identitas customer;
	Date pemesanan, digunakan;
	Identitas input_customer;
	Date input_pemesanan, input_digunakan;
	char kembali = 'r';
	int sewa_fotografer, sewa_videografer;
	int jumlah_fotografer, jumlah_videografer;
	int price_fotografer, price_videografer;
	char opsi;
	int jumlah_opsi;
	int pilih_opsi;
	int harga_opsi;
	int subtotal_opsi = 0;

	welcome();
	pilmenu();
	menu1();


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
			FILE * hasil;
			hasil=fopen("transaksi.txt","w");
			fprintf(hasil, "\n PAKET PREWEDDING");
			fclose (hasil);
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
			//mencetak struk
			FILE * hasil1;
			hasil1=fopen("transaksi.txt","w");
			fprintf(hasil1, "\n Jumlah Fotografer : %d ", jumlah_fotografer);
			fprintf(hasil1, "\n Jumlah Videografer : %d ", jumlah_videografer);
			fclose (hasil1);

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
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

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
				//struk
				FILE * hasil2;
				hasil2=fopen("transaksi.txt","w");
				fprintf (hasil2,"\n Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil2,"\n Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil2,"\n Opsi Tambahan	: Rp. %d", subtotal_opsi);
				fprintf (hasil2,"\n Total Biaya	: Rp. %d", total);
				fclose (hasil2);
				if (total > 1000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 persen!");
					printf ("\n");
					printf ("\n 		Potongan harga : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil3;
					hasil3=fopen("transaksi.txt","w");
					fprintf (hasil3,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil3,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil3,"\n=============================================================================");
					fprintf (hasil3,"\n Bayar : Rp. ");
					fprintf (hasil3, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil3);
				}
				else if (total > 5000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 persen!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil4;
					hasil4=fopen("transaksi.txt","w");
					fprintf (hasil4,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil4,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil4,"\n=============================================================================");
					fprintf (hasil4,"\n Bayar : Rp. ");
					fprintf (hasil4, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil4);
				}
				else {
					printf ("\n 		Potongan hagra : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					//struk
					FILE * hasil5;
					hasil5=fopen("transaksi.txt","w");
					fprintf (hasil5,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil5,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil5,"\n=============================================================================");
					fprintf (hasil5,"\n Bayar : Rp. ");
					fprintf (hasil5, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil5);
				}
			}

			else {
				int total = 0;

				TampilkanHasilRegistrasi(customer, pemesanan, digunakan);

				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);

				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);

				total = total + price_fotografer + price_videografer;
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

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
				//struk
				FILE * hasil6;
				hasil6=fopen("transaksi.txt","w");
				fprintf (hasil6,"\n Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil6,"\n Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil6,"\n Opsi Tambahan	: Rp. %d", subtotal_opsi);
				fprintf (hasil6,"\n Total Biaya	: Rp. %d", total);
				fclose (hasil6);
				if (total > 1000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 %!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil7;
					hasil7=fopen("transaksi.txt","w");
					fprintf (hasil7,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil7,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil7,"\n=============================================================================");
					fprintf (hasil7,"\n Bayar : Rp. ");
					fprintf (hasil7, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil7);
				}
				else if (total > 5000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 %!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil8;
					hasil8=fopen("transaksi.txt","w");
					fprintf (hasil8,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil8,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil8,"\n=============================================================================");
					fprintf (hasil8,"\n Bayar : Rp. ");
					fprintf (hasil8, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil8);
				}
				else {
					printf ("\n 		Potongan hagra : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                   			kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					FILE * hasil9;
					hasil9=fopen("transaksi.txt","w");
					fprintf (hasil9,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil9,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil9,"\n=============================================================================");
					fprintf (hasil9,"\n Bayar : Rp. ");
					fprintf (hasil9, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil9);
				}
			}
		}

		else if (menu == 2){
			FILE * hasil4;
			hasil4=fopen("transaksi.txt","w");
			fprintf(hasil4, "\n PAKET DOKUMENTER");
			fclose (hasil4);
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
			//mencetak history transaksi
			FILE * hasil10;
			hasil10=fopen("transaksi.txt","w");
			fprintf (hasil10, "\n Jumlah Fotografer : %d ", jumlah_fotografer);
			fprintf (hasil10, "\n Jumlah Videografer : %d ", jumlah_videografer);
			fprintf(hasil10, "\n Jumlah Peserta : %d ", jumlah_orang );
			fclose (hasil10);
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
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

				printf ("\n=============================================================================");
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
				printf ("\n	                 	 Biaya	: Rp. %d", total);
				printf ("\n");
				printf ("\n=============================================================================");
				//struct
				FILE * hasil11;
				hasil11=fopen("transaksi.txt","w");
				fprintf (hasil11,"\n Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil11,"\n Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil11,"\n Opsi Tambahan	: Rp. %d", subtotal_opsi);
				fprintf (hasil11,"\n Total Biaya	: Rp. %d", total);
				fclose (hasil11);
				
				if (total > 1000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 %!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil12;
					hasil12=fopen("transaksi.txt","w");
					fprintf (hasil12,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil12,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil12,"\n=============================================================================");
					fprintf (hasil12,"\n Bayar : Rp. ");
					fprintf (hasil12, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil12);
				}
				else if (total > 5000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 %!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil13;
					hasil13=fopen("transaksi.txt","w");
					fprintf (hasil13,"\n Potongan harga : Rp. %d", diskon2);
					fprintf (hasil13,"\n Total Biaya : Rp. %d", total2);
					fprintf (hasil13,"\n=============================================================================");
					fprintf (hasil13,"\n Bayar : Rp. ");
					fprintf (hasil13, "\n Kembalian : Rp. %d", kembaliandisc2);
					fclose (hasil13);
				}
				else {
					printf ("\n 		Potongan hagra : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					//struk
					FILE * hasil14;
					hasil14=fopen("transaksi.txt","w");
					fprintf (hasil14,"\n Potongan harga : Rp. -");
					fprintf (hasil14,"\n Total Biaya : Rp. %d", total);
					fprintf (hasil14,"\n=============================================================================");
					fprintf (hasil14,"\n Bayar : Rp. ");
					fprintf (hasil14, "\n Kembalian : Rp. %d", kembalian);
					fclose (hasil14);
				}
			}

			else {
				int total = 0;
				int total1 =0, total2=0;
				int diskon1, diskon2;
				int bayar=0;
				int kembalian = 0;
				int kembaliandisc1=0, kembaliandisc2=0;


				TampilkanHasilRegistrasi(customer, pemesanan, digunakan);

				price_fotografer = HitungHargaFotografer (sewa_fotografer, jumlah_fotografer);

				price_videografer = HitungHargaVideografer (sewa_videografer, jumlah_videografer);

				price_orang = HitungHargaPerorang (jumlah_orang, harga_perorang);

				total = total + price_fotografer + price_videografer + price_orang;
				diskon1 = total*10/100;
				diskon2 = total*20/100;
				total1=total-diskon1;
				total2=total-diskon2;
				kembaliandisc1=bayar-total1;
				kembaliandisc2=bayar-total2;
				kembalian=bayar-total;

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
				//struct
				FILE * hasil15;
				hasil15=fopen("transaksi.txt","w");
				fprintf (hasil15,"\n Harga Sewa %d Fotografer	: Rp. %d",jumlah_fotografer, price_fotografer);
				fprintf (hasil15,"\n Harga Sewa %d Videografer	: Rp. %d",jumlah_videografer, price_videografer);
				fprintf (hasil15,"\n Opsi Tambahan	: Rp. %d", subtotal_opsi);
				fprintf (hasil15,"\n Total Biaya	: Rp. %d", total);
				fclose (hasil15);
				if (total > 1000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 10 %!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon1);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total1);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
					kembaliandisc1=bayar-total1;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc1);
					//struk
					FILE * hasil16;
					hasil16=fopen("transaksi.txt","w");
					fprintf (hasil16,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil16,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil16,"\n=============================================================================");
					fprintf (hasil16,"\n Bayar : Rp. ");
					fprintf (hasil16, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil16);
				}
				else if (total > 5000000){
					printf ("\n 		Anda mendapatkan diskon sebesar 20 %!");
					printf ("\n");
					printf ("\n 		Potongan hagra : Rp. %d", diskon2);
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total2);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembaliandisc2=bayar-total2;
					printf ("\n		Kembalian : Rp. %d", kembaliandisc2);
					//struk
					FILE * hasil17;
					hasil17=fopen("transaksi.txt","w");
					fprintf (hasil17,"\n Potongan harga : Rp. %d", diskon2);
					fprintf (hasil17,"\n Total Biaya : Rp. %d", total2);
					fprintf (hasil17,"\n=============================================================================");
					fprintf (hasil17,"\n Bayar : Rp. ");
					fprintf (hasil17, "\n Kembalian : Rp. %d", kembaliandisc2);
					fclose (hasil17);
				}
				else {
					printf ("\n 		Potongan hagra : Rp. -");
					printf ("\n");
					printf ("\n 		Total Biaya : Rp. %d", total);
					printf ("\n");
					printf ("\n=============================================================================");
					printf ("\n 		Bayar : Rp. ");
					scanf ("%d", &bayar);
                    			kembalian=bayar-total;
					printf ("\n			Kembalian : Rp. %d", kembalian);
					//struk
					FILE * hasil18;
					hasil18=fopen("transaksi.txt","w");
					fprintf (hasil18,"\n Potongan harga : Rp. %d", diskon1);
					fprintf (hasil18,"\n Total Biaya : Rp. %d", total1);
					fprintf (hasil18,"\n=============================================================================");
					fprintf (hasil18,"\n Bayar : Rp. ");
					fprintf (hasil18, "\n Kembalian : Rp. %d", kembaliandisc1);
					fclose (hasil18);
				}
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
