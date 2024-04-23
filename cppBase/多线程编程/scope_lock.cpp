#include <mutex>
using namespace std;

int main()
{
    mutex mtx1;
    mutex mtx2;
    scoped_lock locks(mtx1, mtx2);
}