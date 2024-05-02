class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // heapsort
        int heapsize = nums.size();
        buildheap(nums, heapsize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i)
        {
            swap(nums[0], nums[i]);
            --heapsize;
            maxheap(nums, 0, heapsize);
        }
        return nums[0];
    }

    void buildheap(vector<int> &nums, int heapsize)
    {
        for (int i = heapsize / 2; i >= 0; --i)
        {
            maxheap(nums, i, heapsize);
        }
    }

    void maxheap(vector<int> &nums, int idx, int heapsize)
    {
        int l = 2 * idx + 1, r = 2 * idx + 2, largest = idx;
        if (l < heapsize && nums[l] > nums[largest])
        {
            largest = l;
        }
        if (r < heapsize && nums[r] > nums[largest])
        {
            largest = r;
        }
        if (largest != idx)
        {
            swap(nums[idx], nums[largest]);
            maxheap(nums, largest, heapsize);
        }
    }
};