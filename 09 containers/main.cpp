#include <iostream>

#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

struct Entry {
    std::string name;
    int number;
};

struct CustomHashAOrNot {
    size_t operator()(const std::string key) const {
        return (key == "a");
    }
};

int main() {

    /* vector */

    std::vector<int> v{1, 2, 3};
    std::cout << v[3] << std::endl; // -> bs, no exception, no crash

    try {
        std::cout << v.at(3) << std::endl; // -> out of range exception
    } catch (std::exception) {
        std::cout << "exception" << std::endl;
    }

    /* list */

    std::list<Entry> book = {
            {"a", 123},
            {"b", 456},
            {"c", 789},
    };

    std::list<Entry>::iterator entry;
    int i = 0;
    for (auto p = book.begin(); p != book.end(); ++p) {
        if (i == 1) {
            entry = p;
        }
        i++;
    }
    std::cout << entry->name << std::endl; // -> b

    Entry entry2 = {"z", 999};
    book.insert(entry, entry2);
    for (auto e : book) {
        std::cout << e.name << std::endl; // -> a, z, b, c
    }

    /* map */

    std::map<std::string, int> m = {
            {"a", 123},
            {"b", 456},
            {"c", 789}, // c++ does not complain about trailing comma
    };

    std::cout << m["b"] << std::endl; // -> 456
    std::cout << m["x"] << std::endl; // -> 0

    auto search = m.find("x2"); // don't check "x", it was created above when trying to access it
    if (search != m.end()) {
        std::cout << search->second << std::endl; //
    } else {
        std::cout << "not found" << std::endl; // -> not found
    }

    /* unordered_map */

    std::unordered_map<std::string, int> um = {
            {"a", 123},
            {"b", 456},
            {"c", 789},
    };
    std::cout << um["b"] << std::endl; // -> 456
    std::cout << um["x"] << std::endl; // -> 0

    std::cout << CustomHashAOrNot()("a") << std::endl;
    std::cout << CustomHashAOrNot()("b") << std::endl;
    std::cout << CustomHashAOrNot()("c") << std::endl;
    std::unordered_map<std::string, int, CustomHashAOrNot> um2 = {
            {"a", 123},
            {"b", 456},
            {"c", 789},
    };
    std::cout << um2["a"] << std::endl; // -> 123
    std::cout << um2["b"] << std::endl; // -> 456
    std::cout << um2["c"] << std::endl; // -> 789



    return 0;
}