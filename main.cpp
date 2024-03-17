#include <iostream>

int main() {
    std::cout << std::endl;
    std::cout << "end" << std::endl;
    return 0;
}

//t1
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int n=0;
    n=v.size();
    for (int i=0; i<n; i++) {
        v.push_back(v[i]);
    }
}
//t2
template <typename Iter>
Iter Unique(Iter first, Iter last){
    if (first == last)
        return last;

    Iter result = first;
    while (++first != last)
        if (!(*result == *first) && ++result != first)
            *result = std::move(*first);

    return ++result;
}

//t3
template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2, OutIter out)
{
    while (first1 != last1)
    {
        if (first2 == last2)
            return std::copy(first1, last1, out);

        if (*first1 < *first2)
            *out++ = *first1++;
        else
        {
            if (! (*first2 < *first1))
                ++first1;
            ++first2;
        }
    }
    return out;
}
//t4
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr1[i];
    }

    for (int i = 0; i < k; ++i) {
        int num;
        std::cin >> num;

        auto it = std::lower_bound(arr1.begin(), arr1.end(), num);
        if (it == arr1.begin()) {
            std::cout << *it << std::endl;
        } else if (it == arr1.end()) {
            std::cout << *(it - 1) << std::endl;
        } else {
            if (std::abs(num - *(it - 1)) <= std::abs(num - *it)) {
                std::cout << *(it - 1) << std::endl;
            } else {
                std::cout << *it << std::endl;
            }
        }
    }

    return 0;
}
//t5
#include <algorithm>
#include <vector>

template <typename T>
void Process(const std::vector<T>& data) {
    std::vector<T> filtered;

    std::copy_if(
            data.begin(),
            data.end(),
            std::back_inserter(filtered),
            [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());
}