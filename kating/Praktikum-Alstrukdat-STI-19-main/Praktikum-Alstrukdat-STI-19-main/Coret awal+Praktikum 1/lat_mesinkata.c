#include"lat_mesinkata.h"
boolean endkata;
kata ckata;

void startkata(){
    start();
    ignore_blank();
    if(cc==mark){
        endkata=true;
    }
    else{
        endkata=false;
        salinkata();
    }
}
void ignore_blank(){
    if (cc==blank){
        adv();
    }

}
void salinkata(){
    int i=0;
    while (cc!=mark && cc!=blank){
        ckata.tabkata[i]=cc;
        adv();
        i++;
    }
    ckata.length=i;

}
void advkata(){
    ignore_blank();
    if (cc==mark){
        endkata=true;
    }
    else{
        salinkata();
    }
}