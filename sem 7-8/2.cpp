#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <unordered_set>
#include <vector>

struct MyStruct {
    int int_;
    double double_;
    bool operator==(const MyStruct other) const {
        return int_ == other.int_ && double_ == other.double_;
    }
};

double fRand()
{
    double f = (double)rand() / RAND_MAX;
    return f * (1e9);
}

MyStruct getRandStruct() {
    MyStruct my_struct;
    my_struct.int_ = rand();
    my_struct.double_ = fRand();
    return my_struct;
}

int hash_value(const MyStruct & value) noexcept
{
    return value.int_;
}

struct MyStruct_Hash
{
    std::size_t operator() (const MyStruct & my_struct) const noexcept
    {
        return hash_value(my_struct);
    }
};

int get_count_collisions(const std::unordered_set < MyStruct, MyStruct_Hash > & unordered_set)
{
    int cnt = 0;
    for (auto index = 0U; index != unordered_set.bucket_count(); ++index)
    {
        int cnt_ = 0;

        for (auto iterator = unordered_set.begin(index);
             iterator != unordered_set.end(index); ++iterator)
        {
            ++cnt_;
        }
        cnt += std::max(0, cnt_ - 1);
    }

    return cnt;
}

int main() {
    std::unordered_set < MyStruct, MyStruct_Hash > u_set;

    for (int i = 0; i < 1e5; ++i) {
        u_set.insert(getRandStruct());
    }
    std::cout << get_count_collisions(u_set);

    return 0;
}