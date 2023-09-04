#include<bits/stdc++.h>//Don't use it just submit the class solution
using namespace std;//Just submit the class solution in leetcode 
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int change = 0, num_of_five = 0, num_of_ten = 0;
        if (bills[0] > 5)
        {
            return false;
        }
        else if (bills[0] == 5)
        {
            change += 5;
            num_of_five++;
        }
        for (int i = 1; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                change += 5;
                num_of_five++;
            }
            else if ((bills[i] == 10 || bills[i] == 20) && num_of_five == 0)
            {
                return false;
            }
            else if (bills[i] == 10)
            {
                if (change < (bills[i] - 5))
                    return false;
                else
                {
                    num_of_five--;
                    change += 5;
                    num_of_ten++;
                }
            }
            else if (bills[i] == 20)
            {
                if (change >= 15 && num_of_five >= 1)
                {
                    if (num_of_ten >= 1)
                    {
                        num_of_ten--;
                        num_of_five--;
                        change += 5;
                    }
                    else if (num_of_five >= 3)
                    {
                        num_of_five -= 3;
                        change += 5;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }

        return true;
    }
};