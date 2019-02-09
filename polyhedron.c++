#include "polyhedron.h++"
#include <iostream> // debugging

polyhedron::polyhedron() : vs(nullptr) {
    // TODO
}

polyhedron::polyhedron(std::size_t size)
: v_count(size), vs(new vertex[size]) {
    std::cout << "created new polyhedron with " << size << " vertices."
              << std::endl;
}

polyhedron::polyhedron(const polyhedron&) {
    // TODO
}

polyhedron::~polyhedron() {
    delete[] vs;
    std::cout << "... and destroyed it." << std::endl;
}

std::size_t polyhedron::vertices() {
    return v_count;
}

void polyhedron::reallocate(std::size_t size) {
    delete[] vs;
    vs = new vertex[size];
    v_count = size;
}

/*----------------------------------------------------------------------------*/
polyhedron::vertex::vertex() : es(nullptr) { }

polyhedron::vertex::vertex(std::size_t size)
: es(new vertex*[size]), e_count(size) {
    std::cout << "vertex(std::size_t)" << std::endl;
}

polyhedron::vertex::~vertex() {
    delete[] es;
    std::cout << "~vertex()" << std::endl;
}


std::size_t polyhedron::vertex::edges() {
    return e_count;
}

void polyhedron::vertex::reallocate(std::size_t size) {
    delete[] es;
    es = new vertex*[size];
    e_count = size;
}
