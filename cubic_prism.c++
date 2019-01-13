#include "vector.t++"

#include <iostream>
#include <cmath>
#include <cstdlib> // std::strtod()

// using vec2 = vector<2>;
using vec3 = vector<3>;

constexpr const double π = 3.141592653589793;

constexpr double deg(double rad) {
    return rad * 180 / π;
}

constexpr double rad(double deg) {
    return deg * π / 180;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "arguments: <angle of twist> <height of prism>"
                  << std::endl;
        return 1;
    }
    
    double phi = rad(std::strtod(argv[1], nullptr));
    double height = std::strtod(argv[2], nullptr);
    
    vec3 Pl(-1, 0, 0);
    vec3 Q0(-1, 0, 1);
    vec3 Q1(-1, 0, -1);
    
    vec3 Ph(std::cos(phi), 0, std::sin(phi));
    vec3 H(0, height, 0);
    
    vec3 E = Pl + Ph + H;
    
    double theta0 = std::acos((E * Q0) / (E() * Q0()));
    double theta1 = std::acos((E * Q1) / (E() * Q1()));
    
    std::cout << "theta0 = " << deg(theta0) << '\n'
              << "theta1 = " << deg(theta1) << '\n'
              << "|E| / |Q0| = " << (E() / Q0()) << std::endl;
    
    return 0;
}
