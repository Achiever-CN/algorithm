#include <iostream>
using namespace std;
#include <vector>


vector<int> bitmap_sort(vector<int> arr)
{
        int min_val = arr[0];
        int max_val = arr[0];
        for(auto i : arr)
        {
                min_val = min(i, min_val);
                max_val = max(i, max_val);
        }
        vector<int> bitmap(max_val - min_val + 1, 0);
        for(auto i : arr)
        {
                bitmap[i-min_val] ++;
        }

        arr.clear();
        for(int i = 0; i < bitmap.size(); ++i)
        {
                while(bitmap[i] > 0)
                {
                        arr.push_back(i+min_val);
                        -- bitmap[i];
                }
        }
        return arr;
}


int main(void)
{
        vector<int> arr = {10,9,8,7,6,5,4,3,2,1};
        arr = bitmap_sort(arr);
        for(auto i : arr)
        {
                cout << i << " ";
        }
        return 0;
}
