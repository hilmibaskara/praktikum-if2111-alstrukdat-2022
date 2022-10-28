#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int dectobin(int n);
int bintodec(int n);

int bintookta(int n);
int oktatobin(int n);

int dectookta(int n);
int oktatodec(int n);

void dectohexa(int n);
int hexatodec(char n[]);

void bintohexa(int n);
int hexatobin(char n[]);

void oktatohexa(int n);
int hexatookta(char n[]);

int main()
{
    printf("FEI'S CONVERSION\n");
    printf("Program ini akan mengkonversi sesuai permintaan pengguna\n");
    printf("***************************************************************\n");
    printf("PILIHAN:\n");
    printf("1. DECIMAL\n");
    printf("2. BINER\n");
    printf("3. OKTA\n");
    printf("4. HEXA\n");
    printf("***************************************************************\n");
    printf("CONTOH PENGGUNAAN:\n");
    printf("Masukkan 1 pada 'Pilihan Dasar: ' dan 2 pada 'Hasil: ' dan program akan mengubah input user dari decimal ke biner\n");
    printf("***************************************************************\n");
    printf("MASUKKAN PILIHAN!\n");
    int pil1,pil2;
    printf("Pilihan Dasar: ");
    scanf("%d",&pil1);
    printf("Hasil: ");
    scanf("%d",&pil2);
    int n,hasil;
    char kata[4];
    if (pil1==1){
        if(pil2==2){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            hasil=dectobin(n);
            printf("Hasil konversi: %d\n",hasil);

        }
        else if(pil2==3){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            hasil=dectookta(n);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==4){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            printf("Hasil konversi: ");
            dectohexa(n);
        }
        else{
            printf("Input salah, ulangi program ini :)\n");
        }
    }
    else if (pil1==2){
        if(pil2==1){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            hasil=bintodec(n);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==3){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            hasil=bintookta(n);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==4){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            bintohexa(n);
        }
        else{
            printf("Input salah, ulangi program ini :)\n");
        }
        
    }
    else if (pil1==3){
        if(pil2==1){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            hasil=oktatodec(n);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==2){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            hasil=oktatobin(n);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==4){
            printf("Masukkan angka anda: ");
            scanf("%d",&n);
            oktatohexa(n);
        }
        else{
            printf("Input salah, ulangi program ini :)\n");
        }
    }
    else if (pil1==4){
        if(pil2==1){
            printf("Masukkan angka anda(MAX 4 DIGIT): ");
            scanf("%s",kata);
            hasil=hexatodec(kata);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==2){
            printf("Masukkan angka anda(MAX 4 DIGIT): ");
            scanf("%s",kata);
            hasil=hexatobin(kata);
            printf("Hasil konversi: %d\n",hasil);
        }
        else if(pil2==3){
            printf("Masukkan angka anda(MAX 4 DIGIT): ");
            scanf("%s",kata);
            hasil=hexatookta(kata);
            printf("Hasil konversi: %d\n",hasil);
        }
        else{
            printf("Input salah, ulangi program ini :)\n");
        }
    }
    else{
        printf("Input salah, ulangi program ini :)\n");
    }
    return 0;

}
int dectookta(int n){
    int hasil,check;
    check=dectobin(n);
    hasil=bintookta(check);
    return hasil;

}
int oktatodec(int n){
    int hasil,check;
    check=oktatobin(n);
    hasil=bintodec(check);
    return hasil;
}
int dectobin(int n)
{
    int sisa,hitung=1,hasil=0;
    while (n!=0)
    {
        sisa=n%2;
        n=n/2;
        hasil=hasil+sisa*hitung;
        hitung=hitung*10;
    }
    return hasil;
}
int bintodec(int n){
    int hasil=0,i=0,sisa;
    while (n!=0){
        sisa=n%10;
        n/=10;
        hasil+=sisa*pow(2,i);
        i++;
    }
    return hasil;
}
int bintookta(int n){
    int check, pangkat=1,bagi=1000,hasil=0;
    while (n>0){
        bagi=pow(1000,pangkat);
        check=n%bagi;
        hasil=bintodec(check)*pow(10,(pangkat-1))+hasil;
        n-=check;
        n/=1000;
        pangkat+=1;
    }
    return hasil;
}
int oktatobin(int n){
    int proses,pangkat,hasil=0;
    pangkat=0;
    while (n!=0){
       proses=n%10;
       hasil=dectobin(proses)*pow(1000,pangkat)+hasil;
       n-=proses;
       n/=10;
       pangkat+=1;
    }
    return hasil;
}
void dectohexa(int n){
    int check,simpan,total,i;
    char sembarang;
    while (n!=0){
        check=n%16;
        if (check<10){
            simpan=48+check;
        }
        else{
            simpan=55+check;
        }
        total=total*100+simpan;
        n/=16;
    }
    for (i=total;i>0;i/=100){
        sembarang=i%100;
        printf("%c",sembarang);
    }
    printf("\n");
}
int hexatodec(char n[]){
    int panjang=strlen(n),i,bilangan=0,pangkat=1;
    for (i=panjang-1;i>=0;i--){
        if ((n[i]>='0')&&(n[i]<='9')){
            bilangan+=(n[i]-48)*pangkat;
        }
        else if ((n[i]>='A')&&(n[i]<='F')){
            bilangan+=(n[i]-55)*pangkat;
        }
        pangkat=pangkat*16;
    }
    return bilangan;
}
void bintohexa(int n){
    int convert=bintodec(n);
    dectohexa(convert);
}
int hexatobin(char n[]){
    int convert=hexatodec(n);
    int check=dectobin(convert);
    return check;
}
void oktatohexa(int n){
    int convert=oktatodec(n);
    dectohexa(convert);
}
int hexatookta(char n[]){
    int convert=hexatodec(n);
    int check=dectookta(convert);
    return check;
}