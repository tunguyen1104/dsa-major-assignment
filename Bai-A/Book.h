#pragma once
#include <bits/stdc++.h>
#include "StringManipulator.h"
using namespace std;
class Book : public StringManipulator
{
private:
    string MaSach;
    string TenSach;
    string TheLoai;
    string TacGia;
    int NamXuatBan;
    int amount;
    int quantity;

public:
    Book() {}
    Book(string Ma = "", string Ten = "", string Loai = "", string TG = "", int NXB = 0, int amount = 0, int quantity = 0)
    {
        MaSach = Ma;
        TenSach = Ten; // dùng standardization() ở đây không được nó bị lỗi
        TheLoai = Loai;
        TacGia = TG;
        NamXuatBan = NXB;
        this->amount = amount;
        this->quantity = quantity;
    }
    ~Book(){};
    void setMaSach(string Ma);

    void setTenSach(string Ten);

    void setTheLoai(string Loai);

    void setTacGia(string TG);
    
    void setNamXuatBan(int NXB);

    void setAmount(int amount);

    void setQuantity(int quantity);

    string getMaSach();

    string getTenSach();

    string getTheLoai();

    string getTacGia();

    int getNamXuatBan();

    int getAmount();

    int getQuantity();
};
void Book::setMaSach(string Ma){
        MaSach = Ma;
    }
    void Book::setTenSach(string Ten){
        TenSach = Ten;
    }

    void Book::setTheLoai(string Loai){
        TheLoai = Loai;
    }

    void Book::setTacGia(string TG){
        TacGia = TG;
    }
    
    void Book::setNamXuatBan(int NXB){
        this->NamXuatBan = NXB;
    }
    void Book::setAmount(int amount){
        this->amount = amount;
    }
    void Book::setQuantity(int quantity){
        this->quantity = quantity;
    }
    string Book::getMaSach(){
        return MaSach;
    }

    string Book::getTenSach(){
        return standardization(TenSach);
    }

    string Book::getTheLoai(){
        return standardization(TheLoai);
    }

    string Book::getTacGia(){
        return TacGia;
    }

    int Book::getNamXuatBan(){
        return NamXuatBan;
    }
    int Book::getAmount(){
        return amount;
    }
    int Book::getQuantity(){
        return quantity;
    }