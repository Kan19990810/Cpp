#include <mutex>
#include <condition_variable>

using namespace std;

class RWlock
{
private:
    mutex mtx;
    condition_variable rcond;
    condition_variable wcond;
    int readwaiting;
    int reading;
    int writewaiting;
    int writing;

public:
    RWlock() : readwaiting(0), writewaiting(0), reading(0), writing(0) {}

    void RLock()
    {
        unique_lock<mutex> locker(mtx);
        readwaiting++;
        rcond.wait(locker, [&]()
                   { return writing == 0; });
        readwaiting--;
        reading++;
    }

    void RUnlock()
    {
        unique_lock<mutex> locker(mtx);
        reading--;
        if (reading == 0)
        {
            wcond.notify_all();
        }
    }

    void WLock()
    {
        unique_lock<mutex> locker(mtx);
        writewaiting++;
        wcond.wait(locker, [&]()
                   { return reading == 0 && readwaiting == 0 && writing == 0; });
        writewaiting--;
        writing++;
    }

    void WUnlock()
    {
        unique_lock<mutex> locker(mtx);
        writing--;
        rcond.notify_one();
    }
};