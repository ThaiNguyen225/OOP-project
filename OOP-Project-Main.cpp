#include <iostream>
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
	
	//danh sach phuong tien co san
	XeMay* PT1 = new XeMay("001", "Honda", 2017, 0, 200000, 100, 2); qlpt.themPhuongTien(PT1);
	XeMay* PT2 = new XeMay("002", "Vision", 2018, 0, 320000, 150, 1); qlpt.themPhuongTien(PT2);
	XeDap* PT3 = new XeDap("003", "Giant", 2020, 0, 130000, 12, 2); qlpt.themPhuongTien(PT3);
	XeDap* PT4 = new XeDap("004", "Fujisan", 2019, 0, 150000, 9, 2); qlpt.themPhuongTien(PT4);
	XeDien* PT5 = new XeDien("005", "Vinfast", 2022, 0, 200000, 60, 3); qlpt.themPhuongTien(PT5);
	XeDien* PT6 = new XeDien("006", "Pega", 2020, 0, 180000, 50, 5); qlpt.themPhuongTien(PT6);
	OTo* PT7 = new OTo("007", "Suzuki", 2017, 0, 800000, 7, 2); qlpt.themPhuongTien(PT7);
	OTo* PT8 = new OTo("008", "Toyota", 2018, 0, 850000, 7, 1); qlpt.themPhuongTien(PT8);
	
	//danh sach khach hang co san
	KhachHang* KH1 = new KhachHang("Nguyen Quoc Thai", 2005, "0841111111", "091211111111", "thai", "Kien Giang", 1); qlkh.themKhachHang(KH1);
	KhachHang* KH2 = new KhachHang("Thai Gia Tan", 2005, "0842222222", "091222222222", "tan", "Ho Chi Minh", 2); qlkh.themKhachHang(KH2);
	KhachHang* KH3 = new KhachHang("Tran Duy Khanh", 2005, "0843333333", "091233333333", "khanh", "Tien Giang", 1); qlkh.themKhachHang(KH3);
	KhachHang* KH4 = new KhachHang("Trinh Tran Phuong A", 1997, "0844444444", "091244444444", "ttpA", "Ben Tre", 2); qlkh.themKhachHang(KH4);
	KhachHang* KH5 = new KhachHang("Le Thi B", 1990, "0845555555", "091255555555", "ltB", "Dong Nai", 1); qlkh.themKhachHang(KH5);
	KhachHang* KH6 = new KhachHang("Truong Van C", 1979, "0846666666", "091266666666", "tvC", "Ca Mau", 1); qlkh.themKhachHang(KH6);
	
    do {
        clearScreen();
        cout << "             ______________________________________________________________________ " << endl;
        cout << "            |                                                                      |" << endl;
        cout << "            |                      QUAN LI CUA HANG                                |" << endl;
        cout << "            |                                 CHO THUE XE                          |" << endl;
        cout << "            |______________________________________________________________________|" << endl;
        cout << "            |                                 |                                    |" << endl;
        cout << "            |      1.Nhap thong tin           |      6.Chon xe de tra              |" << endl;
        cout << "            |_________________________________|____________________________________|" << endl;
        cout << "            |                                 |                                    |" << endl;
        cout << "            |      2.Hien thi danh sach       |      7.Danh sach hop dong          |" << endl;
        cout << "            |_________________________________|____________________________________|" << endl;
        cout << "            |                                 |                                    |" << endl;
        cout << "            |      3.Cap nhat thong tin       |      8.Xem hoa don                 |" << endl;
        cout << "            |_________________________________|____________________________________|" << endl;
        cout << "            |                                 |                                    |" << endl;
        cout << "            |      4.Xoa thong tin            |      9.Tim kiem                    |" << endl;
        cout << "            |_________________________________|____________________________________|" << endl;
        cout << "            |                                 |                                    |" << endl;
        cout << "            |      5.Chon xe de thue          |      10.Thoat                      |" << endl;
        cout << "            |_________________________________|____________________________________|" << endl << endl;
        
        cout << "        -->Moi ban nhap lua chon: "; 
        cin >> choice;

        clearScreen();

        if (choice == 1) {
            PhuongTien* phuongTien;
            int choice1;

            do {
                cout << "           ______________________________________________________________"   << endl;
                cout << "          |                               |                              |"   << endl;
                cout << "          | 1- Nhap thong tin phuong tien | 2- Nhap thong tin khach hang | " << endl;
                cout << "          |_______________________________|______________________________|"   << endl << endl;
                cout << "-->Chon doi tuong nhap: ";
                cin >> choice1;
                
                if (choice1 == 1) {
                    int loaiPhuongTien;
                    do {
                        cout << "           ______________________________________________________________ " << endl;
                        cout << "          |               |               |                |             |" << endl;
                        cout << "          |   1- Xe may   |   2- Xe dap   |   3- Xe dien   |   4- O to   |" << endl;
                        cout << "          |_______________|_______________|________________|_____________|" << endl << endl;
                        cout << "-->Chon loai phuong tien: ";
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
                            cout << "-->Lua chon khong hop le!" << endl;
                        }
                    } while (loaiPhuongTien != 1 && loaiPhuongTien != 2 && loaiPhuongTien != 3 && loaiPhuongTien != 4);
                    phuongTien->nhapThongTin();
                    qlpt.themPhuongTien(phuongTien);
                } else if (choice1 == 2) {
                    KhachHang* khachHang = new KhachHang();
                    khachHang->nhapThongTin1();
                    qlkh.themKhachHang(khachHang);
                } else {
                    cout << "-->Lua chon khong hop le!" << endl;
                }
            } while(choice1 != 1 && choice1 != 2);
            cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 2) {
        	int choice2;
        	cout << "           ____________________________________________________ "<< endl;
            cout << "          |                          |                         |"<< endl;
            cout << "          | 1- Danh sach phuong tien | 2- Danh sach khach hang |"<< endl;
            cout << "          |__________________________|_________________________|"<< endl << endl;;
            do {
            	cout << "-->Nhap doi tuong can xem danh sach: "; cin >> choice2;
			} while(choice2 != 1 && choice2 != 2);
			clearScreen();
            if (choice2 == 1) {
            	qlpt.hienThiDanhSach();
			} else qlkh.hienThiDanhSach1();
			cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 3) {
            int choice3;
        	cout << "           ____________________________________________________ "<< endl;
            cout << "          |                          |                         |"<< endl;
            cout << "          |      1- Phuong tien      |      2- Khach hang      |"<< endl;
            cout << "          |__________________________|_________________________|"<< endl << endl;
            do {
            	cout << "-->Nhap doi tuong can chinh sua: "; 
				cin >> choice3;
            	cin.ignore();
			} while(choice3 != 1 && choice3 != 2);
			clearScreen();
			if (choice3 == 1) {
				int choice31;
				string id;
				qlpt.hienThiDanhSach();
				do {
                	cout << "\n-->Nhap ID phuong tien can chinh sua thong tin: "; 
					getline(cin, id);
				} while(!qlpt.tonTaiPhuongTien(id));
				clearScreen();
				qlpt.timKiemPhuongTien(id);
				cout << "           ____________________________________________________________ "<< endl;
            	cout << "          |            |                 |               |             |"<< endl;
            	cout << "          | 1- Hang xe | 2- Nam san xuat | 3- Tinh trang | 4- Gia thue |"<< endl;
            	cout << "          |____________|_________________|_______________|_____________|"<< endl;
				int thuocTinh;
				do {
                	cout << "\n-->Nhap thuoc tinh can chinh sua: "; cin >> thuocTinh;
				} while(thuocTinh < 1 && thuocTinh > 4);
				
				if (thuocTinh == 1) {
					string newBrand;
					cin.ignore();
					cout << "\n-->Nhap hang xe moi: ";
					getline(cin, newBrand);
					qlpt.capNhatHangXe(id, newBrand);
				} else if (thuocTinh == 2) {
					int newYear;
					time_t now = time(0);
    				tm *ltm = localtime(&now);
    				int namHienTai = 1900 + ltm->tm_year;
    				do {
           				cout << "\n-->Nhap nam san xuat moi: ";
           				cin >> newYear;
           				if (newYear > namHienTai) {
               				cout << "\n-->Vui long nhap nam nho hon hoac bang " << namHienTai << "!" << endl;
           				}
   					 } while (newYear > namHienTai);
					cin >> newYear;
					qlpt.capNhatNamSanXuat(id, newYear);
				} else if (thuocTinh == 3) {
					qlpt.thayDoiTinhTrangPhuongTien(id);
				} else {
					double newCost;
					cout << "\n-->Nhap gia thue moi: ";
					cin >> newCost;
					qlpt.capNhatGiaThue(id, newCost);
				}
			} else {
				qlkh.hienThiDanhSach1();
				string cccd;
				do {
					cout << "\n-->Nhap CCCD cua khach hang can chinh sua thong tin: ";
					getline(cin, cccd);
				} while(!qlkh.tonTaiKhachHang(cccd));
				cin.ignore();
				clearScreen();
				qlkh.timKiemKhachHang(cccd);
				cout << "           ________________________________________________________________ "<< endl;
            	cout << "          |                  |               |               |             |"<< endl;
            	cout << "          | 1- So dien thoai |    2- CCCD    |   3- Email    | 4- Bang lai |"<< endl;
            	cout << "          |__________________|_______________|_______________|_____________|"<< endl;
            	int thuocTinh;
            	do {
            		cout << "\n-->Nhap thuoc tinh can chinh sua: ";
            		cin >> thuocTinh;
				} while(thuocTinh < 1 && thuocTinh > 4);
				if (thuocTinh == 1) {
					cout << "\n-->Nhap so dien thoai moi: ";
					string newPhone;
					cin.ignore();
					getline(cin, newPhone);
					qlkh.capNhatSoDienThoai(cccd, newPhone);
				} else if (thuocTinh == 2) {
					cout << "\n-->Nhap CCCD moi: ";
					string newCCCD;
					cin.ignore();
					getline(cin, newCCCD);
					qlkh.capNhatCCCD(cccd, newCCCD);
				} else if (thuocTinh == 3) {
					cout << "\n-->Nhap Email moi: ";
					string newEmail;
					cin.ignore();
					getline(cin, newEmail);
					qlkh.capNhatCCCD(cccd, newEmail);
				} else {
					qlkh.chinhSuaBangLai(cccd);
				}
			}
			cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 4) {
        	cout << "           ____________________________________________________ "<< endl;
            cout << "          |                          |                         |"<< endl;
            cout << "          |      1- Phuong tien      |      2- Khach hang      |"<< endl;
            cout << "          |__________________________|_________________________|"<< endl << endl;
            int choice4;
            do {
            	cout << "\n-->Chon doi tuong de xoa: ";
            	cin >> choice4;
			} while(choice4 != 1 && choice4 != 2);
			clearScreen();
			if (choice4 == 1) {
				qlpt.hienThiDanhSach();
				string id;
				cout << "\n-->Nhap ID phuong tien can xoa: ";
				cin.ignore();
				getline(cin, id);
				qlpt.xoaPhuongTien(id);
			} else {
				qlkh.hienThiDanhSach1();
				string cccd;
				cout << "\n-->Nhap CCCD khach hang can xoa: ";
				cin.ignore();
				getline(cin, cccd);
				qlkh.xoaKhachHang(cccd);
			}
			cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 5) {
            HopDongThueXe* hopDong = new HopDongThueXe();
            hopDong->NhapHopDong(qlpt, qlkh);
            qlhd.themHopDong(hopDong);
            cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 6) {
        	qlhd.hienThiDanhSach2(); 
            string id4;
            cout << "\n-->Nhap ID hop dong cua phuong tien can tra: ";
            cin.ignore();
            getline(cin, id4);
            qlhd.xoaHopDong(id4, qlpt);
            cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 7) {
            cout << "                  =========DANH SACH HOP DONG===========" << endl;
            qlhd.hienThiDanhSach2();
            cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice == 8) {
        	string ID;
        	cin.ignore();
        	cout << "\n-->Nhap ma hoa don can xem: ";
        	getline(cin, ID);
        	cout << endl;
        	clearScreen();
        	qlhd.timKiemHopDong(ID);
        	cout << "\nNhan Enter de quay lai Menu!";
            
        } else if (choice == 9) {
        	int choice9;
            do {
            	cout << "           ______________________________________________________________"   << endl;
                cout << "          |                               |                              |"   << endl;
                cout << "          |    1- Tim kiem phuong tien    |    2- Tim kiem khach hang    | " << endl;
                cout << "          |_______________________________|______________________________|"   << endl << endl;
                cout << "-->Chon doi tuong tim kiem: ";
                cin >> choice9;
			} while(choice9 != 1 && choice9 != 2);
			if (choice9 == 1) {
				string ID;
				cout << "\n-->Nhap ID phuong tien can tim: ";
				cin.ignore();
				getline(cin, ID);
				clearScreen();
				qlpt.timKiemPhuongTien(ID);
			} else {
				string CCCD;
				cout << "\n-->Nhap CCCD khach hang can tim: ";
				cin.ignore();
				getline(cin, CCCD);
				clearScreen();
				qlkh.timKiemKhachHang(CCCD);
			}
			cout << "\nNhan Enter de quay lai Menu!";
        } else if (choice != 10) {
            cout << "-->Vui long nhap lai tu 1 den 10!" << endl;
        } else {
        	cout << "Dang thoat...";
		}
        cin.ignore();
        cin.get();
    } while (choice != 10);
    return 0;
}

