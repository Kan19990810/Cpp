class FrequencyTracker
{
private:
    static const int N = 100001;
    unordered_map<int, int> num_frequent;
    unordered_map<int, int> frequent_time;

public:
    FrequencyTracker() : num_frequent(N), frequent_time(N)
    {
    }

    void add(int number)
    {
        frequent_time[num_frequent[number]]--;
        num_frequent[number]++;
        frequent_time[num_frequent[number]]++;
    }

    void deleteOne(int number)
    {
        if (num_frequent[number] == 0)
        {
            return;
        }
        frequent_time[num_frequent[number]]--;
        num_frequent[number]--;
        frequent_time[num_frequent[number]]++;
    }

    bool hasFrequency(int frequency)
    {
        return frequent_time[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */