#include <iostream>
#include <fstream>
#include "Vehicles.cpp"
#include "Customer.cpp"
#include "Bike.cpp"
#include "Car.cpp"
#include "Motor.cpp"
#include "E-bike.cpp"
#include "Rental.cpp"

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("CLS"); 
    #else
        system("clear"); 
    #endif
}

int main() {
    
    int choice;
    QLPT qlpt;
    QLKH qlkh;
    QLHD qlhd;
    do {
        clearScreen();
        cout << "				________________MENU_______________" << endl;
        cout << "				|      1.Nhap thong tin           |" << endl;
        cout << "				|      2.Hien thi phuong tien     |" << endl;
        cout << "				|      3.Hien thi khach hang      |" << endl;
        cout << "				|      4.Cap nhat gia thue        |" << endl;
        cout << "				|      5.Xoa 1 phuong tien        |" << endl;
        cout << "				|      6.Chon xe de thue          |" << endl;
        cout << "				|      7.Chon xe de tra           |" << endl;
        cout << "				|      8.Xuat hoa don             |" << endl;
        cout << "				|      9.Tim kiem phuong tien     |" << endl;
        cout << "				|      10.Tim kiem khach hang     |" << endl;
        cout << "				|      11.Thoat                   |" << endl;
        cout << "				|_________________________________|" << endl;
        cout << "		-->Moi ban nhap lua chon: "; cin >> choice;
        
        clearScreen(); 

        if (choice == 1) {
            PhuongTien* phuongTien;
            int choice1;

            do {
            	cout << "-->Chon doi tuong nhap (1- Nhap thong tin phuong tien | 2- Nhap thong tin khach hang): ";
            	cin >> choice1;
            if (choice1 == 1) {
                int loaiPhuongTien;
                do {
    			cout << "-->Chon loai phuong tien (1- Xe may | 2- Xe dap | 3- Xe dien | 4- O to): ";
    			cin >> loaiPhuongTien;

    			if (loaiPhuongTien == 1) {
    			    phuongTien = new XeMay();
    			} else if (loaiPhuongTien == 2) {
        			phuongTien = new XeDap();
   				} else if (loaiPhuongTien == 3) {
    			    phuongTien = new XeDien();
    			} else if (loaiPhuongTien == 4) {
    			    phuongTien = new OTo();
    			} else {
    			    cout << "			Lua chon khong hop le!" << endl;
    			}
				} while (loaiPhuongTien != 1 && loaiPhuongTien != 2 && loaiPhuongTien != 3 && loaiPhuongTien != 4);
                phuongTien->nhapThongTin();
                qlpt.themPhuongTien(phuongTien);
            } else if (choice1 == 2) {
                KhachHang* khachHang = new KhachHang();
                khachHang->nhapThongTin1();
                qlkh.themKhachHang(khachHang);
            } else {
                cout << "			Lua chon khong hop le!" << endl;
            }
			} while(choice1 != 1 && choice1 != 2);
        } else if (choice == 2) {
            cout << "				  =========DANH SACH PHUONG TIEN=========" << endl;
            qlpt.hienThiDanhSach();
        } else if (choice == 3) {
            cout << "				  =========DANH SACH KHACH HANG=========" << endl;
            qlkh.hienThiDanhSach1();
        } else if (choice == 4) {
            string id;
            double giaThueMoi; 
            cin.ignore();
            cout << "-->Nhap ID phuong tien can cap nhat gia thue: ";
            getline(cin, id);
            cout << "-->Nhap gia thue moi: ";
            cin >> giaThueMoi;
            qlpt.capNhatGiaThue(id, giaThueMoi);
        } else if (choice == 5) {
            string id1;
            cout << "-->Nhap ID phuong tien can xoa: ";
            cin.ignore();
            getline(cin, id1);
            qlpt.xoaPhuongTien(id1);
        } else if (choice == 6) {
            HopDongThueXe* hopDong = new HopDongThueXe();
            hopDong->NhapHopDong(qlpt, qlkh);
            qlhd.themHopDong(hopDong);
        } else if (choice == 7) {
        	string id4;
        	cout << "-->Nhap ID hop dong cua phuong tien can tra: ";
        	cin.ignore();
        	getline(cin, id4);
        	qlhd.xoaHopDong(id4, qlpt);
		}else if (choice == 8) {
            cout << "				  =========DANH SACH HOP DONG===========" << endl;
            qlhd.hienThiDanhSach2();
        } else if (choice == 9) {
            string id3;
            cout << "-->Nhap ID phuong tien can tim kiem: ";
            cin.ignore();
            getline(cin, id3);
            qlpt.timKiemPhuongTien(id3);
        } else if (choice == 10) {
            string cccd3;
            cout << "-->Nhap CCCD khach hang can tim kiem: ";
            cin.ignore();
            getline(cin, cccd3);
            qlkh.timKiemKhachHang(cccd3);
        } 
        cin.ignore();
        cout << "			Nhan Enter de quay lai Menu";
        cin.get();
    	
    } while (choice != 11);
    return 0;
}

