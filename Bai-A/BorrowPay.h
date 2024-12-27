#pragma once
#include <bits/stdc++.h>
#include "Date.h"
#include "Student.h"
#include "Book.h"
using namespace std;
class BorrowPay : public Student, public Book, public Date
{
public:
    Date xNgayMuon, xNgayTra;
    // Các hàm xử lí chuẩn ngày
    int nNgayPlus(int nN);
    int nThangPlus(int nN);
    int nNamPlus(int nN);
    bool ktrNamNhuan();

    // constructor này dùng để đọc file BorrowPay.txt,nếu dùng constructor bên dưới thì day month year trong file sẽ bị đổi thành thời gian thực

    BorrowPay(string MSV = "", string MS = "", string name_students_borrow_pay = "", int a = 0, int b = 0,
              int c = 0, int d = 0, int e = 0, int f = 0) : Student(MSV, name_students_borrow_pay), Book(MS), xNgayMuon(a, b, c), xNgayTra(d, e, f)
    {
    }

    BorrowPay(int cnt = 0, string MSV = "", string MS = "", string name_students_borrow_pay = "") : Student(MSV, name_students_borrow_pay), Book(MS)
    {
        time_t t = time(0);
        struct tm *Now = localtime(&t);
        xNgayMuon.setNgay(Now->tm_mday);
        xNgayMuon.setThang(Now->tm_mon + 1);
        xNgayMuon.setNam(Now->tm_year + 1900);

        xNgayTra.setNgay(nNgayPlus(7));
        xNgayTra.setThang(nThangPlus(7));
        xNgayTra.setNam(nNamPlus(7));
    }

    ~BorrowPay(){};
};
int BorrowPay::nNgayPlus(int nN)
{
    time_t t = time(0);
    struct tm *ta = localtime(&t);
    ta->tm_mon += 1;
    ta->tm_year += 1900;

    int nTongNgay = ta->tm_mday + nN;
    if (ta->tm_mon == 1 || ta->tm_mon == 3 || ta->tm_mon == 5 || ta->tm_mon == 7 || ta->tm_mon == 8 || ta->tm_mon == 10 || ta->tm_mon == 12)
    {
        if (nTongNgay > 31)
        {
            nTongNgay -= 31;
        }
    }
    else if (ta->tm_mon == 2)
    {
        int maxDays = (ktrNamNhuan()) ? 29 : 28;
        if (nTongNgay > maxDays)
        {
            nTongNgay -= maxDays;
        }
    }
    else
    {
        if (nTongNgay > 30)
        {
            nTongNgay -= 30;
        }
    }
    return nTongNgay;
}

int BorrowPay::nThangPlus(int nN)
{
    time_t t = time(0);
    struct tm *ta = localtime(&t);
    ta->tm_mon += 1;
    ta->tm_year += 1900;

    int nTongNgay = ta->tm_mday + nN;
    if (ta->tm_mon == 1 || ta->tm_mon == 3 || ta->tm_mon == 5 || ta->tm_mon == 7 || ta->tm_mon == 8 || ta->tm_mon == 10)
    {
        if (nTongNgay > 31)
        {
            ta->tm_mon += 1;
        }
    }
    else if (ta->tm_mon == 12)
    {
        if (nTongNgay > 31)
        {
            ta->tm_mon = 1;
        }
    }
    else if (ta->tm_mon == 2)
    {
        int maxDays = (ktrNamNhuan()) ? 29 : 28;
        if (nTongNgay > maxDays)
        {
            ta->tm_mon += 1;
        }
    }
    else
    {
        if (nTongNgay > 30)
        {
            ta->tm_mon += 1;
        }
    }
    return ta->tm_mon;
}

int BorrowPay::nNamPlus(int nN)
{
    time_t t = time(0);
    struct tm *ta = localtime(&t);
    ta->tm_mon = ta->tm_mon + 1;
    ta->tm_year = ta->tm_year + 1900;
    int nTongNgay = ta->tm_mday + nN;
    if (ta->tm_mon == 12 && nTongNgay > 31)
    {
        ta->tm_year += 1;
    }
    return ta->tm_year;
}
bool BorrowPay::ktrNamNhuan()
{
    time_t t = time(0);
    struct tm *ta = localtime(&t);
    ta->tm_year = ta->tm_year + 1900;
    if (ta->tm_year % 400 == 0 || ta->tm_year % 4 == 0 && ta->tm_year % 100 != 0)
        return true;
    else
        return false;
}