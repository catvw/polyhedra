#include "polyhedron.t++"

using poly3 = polyhedron<3>;

int main(int argc, char** argv) {
    poly3 poly(20);
    
    vector<3> v1;
    vector<3> v2;
    v1.cross(v2);
    
    vector<2> v3;
    vector<2> v4;
    v3.cross(v4);
    
    return 0;
}
