#pragma once
#include <bits/stdc++.h>
#include "StringManipulator.h"
#include "BorrowPay.h"
#include "BookList.h"
using namespace std;
#define endl "\n"
class List_BorrowPay : public List_Books{
    private:
        vector<BorrowPay> borrow_pay;
public:
    int get_size_vector() const{
        return borrow_pay.size();
    }
    void MuonSach()
    {
        // Quản lý theo mã sinh viên và mã sách
        cout << "\t\t[!] : Nhap N de thoat.\n\n";
        string nMS = ""; // mã sách
        int check;
        while (true)
        {
            cout << "- Nhap ma sach: ";
            cin >> nMS;
            if (nMS == "")
            {
                cout << "Khong duoc de trong. Nhap lai!\n";
                continue;
            }
            else if (nMS == "N" || nMS == "n")
            {
                cout << "=========================\n";
                cout << "Ban chon thoat !\n";
                return;
            }
            check = kiem_tra_sach_du_tieu_chuan_muon(nMS);
            if (check == 1)
            {
                break;
            }
            else if (check == 2)
            {
                cout << "\t\tSach hien dang co ban doc khac muon.\n";
                continue;
            }
            else
            {
                cout << "\t\tMa sach khong ton tai!.\n";
                continue;
            }
        }
        
        List_Books::get_data_1_book(nMS);
        string nMSV = "";
        while (true)
        {
            cout << "- Nhap ma ban doc can muon sach: ";
            cin >> nMSV;
            if (nMSV == "")
            {
                cout << "Khong duoc de trong ! \n";
                continue;
            }
            else if (nMSV == "N" || nMSV == "n")
            {
                cout << "=========================\n";
                cout << "Ban chon thoat !\n";
                return;
            }
            else
            {
                break;
            }
        }
        cin.ignore();
        string name_students_borrow_pay = "";
        while (true)
        {
            cout << "- Nhap ten ban doc muon sach: ";
            getline(cin, name_students_borrow_pay);
            if (name_students_borrow_pay == "")
            {
                cout << "Khong duoc de trong ! \n";
                continue;
            }
            else if (name_students_borrow_pay == "N")
            {
                cout << "=========================\n";
                cout << "Ban chon thoat !\n";
                return;
            }
            else
            {
                break;
            }
        }
        BorrowPay pm(0, nMSV, nMS, standardization(name_students_borrow_pay));
        borrow_pay.push_back(pm);
        cout << "________________________________________\n";
        cout << "Yeu cau cua ban dang duoc thuc hien..." << endl;
        cout << "   MSV: " << nMSV << endl;
        cout << "   Ho ten: " << standardization(name_students_borrow_pay) << endl;
        cout << "   Ma sach: " << nMS << endl;
        cout << "   Thoi gian: " << get_time() << endl;
        cout << "   Ngay: " << get_day() << endl;
        cout << "   Tao phieu muon thanh cong!\n";
        cout << "________________________________________\n";
        ofstream File;
        File.open("BorrowPay.txt", ios::app);
        int i = borrow_pay.size() - 1;
        if (i == 0)
        {
            File
                << borrow_pay[i].getMSV() << "," << borrow_pay[i].getMaSach() << "," << borrow_pay[i].getHoTen() << "," << borrow_pay[i].xNgayMuon.getNgay() << ","
                << borrow_pay[i].xNgayMuon.getThang() << "," << borrow_pay[i].xNgayMuon.getNam() << "," << borrow_pay[i].xNgayTra.getNgay() << ","
                << borrow_pay[i].xNgayTra.getThang() << "," << borrow_pay[i].xNgayTra.getNam();
        }
        else
            File << "\n"
                 << borrow_pay[i].getMSV() << "," << borrow_pay[i].getMaSach() << "," << borrow_pay[i].getHoTen() << "," << borrow_pay[i].xNgayMuon.getNgay() << ","
                 << borrow_pay[i].xNgayMuon.getThang() << "," << borrow_pay[i].xNgayMuon.getNam() << "," << borrow_pay[i].xNgayTra.getNgay() << ","
                 << borrow_pay[i].xNgayTra.getThang() << "," << borrow_pay[i].xNgayTra.getNam();
        File.close();
        
        List_Books::set_quantity_1_book(nMS,0);
        List_Books::outputData_Book_File();
    }
    
    void outputData_BorrowPay_File()
    {
        ofstream File;
        File.open("./file_txt/BorrowPay.txt");
        int cnt = 0;
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            File
                << borrow_pay[i].getMSV() << "," << borrow_pay[i].getMaSach() << "," << borrow_pay[i].getHoTen() << "," << borrow_pay[i].xNgayMuon.getNgay() << ","
                << borrow_pay[i].xNgayMuon.getThang() << "," << borrow_pay[i].xNgayMuon.getNam() << "," << borrow_pay[i].xNgayTra.getNgay() << "," << borrow_pay[i].xNgayTra.getThang() << ","
                << borrow_pay[i].xNgayTra.getNam();
            if (cnt < borrow_pay.size() - 1)
            {
                File << endl;
                cnt++;
            }
        }
        File.close();
    }
    void inputData_BorrowPay(){
        borrow_pay.clear();
        string MSV = "";
        string MS = "";
        string name_students_borrow_pay = "";
        int nNgayMuon = 0;
        int nThangMuon = 0;
        int nNamMuon = 0;
        int nNgayTra = 0;
        int nThangTra = 0;
        int nNamTra = 0;
        ifstream File("./file_txt/BorrowPay.txt");
        if (!File.is_open())
            return;
        while (!File.eof())
        {
            getline(File, MSV, ',');
            getline(File, MS, ',');
            getline(File, name_students_borrow_pay, ',');
            File >> nNgayMuon;
            File.ignore(1, ',');
            File >> nThangMuon;
            File.ignore(1, ',');
            File >> nNamMuon;
            File.ignore(1, ',');
            File >> nNgayTra;
            File.ignore(1, ',');
            File >> nThangTra;
            File.ignore(1, ',');
            File >> nNamTra;
            File.ignore(1, '\n');
            BorrowPay pm(MSV, MS, standardization(name_students_borrow_pay), nNgayMuon, nThangMuon, nNamMuon, nNgayTra, nThangTra, nNamTra);
            borrow_pay.push_back(pm);
        }
        File.close();
    }
    void Export_a_list_of_borrowed_tickets(){
        cout << "\t\t\t\tPhieu muon sach thu vien" << endl;
        cout << endl;
        cout << center("STT", 5) << " | "
             << center("Ho Ten", 25) << " | "
             << center("Ma sinh vien", 25) << " | "
             << center("Ma sach", 15) << " | "
             << center("Ngay muon", 14) << " | "
             << center("Ngay tra", 12) << "\n";
        cout << string(5 + 15 + 25 * 2 + 14 + 12 + 5 * 3, '_') << "\n";
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            cout << centerv2(i + 1, 5) << " | "
                 << center(borrow_pay[i].getHoTen(), 25) << " | "
                 << center(borrow_pay[i].getMSV(), 25) << " | "
                 << center(borrow_pay[i].getMaSach(), 15) << " | "
                 << center(convert_datev2(borrow_pay[i].xNgayMuon.getNgay(), borrow_pay[i].xNgayMuon.getThang(), borrow_pay[i].xNgayMuon.getNam()), 14) << " | "
                 << center(convert_datev2(borrow_pay[i].xNgayTra.getNgay(), borrow_pay[i].xNgayTra.getThang(), borrow_pay[i].xNgayTra.getNam()), 12) << "\n";
            if (i < borrow_pay.size() - 1)
                cout << string(5 + 15 + 25 * 2 + 14 + 12 + 5 * 3, '_') << "\n";
        }
    }
    void TraSach(){
        cin.ignore();
        cout << "\t\tTra sach" << endl;
        cout << "[!] : Nhap N de thoat.\n\n";
        string msv, ms;
        int check = -1;
    xmsv:
        cout << "- Nhap ma sinh vien: ";
        getline(cin, msv);
        if (msv == "N" || msv == "n")
        {
            cout << "\n===========================\n";
            cout << "\t\tBan chon thoat!\n";
            return;
        }
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (check == -1 && borrow_pay[i].getMSV() == msv)
            {
                check = i;
                cout << center("STT", 5) << " | "
                     << center("Ho Ten", 25) << " | "
                     << center("Ma sinh vien", 25) << " | "
                     << center("Ma sach", 15) << " | "
                     << center("Ngay muon", 14) << " | "
                     << center("Ngay tra", 12) << "\n";
            }
            if (borrow_pay[i].getMSV() == msv)
                xuat_thongtin_1_phieu_muon(i);
        }
        if (check != -1)
            goto xms;
        cout << "- Khong co ma sinh vien nao nhu vay da muon sach!\nNhap lai:\n";
        goto xmsv;
    xms:
        cout << "- Nhap ma sach muon tra: ";
        cin >> ms;
        if (ms == "N" || ms == "n")
        {
            cout << "\n===========================\n";
            cout << "\t\tBan chon thoat!\n";
            return;
        }
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].getMSV() == msv && borrow_pay[i].getMaSach() == ms)
            {   
                borrow_pay.erase(borrow_pay.begin() + i);
                cout << "\tTra sach thanh cong!\n";
                goto done;
            }
        }
        cout << "- Nhap sai ma sach duoc muon!\nNhap lai:\n";
        goto xms;
    done:
        
        List_Books::set_quantity_1_book(ms,1);
        outputData_BorrowPay_File();
        List_Books::outputData_Book_File();
    }
    void xuat_thongtin_1_phieu_muon(int i){
        cout << string(5 + 15 + 25 * 2 + 14 + 12 + 5 * 3, '_') << "\n";
        cout << centerv2(i + 1, 5) << " | "
             << center(borrow_pay[i].getHoTen(), 25) << " | "
             << center(borrow_pay[i].getMSV(), 25) << " | "
             << center(borrow_pay[i].getMaSach(), 15) << " | "
             << center(convert_datev2(borrow_pay[i].xNgayMuon.getNgay(), borrow_pay[i].xNgayMuon.getThang(), borrow_pay[i].xNgayMuon.getNam()), 14) << " | "
             << center(convert_datev2(borrow_pay[i].xNgayTra.getNgay(), borrow_pay[i].xNgayTra.getThang(), borrow_pay[i].xNgayTra.getNam()), 12) << "\n";
    }
    void search_borrow_pay_namestudent()
    {
        string name;
        cout << "- Nhap ten ban doc: ";
        cin.ignore();
        getline(cin, name);
        bool found = false;
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (found == false && borrow_pay[i].getHoTen() == standardization(name))
            {
                cout << "[!] : Da tim thay phieu muon cua ban doc " << name << " !\n\n";
                cout << center("STT", 5) << " | "
                     << center("Ho Ten", 25) << " | "
                     << center("Ma sinh vien", 25) << " | "
                     << center("Ma sach", 15) << " | "
                     << center("Ngay muon", 14) << " | "
                     << center("Ngay tra", 12) << "\n";
                xuat_thongtin_1_phieu_muon( i);
                found = true;
            }
            else if (found && borrow_pay[i].getHoTen() == standardization(name))
            {
                xuat_thongtin_1_phieu_muon( i);
            }
        }
        if (!found)
            cout << "\n[!] : Khong ton tai phieu muon co ten ban doc " << name << " !\n\n";
    }

    void in_phieu_muon_qua_han()
    {
        BorrowPay current_day(0, "test", "test");
        int day = current_day.xNgayMuon.getNgay();
        int month = current_day.xNgayMuon.getThang();
        int year = current_day.xNgayMuon.getNam();
        cout << center("STT", 5) << " | "
             << center("Ho Ten", 25) << " | "
             << center("Ma sinh vien", 25) << " | "
             << center("Ma sach", 15) << " | "
             << center("Ngay muon", 14) << " | "
             << center("Ngay tra", 12) << "\n";
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].xNgayTra.getNam() > year || (borrow_pay[i].xNgayTra.getNam() == year && (borrow_pay[i].xNgayTra.getThang() > month ||
                                                                                                       (borrow_pay[i].xNgayTra.getThang() == month &&
                                                                                                        borrow_pay[i].xNgayTra.getNgay() > day))))
            {
                continue;
            }
            else
                xuat_thongtin_1_phieu_muon(i);
        }
    }
    void in_phieu_muon_motsinhvien(string username)
    {   
        bool found = false;
        cout << center("STT", 5) << " | "
             << center("Ho Ten", 25) << " | "
             << center("Ma sinh vien", 25) << " | "
             << center("Ma sach", 15) << " | "
             << center("Ngay muon", 14) << " | "
             << center("Ngay tra", 12) << "\n";
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].getMSV() == username)
            {
                xuat_thongtin_1_phieu_muon(i);
                found = true;
            }
        }
        if(!found) cout << "\t\tBan chua muon quyen sach nao!\n";
    }
    int check_phieuquahan_motsinhvien(const string &username){
        BorrowPay current_day(0, "test", "test");
        int day = current_day.xNgayMuon.getNgay();
        int month = current_day.xNgayMuon.getThang();
        int year = current_day.xNgayMuon.getNam();
        int cnt = 0;
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].getMSV() == username)
            {   
                if (borrow_pay[i].xNgayTra.getNam() > year || (borrow_pay[i].xNgayTra.getNam() == year && (borrow_pay[i].xNgayTra.getThang() > month ||
                                                                                                       (borrow_pay[i].xNgayTra.getThang() == month &&
                                                                                                        borrow_pay[i].xNgayTra.getNgay() > day))))
            {
                continue;
            }
                else ++cnt;
            }
        }
        return cnt;
    }
};