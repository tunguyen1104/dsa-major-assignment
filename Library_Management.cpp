#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool flag = false; // check xem web đang ở tư cách admin hay người dùng
bool ok2 = false;  // check xem da dang nhap vao web hay chua
bool ok = false;   // check dang ky
/*! Kẻ bảng, căn giữa chuỗi */
string center(const string s, const int width)
{
    stringstream ss, spaces;
    int padding = width - s.size(); // đếm phần thừa để căn
    for (int i = 0; i < padding / 2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str(); // format with padding
    if (padding > 0 && padding % 2 != 0)     // nếu padding là số lẻ thì thêm 1 dấu cách vào sau cùng ss.
        ss << " ";
    return ss.str();
}
int size_number(int s)
{
    int cnt = 0;
    while (s > 0)
    {
        s /= 10;
        ++cnt;
    }
    return cnt;
}
// nếu data là số
string centerv2(const int s, const int width)
{
    stringstream ss, spaces;
    int padding = width - size_number(s);
    for (int i = 0; i < padding / 2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();
    if (padding > 0 && padding % 2 != 0)
        ss << " ";
    return ss.str();
}
// chuẩn hoá tên---------------------------------
string convert(string s)
{
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
string standardization(string s1) // in hoa các chữ cái đầu của tên và in thường các chữ còn lại vd: hOAng dinh NAm -> Hoang Dinh Nam
{
    stringstream ss(s1);
    vector<string> res;
    string tmp;
    while (ss >> tmp)
    {
        res.push_back(tmp);
    }
    string key = "";
    for (int i = 0; i < res.size() - 1; ++i)
    {
        key += convert(res[i]) + " ";
    }
    key += convert(res[res.size() - 1]);
    return key;
}
string convertv2(string s) // vd: hoang dinh nam -> namhoangdinh
{
    stringstream ss(s);
    string tmp;
    vector<string> res;
    while (ss >> tmp)
    {
        res.push_back(tmp);
    }
    tmp = "";
    tmp += res[res.size() - 1];
    for (int i = 0; i < res.size() - 1; ++i)
    {
        tmp += res[i];
    }
    return tmp;
}
string convert_date(string s) // vd: 5/7/2023 -> 05/07/2023
{
    if (s[2] != '/')
        s = "0" + s;
    if (s[5] != '/')
        s.insert(3, "0");
    return s;
}
string convert_datev2(int day, int month, int year)
{
    string s;
    s += to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    return convert_date(s);
}
//------------------------------------------------
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
    void setNgay(int);
    void setThang(int);
    void setNam(int);
    int getNgay();
    int getThang();
    int getNam();
    void xuat();
    ~Date(void){};
};
void Date::setNgay(int d)
{
    this->day = d;
}
void Date::setThang(int m)
{
    this->month = m;
}
void Date::setNam(int y)
{
    this->year = y;
}
int Date::getNgay()
{
    return this->day;
}
int Date::getThang()
{
    return this->month;
}
int Date::getNam()
{
    return this->year;
}
void Date::xuat()
{
    cout << this->day << "/" << this->month << "/" << this->year;
}
class Sach
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
    Sach() {}
    Sach(string Ma = "", string Ten = "", string Loai = "", string TG = "", int NXB = 0, int amount = 0, int quantity = 0)
    {
        MaSach = Ma;
        TenSach = Ten; // dùng standardization() ở đây không được nó bị lỗi
        TheLoai = Loai;
        TacGia = TG;
        NamXuatBan = NXB;
        this->amount = amount;
        this->quantity = quantity;
    }
    ~Sach(){};
    void setMaSach(string);
    void setTenSach(string);
    void setTheLoai(string);
    void setTacGia(string);
    void setNamXuatBan(int);
    void setAmount(int);
    void setQuantity(int);
    string getMaSach();
    string getTenSach();
    string getTheLoai();
    string getTacGia();
    int getNamXuatBan();
    int getAmount();
    int getQuantity();
};

void Sach ::setMaSach(string Ma)
{
    MaSach = Ma;
}

void Sach ::setTenSach(string Ten)
{
    TenSach = Ten;
}

void Sach ::setTheLoai(string Loai)
{
    TheLoai = Loai;
}

void Sach ::setTacGia(string TG)
{
    TacGia = TG;
}

void Sach ::setNamXuatBan(int NXB)
{
    this->NamXuatBan = NXB;
}
void Sach ::setAmount(int amount)
{
    this->amount = amount;
}
void Sach ::setQuantity(int quantity)
{
    this->quantity = quantity;
}
string Sach ::getMaSach()
{
    return MaSach;
}

string Sach ::getTenSach()
{
    return standardization(TenSach);
}

string Sach ::getTheLoai()
{
    return standardization(TheLoai);
}

string Sach ::getTacGia()
{
    return TacGia;
}

int Sach ::getNamXuatBan()
{
    return NamXuatBan;
}
int Sach ::getAmount()
{
    return amount;
}
int Sach ::getQuantity()
{
    return quantity;
}
//-------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
class BanDoc
{
private:
    string MSV;
    string HoTen;
    string NganhHoc;
    string Khoa; // Khoá
    string date_of_birth;

public:
    BanDoc() {}
    BanDoc(string MSV = "", string HoTen = "", string NganhHoc = "", string Khoa = "", string date_of_birth = "")
    {
        this->MSV = MSV;
        this->HoTen = HoTen;
        this->NganhHoc = NganhHoc;
        this->Khoa = Khoa;
        this->date_of_birth = date_of_birth;
    }
    ~BanDoc() {}
    void setMSV(string);
    void setHoTen(string);
    void setNganhHoc(string);
    void setKhoa(string);
    void setDay(string date_of_birth)
    {
        this->date_of_birth = date_of_birth;
    }
    string getMSV();
    string getHoTen();
    string getNganhHoc();
    string getKhoa();
    string getDate_of_Birth()
    {
        return convert_date(date_of_birth);
    }
};
void BanDoc ::setKhoa(string Khoa)
{
    this->Khoa = Khoa;
}
void BanDoc ::setMSV(string msv)
{
    MSV = msv;
}

void BanDoc ::setHoTen(string hoten)
{
    HoTen = hoten;
}

void BanDoc ::setNganhHoc(string nganhhoc)
{
    NganhHoc = nganhhoc;
}

string BanDoc ::getMSV()
{
    return MSV;
}

string BanDoc ::getHoTen()
{
    return standardization(HoTen);
}

string BanDoc ::getNganhHoc()
{
    return NganhHoc;
}
string BanDoc ::getKhoa()
{
    return Khoa;
}
//----------------------------------------------------------------------------------------
class PhieuMuon : public BanDoc, public Sach, public Date
{
public:
    string name_students_borrow_pay;
    Date xNgayMuon, xNgayTra;
    // Các hàm xử lí chuẩn ngày
    int nNgayPlus(int nN);
    int nThangPlus(int nN);
    int nNamPlus(int nN);
    bool ktrNamNhuan();
    void setname_students(string name_students_borrow_pay)
    {
        this->name_students_borrow_pay = name_students_borrow_pay;
    }
    string getname_students()
    {
        return standardization(name_students_borrow_pay);
    }
    // constructor này dùng để đọc file PhieuMuon.txt,nếu dùng constructor bên dưới thì day month year trong file sẽ bị đổi thành thời gian thực
    PhieuMuon(string MSV = "", string MS = "", string name_students_borrow_pay = "", int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0) : BanDoc(MSV), Sach(MS), xNgayMuon(a, b, c), xNgayTra(d, e, f)
    {
        this->name_students_borrow_pay = name_students_borrow_pay;
    }
    PhieuMuon(int cnt = 0, string MSV = "", string MS = "", string name_students_borrow_pay = "") : BanDoc(MSV), Sach(MS)
    {
        time_t t = time(0);
        struct tm *Now = localtime(&t);
        xNgayMuon.setNgay(Now->tm_mday);
        xNgayMuon.setThang(Now->tm_mon + 1);
        xNgayMuon.setNam(Now->tm_year + 1900);

        xNgayTra.setNgay(nNgayPlus(7));
        xNgayTra.setThang(nThangPlus(7));
        xNgayTra.setNam(nNamPlus(7));
        this->name_students_borrow_pay = name_students_borrow_pay;
    }
    ~PhieuMuon(){};
};
int PhieuMuon::nNgayPlus(int nN)
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

int PhieuMuon::nThangPlus(int nN)
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

int PhieuMuon::nNamPlus(int nN)
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
bool PhieuMuon::ktrNamNhuan()
{
    time_t t = time(0);
    struct tm *ta = localtime(&t);
    ta->tm_year = ta->tm_year + 1900;
    if (ta->tm_year % 400 == 0 || ta->tm_year % 4 == 0 && ta->tm_year % 100 != 0)
        return true;
    else
        return false;
}
//----------------------------------------------------------------------
class List_Books
{
private:
    vector<Sach> books;

public:
    void ThemSach(vector<Sach> &books)
    {
        cout << "\t\tNhap them mot cuon sach" << endl;
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
        Sach New(MS, Ten, Loai, TG, NXB, amount, quantity);
        books.push_back(New);
        // Không có file outputData_Sach_File vì ?
        ofstream File;
        File.open("Sach.txt", ios::app);
        int i = books.size() - 1;
        if (i == 0)
        {
            File
                << books[i].getMaSach() << "," << books[i].getTenSach() << "," << books[i].getTheLoai() << ","
                << books[i].getTacGia() << "," << books[i].getNamXuatBan() << "," << books[i].getAmount() << "," << books[i].getQuantity();
        }
        else
            File << "\n"
                 << books[i].getMaSach() << "," << books[i].getTenSach() << "," << books[i].getTheLoai() << ","
                 << books[i].getTacGia() << "," << books[i].getNamXuatBan() << "," << books[i].getAmount() << "," << books[i].getQuantity();

        File.close();
        cout << "\t\tThem sach thanh cong !\n";
    }

    void SuaSach(vector<Sach> &books)
    {
        // Tìm và sửa theo mã sách
        cout << "\t\tSua thong tin sach" << endl;
        cout << endl;
        string Find;
        string MS, Ten, Loai, TG;
        int NXB;
        int amount;
        cout << "Nhap ma sach can sua: ";
        bool check_find_sach = false;
        cin.ignore();
        getline(cin, Find);
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == Find)
            {
                check_find_sach = true;

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
                    {
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
                Sach change(MS, standardization(Ten), standardization(Loai), TG, NXB, amount, 1);
                books[i] = change;
                break;
            }
        }
        if (!check_find_sach)
            cout << "- Khong ton tai ma sach can sua !\n";
        else
            outputData_Sach_File(books);
    }

    void XoaSach(vector<Sach> &books, vector<PhieuMuon> &borrow_pay)
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
            outputData_Sach_File(books);
    }
    void outputData_Sach_File(vector<Sach> &books) // lấy data từ books ghi mới vào Sach.txt
    {
        ofstream File;
        File.open("Sach.txt");
        int cnt = 0;
        for (int i = 0; i < books.size(); ++i)
        {
            File << books[i].getMaSach() << "," << books[i].getTenSach()
                 << "," << books[i].getTheLoai() << "," << books[i].getTacGia() << "," << books[i].getNamXuatBan() << "," << books[i].getAmount() << "," << books[i].getQuantity();
            if (cnt < books.size() - 1)
            {
                File << endl;
                cnt++;
            }
        }
        File.close();
    }
    void readinputData_Sach(vector<Sach> &books) // lấy data từ file Sach.txt đẩy vào books
    {
        books.clear();
        string Ma, Name_book, TL, TG;
        int NamXB, amount, quantity;
        ifstream File("Sach.txt");
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
            Sach s(Ma, standardization(Name_book), standardization(TL), TG, NamXB, amount, quantity);
            books.push_back(s);
        }
        File.close();
    }
    void ToanBoSach(vector<Sach> &books)
    {
        cout << "\t\t\t\tLiet ke toan bo sach trong thu vien" << endl;
        cout << endl;
        cout << center("STT", 5) << " | "
             << center("Name", 25) << " | "
             << center("The loai", 15) << " | "
             << center("Tac Gia", 15) << " | "
             << center("Nam xuat ban", 12) << " | "
             << center("Amount", 10) << " | "
             << center("Quantity", 9) << "\n";

        cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '_') << "\n";
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
                cout << string(5 + 25 + 15 * 2 + 12 + 10 + 9 + 3 * 6, '_') << "\n";
        }
    }
    void ToanBoSachv2(vector<Sach> &books) // lấy data từ file Sach.txt đẩy vào books
    {
        string Ma, Name_book, TL, TG;
        int NamXB, amount, quantity;
        cout << "\t\t\t\tLiet ke toan bo sach trong thu vien" << endl;
        cout << endl;
        cout << center("STT", 5) << " | "
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
    void xuat_thongtin_1quyen(vector<Sach> &books, int i)
    {
        cout << center("STT", 5) << " | "
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
    // static giúp chúng trở thành các hàm tĩnh của class, và do đó, chúng có thể được sử dụng như làm hàm so sánh thông thường cho std::sort.
    static bool cmpBook_amount_small_large(Sach &a, Sach &b)
    {
        return a.getAmount() < b.getAmount();
    }
    static bool cmpBook_name(Sach &a, Sach &b)
    {
        return convert(a.getTenSach()) < convert(b.getTenSach());
    }
    static bool cmpBook_quantity(Sach &a, Sach &b)
    {
        return a.getQuantity() < b.getQuantity();
    }
    void arrange_book_quantity(vector<Sach> &books)
    {
        sort(books.begin(), books.end(), cmpBook_quantity);
        outputData_Sach_File(books);
    }
    void arrange_book_amount(vector<Sach> &books)
    {
        sort(books.begin(), books.end(), cmpBook_amount_small_large);
        outputData_Sach_File(books);
    }
    void arrange_book_name(vector<Sach> &books)
    {
        sort(books.begin(), books.end(), cmpBook_name);
        outputData_Sach_File(books);
    }
    void search_book_to_id(vector<Sach> &books)
    {
        string id;
        cout << "- Nhap ma sach ban can tim: ";
        cin >> id;
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == id)
            {
                cout << "\t\t[!] Da tim thay " << books[i].getQuantity() << " quyen sach ban can tim!\n\n";
                xuat_thongtin_1quyen(books, i);
                return;
            }
        }
        cout << "\n[!] Khong tim thay quyen sach ban can tim!\n";
    }
    void search_book_to_name(vector<Sach> &books)
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
                xuat_thongtin_1quyen(books, i);
                return;
            }
        }
        cout << "\n[!] Khong tim thay quyen sach ban can tim!\n";
    }
    void search_book_to_category(vector<Sach> &books)
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
                    cout << center("STT", 5) << " | "
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
//-------------------------------------------------------------------
class List_students
{
public:
    vector<BanDoc> students;
    void addStudent(vector<BanDoc> &students)
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
        BanDoc New(MSV, standardization(Ten), NganhHoc, Khoa, convert_date(date_of_birth));
        students.push_back(New);
        ofstream File;
        File.open("SinhVien.txt", ios::app);
        int i = students.size() - 1;
        if (i == 1)
        {
            File
                << students[i].getMSV() << "," << students[i].getHoTen() << "," << students[i].getNganhHoc() << ","
                << students[i].getKhoa() << "," << students[i].getDate_of_Birth();
        }
        else
        {
            File << "\n"
                 << students[i].getMSV() << "," << students[i].getHoTen() << "," << students[i].getNganhHoc() << ","
                 << students[i].getKhoa() << "," << students[i].getDate_of_Birth();
        }

        File.close();
        cout << "\t\tThem ban doc thanh cong !\n";
    }
    void removeStudent(vector<BanDoc> &students)
    {
        string MSV;
        cout << "- Nhap ma sinh vien can xoa: ";
        cin >> MSV;

        bool found = false;

        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getMSV() == MSV)
            {
                found = true;
                students.erase(students.begin() + i);
                cout << "Da xoa sach co ma: " << MSV << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Khong tim thay ma sinh vien: " << MSV << endl;
        }
        else
            outputData_BanDoc_File(students);
    }
    void updateStudent(vector<BanDoc> &students)
    {
        // Tìm và sửa theo mã sách
        cout << "\t\tSua thong tin Ban doc" << endl;
        cout << endl;
        string MSV, Ten, NganhHoc, Khoa;
        string date_of_birth;
        cout << "Nhap ma sinh vien can sua: ";
        bool check_find_student = false;
        cin.ignore();
        getline(cin, MSV);
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getMSV() == MSV)
            {
                check_find_student = true;
            ms:
                cout << "- Nhap ma sinh vien moi: ";
                cin >> MSV;
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
                BanDoc change(MSV, standardization(Ten), NganhHoc, Khoa, convert_date(date_of_birth));
                students[i] = change;
                break;
            }
        }
        if (!check_find_student)
            cout << "- Khong ton tai ma sinh vien can sua !\n";
        else
            outputData_BanDoc_File(students);
    }
    void outputData_BanDoc_File(vector<BanDoc> &students)
    {
        ofstream File;
        File.open("SinhVien.txt");
        int cnt = 0;
        for (int i = 0; i < students.size(); ++i)
        {
            File
                << students[i].getMSV() << "," << students[i].getHoTen() << "," << students[i].getNganhHoc() << ","
                << students[i].getKhoa() << "," << students[i].getDate_of_Birth();
            ;
            if (cnt < students.size() - 1)
            {
                File << endl;
                ++cnt;
            }
        }
        File.close();
    }
    void inputData_BanDoc(vector<BanDoc> &students) // lấy data từ file SinhVien.txt
    {
        students.clear();
        string MSV = "", Ten = "", NganhHoc = "", Khoa = "";
        string date_of_birth = "";
        ifstream File("SinhVien.txt");
        if (!File.is_open())
            return;
        while (!File.eof())
        {
            getline(File, MSV, ',');
            getline(File, Ten, ',');
            getline(File, NganhHoc, ',');
            getline(File, Khoa, ',');
            File >> date_of_birth;
            File.ignore(1, '\n');
            BanDoc bd(MSV, standardization(Ten), NganhHoc, Khoa, convert_date(date_of_birth));
            students.push_back(bd);
        }
        File.close();
    }
    void Export_a_list_of_student(vector<BanDoc> &students)
    {
        cout << "\t\t\t\tIn ra cac ban doc trong thu vien hien tai" << endl;
        cout << endl;
        cout << center("STT", 5) << " | "
             << center("Ma sinh vien", 15) << " | "
             << center("Ho Ten", 25) << " | "
             << center("Nganh Hoc", 15) << " | "
             << center("Khoa", 10) << " | "
             << center("Ngay sinh", 12) << "\n";

        cout << string(5 + 15 * 2 + 25 + 10 + 12 + 5 * 3, '_') << "\n";
        for (int i = 0; i < students.size(); ++i)
        {
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
    void xuat_thongtin_1student(vector<BanDoc> &students, int i)
    {
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
    static bool cmp_student_to_name(BanDoc &a, BanDoc &b)
    {
        return convertv2(a.getHoTen()) < convertv2(b.getHoTen());
    }
    void arrange_student_name(vector<BanDoc> &students)
    {
        sort(students.begin(), students.end(), cmp_student_to_name);
        outputData_BanDoc_File(students);
    }
    void search_student_to_id(vector<BanDoc> &students)
    {
        string id;
        cout << "- Nhap ma sinh vien ban doc ban can tim: ";
        cin >> id;
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getMSV() == id)
            {
                cout << "\t\t\t[!] : Da tim thay ban doc co id " << id << "\n\n";
                xuat_thongtin_1student(students, i);
                return;
            }
            cout << "\n[!] : Khong tim thay ban doc co id = " << id << "\n";
        }
    }
    void search_student_to_name(vector<BanDoc> &students)
    {
        string name;
        cout << "- Nhap ten sinh vien ban doc ban can tim: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < students.size(); ++i)
        {
            if (students[i].getHoTen() == standardization(name))
            {
                cout << "\t\t\t[!] : Da tim thay ban doc co name " << name << "\n\n";
                xuat_thongtin_1student(students, i);
                return;
            }
        }
        cout << "\n[!] : Khong ton tai ban doc co name " << name << " trong thu vien\n";
    }
};
class List_BorrowPay : public List_Books
{
public:
    vector<PhieuMuon> borrow_pay;
    void MuonSach(vector<Sach> &books, vector<PhieuMuon> &borrow_pay)
    {
        // Quản lý theo mã sinh viên và mã sách
        cout << "\t\t[!] : Nhap N de thoat.\n\n";
        string nMS = ""; // mã sách
        while (true)
        {
            cout << "- Nhap ma sach: ";
            cin >> nMS;
            if (nMS == "")
            {
                cout << "Khong duoc de trong. Nhap lai!\n";
                continue;
            }
            else if (nMS == "N")
            {
                cout << "=========================\n";
                cout << "Ban chon thoat !\n";
                return;
            }
            else if (kiemTraSach_DuTieuChuanMuon(books, nMS))
            {
                break;
            }
            else
            {
                cout << "\t\tMa sach khong ton tai! hoac dang co ban doc muon.\n";
                continue;
            }
        }
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == nMS)
            {
                cout << "\t\t" << nMS << " : " << books[i].getTenSach() << " | quantity : " << books[i].getQuantity() << endl;
            }
        }
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
            else if (nMSV == "N")
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
        PhieuMuon pm(0, nMSV, nMS, standardization(name_students_borrow_pay));
        borrow_pay.push_back(pm);
        time_t t = time(0);
        struct tm *Now = localtime(&t);
        cout << "______________________________________\n";
        cout << "\t\tYeu cau cua ban dang duoc thuc hien!\n";
        cout << "\t\tThoi gian: " << Now->tm_hour << ":" << Now->tm_min << ":" << Now->tm_sec << endl;
        cout << "\t\tNgay: " << Now->tm_mday << "/" << Now->tm_mon + 1 << "/" << Now->tm_year + 1900 << endl;
        cout << "\t\tTao phieu muon thanh cong!\n";
        cout << "______________________________________\n";
        ofstream File;
        File.open("PhieuMuon.txt", ios::app);
        int i = borrow_pay.size() - 1;
        if (i == 0)
        {
            File
                << borrow_pay[i].getMSV() << "," << borrow_pay[i].getMaSach() << "," << borrow_pay[i].getname_students() << "," << borrow_pay[i].xNgayMuon.getNgay() << ","
                << borrow_pay[i].xNgayMuon.getThang() << "," << borrow_pay[i].xNgayMuon.getNam() << "," << borrow_pay[i].xNgayTra.getNgay() << ","
                << borrow_pay[i].xNgayTra.getThang() << "," << borrow_pay[i].xNgayTra.getNam();
        }
        else
            File << "\n"
                 << borrow_pay[i].getMSV() << "," << borrow_pay[i].getMaSach() << "," << borrow_pay[i].getname_students() << "," << borrow_pay[i].xNgayMuon.getNgay() << ","
                 << borrow_pay[i].xNgayMuon.getThang() << "," << borrow_pay[i].xNgayMuon.getNam() << "," << borrow_pay[i].xNgayTra.getNgay() << ","
                 << borrow_pay[i].xNgayTra.getThang() << "," << borrow_pay[i].xNgayTra.getNam();
        File.close();
        // Sửa quantity của quyển sách vừa mượn
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == nMS)
            {
                int quantity = books[i].getQuantity();
                books[i].setQuantity(quantity - 1);
            }
        }
        outputData_Sach_File(books);
    }
    bool kiemTraSach_DuTieuChuanMuon(vector<Sach> &books, string MS)
    {
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == MS && books[i].getQuantity() > 0)
            {
                return true;
            }
        }
        return false;
    }
    void outputData_PhieuMuon_File(vector<PhieuMuon> &borrow_pay)
    {
        ofstream File;
        File.open("PhieuMuon.txt");
        int cnt = 0;
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            File
                << borrow_pay[borrow_pay.size() - 1].getMSV() << "," << borrow_pay[borrow_pay.size() - 1].getMaSach() << "," << borrow_pay[borrow_pay.size() - 1].getname_students() << "," << borrow_pay[borrow_pay.size() - 1].xNgayMuon.getNgay() << ","
                << borrow_pay[borrow_pay.size() - 1].xNgayMuon.getThang() << "," << borrow_pay[borrow_pay.size() - 1].xNgayMuon.getNam() << "," << borrow_pay[borrow_pay.size() - 1].xNgayTra.getNgay() << "," << borrow_pay[borrow_pay.size() - 1].xNgayTra.getThang() << ","
                << borrow_pay[borrow_pay.size() - 1].xNgayTra.getNam();
            if (cnt < borrow_pay.size() - 1)
            {
                File << endl;
                cnt++;
            }
        }
        File.close();
    }
    void inputData_PhieuMuon(vector<PhieuMuon> &borrow_pay) // lấy data từ file PhieuMuon.txt
    {
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
        ifstream File("PhieuMuon.txt");
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
            PhieuMuon pm(MSV, MS, standardization(name_students_borrow_pay), nNgayMuon, nThangMuon, nNamMuon, nNgayTra, nThangTra, nNamTra);
            borrow_pay.push_back(pm);
        }
        File.close();
    }
    void Export_a_list_of_borrowed_tickets(vector<PhieuMuon> &borrow_pay)
    {
        cout << "\t\t\t\tIn ra cac phieu muon sach thu vien" << endl;
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
                 << center(borrow_pay[i].getname_students(), 25) << " | "
                 << center(borrow_pay[i].getMSV(), 25) << " | "
                 << center(borrow_pay[i].getMaSach(), 15) << " | "
                 << center(convert_datev2(borrow_pay[i].xNgayMuon.getNgay(), borrow_pay[i].xNgayMuon.getThang(), borrow_pay[i].xNgayMuon.getNam()), 14) << " | "
                 << center(convert_datev2(borrow_pay[i].xNgayTra.getNgay(), borrow_pay[i].xNgayTra.getThang(), borrow_pay[i].xNgayTra.getNam()), 12) << "\n";
            if (i < borrow_pay.size() - 1)
                cout << string(5 + 15 + 25 * 2 + 14 + 12 + 5 * 3, '_') << "\n";
        }
    }
    void TraSach(vector<Sach> &books, vector<PhieuMuon> &borrow_pay)
    {
        cin.ignore();
        cout << "\t\tTra sach" << endl;
        cout << "[!] : Nhap N de thoat.\n\n";
        string msv, ms, name;
        int ok = 0;
    xmsv:
        cout << "- Nhap ma sinh vien: ";
        getline(cin, msv);
        if (msv == "N")
        {
            cout << "\n===========================\n";
            cout << "\t\tBan chon thoat!\n";
            return;
        }
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].getMSV() == msv)
            {
                ok = i;
                goto xname;
            }
        }
        cout << "- Khong co ma sinh vien nao nhu vay da muon sach!\nNhap lai:\n";
        goto xmsv;
    xname:
        cout << "- Nhap ten sinh vien: ";
        getline(cin, name);
        if (name == "N")
        {
            cout << "\n===========================\n";
            cout << "\t\tBan chon thoat!\n";
            return;
        }
        if (borrow_pay[ok].getname_students() == standardization(name))
        {
            goto xms;
        }
        cout << "- Nhap sai ten sinh vien muon sach!\nNhap lai:\n";
        goto xname;
    xms:
        cout << "- Nhap ma sach: ";
        cin >> ms;
        if (ms == "N")
        {
            cout << "\n===========================\n";
            cout << "\t\tBan chon thoat!\n";
            return;
        }
        if (borrow_pay[ok].getMaSach() == ms)
        {
            goto done;
        }
        cout << "- Nhap sai ma sach duoc muon!\nNhap lai:\n";
        goto xms;
    done:
        borrow_pay.erase(borrow_pay.begin() + ok);

        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].getMaSach() == ms)
            {
                books[i].setQuantity(books[i].getQuantity() + 1);
            }
        }
        outputData_PhieuMuon_File(borrow_pay);
        outputData_Sach_File(books);
    }
    void xuat_thongtin1phieumuon(vector<PhieuMuon> &borrow_pay, int i)
    {
        cout << string(5 + 15 + 25 * 2 + 14 + 12 + 5 * 3, '_') << "\n";
        cout << centerv2(i + 1, 5) << " | "
             << center(borrow_pay[i].getname_students(), 25) << " | "
             << center(borrow_pay[i].getMSV(), 25) << " | "
             << center(borrow_pay[i].getMaSach(), 15) << " | "
             << center(convert_datev2(borrow_pay[i].xNgayMuon.getNgay(), borrow_pay[i].xNgayMuon.getThang(), borrow_pay[i].xNgayMuon.getNam()), 14) << " | "
             << center(convert_datev2(borrow_pay[i].xNgayTra.getNgay(), borrow_pay[i].xNgayTra.getThang(), borrow_pay[i].xNgayTra.getNam()), 12) << "\n";
    }
    void search_borrow_pay_namestudent(vector<PhieuMuon> &borrow_pay)
    {
        string name;
        cout << "- Nhap ten ban doc: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].getname_students() == standardization(name))
            {
                cout << "[!] : Da tim thay phieu sach cua ban doc " << name << " !\n\n";
                cout << center("STT", 5) << " | "
                     << center("Ho Ten", 25) << " | "
                     << center("Ma sinh vien", 25) << " | "
                     << center("Ma sach", 15) << " | "
                     << center("Ngay muon", 14) << " | "
                     << center("Ngay tra", 12) << "\n";
                xuat_thongtin1phieumuon(borrow_pay, i);
                return;
            }
        }
        cout << "\n[!] : Khong ton tai phieu sach co ten ban doc " << name << " !\n\n";
    }

    void InPhieumuon_quahan(vector<PhieuMuon> &borrow_pay)
    {
        PhieuMuon current_day(0, "test", "test");
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
                xuat_thongtin1phieumuon(borrow_pay, i);
        }
    }
    void inphieumuon_motsinhvien(vector<PhieuMuon> &borrow_pay, string username)
    {
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
                xuat_thongtin1phieumuon(borrow_pay, i);
                return;
            }
        }
        cout << "\t\tBan chua muon quyen sach nao!\n";
    }
    int check_phieuquahan_motsinhvien(vector<PhieuMuon> &borrow_pay, string username)
    {
        int cnt = 0;
        for (int i = 0; i < borrow_pay.size(); ++i)
        {
            if (borrow_pay[i].getMSV() == username)
            {
                ++cnt;
            }
        }
        return cnt;
    }
};
//----------------------------------------------------------------------------
class app
{
private:
    // vector<Sach> &books, vector<BanDoc> &students, vector<PhieuMuon> &borrow_pay
    vector<Sach> books;
    vector<BanDoc> students;
    vector<PhieuMuon> borrow_pay;
    List_Books _books;
    List_BorrowPay _borrowPay;
    List_students _students;

public:
    void menu1()
    {
        int chon;
        do
        {
            system("cls");
            cout << "========================MENU 1===========================\n";
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
                _books.ThemSach(books);
                break;
            case 2:
                cout << "[2] : Sua thong tin sach\n";
                _books.SuaSach(books);
                break;
            case 3:
                cout << "[3] : Xoa mot quyen sach\n";
                _books.XoaSach(books, borrow_pay);
                break;
            case 4:
                cout << "[4] : Liet ke toan bo sach trong thu vien\n";
                _books.ToanBoSach(books);
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
    void menu2()
    {

        int chon;
        do
        {
            system("cls");
            cout << "========================MENU 2===========================\n";
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
                _borrowPay.MuonSach(books, borrow_pay);
                break;
            case 2:
                cout << "[5] : Tra sach\n";
                _borrowPay.TraSach(books, borrow_pay);
                break;
            case 3:
                cout << "[3] : Xuat danh sach phieu muon\n";
                _borrowPay.Export_a_list_of_borrowed_tickets(borrow_pay);
                break;
            case 4:
                cout << "[4] : Xuat danh sach phieu muon qua han!\n";
                _borrowPay.InPhieumuon_quahan(borrow_pay);
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
    void menu3() // quản lý sinh viên ra vào đọc sách thư viện
    {
        int chon;
        do
        {
            system("cls");
            cout << "========================MENU 3===============================\n";
            cout << "==                                                         ==\n";
            cout << "==        1.Them mot ban doc.                              ==\n";
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
                _students.addStudent(students);
                break;
            case 2:
                cout << "[2] : Sua thong tin ban doc\n";
                _students.updateStudent(students);
                break;
            case 3:
                cout << "[3] : Xoa mot ban doc\n";
                _students.removeStudent(students);
                break;
            case 4:
                cout << "[4] : Liet ke toan bo sinh vien o trong thu vien\n";
                _students.Export_a_list_of_student(students);
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
    void menu4()
    {
        int chon;
        do
        {
            system("cls");
            cout << "========================MENU 4===========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Sap xep sach theo gia tien tang dan.       ==\n";
            cout << "==        2.Sap xep sach theo name alphabet.           ==\n";
            cout << "==        3.Sap xep danh sach cac ban doc theo name.   ==\n";
            cout << "==        4.Exit.                                      ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : Sap xep sach theo gia tien\n";
                _books.arrange_book_amount(books);
                cout << "\nDone sap xep sach theo ma!\n";
                break;
            case 2:
                cout << "[2] : Sap xep sach theo name alphabet\n";
                _books.arrange_book_name(books);
                cout << "\nDone sap xep sach theo name!\n";
                break;
            case 3:
                cout << "[3] : Sap xep cac ban doc theo name alphabet\n";
                _students.arrange_student_name(students);
                cout << "\nDone sap xep ban doc theo name!\n";
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
    void menu5()
    {
        int chon;
        do
        {
            system("cls");
            cout << "========================MENU 5===========================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.Tim kiem sach theo ma sach                 ==\n";
            cout << "==        2.Tim kiem sach theo name                    ==\n";
            cout << "==        3.Tim kiem theo the loai sach                ==\n";
            cout << "==        4.Tim kiem cac ban doc theo ma sinh vien     ==\n";
            cout << "==        5.Tim kiem ban doc theo name                 ==\n";
            cout << "==        6.Tim kiem phieu sach theo ten sinh vien.    ==\n";
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
                _books.search_book_to_id(books);
                break;
            case 2:
                cout << "[2] : Tim kiem sach theo ma name\n";
                _books.search_book_to_name(books);
                break;
            case 3:
                cout << "[3] : Tim kiem sach theo the loai\n";
                _books.search_book_to_category(books);
                break;
            case 4:
                cout << "[4] : Tim kiem ban doc theo ma sinh vien\n";
                _students.search_student_to_id(students);
                break;
            case 5:
                cout << "[5] : Tim kiem ban doc theo name\n";
                _students.search_student_to_name(students);
                break;
            case 6:
                cout << "[6] : Tim kiem ten sinh vien da muon sach\n";
                _borrowPay.search_borrow_pay_namestudent(borrow_pay);
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
            cout << "========================MENU 6===========================\n";
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
                cout << "Hien dang co ";
                cout << students.size() << endl;
                cout << " sinh vien trong thu vien\n";
                break;
            case 2:
                cout << "[2] : Thong ke so dau sach trong thu vien: ";
                cout << books.size() << endl;
                break;
            case 3:
                cout << "[3] : Thong ke so phieu muon : ";
                cout << borrow_pay.size() << endl;
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
    void menu()
    {
        _books.readinputData_Sach(books);
        _borrowPay.inputData_PhieuMuon(borrow_pay);
        _students.inputData_BanDoc(students);
        int chon;
        do
        {
            system("cls");
            cout << "\t     Chuong Trinh Quan Ly Thu Vien." << endl;
            cout << "========================MENU=============================\n";
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
                cout << "[1] : Quan ly sach\n";
                menu1();
                break;
            case 2:
                cout << "[2] : Quan ly phieu muon sach\n";
                menu2();
                break;
            case 3:
                cout << "[3] : Quan ly danh sach ban doc trong thu vien\n";
                menu3();
                break;
            case 4:
                cout << "[4] : Sap xep sach\n";
                menu4();
                break;
            case 5:
                cout << "[5] : Tim kiem sach\n";
                menu5();
                break;
            case 6:
                cout << "[6] : Thong ke\n";
                menu6();
                break;
            case 7:
                cout << "[7] : Thoat\n";
                cout << "\n\t\tXin chao va hen gap lai !\n";
                break;
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
    void menuv2(string username, string password)
    {
        _books.readinputData_Sach(books);
        _borrowPay.inputData_PhieuMuon(borrow_pay);
        _students.inputData_BanDoc(students);
        int chon;
        do
        {
            system("cls");
            cout << "\t     Chuong Trinh Quan Ly Thu Vien." << endl;
            int cnt_phieuquanhan = _borrowPay.check_phieuquahan_motsinhvien(borrow_pay, username);
            if (cnt_phieuquanhan)
                cout << "[Warning] : Ban co " << cnt_phieuquanhan << " quyen sach chua tra cho thu vien!\n";
            cout << "========================MENU=============================\n";
            cout << "==                                                     ==\n";
            cout << "==        1.In toan bo sach co trong thu vien.         ==\n";
            cout << "==        2.Muon sach.                                 ==\n";
            cout << "==        3.Tra sach.                                  ==\n";
            cout << "==        4.In cac phieu muon sach cua ban.            ==\n";
            cout << "==        5.Tim kiem sach theo ten.                    ==\n";
            cout << "==        6.Tim kiem theo the loai sach ban muon doc.  ==\n";
            cout << "==        7.Sap xep sach theo tang dan gia tien.       ==\n";
            cout << "==        8.Exit.                                      ==\n";
            cout << "==                                                     ==\n";
            cout << "=========================================================\n";
            cout << "=> Moi chon chuc nang: ";
            cin >> chon;
            cout << "=========================" << endl;
            switch (chon)
            {
            case 1:
                cout << "[1] : In toan bo sach co trong thu vien\n";
                _books.ToanBoSach(books);
                break;
            case 2:
                cout << "[2] : Muon sach\n";
                _borrowPay.MuonSach(books, borrow_pay);
                break;
            case 3:
                cout << "[3] : Tra sach\n";
                _borrowPay.TraSach(books, borrow_pay);
                break;
            case 4:
                cout << "[4] : In cac phieu muon sach cua ban\n";
                _borrowPay.inphieumuon_motsinhvien(borrow_pay, username);
                break;
            case 5:
                cout << "[5] : Tim kiem sach theo ten\n";
                _books.search_book_to_name(books);
                break;
            case 6:
                cout << "[6] : Tim kiem sach theo the loai ban muon doc\n";
                _books.search_book_to_category(books);
                break;
            case 7:
                cout << "[7] : Sap xep sach theo tang dan gia tien\n";
                _books.arrange_book_amount(books);
                cout << "\t\tDa sap xep thanh cong!\n";
                break;
            case 8:
                cout << "[8] : Thoat\n";
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
class Admin : public app
{
public:
    bool checkuser(string username, string password, string filetxt)
    {
        string usernamev2, passwordv2;
        ifstream File(filetxt);
        while (!File.eof())
        {
            getline(File, usernamev2, ' ');
            getline(File, passwordv2, '\n');
            if (usernamev2 == username && passwordv2 == password)
            {
                return true;
            }
        }
        File.close();
        return false;
    }
    void forgotPassword()
    {
    }
    void admin_login()
    {

        string username, password;
    lg:
        system("cls");
        cout << "\t\t"
             << "+---------------------+" << endl;
        cout << "\t\t"
             << "|     Login Admin     |" << endl;
        cout << "\t\t"
             << "+---------------------+" << endl;
        cout << "\n[!] : Nhap T de vao web voi tu cach user!\n";
    name:
        cout << "- Nhap username: ";
        cin >> username;
        if (username == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto name;
        }
        else if (username == "T")
        {
            int chon;
            do
            {
                system("cls");
                cout << "\t\t"
                     << "+---------------+" << endl;
                cout << "\t\t"
                     << "|     User      |" << endl;
                cout << "\t\t"
                     << "+---------------+" << endl;
                cout << endl;
                cout << "1. Login\n";
                cout << "2. Signup\n";
                cout << "Moi chon chuc nang: ";
                cin >> chon;
                if (chon == 1)
                {
                    user_login();
                    return;
                }
                else if (chon == 2)
                {
                    user_register();
                    return;
                }
                else
                {
                    cout << "Nhap sai lua chon!\n";
                    cout << "=> Nhan Enter de tro ve !";
                    cin.ignore();
                    cin.get();
                }
            } while (chon != 1 && chon != 2);
        }
        if (ok || ok2)
            return;
        else if (username.length() < 8)
        {
            cout << "\t\tUsername phai co 8 tu tro len. Nhap lai!\n";
            goto name;
        }

    pass:
        cout << "- Nhap password: ";
        cin >> password;
        if (password == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto pass;
        }
        else if (username == "T")
        {
            int chon;
            do
            {
                system("cls");
                cout << "\t\t"
                     << "+---------------+" << endl;
                cout << "\t\t"
                     << "|     User      |" << endl;
                cout << "\t\t"
                     << "+---------------+" << endl;
                cout << endl;
                cout << "1. Login\n";
                cout << "2. Signup\n";
                cout << "Moi chon chuc nang: ";
                cin >> chon;
                if (chon == 1)
                    user_login();
                else if (chon == 2)
                    user_register();
                else
                {
                    cout << "Nhap sai lua chon!\n";
                    cout << "=> Nhan Enter de tro ve !";
                    cin.ignore();
                    cin.get();
                }
            } while (chon != 1 && chon != 2);
        }
        if (ok || ok2)
            return;
        else if (password.length() < 8)
        {
            cout << "\t\tPassword phai co 8 tu tro len. Nhap lai!\n";
            goto pass;
        }

        if (checkuser(username, password, "database.txt"))
        {
            cout << "\n\t\tDang nhap thanh cong!";
            flag = true;
            menu();
        }
        else
        {
            cout << "\n\t\tTai khoan hoac mat khau khong dung!\n\n";
            int chon;
            do
            {
                cout << "1. Nhap lai\n";
                cout << "2. Thoat!\n";
                cout << "3. Vao web voi tu cach user\n";
                cout << "Moi chon chuc nang: ";
                cin >> chon;
                switch (chon)
                {
                case 1:
                    cout << "[1] : Nhap lai\n";
                    cout << "\t\tBan chon nhap lai. Quay lai trang login!";
                    goto lg;
                    break;
                case 2:
                    cout << "[2] : Thoat!\n";
                    cout << "\t\tBan chon thoat! Xin chao va hen gap lai !\n";
                    break;
                case 3:
                    cout << "[3] : Vao web voi tu cach user!\n";
                    ok = true;
                    user_login();
                    break;
                default:
                    cout << "\t\tNhap sai lua chon!\n";
                    cout << "=> Nhan Enter de tro ve !";
                    cin.ignore();
                    cin.get();
                    break;
                }
                if (ok)
                    return;
            } while (chon != 2);
        }
    }
    bool valid_account(string username, string password)
    {
        string usernamev2, passwordv2;
        ifstream File("databasev2.txt");
        while (!File.eof())
        {
            getline(File, usernamev2, ' ');
            getline(File, passwordv2, '\n');
            if (usernamev2 == username)
            {
                return true;
            }
        }
        File.close();
        return false;
    }
    void user_register()
    {

        string username, password;
    front:
        system("cls");
        cout << "\t\t"
             << "+----------------------+" << endl;
        cout << "\t\t"
             << "|     Register User    |" << endl;
        cout << "\t\t"
             << "+----------------------+" << endl;
    name:
        cout << "- Nhap username: ";
        cin >> username;
        if (username == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto name;
        }
        else if (username.length() < 8)
        {
            cout << "\t\tUsername phai co 8 tu tro len. Nhap lai!\n";
            goto name;
        }
    pass:
        cout << "- Nhap password: ";
        cin >> password;
        if (password == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto pass;
        }
        else if (password.length() < 8)
        {
            cout << "\t\tPassword phai co 8 tu tro len. Nhap lai!\n";
            goto pass;
        }
        if (!valid_account(username, password))
        {
            ofstream File("databasev2.txt", ios::app);
            File << "\n"
                 << username << " " << password;
            File.close();
            cout << endl
                 << "\t\tDang ky thanh cong!" << endl;
            cout << "=> Nhan Enter de den trang chu !";
            cin.ignore();
            cin.get();
            ok = true;
            menuv2(username, password);
            return;
        }
        else
        {
            int chon;
            cout << "\n\t\tTai khoan da ton tai!\n";
            do
            {
                cout << "1. Dang ky.\n";
                cout << "2. Thoat!\n";
                cout << "Moi chon chuc nang: ";
                cin >> chon;
                switch (chon)
                {
                case 1:
                    goto back;
                case 2:
                    cout << "[2] : Thoat!\n";
                    cout << "\t\tBan chon thoat. Xin chao va hen gap lai!";
                    return;
                default:
                    cout << "\t\tNhap sai lua chon!\n";
                    break;
                }
            } while (chon != 2);
        }
    back:
        goto front;
    }
    void user_login()
    {
        string username, password;
    lg:
        system("cls");
        cout << "\t\t"
             << "+--------------------+" << endl;
        cout << "\t\t"
             << "|     Login User     |" << endl;
        cout << "\t\t"
             << "+--------------------+" << endl;
        cout << "\t\t[!] : Nhap R de dang ky tai khoan" << endl;
    name:
        cout << "- Nhap username: ";
        cin >> username;
        if (username == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto name;
        }
        else if (username == "R")
        {
            user_register();
        }
        if (ok)
            return;
        else if (username.length() < 8)
        {
            cout << "\t\tUsername phai co 8 tu tro len. Nhap lai!\n";
            goto name;
        }
    pass:
        cout << "- Nhap password: ";
        cin >> password;
        if (password == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto pass;
        }
        else if (password == "R")
            user_register();
        if (ok)
            return;
        else if (password.length() < 8)
        {
            cout << "\t\tPassword phai co 8 tu tro len. Nhap lai!\n";
            goto pass;
        }
        if (checkuser(username, password, "databasev2.txt"))
        {
            cout << "\n\t\tDang nhap thanh cong!\n";
            cout << "=> Nhan Enter de den trang chu !";
            cin.ignore();
            cin.get();
            ok2 = true;
            menuv2(username, password);
        }
        else
        {
            cout << "\n_____________________________________________";
            cout << "\n\t\tTai khoan hoac mat khau khong dung!\n\n";
            int chon;
            do
            {
                cout << "1. Nhap lai\n";
                cout << "2. Thoat!\n";
                cout << "3. Dang ky\n";
                cout << "Moi chon chuc nang: ";
                cin >> chon;
                switch (chon)
                {
                case 1:
                    cout << "[1] : Nhap lai\n";
                    cout << "\t\tBan chon nhap lai. Quay lai trang login!";
                    goto lg;
                    break;
                case 2:
                    cout << "[2] : Thoat!\n";
                    cout << "\t\tBan chon thoat! Xin chao va hen gap lai !\n";
                    break;
                case 3:
                    cout << "[3] : Dang ky tai khoan\n";
                    user_register();
                    break;
                default:
                    cout << "\t\tNhap sai lua chon!\n";
                    break;
                }
                return;
            } while (chon != 2);
        }
    }
};
int main()
{
    Admin key;
    key.admin_login();
    return 0;
}