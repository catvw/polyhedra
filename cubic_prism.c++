#include "vector.t++"

#include <iostream>
#include <string> // std::stod()

using vec2 = vector<2>;
using vec3 = vector<3>;

int main(int argc, char** argv) {
    vec2 v1(1.5, 2.75);
    vec2 v2(1.5, 2.25);
    vec2 v3 = v1 + v2;
    vec3 v4(0.99, 0.8, 0.7);
    vec3 v5(1, 0, 0);
    
    std::cout << v1 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v3() << std::endl;
    std::cout << (v4 + v5) << std::endl;
    
    return 0;
}
