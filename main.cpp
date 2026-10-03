#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThree {
private:
    long long sum_ = 0;
    int count_ = 0;

public:
    void operator()(int value) {
        if (value % 3 == 0) {
            sum_ += value;
            ++count_;
        }
    }

    long long get_sum() const { return sum_; }
    int get_count() const { return count_; }
};

int main() {
    std::vector<int> numbers;
    int value;

    while (std::cin >> value) {
        numbers.push_back(value);
    }

    DivisibleByThree counter = std::for_each(numbers.begin(), numbers.end(), DivisibleByThree());

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}
