//Å£¿ÍÍø¡ª¡ªÎ¢ÐÅºì°ü
#include<vector>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here

        vector<int> count(100001);

        for (int i = 0; i < n; ++i)
        {
            count[gifts[i]]++;
        }

        for (int i = 0; i < n; ++i)
        {
            if (count[gifts[i]] >= n / 2)
            {
                return gifts[i];
            }
        }
        return 0;
    }
};