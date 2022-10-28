//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRA-PRAKTIKUM 2

#include <stdio.h>
#include "time.h"

boolean IsTIMEValid (int H, int M, int S){
    return (0<=H) && (H<24) && (0<=M) && (M<60) && (0<=S) && (S<60);
}

TIME MakeTIME (int HH, int MM, int SS){
    TIME time;
    Hour(time)=HH;
    Minute(time)=MM;
    Second(time)=SS;
    return time;
}

void BacaTIME (TIME * T){
    boolean benar=false;
    int j,m,d;
    while(benar == false){
        scanf("%d %d %d", &j,&m,&d);
        benar=IsTIMEValid(j,m,d);
        if (benar == false){
            printf("Jam tidak Valid\n");
        }
    }
    *T=MakeTIME(j,m,d);
}

void TulisTIME (TIME T){
   printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T){
    return (3600*Hour(T)+ 60*Minute(T) + Second(T));
}

TIME DetikToTIME (long N){
    TIME time ;
    int j,m,d;
    N = N%86400; //mengatasi agar maksimal adalah jam 24 (sehari ada 86400 detik)
    j = N/3600;
    m = (N%3600)/60;
    d = (N%3600)%60;
    time = MakeTIME(j,m,d);
    return time ;
}

boolean TEQ (TIME T1, TIME T2){
    return (Hour(T1)==Hour(T2)) && (Minute(T1)==Minute(T2)) && (Second(T1)==Second(T2));
}

boolean TNEQ (TIME T1, TIME T2){
    return!((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2)));
}

boolean TLT (TIME T1, TIME T2){
    return TIMEToDetik(T1)<TIMEToDetik(T2);
}

boolean TGT (TIME T1, TIME T2){
    return TIMEToDetik(T1)>TIMEToDetik(T2);
}

TIME NextDetik (TIME T){
    long detik;
    detik = TIMEToDetik(T);
    detik = detik+1 ;
    return DetikToTIME(detik);
}

TIME NextNDetik (TIME T, int N){
    long detik;
    detik = TIMEToDetik(T);
    detik = detik + N;
    return DetikToTIME(detik);
}

TIME PrevDetik (TIME T){
    long detik;
    detik = TIMEToDetik(T);
    detik = detik-1 ;
    return DetikToTIME(detik);
}

TIME PrevNDetik (TIME T, int N){
    long detik;
    detik = TIMEToDetik(T);
    detik = detik-N ;
    return DetikToTIME(detik);
}

long Durasi (TIME TAw, TIME TAkh){
    long selisih = TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    if (selisih < 0) {
        selisih += 86400;
    }
    return selisih;
}
