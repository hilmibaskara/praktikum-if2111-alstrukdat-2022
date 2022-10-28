/*
NIM			: 18221072
Nama		: Hilmi Baskara Radanto
TAnggal		: 3 Oktober 2022
TOpik		: Praktikum 5 Soal 1
Deskripsi	: Menghitung jumlah kemunculan kata tiga pada kata tersebut
*/

#include <stdio.h>
#include <stdlib.h>
#include "hitungfrekuensi.h"

int hitungfrekuensi(){
	int count = 0;
	START();
	while (GetCC() != MARK){
		if (GetCC() == 't' || GetCC() == 'T'){
			ADV();
			if (GetCC() == 'i' || GetCC() == 'I'){
				ADV();
				if (GetCC() == 'g' || GetCC() == 'G'){
					ADV();
					if (GetCC() == 'a' || GetCC() == 'A'){
						count += 1;
						ADV();
					}
					else {
						ADV();
					}
				}
				else {
					ADV();
				}
			}
			else {
				ADV();
			}
		}
		else {
			ADV();
		}
	}
	return count;
}

