#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int minSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    int minLength = INT_MAX;
    int left = 0;
    int sum = 0;

    for (int right = 0; right < n; right++)
    {
        sum += nums[right];

        while (sum >= k)
        {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = minSubarrayLength(nums, k);
    cout << result << endl;

    return 0;
}
//3429