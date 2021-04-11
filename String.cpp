// 实现一个字符串类
#include <cassert>
#include <cstring>
#include <iostream>
#include <iterator>
using namespace std;

class String {
  public:
    String();                             // 构造函数
    String(const char *str);              // 全缺省构造函数
    String(const String &str);            // 全缺省构造函数
    String &operator=(const String &str); // 赋值函数
    ~String();                            // 析构函数

    // 容量部分
    size_t capacity();
    size_t size();
    bool empty();
    void reserve(size_t newCapacity);
    void resize(size_t newSize, char c = '\0');

    // 迭代器部分
    iterator begin();
    iterator end();
    const_iterator cbegin() const {}
    const_iterator cend() const {}

    // 修改部分
    String &insert(size_t pos, char c);
    String &insert(size_t pos, const char *str);
    String &erase(size_t pos, size_t len = npos);
    void push_back(char c);
    void pop_back();
    String &operator+=(char c);
    String &operator+=(const char *str);
    void append(char c);
    void append(const char *str);
    void clear();
    void swap(String &str);

    // 元素访问部分
    char &operator[](size_t index);
    const char &operator[](size_t index) const;

    // 关系运算符
    bool operator==(const String &s);
    bool operator!=(const String &s);
    bool operator<(const String &s);
    bool operator<=(const String &s);
    bool operator>(const String &s);
    bool operator>=(const String &s);

    // 字符串操作
    const char *c_str() const;
    size_t find(char c, size_t pos = 0) const;
    size_t find(const char *c, size_t pos = 0) const;

    // IO 部分
    friend std::istream &operator>>(std::ostream &_cin, String &s);
    friend std::ostream &operator<<(std::ostream &_cout, const String &s);

  private:
    size_t m_size;
    size_t m_capacity;
    char *m_str;
    static size_t npos;
};

size_t String::npos = -1;

// 构造函数
String::String(const char *str = "")
    : m_size(strlen(str)), m_capacity(m_size), m_str(new char[m_size + 1]) {
    strcpy(m_str, str);
}

// 全缺省构造函数
String::String(const String &str) : m_size(0), m_capacity(0), m_str(nullptr) {
    String temp(str.m_str);
    swap(temp);
}

// 全缺省赋值函数
String &String::operator=(const String &str) {
    String temp(str.m_str);
    swap(temp);
    return *this;
}

// 析构函数
String::~String() {
    m_size = 0;
    m_capacity = 0;
    delete[] m_str;
    m_str = nullptr;
}

// 容量部分 =========================================
size_t String::capacity() { return m_capacity; }

size_t String::size() { return m_size; }

bool String::empty() { return !m_size; }

void String::resize(size_t newSize, char c = '\0') {
    // 如果size不够，扩容
    if (m_size < newSize) {
        if (m_capacity < newSize) {
            String::reserve(newSize);
        }
        // 将多出来的空间全部初始化为 c
        memset(m_str + m_size, c, newSize - m_size);
    }
    // 当空间够的时候，直接截断字符串
    m_size = newSize;
    m_str[m_size] = '\0';
}

// 重新分配 capacity
void String::reserve(size_t newCapacity) {
    if (m_capacity >= newCapacity) {
        return;
    }

    char *str = new char[newCapacity + 1];
    strcpy(str, m_str);
    delete[] m_str;

    m_str = str;
    m_capacity = newCapacity;
}

// 迭代器部分 =========================================
iterator String::begin() { return m_str; }

iterator String::end() { return m_str + m_size; }

const_iterator String::cbegin() const { return m_str; }

const_iterator String::cend() const { return m_str + m_size; }

// 修改部分 =========================================
String String::insert(size_t pos, char c) {
    assert(pos < m_size);

    if (m_capacity == m_size) {
        size_t newCapacity = (m_capacity == 0) ? 2 : 2 * m_capacity;
        reverse(newCapacity);
    }
    // 数据后移
    for (size_t i = m_size; i > pos; --i) {
        m_str[i] = m_str[i - 1];
    }
    m_str[pos] = c;
    m_str[++m_size] = '\0';
    return *this;
}

String &String::insert(size_t pos, const char *str) {
    assert(pos < m_size);

    size_t size = strlen(str);
    // 检查容量，不够就扩容
    if (m_size + size < m_capacity) {
        reserve(m_size + size);
    }
    // 数据后移 size 个位置
    for (size_t i = m_size + size - 1; i > pos + size - 1; --i) {
        m_str[i] = m_str[i - size];
    }
    // 拷贝数据到 pos 位置
    memcpy(m_str + pos, str, size);
    m_size += size;
    m_str[size] = '\0';
    return *this;
}

String &String::erase(size_t pos, size_t len = npos) {
    // 如果pos位置后面没有len长的数据，就直接从pos位置截断，删除后面所有数据
    if (len >= m_size - pos) {
        m_str[pos] = '\0';
        m_size = pos;
    } else {
        // 从pos位置删除数据
        for (size_t i = pos + len; i <= m_size; ++i) {
            m_str[i - len] = m_str[i];
        }
    }
    m_size -= len;
    m_str[m_size] = '\0';
    return *this;
}

void String::push_back(char c) {
    if (m_size == m_capacity) {
        size_t newCapacity = (newCapacity == 0) ? 2 : 2 * m_capacity;
        reverse(newCapacity);
    }
    m_str[m_size++] = c;
    m_str[m_size] = '\0';
}

void String::pop_back() { m_str[--m_size] = '\0'; }

void String::append(char c) { push_back(c); }

void String::append(const char *str) {
    size_t size = strlen(str);
    // 检查容量，不够就扩容
    if (m_size + size > m_capacity) {
        reserve(m_size + size);
    }
    // 尾部追加字符串
    strcpy(m_str + m_size, str);
    m_size += size;
}

String &String::operator+=(char c) {
    push_back(c);
    return *this;
}

String &String::operator+=(const char *str) {
    append(str);
    return *this;
}

void String::clear() {
    m_size = 0;
    m_str[m_size] = '\0';
}

void String::swap(String &s) {
    std::swap(m_str, s.m_str);
    std::swap(m_size, s.m_size);
    std::swap(m_capacity, s.m_capacity);
}

// 元素访问部分 =========================================
char &String::operator[](size_t index) {
    assert(index < m_size);

    return m_str[index];
}

const char &String::operator[](size_t index) const {
    assert(index < m_size);

    return m_str[index];
}

// 关系运算符 =========================================
bool String::operator==(const String &s) {
    if (strcmp(m_str, s.m_str) == 0) {
        return true;
    } else {
        return false;
    }
}

bool String::operator!=(const String &s) { return !(*this == s); }

bool String::operator<(const String &s) {
    if (strcmp(m_str, s.m_str) == -1) {
        return true;
    } else {
        return false;
    }
}

bool String::operator<=(const String &s) { return (*this < s) || (*this == s); }

bool String::operator>(const String &s) { return !(*this <= s); }

bool String::operator>=(const String &s) { return !(*this < s); }

// 字符串操作
const char *String::c_str() const { return m_str; }

size_t String::find(char c, size_t pos = 0) const {
    assert(pos < m_size);

    size_t i = pos;
    while (i < m_size) {
        if (m_str[i] == c) {
            return i;
        }
        ++i;
    }
    return npos;
}

size_t String::find(const char *str, size_t pos = 0) const {
    const char *src = m_str;
    const char *sub = str;

    while (*src) {
        // 如果两个位置匹配，则继续遍历
        while (*src == *sub && *sub) {
            ++src;
            ++sub;
        }
        // 如果 sub 走完就说明完全匹配，返回 sub 第一次出现的位置
        if ('\0' == *sub) {
            return (src - m_str - strlen(str));
        } else { // 不匹配则回溯，继续匹配下一个位置
            sub = str;
            src = ++src;
        }
    }
    return npos;
}

std::istream &operator>>(std::istream &in, String &s) {
    // 直接用 cin 输入进 str 会有无法扩容的问题，需要手动扩容
    while (true) {
        char ch;
        ch = in.get();
        // 遇到分隔符则暂停
        if (ch == '\n' || ch == ' ') {
            break;
        } else {
            s.push_back(ch);
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    out << s.m_str;
    return out;
}