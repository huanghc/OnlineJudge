vector<int> maxVector(vector<int> nums, int k) {
    while (nums.size() > k) {
        int i = 0, n = nums.size();
        for (; i < n - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                nums.erase(nums.begin() + i);
                break;
            }
        }
        if (i == n - 1) nums.erase(nums.begin() + i);
    }

    return nums;
}

bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
        ++i;
        ++j;
    }
    if (i < nums1.size() && nums1[i] > nums2[j])  //num2<num1
	or (j == nums2.size())                        //num2 empty
	{
		return true;
	} 
    else return false;
}

vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> res(k, 0);
    for (int i = 0, j = 0, r = 0; r < k; ++r) {
        res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    }

    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> res(k, 0);

    for (int i = max(0, k - n); i <= min(k, m); ++i) {
        auto v1 = maxVector(nums1, i);
        auto v2 = maxVector(nums2, k - i);
        auto tmp = merge(v1, v2, k);
        if (compare(tmp, 0, res, 0)) res = tmp;
    }

    return res;
}
