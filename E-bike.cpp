#pragma once
#include <iostream>
#include <string>
#include "Vehicles.cpp"
using namespace std;

class XeDien : public virtual PhuongTien{
	protected:
		float quangDuongMax;
		float thoiGianSac;
	public:	
	XeDien(){}
	XeDien(string id2, string hangXe2, int namSanXuat2, int tinhTrang2, double giaThue2, 
    float QUANGDUONGMAX, float THOIGIANSAC) : PhuongTien(id2, hangXe2, namSanXuat2, tinhTrang2, giaThue2) {
    quangDuongMax = QUANGDUONGMAX;
    thoiGianSac = THOIGIANSAC;
    }

	void nhapThongTin() override {
		PhuongTien::nhapThongTin();
		cout<<"| Nhap so km toi da di duoc (km): ";
		cin>>quangDuongMax;
		cin.ignore();
		cout<<"| Nhap thoi gian sac day dien (h): ";
		cin>>thoiGianSac;
	}
	void hienThiThongTin() override {
		PhuongTien::hienThiThongTin();
		cout << left << setw(27) << "| Quang duong toi da: " << left << setw(4) << fixed << setprecision(1) << quangDuongMax
		<< left << setw(16) << "km" << "|" << endl;
		cout << left << setw(27) << "| Thoi gian sac day: " << left << setw(3) << fixed << setprecision(1) << thoiGianSac 
		<< left << setw(17) << "h" << "|" << endl;
		cout << left << setw(27) << "|______________________________________________|" << endl; 
	}
};

