#pragma once
#include <bits/stdc++.h>
#include "StringManipulator.h"
#include "Book.h"

using namespace std;
#define endl "\n"
class List_Books : public StringManipulator{
private:
    vector<Book> books;
public:
    int get_size_vector_books(){
        return books.size();
    }
    int kiem_tra_sach_du_tieu_chuan_muon(const string &MS)
    {
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == MS)
            {
                if (books[i].getQuantity() > 0)
                    return 1;
                else
                    return 2;
            }
        }
        return 0;
    }
    void set_quantity_1_book(const string& nMS,int check){
        // Sửa quantity của quyển sách vừa mượn
        if(check == 1)
            for (int i = 0; i < books.size(); ++i)
            {
                if (books[i].getMaSach() == nMS)
                {
                    books[i].setQuantity(books[i].getQuantity() + 1);
                }
            }
        else {
            for (int i = 0; i < books.size(); ++i)
            {
                if (books[i].getMaSach() == nMS)
                {
                    books[i].setQuantity(books[i].getQuantity() - 1);
                }
            }
        }
    }
    void get_data_1_book(const string& nMS){
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == nMS)
            {
                cout << "\t\t" << nMS << " : " << books[i].getTenSach() << " | quantity : " << books[i].getQuantity() << endl;
            }
        }
    }
    void ThemSach()
    {
        int chon, index = 0;
        cout << "\t\tNhap them mot cuon sach" << endl;
        cout << "1.Them vao dau." << endl;
        cout << "2.Them vao giua." << endl;
        cout << "3.Them vao cuoi" << endl;
        cout << "_____________________________" << endl;

        do
        {
            cout << "Ban chon chuc nang: ";
            cin >> chon;
            if (chon < 1 || chon > 3)
                cout << "\tKhong co chuc nang nay, moi ban nhap lai!" << endl;
        } while (chon < 1 || chon > 3);

        if (chon == 2)
        {
            do
            {
                cout << "Nhap vi tri ban muon them vao: ";
                cin >> index;
                if (index < 0 || index > books.size())
                cout << "\tKhong ton tai vi tri day, moi ban nhap lai!" << endl;
            } while (index < 0 || index > books.size());
        }
        cout << endl;
        string MS, Ten, Loai, TG;
        int NXB;
        int amount;
        int quantity;
        cin.ignore();
    ms:
        cout << "- Nhap ma sach: ";
        getline(cin, MS);
        if (MS.size() == 0)
        {
            cout << "\t\t\tKhong duoc de trong !\n";
            goto ms;
        }
        else
        {
            for (int i = 0; i < books.size(); ++i)
            {

                if (MS == books[i].getMaSach())
                {
                    int cnt = books[i].getQuantity();
                    books[i].setQuantity(cnt + 1);
                    cout << "\t Da tang so luong san pham " << books[i].getTenSach() << "!\n";
                    return;
                }
            }
        }
    ten:
        cout << "- Nhap ten sach: ";
        getline(cin, Ten);
        if (Ten == "")
        {
            cout << "\t\t\tKhong duoc de trong !\n";
            goto ten;
        }
        else
        {
            for (int i = 0; i < books.size(); ++i)
            {
                if (books[i].getTenSach() == Ten)
                {
                    cout << "\nDa ton tai ten quyen sach nay trong thu vien!\n";
                    cout << "=========================\n";
                    cout << "- Nhan Enter de nhap lai: ";
                    cin.ignore();
                    cin.get();
                    goto ten;
                }
            }
        }
    tl:
        cout << "- Nhap The Loai: ";
        getline(cin, Loai);
        if (Loai == "")
        {
            cout << "\t\t\tKhong duoc de trong !\n";
            goto tl;
        }
    tg:
        cout << "- Nhap ten tac gia: ";
        getline(cin, TG);
        if (TG == "")
        {
            cout << "\t\t\tKhong duoc de trong !\n";
            goto tg;
        }
        cout << "- Nhap nam xuat ban: ";
        cin >> NXB;
        cout << "- Nhap gia cuon sach: ";
        cin >> amount;
        cout << "- Nhap so luong cuon sach them vao: ";
        cin >> quantity;
        Book New(MS, Ten, Loai, TG, NXB, amount, quantity);
        if (chon == 3)
            books.push_back(New);
        else if (chon == 2)
        {
            auto it = books.begin() + index - 1;
            books.insert(it, New);
        }
        else if (chon == 1)
        {
            auto it = books.begin();
            books.insert(it, New);
        }
        outputData_Book_File();
        cout << "\t\tThem sach thanh cong !\n";
    }

    void SuaSach()
    {
        // Tìm và sửa theo mã sách
        cout << "\t\tSua thong tin sach" << endl;
        cout << endl;
        string Find;
        string MS, Ten, Loai, TG;
        int NXB;
        int amount;
        int quantity;
        cout << "Nhap ma sach can sua: ";
        bool check_find_sach = false;
        cin.ignore();
        getline(cin, Find);
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == Find)
            {
                check_find_sach = true;
                xuat_thongtin_1quyen(i);
                cout << "________________________________________________" << endl;
            ms:
                cout << "- Nhap ma sach moi: ";
                getline(cin, MS);
                if (MS == "")
                {
                    cout << "\t\t\tKhong duoc de trong !\n";
                    goto ms;
                }
                for (int i = 0; i < books.size(); ++i)
                {

                    if (MS == books[i].getMaSach())
                    {   cout << "\nBan muon so luong quyen sach nay trong thu vien!\n";
                        int cnt = books[i].getQuantity();
                        books[i].setQuantity(cnt + 1);
                        cout << "\t Da tang so luong san pham " << books[i].getTenSach() << "!\n";
                        return;
                    }
                }
            ten:
                cout << "- Nhap ten sach moi: ";
                getline(cin, Ten);
                if (Ten == "")
                {
                    cout << "\t\t\tKhong duoc de trong !\n";
                    goto ten;
                }
                else
                {
                    for (int i = 0; i < books.size(); ++i)
                    {
                        if (books[i].getTenSach() == Ten)
                        {
                            cout << "\nDa ton tai ten quyen sach nay trong thu vien!\n";
                            cout << "=========================\n";
                            cout << "- Nhan Enter de nhap lai: ";
                            cin.ignore();
                            cin.get();
                            goto ten;
                        }
                    }
                }
            tl:
            cout << "- Nhap The Loai: ";
            getline(cin, Loai);
            if (Loai == "")
            {
                cout << "\t\t\tKhong duoc de trong !\n";
                goto tl;
            }
            tg:
                cout << "- Nhap ten tac gia moi: ";
                getline(cin, TG);
                if (TG == "")
                {
                    cout << "\t\t\tKhong duoc de trong !\n";
                    goto tg;
                }
                cout << "- Nhap nam xuat ban moi: ";
                cin >> NXB;
                cout << "- Nhap gia cuon sach moi: ";
                cin >> amount;
                cout << "- Nhap so luong cuon sach moi: ";
                cin >> quantity;
                Book change(MS, standardization(Ten), standardization(Loai), TG, NXB, amount, quantity);
                books[i] = change;
                cout << "\t\tDa sua thanh cong!\n";
                break;
            }
        }
        if (!check_find_sach)
            cout << "- Khong ton tai ma sach can sua !\n";
        else
            outputData_Book_File();
    }

    void XoaSach()
    {
        string Find;
        cout << "- Nhap ma sach can xoa: ";
        cin >> Find;

        bool found = false;

        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == Find)
            {
                // Kiểm tra xem cuốn sách đang được mượn hay không

                if (books[i].getQuantity())
                {
                    books.erase(books.begin() + i);
                    cout << "Da xoa sach co ma: " << Find << endl;
                }
                else
                {
                    cout << "Khong the xoa cuon sach nay vi dang co sinh vien muon!" << endl;
                }

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Khong tim thay cuon sach co ma: " << Find << endl;
        }
        else
            outputData_Book_File();
    }
    void outputData_Book_File(){
        // lấy data từ books ghi mới vào Sach.txt
        ofstream File;
        File.open("./file_txt/Book.txt");
        int cnt = 0;
        for (int i = 0; i < books.size(); ++i)
        {
            File << books[i].getMaSach() << "," << books[i].getTenSach()
                 << "," << books[i].getTheLoai() << "," << books[i].getTacGia() << "," << books[i].getNamXuatBan() << ","
                  << books[i].getAmount() << "," << books[i].getQuantity();
            if (cnt < books.size() - 1)
            {
                File << endl;
                cnt++;
            }
        }
        File.close();
    }
    void readinputData_Booktxt(){
        // lấy data từ file Sach.txt đẩy vào books
        books.clear();
        string Ma, Name_book, TL, TG;
        int NamXB, amount, quantity;
        ifstream File("./file_txt/Book.txt");
        if (!File.is_open())
            return;
        while (!File.eof())
        {
            getline(File, Ma, ',');
            getline(File, Name_book, ',');
            getline(File, TL, ',');
            getline(File, TG, ',');
            File >> NamXB;
            File.ignore(1, ',');
            File >> amount;
            File.ignore(1, ',');
            File >> quantity;
            File.ignore(1, '\n');
            Book s(Ma, standardization(Name_book), standardization(TL), TG, NamXB, amount, quantity);
            books.push_back(s);
        }
        File.close();
    }
    void ToanBoSach()// lấy data từ vector
    {
        cout << endl;
        cout << center("ID", 5) << " | "
             << center("Name", 25) << " | "
             << center("The loai", 15) << " | "
             << center("Tac Gia", 15) << " | "
             << center("Nam xuat ban", 12) << " | "
             << center("Amount", 10) << " | "
             << center("Quantity", 9) << "\n";

        cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '-') << "\n";
        if (books.size() == 0)
        {
            cout << "\t\tHien khong co quyen sach nao trong thu vien!" << endl;
            return;
        }
        for (int i = 0; i < books.size(); ++i)
        {
            cout << center(books[i].getMaSach(), 5) << " | "
                 << center(books[i].getTenSach(), 25) << " | "
                 << center(books[i].getTheLoai(), 15) << " | "
                 << center(books[i].getTacGia(), 15) << " | "
                 << centerv2(books[i].getNamXuatBan(), 12) << " | "
                 << centerv2(books[i].getAmount(), 10) << " | "
                 << centerv2(books[i].getQuantity(), 8) << "\n";
            if (i < books.size() - 1)
                cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '-') << "\n";
        }
    }
    void readinputData_Booktxtv2() // lấy data từ file Sach.txt đẩy vào books
    {
        string Ma, Name_book, TL, TG;
        int NamXB, amount, quantity;
        cout << "\t\t\t\tLiet ke toan bo sach trong thu vien" << endl;
        cout << endl;
        cout << center("ID", 5) << " | "
             << center("Name", 25) << " | "
             << center("The loai", 15) << " | "
             << center("Tac Gia", 15) << " | "
             << center("Nam xuat ban", 12) << " | "
             << center("Amount", 10) << " | "
             << center("Quantity", 9) << "\n";

        cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '_') << "\n";
        ifstream File("Sach.txt");
        if (!File.is_open())
        {
            cout << "Khong co quyen sach nao trong thu vien ca!\n";
            return;
        }

        while (!File.eof())
        {
            getline(File, Ma, ',');
            getline(File, Name_book, ',');
            getline(File, TL, ',');
            getline(File, TG, ',');
            File >> NamXB;
            File.ignore(1, ',');
            File >> amount;
            File.ignore(1, ',');
            File >> quantity;
            File.ignore(1, '\n');
            cout << center(Ma, 5) << " | "
                 << center(Name_book, 25) << " | "
                 << center(TL, 15) << " | "
                 << center(TG, 15) << " | "
                 << centerv2(NamXB, 12) << " | "
                 << centerv2(amount, 10) << " | "
                 << centerv2(quantity, 8) << "\n";
            cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '_') << "\n";
        }
        File.close();
    }
    void xuat_thongtin_1quyen(int i)
    {
        cout << center("ID", 5) << " | "
             << center("Name", 25) << " | "
             << center("The loai", 15) << " | "
             << center("Tac Gia", 15) << " | "
             << center("Nam xuat ban", 12) << " | "
             << center("Amount", 10) << " | "
             << center("Quantity", 9) << "\n";

        cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '_') << "\n";
        cout << center(books[i].getMaSach(), 5) << " | "
             << center(books[i].getTenSach(), 25) << " | "
             << center(books[i].getTheLoai(), 15) << " | "
             << center(books[i].getTacGia(), 15) << " | "
             << centerv2(books[i].getNamXuatBan(), 12) << " | "
             << centerv2(books[i].getAmount(), 10) << " | "
             << centerv2(books[i].getQuantity(), 8) << "\n";
    }
    // static giúp chúng trở thành các hàm tĩnh của class và do đó, chúng có thể được sử dụng như làm hàm so sánh thông thường cho std::sort.
    static bool cmpBook_amount_small_large(Book &a, Book &b)
    {
        return a.getAmount() < b.getAmount();
    }
    void arrange_book_amount()
    {
        sort(books.begin(), books.end(), cmpBook_amount_small_large);
        cout << "\nDone sap xep sach theo tang dan gia tien!\n";
        ToanBoSach();
    }
    
    static bool cmpBook_quantity(Book &a, Book &b)
    {
        return a.getQuantity() < b.getQuantity();
    }
    void arrange_book_quantity()
    {
        sort(books.begin(), books.end(), cmpBook_quantity);
        cout << "\nDone sap xep sach theo tang dan so luong!\n";
        ToanBoSach();
    }
    static bool cmpBook_name(Book &a, Book &b)
    {
        return a.convert(a.getTenSach()) < b.convert(b.getTenSach());
    }
    void arrange_book_name()
    {
        sort(books.begin(), books.end(), cmpBook_name);
        cout << "\nDone sap xep sach theo tang dan name!\n";
        ToanBoSach();
    }
    void search_book_to_id()
    {
        string id;
        cout << "- Nhap ma sach ban can tim: ";
        cin >> id;
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == id)
            {
                cout << "\t\t[!] Da tim thay " << books[i].getQuantity() << " quyen sach ban can tim!\n\n";
                xuat_thongtin_1quyen(i);
                return;
            }
        }
        cout << "\n[!] Khong tim thay quyen sach ban can tim!\n";
    }
    void search_book_to_name()
    {
        string name;
        cin.ignore();
        cout << "- Nhap ten sach ban can tim: ";
        getline(cin, name);
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getTenSach() == standardization(name))
            {
                cout << "\t\t[!] Da tim thay " << books[i].getQuantity() << " quyen sach ban can tim!\n\n";
                xuat_thongtin_1quyen(i);
                return;
            }
        }
        cout << "\n[!] Khong tim thay quyen sach ban can tim!\n";
    }
    void search_book_to_category()
    {
        string category;
        cin.ignore();
        bool check = false;
        cout << "- Nhap the loai ban muon doc: ";
        getline(cin, category);
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getTheLoai() == standardization(category))
            {
                if (!check)
                {
                    cout << "\t\t[!] Da tim thay quyen sach co the loai " << standardization(category) << endl
                         << endl;
                    cout << center("ID", 5) << " | "
                         << center("Name", 25) << " | "
                         << center("The loai", 15) << " | "
                         << center("Tac Gia", 15) << " | "
                         << center("Nam xuat ban", 12) << " | "
                         << center("Amount", 10) << " | "
                         << center("Quantity", 9) << "\n";
                    check = true;
                }
                cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '_') << "\n";
                cout << center(books[i].getMaSach(), 5) << " | "
                     << center(books[i].getTenSach(), 25) << " | "
                     << center(books[i].getTheLoai(), 15) << " | "
                     << center(books[i].getTacGia(), 15) << " | "
                     << centerv2(books[i].getNamXuatBan(), 12) << " | "
                     << centerv2(books[i].getAmount(), 10) << " | "
                     << centerv2(books[i].getQuantity(), 8) << "\n";
            }
        }
        if (!check)
            cout << "\n[!] Rat xin loi, thu vien khong co the loai ban muon doc!\n";
    }
};