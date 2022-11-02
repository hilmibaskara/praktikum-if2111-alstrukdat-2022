/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	Tanggal		: 31 Oktober 2022
	Topik		: Praktikum 8
	Deskripsi	: SOAL 2 - Implementasi union_map.h
*/

#include "union_map.h"

Map UnionMap(Map m1, Map m2, boolean key_based ){ 
	
	Map m3, temp;
	CreateEmpty(&m3);
	CreateEmpty(&temp);
	int temp_k, temp_v;

	// gabungin semua dalam temp
	// masukin m1 ke temp
	for (int i = 0; i < m1.Count; i++){
		temp_k = m1.Elements[i].Key;
		temp_v = m1.Elements[i].Value;
		Insert(&temp, temp_k, temp_v);
	}
	
	//masukin m2 ke temp
	for (int i = 0; i < m2.Count; i++){
		temp_k = m2.Elements[i].Key;
		temp_v = m2.Elements[i].Value;
		Insert(&temp, temp_k, temp_v);
	}

	int val_min, key_min;
	int len = temp.Count;
	// terurut membesar berdasarkan key
	if (key_based)
	{
		for (int i = 0; i < len; i++){
			key_min = temp.Elements[0].Key;
			for (int j = 0; j < temp.Count; j++){
				if (temp.Elements[j].Key < key_min){
					key_min = temp.Elements[j].Key;
				}
			}
			val_min = Value(temp, key_min);
			Insert(&m3, key_min, val_min);
			Delete(&temp, key_min);
		}
	} else if (!key_based) {
		// berdasarkan value, nyoba pake algoritma bubble sorting
		// coba masukin dulu ke m3
		for (int i = 0; i < temp.Count; i++){
			Insert(&m3, temp.Elements[i].Key, temp.Elements[i].Value);
		}
		int temp_val, temp_key, n = m3.Count;
		for (int i = 0; i < n - 1; i++){
			for (int j = 0; j < n - i - 1; j++){
				if (m3.Elements[j].Value > m3.Elements[j+1].Value){
					temp_val = m3.Elements[j].Value; temp_key = m3.Elements[j].Key;					
					m3.Elements[j].Value = m3.Elements[j+1].Value; m3.Elements[j].Key = m3.Elements[j+1].Key;
					m3.Elements[j+1].Value = temp_val; m3.Elements[j+1].Key = temp_key;
					
				}
			}
		}
	}

	return m3;
}