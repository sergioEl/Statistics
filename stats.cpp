#include "../std_lib_facilities.h"

// seokho han 201761541
// ass2_q1
/* 
 find mode, range, and mean of a vector of real numers.
 using struct containing mode, range, and mean.

 b) Using a structure enables a programmer to control attributes more efficiently.
    Also, passing a structure can be done more quickly than passing all attributes
    when using reference args.

 c) Passing large structures will result in increment of memory and slowing the system.
*/


struct Stats
{
    double range;
    double mean;
    double mode;
};

Stats getStats(vector<double>& v)
{
    Stats s1 = {0, 0, v[0]};
    double mean = 0, range = 0, mode = v[0];
    double min, max, sum = 0;
    int count = 1;
    int tempCount = 1;
    double lastNum = v[0];

    min = *min_element(v.begin(), v.end());//find range 
    max = *max_element(v.begin(), v.end());
    range = max - min;
    s1.range = range;

   // cout << "range: " << range << endl;
    for (double n : v)// find mean
    {
        sum += n;
    }
    mean = sum / v.size();
    s1.mean = mean;
   // cout << "mean: " << mean << endl;

    for (int i = 1; i < v.size(); i++)// find mode
    {
        if (lastNum == v[i])
        {
            ++ count;
        }
        else
        {
            if (tempCount < count)
            {
                tempCount = count;
                mode = lastNum;
            }
            lastNum = v[i];
            count = 1;
        }
    }
    s1.mode = mode;
  //  cout << "mode: " << mode << endl;
    return s1;
}

double getMode(vector<double>& v)// find mode
{

    int count = 1;
    int tempCount = 1;
    double lastNum = v[0];
    double mode = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (lastNum == v[i])
        {
            ++ count;
        }
        else
        {
            if (tempCount < count)
            {
                tempCount = count;
                mode = lastNum;
            }
            lastNum = v[i];
            count = 1;
        }
    }
    return mode;
}

double getMean(vector<double>& v)// find mean
{
    double sum = 0, mean = 0;

    for (double n : v)
    {
        sum += n;
    }
    mean = sum / v.size();
    return mean;
}

double getRange(vector<double>& v)//find range 
{
    double min = *min_element(v.begin(), v.end());
    double max = *max_element(v.begin(), v.end());
    double range = max - min;
    return range;
}

Stats getStats2(vector<double>& v)
{
    Stats s3 = {0, 0, v[0]};

    s3.mode = getMode(v);
    s3.mean = getMean(v);
    s3.range =getRange(v);

    return s3;
}

int main()
{
    vector<double> v = {3, 4 ,3, 3, 3, 9, 10.21, 100};

    cout << "getStats() called\n";
    Stats s2 = getStats(v);

    cout << "mode: " << s2.mode << endl;
    cout << "mean: " << s2.mean << endl;
    cout << "range: " << s2.range << endl;

    cout << "getStats2() called\n";
    Stats s4 = getStats2(v);

    cout << "mode: " << s4.mode << endl;
    cout << "mean: " << s4.mean << endl;
    cout << "range: " << s4.range << endl;


    return 0;
}