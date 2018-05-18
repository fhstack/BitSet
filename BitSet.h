#pragma once
#include <vector>
#include <iostream>
using namespace std;

class BitSet
{
public:
    BitSet(size_t num)
    {
        _v.resize(num/8 + 1);
    }
    void Set(const size_t data)
    {
        size_t index = data/8;
        size_t pos = data % 8;
        char tmp = 1;
        _v[index] |= (tmp<<pos);
    }
    void ReSet(const size_t data)
    {
        size_t index = data/8;
        size_t pos = data%8;
        char tmp = 1;
        _v[index] &= (~(tmp<<pos));
    }
    bool Test(const size_t data)
    {
        size_t index = data/8;
        size_t pos = data%8;
        char tmp = 1;
        if(_v[index] & (tmp<<pos))
            return true;
        else
            return false;
    }
protected:
    vector<char> _v;
};

void TestMyBitSet()
{
    BitSet bt(9);
    bt.Set(7);
    bt.Set(100);
    bt.Set(77);
    bt.Set(76);
    bt.Set(78);
    bt.Set(79);
    bt.Set(80);
    bt.Set(101);
    cout<<"Test"<<endl;
    cout<<bt.Test(100)<<endl;
    cout<<bt.Test(102)<<endl;

    
}
