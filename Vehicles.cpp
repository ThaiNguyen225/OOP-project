#pragma once
#include <iostream>
#include <string>
using namespace std;

class PhuongTien {
	protected:
		string id;
		string hangXe;
		int namSanXuat;
		int tinhTrang;
		double giaThueTheoNgay;
	public:
		virtual void nhapThongTin();
		virtual void hienThiThongTin();
		string getID() {
			return id;
		}
		int getTinhTrang() {
			return tinhTrang;
		}
		double getGiaThue() {
			return giaThueTheoNgay;
		}
		void setGiaThue(int n) {
			giaThueTheoNgay = n;
		} 
		void setTinhTrang() {
			if (tinhTrang == 0) {
				tinhTrang = 1;
			} else {
				tinhTrang = 0;
			}
		}
};

void PhuongTien::nhapThongTin() {
	cout << "-----------NHAP THONG TIN PHUONG TIEN-----------" << endl;
    cout << "| Nhap ID xe: ";
    cin.ignore();
    getline(cin, id);
	cout << "| Nhap hang xe: ";
	getline(cin, hangXe);
    cout << "| Nhap nam san xuat: ";
    cin >> namSanXuat; cin.ignore();
    do {
        cout << "| Nhap tinh trang (0: chua thue, 1: da thue): ";
        cin >> tinhTrang; cin.ignore();
        if (tinhTrang != 0 && tinhTrang != 1) {
            cout << "| Tinh trang khong hop le! Vui long nhap lai." << endl;
        }
    } while (tinhTrang != 0 && tinhTrang != 1);
    cout << "| Nhap gia thue theo ngay(VND): ";
    cin >> giaThueTheoNgay;
    cin.ignore();  
}

void PhuongTien::hienThiThongTin() {
	cout << "				-------------THONG TIN PHUONG TIEN-------------" << endl;
	cout << "				| ID: " << id << endl;
    cout << "				| Hang xe: " << hangXe << endl;
	cout << "				| Nam san xuat: " << namSanXuat << endl;
	cout << "				| Tinh trang: " << (tinhTrang == 0 ? "Chua thue" : "Da thue") << endl;
	cout << "				| Gia thue theo ngay: " << giaThueTheoNgay << endl;
}

class QLPT {
protected:
    PhuongTien* danhSachPhuongTien[100];
    int soLuongPhuongTien;
public:
    QLPT() : soLuongPhuongTien(0) {}
    
    int getSoLuongPT() {
    	return soLuongPhuongTien;
	}
	
	bool tonTaiPhuongTien(const string& id1) {
		for (int i = 0; i < soLuongPhuongTien; i++) {
			if (danhSachPhuongTien[i]->getID() == id1)
				return true;
		} 
		return false;
	}
    
    void thayDoiTinhTrangPhuongTien(const string& id) {
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            if (danhSachPhuongTien[i]->getID() == id) {
                danhSachPhuongTien[i]->setTinhTrang();  
                return;
            }
        }
    }
    
	void capNhatGiaThue(string id, double giaThueMoi) {
        bool timThay = false;
        for (int i = 0; i < soLuongPhuongTien; i++) {
            if (danhSachPhuongTien[i]->getID() == id) { 
                danhSachPhuongTien[i]->setGiaThue(giaThueMoi);
                cout << "Cap nhat gia thue thanh cong!" << endl;
                timThay = true;
                break;
            }
        }
        if (!timThay) {
            cout << "Khong tim thay phuong tien voi ID: " << id << endl;
        }
    }
    
    void themPhuongTien(PhuongTien* pt) {
        if (soLuongPhuongTien < 100) {
            danhSachPhuongTien[soLuongPhuongTien++] = pt;
        }
    }

    void timKiemPhuongTien(const string& ID) {
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            if (danhSachPhuongTien[i]->getID() == ID) {
                danhSachPhuongTien[i]->hienThiThongTin();
                return;
            }
        }
        cout << "Khong tim thay phuong tien co ID " << ID << endl;
    }

    void hienThiDanhSach() {
    	if (soLuongPhuongTien == 0) {
        cout << "Danh sach phuong tien hien dang trong." << endl;
        return;
    }
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            danhSachPhuongTien[i]->hienThiThongTin();
        }
    }

    void xoaPhuongTien(const string& ID) {
        for (int i = 0; i < soLuongPhuongTien; ++i) {
            if (danhSachPhuongTien[i]->getID() == ID) {
            	for (int j = i; j < soLuongPhuongTien - 1; ++j) {
                    danhSachPhuongTien[j] = danhSachPhuongTien[j + 1];
                }
                --soLuongPhuongTien;
                cout << "			Da xoa phuong tien co ID " << ID << endl;
                return;
            }
        } cout << "			Khong tim thay phuong tien de xoa!" << endl;
    }
    
    PhuongTien layPhuongTien(const string& ID) {
    for (int i = 0; i < soLuongPhuongTien; ++i) {
        if (danhSachPhuongTien[i]->getID() == ID) {
            return *danhSachPhuongTien[i]; 
        }
    }
    cout << "Khong tim thay phuong tien co ID: " << ID << endl;
    return PhuongTien(); 
	}
};


