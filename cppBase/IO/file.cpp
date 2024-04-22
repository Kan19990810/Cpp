#include <fstream>

using namespace std;

int main()
{
    fstream outFile{"test.txt"};
    for (int i = 0; i < 10; i++)
    {
        outFile << i << endl;
    }
    outFile.close();
}