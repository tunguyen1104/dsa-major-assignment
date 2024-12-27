#pragma once
#include <bits/stdc++.h>
#include "StringManipulator.h"
#include "Student.h"

using namespace std;
#define endl "\n"
class List_students : public StringManipulator{
    private:
        vector<Student> students;
public:
int get_size_vector(){
    return students.size();
}
    void addStudent()
    {
        cout << "\t\tNhap them mot ban doc" << endl;
        cout << endl;
        string MSV, Ten, NganhHoc;
        string Khoa;
        string date_of_birth;
        cin.ignore();
    msv:
        cout << "- Nhap ma sinh vien: ";
        getline(cin, MSV);
        if (MSV == "")
        {
            cout << "\t\t\tKhong duoc de trong. Nhap lai!\n";
            goto msv;
        }
        for (int i = 0; i < students.size(); ++i)
        {

            if (MSV == students[i].getMSV())
            {
                goto ten;
            }
        }
    ten:
        cout << "- Nhap ten sinh vien: ";
        getline(cin, Ten);
        if (Ten == "")
        {
            cout << "\t\t\tKhong duoc de trong. Nhap lai!\n";
            goto ten;
        }
    nh:
        cout << "- Nhap nganh hoc: ";
        getline(cin, NganhHoc);
        if (NganhHoc == "")
        {
            cout << "\t\t\tKhong duoc de trong. Nhap lai!\n";
            goto nh;
        }
    khoav2:
        cout << "- Nhap khoa hoc: ";
        cin >> Khoa;
        if (Khoa == "")
        {
            cout << "\t\t\tKhong duoc de trong. Nhap lai!\n";
            goto khoav2;
        }
        cout << "- Nhap ngay thang nam sinh theo dinh dang dd/mm/yyyy: ";
        cin >> date_of_birth;
        Student New(MSV, standardization(Ten), NganhHoc, Khoa, convert_date(date_of_birth));
        students.push_back(New);
        cout << "\t\tThem ban doc thanh cong !\n";
    }
    void removeStudent()
    {
        string MSV;
        cout << "- Nhap ma sinh vien can xoa: ";
        cin >> MSV;
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getMSV() == MSV)
            {
                students.erase(students.begin() + i);
                cout << "Da xoa sach co ma: " << MSV << endl;
                return;
            }
        }
        cout << "\t\tKhong tim thay ma sinh vien: " << MSV << endl;
    }
    void updateStudent()
    {
        // Tìm và sửa theo mã sách
        cout << "\t\tSua thong tin Ban doc" << endl;
        cout << endl;
        string MSV, Ten, NganhHoc, Khoa;
        string date_of_birth;
        cout << "Nhap ma sinh vien can sua: ";
        cin.ignore();
        cin >> MSV;
        cin.ignore();
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getMSV() == MSV)
            {
                xuat_thongtin_1student(i);
                cout << "______________________________" << endl;
            ms:
                cout << "- Nhap ma sinh vien moi: ";
                getline(cin, MSV);
                if (MSV == "")
                {
                    cout << "\t\t\tKhong duoc de trong !\n";
                    goto ms;
                }
            ten:
                cout << "- Nhap ten sinh vien moi: ";
                getline(cin, Ten);
                if (Ten == "")
                {
                    cout << "\t\t\tKhong duoc de trong !\n";
                    goto ten;
                }
            nh:
                cout << "- Nhap nganh hoc moi: ";
                getline(cin, NganhHoc);
                if (NganhHoc == "")
                {
                    cout << "\t\t\tKhong duoc de trong !\n";
                    goto nh;
                }
            khoav2:
                cout << "- Nhap Khoa hoc moi: ";
                cin >> Khoa;
                if (Khoa == "")
                {
                    cout << "Khong duoc de trong. Nhap lai !\n";
                    goto khoav2;
                }
                cout << "- Nhap ngay sinh moi: ";
                cin >> date_of_birth;
                Student change(MSV, standardization(Ten), NganhHoc, Khoa, convert_date(date_of_birth));
                students[i] = change;
                return;
            }
        }
        cout << "- Khong ton tai ma sinh vien can sua !\n";
    }
    void Export_a_list_of_student() {
        cout << endl;
        cout << center("STT", 5) << " | "
             << center("Ma sinh vien", 15) << " | "
             << center("Ho Ten", 25) << " | "
             << center("Nganh Hoc", 15) << " | "
             << center("Khoa", 10) << " | "
             << center("Ngay sinh", 12) << "\n";
        cout << string(5 + 15 * 2 + 25 + 10 + 12 + 5 * 3, '_') << "\n";
        if (students.size() == 0){
            cout << "\t\tHien khong co ban doc nao trong thu vien!\n";
            return;
        }
        for (int i = 0; i < students.size(); ++i){
            cout << centerv2(i + 1, 5) << " | "
                 << center(students[i].getMSV(), 15) << " | "
                 << center(students[i].getHoTen(), 25) << " | "
                 << center(students[i].getNganhHoc(), 15) << " | "
                 << center(students[i].getKhoa(), 10) << " | "
                 << center(students[i].getDate_of_Birth(), 11) << "\n";
            if (i < students.size() - 1)
                cout << string(5 + 15 * 2 + 25 + 10 + 12 + 5 * 3, '_') << "\n";
        }
    }
    void xuat_thongtin_1student(int i){
        cout << center("STT", 5) << " | "
             << center("Ma sinh vien", 15) << " | "
             << center("Ho Ten", 25) << " | "
             << center("Nganh Hoc", 15) << " | "
             << center("Khoa", 10) << " | "
             << center("Ngay sinh", 15) << "\n";
        cout << string(5 + 15 * 3 + 25 + 10 + 5 * 3, '_') << "\n";
        cout << centerv2(i + 1, 5) << " | "
             << center(students[i].getMSV(), 15) << " | "
             << center(students[i].getHoTen(), 25) << " | "
             << center(students[i].getNganhHoc(), 15) << " | "
             << center(students[i].getKhoa(), 10) << " | "
             << center(students[i].getDate_of_Birth(), 15) << "\n";
    }
    static bool cmp_student_to_name(Student &a, Student &b)
    {
        return a.convertv2(a.getHoTen()) < b.convertv2(b.getHoTen());
    }
    void arrange_student_name()
    {
        sort(students.begin(), students.end(), cmp_student_to_name);
        cout << "\nDone! Da sap xep name ban doc theo thu tu alphabet\n";
        Export_a_list_of_student();
    }
    static bool cmp_student_to_majors(Student &a, Student &b)
    {
        return a.getNganhHoc() < b.getNganhHoc();
    }
    void arrange_student_majors()
    {
        sort(students.begin(), students.end(), cmp_student_to_majors);
        cout << "\nDone! Da sap xep cac ban doc theo nganh\n";
        Export_a_list_of_student();
    }
    void search_student_to_id() {
        string id;
        cout << "- Nhap ma sinh vien ban doc ban can tim: ";
        cin >> id;
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getMSV() == id)
            {
                cout << "\t\t\t[!] : Da tim thay ban doc co id " << id << "\n\n";
                xuat_thongtin_1student( i);
                return;
            }
            cout << "\n[!] : Khong tim thay ban doc co id = " << id << "\n";
        }
    }
    void search_student_to_name() {
        string name;
        cout << "- Nhap ten sinh vien ban doc ban can tim: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getHoTen() == standardization(name))
            {
                cout << "\t\t\t[!] : Da tim thay ban doc co name " << name << "\n\n";
                xuat_thongtin_1student(i);
                return;
            }
        }
        cout << "\n[!] : Khong ton tai ban doc co name " << name << " trong thu vien\n";
    }
};