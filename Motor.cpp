#pragma once
#include<iostream>
#include<string>
#include "Vehicles.cpp"
using namespace std;

class XeMay : public virtual PhuongTien{
	protected:
		float dungTichXiLanh;
		int kieuXe;
	public:	
	XeMay(){}
	XeMay(string a, string b, int c, int d, double e, 
	float f, int g) : PhuongTien(a, b, c, d, e) {
		dungTichXiLanh = f;
		kieuXe = g;
	}
	void nhapThongTin() override {
		PhuongTien::nhapThongTin();
		cout<<"| Nhap dung tich xi lanh cua xe: ";
		cin>>dungTichXiLanh;
		cin.ignore();
		do {
			cout<<"| Nhap kieu xe (1- Xe tay ga; 2- Xe so; 3- Xe tay con): ";
			cin>>kieuXe;
			if (kieuXe !=1 && kieuXe !=2 && kieuXe !=3 ){
				cout<<"| Kieu xe khong hop le. Vui long nhap lai."<<endl;
			}
		} while (kieuXe !=1 && kieuXe !=2 && kieuXe !=3);
	}
	void hienThiThongTin() override {
		PhuongTien::hienThiThongTin();
		cout << left << setw(27) << "| Dung tich xi lanh: " << left << setw(3) << dungTichXiLanh << left << setw(17) << "cc" << "|" << endl;
		cout << left << setw(27) << "| Kieu xe: " << left << setw(20) << (kieuXe ==1? "Xe tay ga" :(kieuXe==2? "Xe so" : "Xe tay con")) << "|" << endl;
		cout << left << setw(27) << "|______________________________________________|" << endl; 
	}
};
