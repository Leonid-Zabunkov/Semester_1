#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

const int L = 10;
const int MAX_BLOCK_NO = 30000;

void process_requests(std::istream& in, std::ostream& out) {
    std::set<int> free_blocks;
    for (int i = 1; i <= MAX_BLOCK_NO; ++i) {
        free_blocks.insert(i);
    }

    std::map<int, int> busy_blocks;
    
    int time;
    char type_char;
    int block_no;

    while (in >> time >> type_char) {
        // Освобождение старых блоков
        auto it = busy_blocks.begin();
        while (it != busy_blocks.end() && it->second <= time) {
            free_blocks.insert(it->first);
            it = busy_blocks.erase(it);
        }

        if (type_char == '+') {
            int new_block_no = *free_blocks.begin();
            free_blocks.erase(free_blocks.begin());
            busy_blocks[new_block_no] = time + L;
            out << new_block_no << std::endl;
        } else if (type_char == '.') {
            in >> block_no;
            if (busy_blocks.count(block_no)) {
                busy_blocks[block_no] = time + L;
                out << "+" << std::endl;
            } else {
                out << "-" << std::endl;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    process_requests(std::cin, std::cout);
}