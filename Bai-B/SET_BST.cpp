// SETTING SET(STL) = BINARY SEARCH TREE
#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Node
{
    int val;
    Node *left;  // Lưu địa chỉ của node con bên trái
    Node *right; // Lưu địa chỉ của node con bên phải
};
template <class T>
Node<T> *makeNode(T x)
{
    Node<T> *newNode = new Node<T>(); // Allocate memory for the new node
    newNode->val = x;
    newNode->right = newNode->left = NULL;
    return newNode;
}
// 1. Thao tác tìm kiếm
template <class T>
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
template <class T>
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
template <class T>
Node<T> *minNode(Node<T> *root)
{ // Find node con min_element and > root
    Node<T> *tmp = root;
    while (tmp->left != NULL && tmp != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}
template <class T>
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
// browser and print
template <class T>
void inorder(Node<T> *root, string p = "\n")
{
    if (root != NULL)
    {
        cout << p << root->val;
        inorder(root->left, p + "\t");
        inorder(root->right, p + "\t");
    }
}
//----------------------------------------------
template <class T>
class VECTOR
{
    int n, cap; // n : size
    T *buf;
    // mở rộng kích thước của một mảng động.
    void expand(int new_cap)
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
            expand(cap * 2 + 1);
        buf[n++] = x;
    }
    void clear()
    {
        n = 0;
    }
    T &operator[](T key)
    {
        return buf[key];
    }
    typedef T *iterator;
    // định nghĩa 2 phương thức này để có thể sử dụng vòng lặp
    iterator begin() // trả về địa chỉ
    {
        return buf;
    }
    iterator end()
    {
        return buf + n;
    }
};
//----------------------------------------------
template <class T>
void add_value_toVECTOR(Node<T> *root, VECTOR<T> &v)
{
    if (root != NULL)
    {
        add_value_toVECTOR(root->left, v);
        v.push_back(root->val);
        add_value_toVECTOR(root->right, v);
    }
}
// tìm kiếm theo BST
// template <class T>
// T setting_lower_bound(Node<T> *root, T key)
// {
//     if(root == NULL) return 0;
// 	if(root->val == key) {
// 		return root->val;
// 	}
// 	if(root->val < key) return findBST(root->right,key);
// 	else {
// 		Node<T> *tmp = root;
// 		while(tmp->left != NULL && tmp != NULL){
// 			tmp = tmp->left;
// 		}
// 		return tmp->val;
// 	};
// }
// template <class T>
// T setting_upper_bound(Node<T> *root, T key)
// {
//     if(root == NULL) return 0;
// 	if(root->val < key) return findBST(root->right,key);
// 	else {
// 		Node<T> *tmp = root;
// 		while(tmp->left != NULL && tmp != NULL){
// 			tmp = tmp->left;
// 		}
// 		return tmp->val;
// 	};
// }

// Lomuto partition
template <class T>
T partition(VECTOR<T> &v, int l, int r)
{
    int pivot = v[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (v[j] <= pivot)
        {
            ++i;
            swap(v[j], v[i]);
        }
    }
    ++i;
    swap(v[i], v[r]);
    return i;
}
template <class T>
void quick_sort(VECTOR<T> &v, int l, int r)
{
    if (l < r)
    {
        int p = partition(v, l, r);
        quick_sort(v, l, p - 1);
        quick_sort(v, p + 1, r);
    }
}
template <class T>
T setting_lower_bound(VECTOR<T> &v, int l, int r, int key)
{
    T res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] >= key)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
template <class T>
T setting_upper_bound(VECTOR<T> &v, int l, int r, T key)
{
    T res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] > key)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
template<class T>
void CLEAR(Node<T> *&root)//phân bổ bộ nhớ và dọn dẹp các tài nguyên cây
{
    if (root)
    {
        CLEAR(root->left);
        CLEAR(root->right);
        delete root;
        root = nullptr;//tránh sử dụng địa chỉ bộ nhớ đã xóa
    }
}
template <class T>
struct SET
{
    Node<T> *root = NULL;
    int n;
    SET()
    {
        root = 0;
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
        if (!findBST(root, x))
        {
            ++n;
            add(root, x);
        }
    }
    void clear()
    {
        CLEAR(root);
        n = 0;
    }
    void erase(T x)
    {
        if (findBST(root, x))
        {
            --n;
            root = deleteNode(root, x);
        }
    }
    int count(T x)
    {
        if (findBST(root, x))
            return 1;
        return 0;
    }

    VECTOR<T> v;
    typedef typename VECTOR<T>::iterator iterator;
    iterator begin()
    {
        v.clear();
        add_value_toVECTOR(root, v);
        return v.begin();
    }
    iterator end()
    {
        return v.end();
    }
    iterator find(T x)
    {
            for (int i = 0; i < v.size(); ++i)
            {
                if (v[i] == x)
                    return v.begin() + i;
            }
        return v.end();
    }
    void erase(iterator it)// cùng tên hàm nhưng tham số truyền vào nó khác nên compiler sẽ biết mà phân biệt
    {
        erase(*it);
        --n;
    }
    iterator lower_bound(T key)
    {
        v.clear();
        add_value_toVECTOR(root, v);
        quick_sort(v, 0, n - 1);
        int x = setting_lower_bound(v, 0, v.size() - 1, key);
        if (x != -1)
            return v.begin() + x;
        else
            return v.end();
    }
    iterator upper_bound(T key)
    {
        v.clear();
        add_value_toVECTOR(root, v);
        quick_sort(v, 0, n - 1);
        int x = setting_upper_bound(v, 0, v.size() - 1, key);
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
    Node<int> *root = NULL;
    SET<int> A, B, C;
    readFile("A.txt", A);
    readFile("B.txt", B);
    readFile("C.txt", C);
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
        cout << x << " ";
    cout << endl;
    cout << *A.lower_bound(5) << endl;
    for (auto it = A.begin(); it != A.end(); ++it)
        cout << *it << " ";
}