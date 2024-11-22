#pragma once
#include <iostream>
#include <string>
#include "Vehicles.cpp"
using namespace std;

class OTo : public virtual PhuongTien{
protected:
	int soCho;
	int mauXe;
public:	
	OTo(){}
	OTo(string id1, string hangXe1, int namSanXuat1, int tinhTrang1, double giaThue1,
         int SOCHO, int MAUXE) : PhuongTien(id1, hangXe1, namSanXuat1, tinhTrang1, giaThue1) {
        soCho = SOCHO;
        mauXe = MAUXE;
    }
	void nhapThongTin() override {
		PhuongTien::nhapThongTin();
		cout<<"| Nhap so cho: ";
		cin>>soCho;
		cin.ignore();
		do {
			cout<<"| Nhap mau xe (1- Ban tai; 2- Du lich; 3- Hybrid): ";
			cin>>mauXe;
			if (mauXe !=1 && mauXe !=2 && mauXe !=3 ){
				cout<<"| Mau xe khong hop le. Vui long nhap lai."<<endl;
			}
		} while (mauXe !=1 && mauXe !=2 && mauXe !=3);
	}
	void hienThiThongTin() override {
		PhuongTien::hienThiThongTin();
		cout << left << setw(27) << "| Nhap so cho: " << left << setw(20) << soCho << "|" << endl;
		cout << left << setw(27) << "| Nhap mau xe: " << left << setw(20) << (mauXe ==1? "Ban tai" :(mauXe==2? "Du lich" : "Hybrid")) << "|" << endl;
		cout << left << setw(27) << "|______________________________________________|" << endl; 
	}
};
