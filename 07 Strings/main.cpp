#include <iostream>

#include <iostream>
#include <string>
#include <regex>

int main() {

    /* string */

    std::string h = "hello";
    std::string b = "bye";
    std::cout << h + b << std::endl; // -> hellobye

    std::string s = "hello, world!";
    std::cout << s[0] << std::endl; // -> h
    std::cout << s.substr(7, 5) << std::endl; // -> world

    std::string t = s;
    t.replace(7, 5, "le monde");
    std::cout << t << std::endl; // -> hello, le monde!
    std::cout << s << std::endl; // -> hello, world!

    std::string u = s;
    u.replace(7, 5, "世界");
    std::cout << u << std::endl; // -> hello, 世界!

    for (auto c : s) {
        std::cout << c << std::endl; // -> every char chars
    }

    /* regex */

    std::string c = "abracadabra";

    std::regex r {".*a.?a.*"};
    bool o = regex_match(c, r);
    std::cout << o << std::endl; // -> 1

    r = ("a.?a");
    o = regex_search(c, r);
    std::cout << o << std::endl; // -> 1

    r = ("a.?a");
    std::string ss = regex_replace(c, r, "mmm");
    std::cout << ss << std::endl; // -> abrmmmdabra

    return 0;
}