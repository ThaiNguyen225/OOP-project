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
		cout << "				| Quang duong toi da di duoc (km): " << quangDuongMax << endl;
		cout << "				| Thoi gian sac day (h): " << thoiGianSac << endl;
		cout << "				|______________________________________________" << endl; 
		
		
	}
};

