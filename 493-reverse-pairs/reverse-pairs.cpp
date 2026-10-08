class Solution {
public:
    long long mergeAndCount(vector<int>& nums, int low, int mid, int high) {

    long long count = 0;

    // Count reverse pairs
    int i = low;

    for (int j = mid + 1; j <= high; j++) {

        while (i <= mid && nums[i] <= 2LL * nums[j]) {
            i++;
        }

        count += mid - i + 1;
    }

    // Normal merge
    vector<int> temp;

    int p = low;
    int q = mid + 1;

    while (p <= mid && q <= high) {

        if (nums[p] <= nums[q]) {
            temp.push_back(nums[p]);
            p++;
        }
        else {
            temp.push_back(nums[q]);
            q++;
        }
    }

    while (p <= mid) {
        temp.push_back(nums[p]);
        p++;
    }

    while (q <= high) {
        temp.push_back(nums[q]);
        q++;
    }

    // Copy back
    for (int k = low; k <= high; k++) {
        nums[k] = temp[k - low];
    }

    return count;
}


long long mergeSort(vector<int>& nums, int low, int high) {

    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(nums, low, mid);

    count += mergeSort(nums, mid + 1, high);

    count += mergeAndCount(nums, low, mid, high);

    return count;
}


long long reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}
};