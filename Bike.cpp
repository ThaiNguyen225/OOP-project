#pragma once
#include<iostream>
#include<string>
#include "Vehicles.cpp"
using namespace std;

class XeDap: public virtual PhuongTien {
	protected:
		double trongLuong;
		int kieuXe;
	public:
		void nhapThongTin() override {
			PhuongTien::nhapThongTin();
			cout << "| Nhap trong luong xe: "; cin >> trongLuong;
			do {
    		    cout << "| Nhap kieu xe (1 - Xe dia hinh, 2 - Xe the thao, 3 - Xe dap doi): ";
    		    cin >> kieuXe;

    		    if (kieuXe < 1 || kieuXe > 3) {
    		        cout << "Khong hop le. Vui long nhap lai!\n";
    		    }
    		} while (kieuXe < 1 || kieuXe > 3);
		}
		void hienThiThongTin() override {
			PhuongTien::hienThiThongTin();
			cout << "				| Trong luong xe: " << trongLuong << "kg" << endl;
			cout << "				| Kieu xe: " << (kieuXe==1? "Xe dia hinh" : kieuXe==2 ? "Xe the thao" : "Xe dap doi")  << endl;
			cout << "				|______________________________________________" << endl; 
		}	

};
