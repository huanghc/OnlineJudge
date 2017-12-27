vector<int> arraymax(vector<int> nums, int k) {
    while (nums.size() > k) {
        int  n = nums.size();
        for (i=0; i<n-1; ++i) {
            if (nums[i] < nums[i + 1]) {
                nums.erase(nums.begin() + i); //remove this digit with index i
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
    vector<int> merg(k, 0);
    int i = 0, j = 0, t = 0; 
    for (t = 0; t < k; ++t) {
    	if (compare(nums1, i, nums2, j) == 1){  //nums1 > nums22
    		merg[t] = nums1[i];++i;    //merge into the merg
		}
		else merg[t] = nums2[j];++j;    
    }
    return merg;
}

vector<int> maxKtwoArray(vector<int>& nums1, vector<int>& nums2, int m, int n, int k) {
    vector<int> merg(k, 0);

    for (int i = max(0, k - n); i <= min(k, m); ++i) {
        vector<int> v1 = arraymax(nums1, i);
        vector<int> v2 = arraymax(nums2, k - i);
        vector<int> tmp = merge(v1, v2, k);
        if (compare(tmp, 0, merg, 0)) merg = tmp;
    }

    return merg;
}
