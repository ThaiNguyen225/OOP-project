#pragma once
#include <iostream>
#include "Customer.cpp"
#include "Vehicles.cpp"
using namespace std;

class HopDongThueXe {
	protected:
		string maHopDong;
		KhachHang* khachHang;
		PhuongTien* phuongTien;
		int soNgayThue;
	public:
		HopDongThueXe()
		{
			khachHang=NULL;
			phuongTien=NULL;
			soNgayThue=0;
		}
    	void NhapHopDong(QLPT qlpt, QLKH qlkh);
	    void XuatHoaDon(); 
	    void setKhachHang(KhachHang* kh) {
	    	khachHang = kh;
		}
		void setPhuongTien(PhuongTien* pt) {
			phuongTien = pt;
		}
		void setSoNgayThue(int n) {
			soNgayThue = n;
		}
		string getIDHopDong() {
			return maHopDong;
		}
		PhuongTien* getPhuongTien() {
			return phuongTien;
		} 
		
};

void HopDongThueXe::NhapHopDong(QLPT qlpt, QLKH qlkh) {
	cout << "-->Nhap ma hop dong: "; 
	cin.ignore();
	getline(cin, maHopDong);
	string id2, cccd2; 
	PhuongTien a; KhachHang b; 
	cout << "-->Nhap ID xe can thue: "; getline(cin, id2); 
	a = qlpt.layPhuongTien(id2);
	cout << "-->Nhap CCCD cua khach hang thue xe: "; getline(cin, cccd2);
	b = qlkh.layKhachHang(cccd2);
	int days;
	cout << "-->Nhap so ngay thue: "; cin >> days;
	qlpt.thayDoiTinhTrangPhuongTien(id2);
	if (!qlkh.tonTaiKhachHang(cccd2)) {
		cout << "			Khong tim thay khach hang co CCCD: " << cccd2 << endl;
	} else if (!qlpt.tonTaiPhuongTien(id2)) {
		cout << "			Khong tim thay phuong tien co ID: " << id2 << endl;
	} else if (a.getTinhTrang() == 1) {
		cout << "			Phuong tien da duoc thue boi nguoi khac" << endl;
	} else {
		a.setTinhTrang();
		khachHang = new KhachHang();
		*khachHang = b;
		phuongTien = new PhuongTien();
		*phuongTien = a;
		soNgayThue = days;
	} 
}
void HopDongThueXe::XuatHoaDon() {
	khachHang->hienThiThongTin1();
	phuongTien->hienThiThongTin();
	cout << "				| Gia thue: " << phuongTien->getGiaThue()*soNgayThue << " vnd" << endl;
	cout << "				| So tien can dat coc: " << phuongTien->getGiaThue()*soNgayThue*0.3<< " vnd" << endl;
}

class QLHD: public HopDongThueXe {
	protected:
		HopDongThueXe* danhSachHopDong[100];
		int soLuongHopDong;
	public:
		QLHD() : soLuongHopDong(0) {}
		void themHopDong(HopDongThueXe* hd) {
        	if (soLuongHopDong < 100) {
            	danhSachHopDong[soLuongHopDong++] = hd;
       		} else {
        	    cout << "			Danh sach hop dong da day!" << endl;
        	}
    	}
    	void hienThiDanhSach2() {
    		if (soLuongHopDong == 0) {
        	cout << "			Danh sach hop dong hien dang trong." << endl;
        	return;
    	}
        	for (int i = 0; i < soLuongHopDong; ++i) {
        		cout << "				| Ma hop dong: " << danhSachHopDong[i]->getIDHopDong() << endl;
        	    danhSachHopDong[i]->XuatHoaDon();
        	    cout << "				_______________________________________________" << endl << endl; 
        	}
    }
    
    void xoaHopDong(const string& ID, QLPT qlpt) {
    	bool found = false;
    	for (int i = 0; i < soLuongHopDong; ++i) {
    	    if (danhSachHopDong[i]->getIDHopDong() == ID) {
    	        found = true;
    	        delete danhSachHopDong[i];
    	        for (int j = i; j < soLuongHopDong - 1; ++j) {
    	            danhSachHopDong[j] = danhSachHopDong[j + 1];
    	        }
        	    soLuongHopDong--; 
        	    string vehicleID = danhSachHopDong[i]->getPhuongTien()->getID();
				qlpt.thayDoiTinhTrangPhuongTien(vehicleID); 
        	    
        	    cout << "			Xoa hop dong co ma: " << ID << " thanh cong." << endl;
        	    break;
        	}
    	}
    	if (!found) {
    	    cout << "			Khong tim thay hop dong co ma: " << ID << endl;
    	}
}

};


