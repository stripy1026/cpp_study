#include <iostream>
#include <vector>

int main()
{
    int size;
    int num;
    std::cin >> size;
    std::vector<int> v;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> num;
        v.push_back(num);
    }
    std::vector<int>::iterator iter;
    int min = v[0];
    int max = v[0];
    for (iter = v.begin(); iter != v.end(); ++iter)
    {
        min = *iter < min ? *iter : min;
        max = *iter > max ? *iter : max;
    }
    std::cout << min << " " << max << std::endl;
    return (0);
}
