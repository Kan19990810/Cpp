#include <iostream>
#include <fstream>
#include <string_view>
#include <string>
#include <vector>
using namespace std;

class namedb
{
public:
    namedb(string_view namefile)
    {
        ifstream inputfile{namefile.data()};
        if (!inputfile)
        {
            throw invalid_argument{"unable to open file"};
        }

        string name;
        while (inputfile >> name)
        {
            if (nameexists(name))
            {
                incrementnamecount(name);
            }
            else
            {
                addnewname(name);
            }
        }
    }
    int getnamerank(string_view name) const
    {
        int num{getabsolutenumber(name)};
        if (num == -1)
        {
            return -1;
        }
        int rank{1};
        for (auto &entry : mnames)
        {
            if (entry.second > num)
            {
                ++rank;
            }
        }
        return rank;
    }
    int getabsolutenumber(string_view name) const
    {
        for (auto &entry : mnames)
        {
            if (entry.first == name)
            {
                return entry.second;
            }
        }
        return -1;
    }

private:
    vector<pair<string, int>> mnames;
    bool nameexists(string_view name) const
    {
        for (auto &entry : mnames)
        {
            if (entry.first == name)
            {
                return true;
            }
        }
        return false;
    }
    void incrementnamecount(string_view name)
    {
        for (auto &entry : mnames)
        {
            if (entry.first == name)
            {
                ++entry.second;
                return;
            }
        }
    }
    void addnewname(string_view name)
    {
        mnames.push_back(make_pair(name.data(), 1));
    }
};

int main()
{
    namedb boys{"boys_long.txt"};
    cout << boys.getnamerank("daniel") << endl;
    cout << boys.getnamerank("jacob") << endl;
    cout << boys.getnamerank("williiam") << endl;
}