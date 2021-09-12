#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <thread>
#include <queue>
#include <functional>
#include<stack>
#include <list>
#include <regex>



using namespace std;


// even numbers
int findNumbers(vector<int>& vec)
{

    int digits_count = 0;
    int even_count = 0;


    for (size_t i = 0; i < vec.size(); i++)
    {

        digits_count = log10(vec[i]) + 1;

        if (digits_count % 2 == 0)
        {
            even_count++;
        }

    }

    return even_count;

}


vector<int> sortedSquares(vector<int>& vec)
{

    for (size_t i = 0; i < vec.size(); ++i)
    {
        vec[i] *= vec[i];
    }

    sort(begin(vec), end(vec));

    return vec;

}


int findMaxConsecutiveOnes(vector<int>& vec)
{

    int count = 0;
    int res = 0;

    for (size_t i = 0; i < vec.size(); i++)
    {

        if (vec[i] == 1)
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 0;
        }

    }

    return res;

}


void duplicateZeros(vector<int>& vec)
{

    for (int i = 0; i < vec.size() - 1; ++i)
    {

        if (vec[i] == 0)
        {
            for (int j = vec.size() - 2; j > i; --j)
            {
                vec[j + 1] = vec[j];
            }

            vec[++i] = 0;
        }

    }


    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

}


int removeDuplicates(vector<int>& vec)
{

    set<int> s(vec.begin(), vec.end());
    vec.assign(s.begin(), s.end());

    return s.size();

}


bool checkIfExist(vector<int>& vec)
{

    return any_of(vec.begin(), vec.end(), [&](int)
        {
            for (size_t i = 0; i < vec.size(); i++)
            {
                for (size_t j = 0; j < vec.size(); j++)
                {
                    if (vec[i] == vec[j] * 2)
                    {
                        return true;
                    }
                }
            }

        });

}


int thirdMax(vector<int>& vec)
{

    vector<int>temp;

    sort(begin(vec), end(vec));
    vec.erase(unique(begin(vec), end(vec)), vec.end());


    if (vec.size() < 3)
    {
        return *max_element(begin(vec), end(vec));
    }


    for (int i = 0; i < 3; i++)
    {
        temp.push_back(*max_element(begin(vec), end(vec)));
        vec.erase(max_element(begin(vec), end(vec)));
    }

    cout << endl;

    return temp.back();

}


void reverseString(vector<char>& s)
{
    reverse(s.begin(), s.end());
}


int reverse(int x)
{

    string temp = to_string(x);
    int temp_int = x;


    reverse(temp.begin(), temp.end());

    x = atoi(temp.c_str());

    if (temp_int < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }

}


int firstUniqChar(string s)
{

    for (size_t i = 0; i < s.size(); i++)
    {

        bool found = true;

        for (size_t j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }

    }

    return -1;
}


bool isAnagram(string s, string t)
{

    sort(begin(s), end(s));
    sort(begin(t), end(t));

    return equal(begin(s), end(s), begin(t), end(t));

}


bool isPalindrome(string s)
{

    string temp;
    string temp2;

    string compared;


    copy_if(s.begin(), s.end(), back_inserter(temp), [](char c) { return isalnum(c); });
    //regex digit("[[:digit:]]"); 
   // temp = regex_replace(temp, digit, "");


    transform(temp.begin(), temp.end(), back_inserter(temp2), [](char c) {return ::tolower(c); });

    compared = temp2;

    reverse(compared.begin(), compared.end());

    return equal(temp2.begin(), temp2.end(), compared.begin(), compared.end());
}


int strStr(string haystack, string needle)
{
    size_t found = haystack.find(needle);

    return found;
}


int removeElement(vector<int>& vec, int val)
{
    vec.erase(remove_if(vec.begin(), vec.end(), [&](int x) { return x == val; }), vec.end());

    return vec.size();
}


void merge(vector<int>& test, vector<int>& test2)
{

    test.erase(remove_if(test.begin(), test.end(), [](int x) { return x == 0; }), test.end());
    test2.erase(remove_if(test2.begin(), test2.end(), [](int x) { return x == 0; }), test2.end());


    merge(test, test2);


    sort(test.begin(), test.end());

}


void moveZeroes(vector<int>& vec)
{
    int count = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != 0)
        {
            swap(vec[count++], vec[i]);
        }

    }

    for (auto& el : vec)
    {
        cout << el << " ";
    }

}


vector<int> sortArrayByParity(vector<int>& vec)
{

    sort(vec.begin(), vec.end(), [](int a, int b)
        {
            return a % 2 < b % 2;
        });



    return vec;
}


vector<string> fizzBuzz(int val)
{
    vector <string >temp;


    for (size_t i = 1; i <= val; i++)
    {
        switch (i % 15)
        {
        case 0:  temp.push_back("FizzBuzz"); break;

        case 5:
        case 10: temp.push_back("Buzz"); break;

        case 3:
        case 6:
        case 9:
        case 12:  temp.push_back("Fizz"); break;

        default:  temp.push_back(to_string(i)); break;
        }

    }

    return temp;
}


int countPrimes(int n)
{

    vector<bool> temp(n + 1, false);

    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (!temp[i])
        {

            count++;
            for (int j = i; j < n; j += i)
            {
                temp[j] = true;
            }

        }
    }

    return count;
}


double myPow(double x, int y)
{

    double temp;

    if (y == 0)
    {
        return 1;
    }

    temp = myPow(x, y / 2);


    if (y % 2 == 0)
    {
        return temp * temp;
    }
    else
    {

        if (y > 0)
        {
            return x * temp * temp;
        }
        else
        {
            return (temp * temp) / x;
        }

    }

}


int binaryStringToDecimal(string& str)
{

    string temp;

    copy_if(str.begin(), str.end(), back_inserter(temp), [](char c) {return isdigit(c); });
    temp.erase(remove_if(temp.begin(), temp.end(), [](char c) {return c != '1' && c != '0'; }), temp.end());

    return stoi(temp, 0, 2);

}


bool isIsomorphic(string s, string t)
{

    if (s.size() != t.size())
    {
        return false;

    }

    int len = s.size();

    int m1[256] = { 0 };
    int m2[256] = { 0 };



    for (int i = 0; i < len; i++)
    {

        if (m1[s[i]] != m2[t[i]])
            return false;

        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;

    }

    return true;
}


vector<int> twoSum(vector<int>& vec, int target)
{

    vector<int>res;

    int l = 0, r = vec.size() - 1;

    while (l < r)
    {
        if (vec[l] + vec[r] == target)
        {
            res.push_back(l + 1);
            res.push_back(r + 1);
        }

        else if ((vec[l] + vec[r]) < target)
        {
            ++l;

        }
        else
        {
            --r;
        }

        return res;

    }
}


int climbStairs(int val)
{

    int temp1 = 2, temp2 = 1;
    int number = 3, step;


    if (val == 1)
    {
        return 1;
    }

    if (val == 2)
    {
        return 2;
    }

   

    while (number <= val)
    {
        step = temp1 + temp2;
        temp2 = temp1;

        temp1 = step;
        number++;
    }

    return step;
}


void custom_str_reverse(string& str)
{

    for (size_t i = 0; i < str.size() / 2; i++)
    {
        swap(str[i], str[str.size() - i - 1]);
    }


    for (size_t i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
}


string reverseWords(string str)
{

    reverse(str.begin(), str.end());

    str.insert(str.end(), ' ');

    int j = 0;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ' ')
        {
            reverse(str.begin() + j, str.begin() + i);
            j = i + 1;
        }

    }

    str.pop_back();

    return str;

}


vector<int> bubblesort(vector<int>& vec)
{


    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < (vec.size() - i - 1); j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }


    return vec;
}




template <class some_type >
class UniqPtr
{
public:

    UniqPtr()
    {
        ptr = nullptr;
    }

    UniqPtr(some_type* ptr)
    {
        this->ptr = ptr;
    }

    ~UniqPtr()
    {
        delete ptr;
    }


    UniqPtr(UniqPtr&& ref)noexcept
    {
        ptr = ref.ptr;
        ref.ptr = nullptr;

    }

    UniqPtr& operator = (UniqPtr&& ref)
    {
        ptr = ref.ptr;
        ref.ptr = nullptr;

        return *this;
    }

    UniqPtr(const UniqPtr& ref) = delete;
    UniqPtr& operator = (const UniqPtr& ref) = delete;

private:
    some_type* ptr;


};







int main()
{
    





    return 0;
}

