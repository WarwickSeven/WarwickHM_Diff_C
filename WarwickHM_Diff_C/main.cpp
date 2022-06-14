#include <iostream>
#include <vector>

class MyIter {
    std::vector<int> m_vec;
    int *m_begin;
    int *m_end;
public:
    MyIter(std::vector<int>& vec) : m_vec(vec) {
        m_begin = m_vec.empty() ? nullptr : &m_vec.front();
        m_end = m_begin + m_vec.size();
    }
    
    int* begin() {
        return m_begin;
    }
    
    int* end() {
        return m_end;
    }
    
    bool operator!= (int* rhs) {
        return m_begin != rhs;
    }
    
    auto operator++() -> int* {
        return ++m_begin;
    }
    
    int operator* () {
        return *m_begin;
    }
};
    
int main() {
    std::vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
    MyIter it1(v1);
    for (auto &i : it1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
