#pragma once
#include <iostream>
#include <string>
using namespace std;

class KhachHang {
	protected:
		string tenKhachHang;
		int tuoi;
		string sdt;
		string cccd;
		string email;
		string diaChi;
		int bangLai;
	public:
		string getTenKhachHang() {
			return tenKhachHang;
		}
		string getCCCD() {
			return cccd;
		}
	    void nhapThongTin1();
		void hienThiThongTin1(); 
};

void KhachHang::nhapThongTin1() {
	cout << "-----------NHAP THONG TIN KHACH HANG-----------" << endl;
	cin.ignore(); 
	cout << "| Ho ten: "; getline(cin, tenKhachHang);
	cout << "| Tuoi: "; cin >> tuoi; cin.ignore(); 
	cout << "| So dien thoai: "; getline(cin, sdt);
	cout << "| So CCCD: "; getline(cin, cccd);
	cout << "| Email(Khong can nhap @gmail.com): "; getline(cin, email);
	cout << "| Dia chi: "; getline(cin, diaChi);
	cout << "| Bang lai(1-Co, 2-Khong): "; cin >> bangLai; 
}

void KhachHang::hienThiThongTin1() {
	cout << "				-------------THONG TIN KHACH HANG-------------" << endl;
	cout << "				| Ho va ten: " << tenKhachHang << endl;
	cout << "				| Tuoi: " << tuoi << endl;
	cout << "				| So dien thoai: " << sdt << endl;
	cout << "				| So CCCD: " << cccd << endl;
	cout << "				| Email: " << email << "@gmail.com" << endl;
	cout << "				| Dia chi: " << diaChi << endl;
	cout << "				| Bang lai: " << (bangLai == 1 ? "Co" : "Khong") << endl;
	cout << "				|______________________________________________" << endl;  
}

class QLKH {
protected:
    KhachHang* danhSachKhachHang[100];
    int soLuongKhachHang;
public:
	QLKH() : soLuongKhachHang(0) {}
	
	bool tonTaiKhachHang(const string& cccd1) {
		for (int i = 0; i < soLuongKhachHang; i++) {
			if (danhSachKhachHang[i]->getCCCD() == cccd1)
				return true;
		} 
		return false;
	}
	
    void themKhachHang(KhachHang* kh) {
        if (soLuongKhachHang < 100) {
            danhSachKhachHang[soLuongKhachHang++] = kh;
        }
    }

    void timKiemKhachHang(const string& cccd1) {
        for (int i = 0; i < soLuongKhachHang; ++i) {
            if (danhSachKhachHang[i]->getCCCD() == cccd1) {
                danhSachKhachHang[i]->hienThiThongTin1();
                return;
            }
        }
        cout << "			Khong tim thay hang hang co CCCD: " << cccd1 << endl;
    }

    void hienThiDanhSach1() {
    	if (soLuongKhachHang == 0) {
        cout << "			Danh sach khach hang hien dang trong." << endl;
        return;
    }
        for (int i = 0; i < soLuongKhachHang; ++i) {
            danhSachKhachHang[i]->hienThiThongTin1();
            cout << "				|_____________________________________________" << endl; 
        }
    }

	KhachHang layKhachHang(const string& cccd) {
    	for (int i = 0; i < soLuongKhachHang; ++i) {
        	if (danhSachKhachHang[i]->getCCCD() == cccd) {
        	    return *danhSachKhachHang[i]; 
        	}
    	}
    	cout << "			Khong tim thay khach hang co CCCD: " << cccd << endl;
    	return KhachHang(); 
    }
};



