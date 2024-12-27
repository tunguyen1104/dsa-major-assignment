#pragma once
#include <bits/stdc++.h>
using namespace std;
class StringManipulator
{
public:
    /*! Kẻ bảng, căn giữa chuỗi */
    string center(const string s, const int width)
    {
        stringstream ss, spaces;
        int padding = width - s.size(); // đếm phần thừa để căn
        for (int i = 0; i < padding / 2; ++i)
            spaces << " ";
        ss << spaces.str() << s << spaces.str(); // format with padding

        // nếu padding là số lẻ thì thêm 1 dấu cách vào sau cùng ss.
        if (padding > 0 && padding % 2 != 0)
            ss << " ";
        return ss.str();
    }

    int size_number(int s) // tìm số lượng chữ số của s
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

    string convert(string s)
    {
        s[0] = toupper(s[0]);
        for (int i = 1; i < s.size(); ++i)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    }

    string standardization(string s1)
    {
        stringstream ss(s1); // Khởi tạo stringstream từ xâu s1
        vector<string> res;
        string tmp;
        // Đọc lần lượt các phần của xâu. Các phần tách nhau bởi dấu cách
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

    string convertv2(string s)
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

    string convert_date(string s)
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

    // lấy thời gian thực-----------------------------
    string get_time()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    }

    string get_day()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return convert_date(to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) +
                            "/" + to_string(1900 + ltm->tm_year));
    }
};