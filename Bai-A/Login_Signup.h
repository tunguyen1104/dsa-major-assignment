#pragma once
#include <bits/stdc++.h>
#include "StringManipulator.h"
#include "App.h"
using namespace std;
bool check_admin_or_user = false;   // check xem web đang ở tư cách admin hay người dùng
bool check_login = false;    // check xem đã đăng nhập vào web hay chưa
bool check_signup = false;     // check đăng ký
class Login_Signup : public app, public StringManipulator
{
public:
    bool checkuser(string username, string password, string filetxt)
    {
        string usernamev2, passwordv2;
        string fullname;
        ifstream File(filetxt);
        while (!File.eof())
        {
            getline(File, usernamev2, ' ');
            getline(File, passwordv2, ' ');
            getline(File, fullname, '\n');
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
    void admin_login() {
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
        else if (username == "T" || username == "t")
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
                cout << "1. LOGIN\n";
                cout << "2. SIGNUP\n";
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
        if (check_login || check_signup) // nếu đã vào menu rồi mà quay về đây thì chắc chắn là bạn đã chọn chức năng thoát
            return;
        else if (username.length() < 8)
        {
            cout << "\t\tUsername phai co 8 ky tu tro len. Nhap lai!\n";
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
        else if (username == "T" || username == "t")
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
                cout << "1. LOGIN\n";
                cout << "2. SIGNUP\n";
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
        if (check_login || check_signup) // nếu đã vào menu rồi mà quay về đây thì chắc chắn là bạn đã chọn chức năng thoát
            return;
        else if (password.length() < 8)
        {
            cout << "\t\tPassword phai co 8 ky tu tro len. Nhap lai!\n";
            goto pass;
        }

        if (checkuser(username, password, "./file_txt/database.txt"))
        {
            cout << "\n\t\tDang nhap thanh cong!";
            check_admin_or_user = true;
            menu_admin();
        }
        else
        {
            cout << "\n\t\tTai khoan hoac mat khau khong dung!\n";
            cout << "_____________________________________________\n";
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
                    user_login();
                    break;
                default:
                    cout << "\t\tNhap sai lua chon!\n";
                    cout << "=> Nhan Enter de tro ve !";
                    cin.ignore();
                    cin.get();
                    break;
                }
                if (check_signup)
                    return;
            } while (chon != 2);
        }
    }
    bool valid_account(string username, string password)
    {
        string usernamev2, passwordv2, fullname;
        ifstream File("./file_txt/databasev2.txt");
        while (!File.eof())
        {
            getline(File, usernamev2, ' ');
            getline(File, passwordv2, ' ');
            getline(File, fullname, '\n');
            if (usernamev2 == username) // chỉ check tài khoản
            {
                return true;
            }
        }
        File.close();
        return false;
    }
    void user_register() {
        string username, password, fullname;
    front:
        system("cls");
        cout << "\t\t"
             << "+----------------------+" << endl;
        cout << "\t\t"
             << "|     Register User    |" << endl;
        cout << "\t\t"
             << "+----------------------+" << endl;
    name:
        cout << "- Nhap username (Ma sinh vien): ";
        cin >> username;
        if (username == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto name;
        }
        else if (username.length() < 8)
        {
            cout << "\t\tUsername phai co 8 ky tu tro len. Nhap lai!\n";
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
            cout << "\t\tPassword phai co 8 ky tu tro len. Nhap lai!\n";
            goto pass;
        }
        else
        {
            bool a[3] = {false, false, false};
            for (char c : password)
            {
                if (isdigit(c))
                {
                    a[0] = true;
                }
                if ('a' <= c && c <= 'z')
                {
                    a[1] = true;
                }
                if ('A' <= c && c <= 'Z')
                {
                    a[2] = true;
                }
                if (a[0] && a[1] && a[2])
                    break;
            }
            for (bool x : a)
            {
                if (x == false)
                {
                    cout << "\t\tPassword phai co day du cac ky tu a-z, A-Z, 0-9. Nhap lai!\n";
                    goto pass;
                }
            }
        }
        if (!valid_account(username, password))
        {
            cin.ignore();
        fulln:
            cout << "- Nhap ten cua ban: ";
            getline(cin, fullname);
            if (fullname == "")
            {
                cout << "\t\tKhong duoc de trong. Nhap lai!\n";
                goto fulln;
            }
            else if (fullname.length() < 8)
            {
                cout << "\t\tFullname phai co 8 ky tu tro len. Nhap lai!\n";
                goto fulln;
            }
            fullname = standardization(fullname);
            ofstream File("./file_txt/databasev2.txt", ios::app);
            File << "\n"
                 << username << " " << password << " " << fullname;
            File.close();
            cout << endl
                 << "\t\tDang ky thanh cong!" << endl;
            cout << "=> Nhan Enter de den trang chu !";
            cin.ignore();
            cin.get();
            check_signup = true;
            menu_user(username, password, fullname);
            return;
        }
        else
        {
            int chon;
            cout << "\n\t\tTai khoan da ton tai!\n";
            cout << "__________________________________" << endl;
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
        cout << "\t[!] : Nhap R de dang ky tai khoan" << endl;
    name:
        cout << "- Nhap username: ";
        cin >> username;
        if (username == "")
        {
            cout << "\t\tKhong duoc de trong. Nhap lai!\n";
            goto name;
        }
        else if (username == "R" || username == "r")
        {
            user_register();
        }
        if (check_signup)
            return;
        else if (username.length() < 8)
        {
            cout << "\t\tUsername phai co 8 ky tu tro len. Nhap lai!\n";
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
        else if (password == "R" || password == "r")
            user_register();
        if (check_signup)
            return;
        else if (password.length() < 8)
        {
            cout << "\t\tPassword phai co 8 ky tu tro len. Nhap lai!\n";
            goto pass;
        }
        else
        {
            bool a[3] = {false, false, false};
            for (char c : password)
            {
                if (isdigit(c))
                {
                    a[0] = true;
                }
                if ('a' <= c && c <= 'z')
                {
                    a[1] = true;
                }
                if ('A' <= c && c <= 'Z')
                {
                    a[2] = true;
                }
                if (a[0] && a[1] && a[2])
                    break;
            }
            for (bool x : a)
            {
                if (x == false)
                {
                    cout << "\t\tPassword phai co day du cac ky tu a-z, A-Z, 0-9. Nhap lai!\n";
                    goto pass;
                }
            }
        }
        // nhập đúng định dạng xong thì đến bước check data
        bool check = false;
        string usernamev2, passwordv2;
        string fullname;
        ifstream File("./file_txt/databasev2.txt");
        while (!File.eof())
        {
            getline(File, usernamev2, ' ');
            getline(File, passwordv2, ' ');
            getline(File, fullname, '\n');
            if (usernamev2 == username && passwordv2 == password)
            {
                check = true;
                break;
            }
        }
        File.close();
        if (check)
        {
            cout << "\n\t\tDang nhap thanh cong!\n";
            cout << "=> Nhan Enter de den trang chu !";
            cin.ignore();
            cin.get();
            check_login = true;
            menu_user(username, password, standardization(fullname));
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