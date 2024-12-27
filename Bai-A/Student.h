#pragma once
#include <bits/stdc++.h>
#include "StringManipulator.h"
using namespace std;
class Student : public StringManipulator
{
private:
    string MSV;
    string HoTen;
    string NganhHoc;
    string Khoa; // Khoá
    string date_of_birth;

public:
    Student() {}
    Student(string MSV = "", string HoTen = "", string NganhHoc = "", string Khoa = "", string date_of_birth = "")
    {
        this->MSV = MSV;
        this->HoTen = HoTen;
        this->NganhHoc = NganhHoc;
        this->Khoa = Khoa;
        this->date_of_birth = date_of_birth;
    }
    ~Student() {}
    void setDay(string date_of_birth)
    {
        this->date_of_birth = date_of_birth;
    }
    void setKhoa(string Khoa)
    {
        this->Khoa = Khoa;
    }
    void setMSV(string msv)
    {
        MSV = msv;
    }

    void setHoTen(string hoten)
    {
        HoTen = hoten;
    }

    void setNganhHoc(string nganhhoc)
    {
        NganhHoc = nganhhoc;
    }

    string getMSV()
    {
        return MSV;
    }

    string getHoTen()
    {
        return standardization(HoTen);
    }

    string getNganhHoc()
    {
        return NganhHoc;
    }
    string getKhoa()
    {
        return Khoa;
    }
    string getDate_of_Birth()
    {
        return convert_date(date_of_birth);
    }
};