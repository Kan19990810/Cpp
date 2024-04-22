#include <string>
#include <charconv>
#include <iostream>
using namespace std;

int main()
{
    // {
    //     // 数值转换为字符串
    //     long long d = 3;
    //     string s = to_string(d);
    // }

    // {
    //     // 字符串转换为数值
    //     string s = "123abc";
    //     size_t index = 0;
    //     int value = stoi(s, &index);
    //     cout << value << endl;
    //     cout << s[index] << endl;
    // }

    {
        const size_t bufferSize = 50;
        string out(bufferSize, ' ');
        auto result = to_chars(out.data(), out.data() + out.size(), 12345);
    }
}