#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

int n, q, in, begin, end, i, j, val_end, val_begin, count, val;
int main(){

    for(std::cin >> n >> q; n != 0 && std::cin.good(); std::cin >> n >> q){
        std::vector<int> values(n);
        std::unordered_map< int, std::pair<int, int> > map;
        begin = 0;
        std::cin >> in;
        values[0] = in;

        for(end =1; end < n; end++) {
            std::cin >> in;

            values[end] = in;
            if(values[end] != values[end-1]) {
                map.emplace(values[end-1], std::pair<int, int>(begin, end));
                begin = end;
            }
        }

        map.emplace(values[end-1], std::pair<int, int>(begin, end));
        while(q--) {
            std::cin >> i >> j;
            val_end = i, val_begin = i, count = 0;

            while(val_end < j) {
                val_end = (map.find(values[val_begin])->second).second;
                if(val_end > j)
                    val_end = j;
                if(val_end - val_begin > count)
                    count = val_end - val_begin;
                val_begin = val_end;
            }

            std::cout << count << std::endl;
        }
    }
}

