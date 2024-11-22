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
		XeDap(){}
		XeDap(string ID, string HANGXE, int NAMSANXUAT, int TINHTRANG, double GIATHUE, 
		double TRONGLUONG, int KIEUXE) : PhuongTien(ID, HANGXE, NAMSANXUAT, TINHTRANG, GIATHUE) {
			trongLuong = TRONGLUONG;
			kieuXe = KIEUXE;
		}
		void nhapThongTin() override {
			PhuongTien::nhapThongTin();
			cout << "| Nhap trong luong xe: "; cin >> trongLuong;
			do {
    		    cout << "| Nhap kieu xe (1 - Xe dia hinh, 2 - Xe the thao, 3 - Xe dap doi): ";
    		    cin >> kieuXe;

    		    if (kieuXe < 1 || kieuXe > 3) {
    		        cout << "-->Khong hop le. Vui long nhap lai!" << endl;
    		    }
    		} while (kieuXe < 1 || kieuXe > 3);
		}
		void hienThiThongTin() override {
			PhuongTien::hienThiThongTin();
			cout << left << setw(27) << "| Trong luong xe: " << left << setw(3) << trongLuong << left << setw(17) << " kg" << "|" << endl;
			cout << left << setw(27) << "| Kieu xe: " << left << setw(20) << (kieuXe==1? "Xe dia hinh" : kieuXe==2 ? "Xe the thao" : "Xe dap doi") << "|"  << endl;
			cout << left << setw(27) << "|______________________________________________|" << endl; 
		}	
};
