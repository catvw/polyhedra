#ifndef POLYHEDRON_TXX
#define POLYHEDRON_TXX

#include "vector.t++"

#include <cstddef>
// #include <initializer_list>

/**
 * "Look--it's a polyhedron!"
 * 
 * @author Charles Van West
 */
class polyhedron {
public:
    using vector_t = vector<3>;
    
    /**
     * Constructs an empty polyhedron.
     */
    polyhedron();
    
    /**
     * Constructs a polyhedron with n vertices.
     */
    polyhedron(std::size_t);
    
    /**
     * Constructs a polyhedron with list.size() vertices, each initialized with
     * the given number of connected edges.
     */
    // polyhedron(std::initializer_list<std::size_t>);
    
    polyhedron(const polyhedron&);
    polyhedron(polyhedron&&) = default;
    ~polyhedron();
    
    /**
     * Gets the number of vertices.
     */
    std::size_t vertices();
    
    /**
     * Reallocates the number of vertex slots.
     */
    void reallocate(std::size_t);
    
private:
    /**
     * Non-obvious invariant: adjacent vertices in the edges array represent
     * adjacent edges in the physical polyhedron.
     */
    class vertex {
    public:
        /**
         * Constructs an empty vertex.
         */
        vertex();
        
        /**
         * Constructs an empty vertex with n connected-edge slots.
         */
        vertex(std::size_t);
        
        /**
         * Gets the number of edges.
         */
        std::size_t edges();
        
        /**
         * Reallocates the number of edge slots.
         */
        void reallocate(std::size_t);
        
        vertex(const vertex&) = delete;
        vertex(vertex&&) = delete;
        ~vertex();
        
    private:
        std::size_t e_count;
        vector_t p;
        vertex** es;
    };
    
    std::size_t v_count;
    vertex* vs;
};

#endif
