#pragma once
#include <bits/stdc++.h>
#include "BookList.h"
#include "StudentList.h"
#include "BorrowPay_List.h"
using namespace std;
bool flagv2 = false; // check đã vào các mục menu con hay chưa, nếu vào rồi mà ra đây thì trước đó đã bấm Exit
class app {
private:
    List_Books _books;
    List_BorrowPay _borrowPay;
    List_students _students;

public:
    void menu1() {
        int chon;
        do
        {
            system("cls");
            cout << "======================= MENU 1 ==========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Them mot cuon sach.                        ==\n";
            cout << "==        2.Sua thong tin sach.                        ==\n";
            cout << "==        3.Xoa mot cuon sach.                         ==\n";
            cout << "==        4.Liet ke toan bo sach trong thu vien.       ==\n";
            cout << "==        5.Exit.                                      ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Them mot quyen sach\n";
                _books.ThemSach();
                break;
            case 2:
                cout << "[2] : Sua thong tin sach\n";
                _books.SuaSach();
                break;
            case 3:
                cout << "[3] : Xoa mot quyen sach\n";
                _books.XoaSach();
                break;
            case 4:
                cout << "[4] : Liet ke toan bo sach trong thu vien\n";
                cout << "\t\t\t\tLiet ke toan bo sach trong thu vien" << endl;
                _books.ToanBoSach();
                break;
            case 5:
                cout << "[5] : Exit\n";
                return;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 5)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 5);
    }
    void menu2() {
        int chon;
        do
        {
            system("cls");
            cout << "======================= MENU 2 ==========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Muon sach                                  ==\n";
            cout << "==        2.Tra sach                                   ==\n";
            cout << "==        3.Xuat danh sach phieu muon                  ==\n";
            cout << "==        4.Xuat danh sach phieu muon qua han          ==\n";
            cout << "==        5.Exit.                                      ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Muon sach\n";
                _borrowPay.MuonSach();
                break;
            case 2:
                cout << "[5] : Tra sach\n";
                _borrowPay.TraSach();
                break;
            case 3:
                cout << "[3] : Xuat danh sach phieu muon\n";
                _borrowPay.Export_a_list_of_borrowed_tickets();
                break;
            case 4:
                cout << "[4] : Xuat danh sach phieu muon qua han!\n";
                _borrowPay.in_phieu_muon_qua_han();
                break;
            case 5:
                cout << "[5] : Exit\n";
                return;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 5)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 5);
    }
    void menu3(){
        int chon;
        do
        {
            system("cls");
            cout << "======================= MENU 3 ==============================\n";
            cout << "==                                                         ==\n";
            cout << "==        1.Them mot ban doc vao thu vien.                 ==\n";
            cout << "==        2.Sua thong tin ban doc.                         ==\n";
            cout << "==        3.Xoa mot ban doc.                               ==\n";
            cout << "==        4.Liet ke toan bo sinh vien o trong thu vien.    ==\n";
            cout << "==        5.Exit.                                          ==\n";
            cout << "=============================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Them mot ban doc\n";
                _students.addStudent();
                break;
            case 2:
                cout << "[2] : Sua thong tin ban doc\n";
                _students.updateStudent();
                break;
            case 3:
                cout << "[3] : Xoa mot ban doc\n";
                _students.removeStudent();
                break;
            case 4:
                cout << "[4] : Liet ke toan bo sinh vien o trong thu vien\n";
                cout << "\t\t\t\tIn ra cac ban doc trong thu vien hien tai" << endl;
                _students.Export_a_list_of_student();
                break;
            case 5:
                cout << "[5] : Exit\n";
                return;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 5)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 5);
    }
    void menu4() {
        int chon;
        do
        {
            system("cls");
            cout << "========================== MENU 4 =============================\n";
            cout << "==                                                           ==\n";
            cout << "==        1.Sap xep sach theo gia tien tang dan.             ==\n";
            cout << "==        2.Sap xep sach theo name sach tang dan.            ==\n";
            cout << "==        3.Sap xep danh sach cac ban doc theo nganh.        ==\n";
            cout << "==        4.Sap xep cac ban doc theo thu tu alphabet.        ==\n";
            cout << "==        5.Exit.                                            ==\n";
            cout << "===============================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Sap xep sach theo thu tu tang dan gia tien\n";
                _books.arrange_book_amount();
                break;
            case 2:
                cout << "[2] : Sap xep sach theo thu tu tang dan ten sach\n";
                _books.arrange_book_name();
                break;
            case 3:
                cout << "[3] : Sap xep cac ban doc theo nganh\n";
                _students.arrange_student_majors();
                break;
            case 4:
                cout << "[4] : Sap xep cac ban doc theo thu tu alphabet tang dan theo ten + ho\n";
                _students.arrange_student_name();
                break;
            case 5:
                cout << "[5] : Exit\n";
                return;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 5)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 5);
    }
    void menu5() {
        int chon;
        do {
            system("cls");
            cout << "======================= MENU 5 ==========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Tim kiem sach theo ma sach                 ==\n";
            cout << "==        2.Tim kiem sach theo name                    ==\n";
            cout << "==        3.Tim kiem theo the loai sach                ==\n";
            cout << "==        4.Tim kiem cac ban doc theo ma sinh vien     ==\n";
            cout << "==        5.Tim kiem ban doc theo name                 ==\n";
            cout << "==        6.Tim kiem phieu muon theo ten sinh vien.    ==\n";
            cout << "==        7.Exit.                                      ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Tim kiem sach theo ma sach\n";
                // switch case nó không cho nhập ở đây
                _books.search_book_to_id();
                break;
            case 2:
                cout << "[2] : Tim kiem sach theo ma name\n";
                _books.search_book_to_name();
                break;
            case 3:
                cout << "[3] : Tim kiem sach theo the loai\n";
                _books.search_book_to_category();
                break;
            case 4:
                cout << "[4] : Tim kiem ban doc theo ma sinh vien\n";
                _students.search_student_to_id();
                break;
            case 5:
                cout << "[5] : Tim kiem ban doc theo name\n";
                _students.search_student_to_name();
                break;
            case 6:
                cout << "[6] : Tim kiem ten sinh vien da muon sach\n";
                _borrowPay.search_borrow_pay_namestudent();
                break;
            case 7:
                cout << "[7] : Exit\n";
                return;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 7)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 7);
    }
    void menu6()
    {
        int chon;
        do
        {
            system("cls");
            cout << "======================= MENU 6 ==========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Thong ke so sinh vien trong thu vien.      ==\n";
            cout << "==        2.Thong ke so dau sach trong thu vien.       ==\n";
            cout << "==        3.Thong ke so phieu muon.                    ==\n";
            cout << "==        4.Exit.                                      ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Thong ke so sinh vien trong thu vien\n";
                cout << "Hien dang co " << _students.get_size_vector() << " sinh vien trong thu vien\n";
                break;
            case 2:
                cout << "[2] : Thong ke so dau sach trong thu vien: ";
                cout << _books.get_size_vector_books() << endl;
                break;
            case 3:
                cout << "[3] : Thong ke so phieu muon : ";
                cout << _borrowPay.get_size_vector() << endl;
                break;
            case 4:
                cout << "[4] : Exit\n";
                return;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 4)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 4);
    }
    void menu_admin() {
    // lúc bắt đầu chương trình sẽ lấy all data từ file push vào vector
    // để đồng bộ vector vs file
        _books.readinputData_Booktxt();
        _borrowPay.inputData_BorrowPay();
        int chon;
        do
        {
            system("cls");
            flagv2 = false;
            cout << "\t     Chuong Trinh Quan Ly Thu Vien." << endl;
            cout << "====================== MENU ADMIN =======================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Quan ly sach.                              ==\n";
            cout << "==        2.Quan ly phieu muon sach.                   ==\n";
            cout << "==        3.Quan ly cac ban doc trong thu vien.        ==\n";
            cout << "==        4.Sap xep.                                   ==\n";
            cout << "==        5.Tim kiem.                                  ==\n";
            cout << "==        6.Thong ke.                                  ==\n";
            cout << "==        7.Exit.                                      ==\n";
            cout << "==                                                     ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                flagv2 = true;
                cout << "[1] : Quan ly sach\n";
                menu1();
                break;
            case 2:
                flagv2 = true;
                cout << "[2] : Quan ly phieu muon sach\n";
                menu2();
                break;
            case 3:
                flagv2 = true;
                cout << "[3] : Quan ly danh sach ban doc trong thu vien\n";
                menu3();
                break;
            case 4:
                flagv2 = true;
                cout << "[4] : Sap xep sach\n";
                menu4();
                break;
            case 5:
                flagv2 = true;
                cout << "[5] : Tim kiem sach\n";
                menu5();
                break;
            case 6:
                flagv2 = true;
                cout << "[6] : Thong ke\n";
                menu6();
                break;
            case 7:
                flagv2 = true;
                cout << "[7] : Exit\n";
                cout << "\n\t\tXin chao va hen gap lai !\n";
                break;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 7 && flagv2 == false)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 7);
    }
    void menu_user(string username, string password, string fullname) {
    // lúc bắt đầu chương trình sẽ lấy all data từ file push vào vector
    // để đồng bộ vector vs file
        _books.readinputData_Booktxt();
        _borrowPay.inputData_BorrowPay();
        int chon;
        do {
            system("cls");
            cout << "\t     Chuong Trinh Quan Ly Thu Vien." << endl;
            cout << "  Hello : " << fullname << endl;
            int cnt_phieuquanhan = _borrowPay.check_phieuquahan_motsinhvien(username);
            if (cnt_phieuquanhan)
                cout << "[Warning] : Ban co " << cnt_phieuquanhan << " quyen sach chua tra cho thu vien!\n";
            cout << "====================== MENU USER ========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.In toan bo sach co trong thu vien.         ==\n";
            cout << "==        2.Muon sach.                                 ==\n";
            cout << "==        3.Tra sach.                                  ==\n";
            cout << "==        4.In cac phieu muon sach cua ban.            ==\n";
            cout << "==        5.Tim kiem sach theo ten.                    ==\n";
            cout << "==        6.Tim kiem theo the loai sach ban muon doc.  ==\n";
            cout << "==        7.Sap xep sach theo tang dan gia tien.       ==\n";
            cout << "==        8.Dang xuat.                                 ==\n";
            cout << "==                                                     ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : In toan bo sach co trong thu vien\n";
                _books.ToanBoSach();
                break;
            case 2:
                cout << "[2] : Muon sach\n";
                _borrowPay.MuonSach();
                break;
            case 3:
                cout << "[3] : Tra sach\n";
                _borrowPay.TraSach();
                break;
            case 4:
                cout << "[4] : In cac phieu muon sach cua ban\n";
                _borrowPay.in_phieu_muon_motsinhvien(username);
                break;
            case 5:
                cout << "[5] : Tim kiem sach theo ten\n";
                _books.search_book_to_name();
                break;
            case 6:
                cout << "[6] : Tim kiem sach theo the loai ban muon doc\n";
                _books.search_book_to_category();
                break;
            case 7:
                cout << "[7] : Sap xep sach theo tang dan gia tien\n";
                _books.arrange_book_amount();
                break;
            case 8:
                cout << "[8] : Dang xuat\n";
                cout << "\n\t\tXin chao va hen gap lai !\n";
                break;
            default:
                cout << "\t\tNhap sai lua chon!\n";
                break;
            }
            if (chon != 8)
            {
                cout << endl;
                cout << "=========================" << endl;
                cout << "=> Nhan Enter de tro ve !";
                cin.ignore();
                cin.get();
            }
        } while (chon != 8);
    }
};