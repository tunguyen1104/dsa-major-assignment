#pragma once
#include <bits/stdc++.h>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setNgay(int d)
    {
        this->day = d;
    }
    void setThang(int m)
    {
        this->month = m;
    }
    void setNam(int y)
    {
        this->year = y;
    }
    int getNgay()
    {
        return this->day;
    }
    int getThang()
    {
        return this->month;
    }
    int getNam()
    {
        return this->year;
    }
    void xuat()
    {
        cout << this->day << "/" << this->month << "/" << this->year;
    }
    ~Date(){};
};