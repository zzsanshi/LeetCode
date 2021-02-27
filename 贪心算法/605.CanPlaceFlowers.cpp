#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

// 注意这里的原来中的花也要遵守不能两个挨到一起的规则
// 这个写法就是老老实实的遍历判断，填坑赋值
bool canPlaceFlowers_v1(vector<int> &flowerbed, int n)
{
    auto i = flowerbed.begin();
    while(i!=flowerbed.end()&&n>0){
        if(i == flowerbed.begin()&&(!*i)&&(!(*(i+1)))){
            n--;
            *i=1;
        }
        else if(i == flowerbed.end()-1&&(!*i)&&(!(*(i-1)))){
            n--;
            *i=1;
        }
        else if((!(*(i+1)))&&(!(*(i-1)))&&(!(*i))){
            n--;
            *i=1;
        }
        i++;
    }
    return n <= 0;
}

// 16ms 19.5mb
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    // 本题最少也要有一个for循环对数组进行一次遍历，本方法是通过一种跳跃的方式不需要完整的遍历一边数组
    // 首先直接拿变量n做结束控制，使用不同的判断条件进行跳跃查询而不是用查询赋值再查询的策略
    for (int i = 0; i < flowerbed.size() && n > 0;)
    {
        // 当查找到这个位置种花了，这就能得到这个位置不能种了，下一个位置也不能种，所以跳两个格子
        if (flowerbed[i])
        {
            i += 2;
        }
        // 没中花且这个位置能中华的两件就是下面两个，但是这个地方种了花，下个地方就不能种了，所以跳两个格子
        else if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)
        {
            i += 2;
            n--;
        }
        // 没中花且不能种花代表了下一个坑位是跳到下三个坑，因为+2虽然那个位置肯定没花，但也肯定不能种
        else
        {
            i += 3;
        }
    }

    return n <= 0;
}
int main(){
    vector<int> a{1,0,0,0,0,0,1};
    cout<<canPlaceFlowers_v1(a,2);
}