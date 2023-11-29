// SETTING SET(STL) = BINARY SEARCH TREE
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
public:
    T val;
    Node *left;  // Lưu địa chỉ của node con bên trái
    Node *right; // Lưu địa chỉ của node con bên phải

    Node<T> *makeNode(T x)
    {
        Node<T> *newNode = new Node<T>(); // Allocate memory for the new node
        newNode->val = x;
        newNode->right = newNode->left = NULL;
        return newNode;
    }

    // 1. Thao tác tìm kiếm
    bool findBST(Node<T> *root, T key)
    {
        if (root == NULL)
            return false;
        if (root->val == key)
            return true;
        else if (root->val < key)
            return findBST(root->right, key);
        else
            return findBST(root->left, key);
    }

    // 2.Thao tác chèn
    void add(Node<T> *&root, T key)
    {
        if (root == NULL)
        {
            root = makeNode(key);
            return;
        }
        if (root->val < key)
            add(root->right, key);
        else
            add(root->left, key);
    }

    // 3.Thao tác xóa
    Node<T> *minNode(Node<T> *root)
    {
        // Find node con min_element and > root
        Node<T> *tmp = root;
        while (tmp->left != NULL && tmp != NULL)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
    Node<T> *deleteNode(Node<T> *root, T key)
    {
        if (root == NULL)
            return root;
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                Node<T> *temp = root->right;
                delete root; // thu hoi vung root nay
                return temp;
            }
            else if (root->right == NULL)
            {
                Node<T> *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node<T> *temp = minNode(root);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

    void CLEAR(Node<T> *&root) // giải phóng bộ nhớ và dọn dẹp các tài nguyên cây
    {
        if (root != nullptr)
        {
            CLEAR(root->left);
            CLEAR(root->right);
            delete root;
            root = nullptr; // tránh sử dụng địa chỉ bộ nhớ đã xóa
        }
    }
};

template <class T>
class VECTOR
{
    int n, cap; // n : size, cap : capacity
    T *buf;     // buffer

    // mở rộng kích thước của một mảng động.
    void auto_resize(int new_cap)
    {
        if (new_cap < cap)
            return;
        T *tem = buf;
        cap = new_cap;
        buf = new T[cap]; // tạo mảng mới
        for (int i = 0; i < n; i++)
            buf[i] = tem[i];
        if (tem)
            delete[] tem;
    }

public:
    VECTOR()
    {
        n = cap = 0;
        buf = NULL;
    }
    ~VECTOR()
    {
        if (buf)
            delete[] buf;
    }
    void swap(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
    int size()
    {
        return n;
    }
    void push_back(T x)
    {
        if (n == cap)
            auto_resize(cap * 2 + 1);
        buf[n++] = x;
    }
    void clear()
    {
        n = 0;
    }
    T &operator[](T index)
    {
        return buf[index];
    }
    typedef T *iterator;
    iterator begin()
    {
        return buf;
    }
    iterator end()
    {
        return buf + n;
    }
    // Duyệt cây rồi thêm value các node vào VECTOR
    void add_value_toVECTOR(Node<T> *root)
    {
        if (root != NULL)
        {
            add_value_toVECTOR(root->left);
            push_back(root->val);
            add_value_toVECTOR(root->right);
        }
    }
    T partition(int l, int r)
    {
        int pivot = buf[r];
        int i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (buf[j] <= pivot)
            {
                ++i;
                swap(buf[j], buf[i]);
            }
        }
        ++i;
        swap(buf[i], buf[r]);
        return i;
    }
    void quick_sort(int l, int r)
    {
        if (l < r)
        {
            int p = partition(l, r);
            quick_sort(l, p - 1);
            quick_sort(p + 1, r);
        }
    }

    T setting_lower_bound(int l, int r, int key)
    {
        T res = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (buf[mid] >= key)
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }

    T setting_upper_bound(int l, int r, T key)
    {
        T res = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (buf[mid] > key)
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }
};
template <class T>
class SET
{
public:
    Node<T> *root = nullptr;
    int n;
    SET()
    {
        root = nullptr;
        n = 0;
    }
    int size()
    {
        return n;
    }
    bool empty()
    {
        return n == 0;
    }
    void insert(T x)
    {
        if (!root || !root->findBST(root, x))
        {
            ++n;
            root->add(root, x);
        }
    }
    void clear()
    {
        root->CLEAR(root);
        n = 0;
    }
    void erase(T x)
    {
        if (root->findBST(root, x))
        {
            --n;
            root = root->deleteNode(root, x);
        }
    }
    int count(T x)
    {
        if (root->findBST(root, x))
            return 1;
        return 0;
    }

    VECTOR<T> v;
    typedef typename VECTOR<T>::iterator iterator;
    iterator begin()
    {
        v.clear();
        v.add_value_toVECTOR(root);
        return v.begin();
    }
    iterator end()
    {
        return v.end();
    }
    //Tìm kiếm key và trả về kiểu iterator
    iterator find(T key)
    {
        v.clear();
        v.add_value_toVECTOR(root);
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] == key)
                return v.begin() + i;
        }
        return v.end();
    }
    // cùng tên hàm nhưng tham số truyền vào nó khác nên compiler sẽ biết mà phân biệt
    void erase(iterator it)
    {
        erase(*it);
        --n;
    }
    iterator lower_bound(T key)
    {
        v.clear();
        v.add_value_toVECTOR(root);
        v.quick_sort(0, n - 1);
        int x = v.setting_lower_bound(0, v.size() - 1, key);
        if (x != -1)
            return v.begin() + x;
        else
            return v.end();
    }
    iterator upper_bound(T key)
    {
        v.clear();
        v.add_value_toVECTOR(root);
        v.quick_sort(0, n - 1);
        int x = v.setting_upper_bound(0, v.size() - 1, key);
        if (x != -1)
            return v.begin() + x;
        else
            return v.end();
    }
};
void readFile(string file, SET<int> &A)
{
    int a;
    ifstream File(file);
    if (!File.is_open())
    {
        cout << "Error: " << file << " not found" << endl;
        return;
    }
    while (!File.eof())
    {
        File >> a;
        A.insert(a);
        File.ignore(1, ' ');
    }
    File.close();
}
int main()
{
    SET<int> A, B, C;
    readFile("A.txt", A);//1 2 3 4 5 8
    readFile("B.txt", B);//5 4 11 56 0
    readFile("C.txt", C);//20 2 10 3 7 12 4
    for(int x: A)
        cout << x << " ";
    cout << endl;
    for(int x: B)
        cout << x << " ";
    cout << endl;
    for(int x: C)
        cout << x << " ";
    cout << endl;
    for (int x : B)
    {
        A.insert(x);
    }
    for (int x : A)
    {
        if (C.count(x))
        {
            A.erase(x);
        }
    }
    for (int x : A)
        cout << x << " ";//0 1 5 8 11 56 
}
