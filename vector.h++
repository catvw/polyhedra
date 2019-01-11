#include <cstddef>
#include <cmath>
#include <ostream>
#include <type_traits>

/**
 * Simple vector class for my ridiculous polyhedron modeler.
 * 
 * @author Charles Van West
 */
template <int D>
class vector {
public:
    vector();
    
    template <typename... A>
    vector(const A...);
    
    /**
     * Accesses vector members by index.
     * 
     * @param the index
     */
    double& operator[](const std::size_t);
    const double& operator[](const std::size_t) const;
    
    /**
     * Gets the absolute value (length) of the vector.
     */
    double operator()() const;
    
    friend vector operator+(vector lh, const vector& rh);
    friend vector operator-(vector lh, const vector& rh);
private:
    struct flag { int index = 0; };
    
    template <typename T>
    vector(flag, const T);
    
    template <typename T,
              typename... A>
    vector(flag, const T, const A...);
    
    double v[D];
};

template <int D>
inline vector<D>::vector() {
    
}

template <int D>
template <typename... A>
inline vector<D>::vector(const A... args) {
    static_assert(sizeof...(A) == D, "error: invalid number of arguments to constructor");
    vector(flag(), args...);
}

template <int D>
template <typename T>
inline vector<D>::vector(flag f, const T next) {
    static_assert(std::is_arithmetic<T>::value, "error: T not an arithmetic type");
}

template <int D>
template <typename T,
          typename... A>
inline vector<D>::vector(flag f, const T next, const A... args) {
    static_assert(std::is_arithmetic<T>::value, "error: T not an arithmetic type");
    
    f.index += 1;
    vector(f, args...);
}

template <int D>
inline double& vector<D>::operator[](const std::size_t index) {
    return v[index];
}

template <int D>
inline const double& vector<D>::operator[](const std::size_t index) const {
    return v[index];
}

template <int D>
inline double vector<D>::operator()() const {
    return sqrt(v[0] * v[0] + v[1] * v[1]);
}

template <int D>
inline vector<D> operator+(vector<D> lh, const vector<D>& rh) {
    lh.v[0] += rh.v[0];
    lh.v[1] += rh.v[1];
    return lh;
}

template <int D>
inline vector<D> operator-(vector<D> lh, const vector<D>& rh) {
    lh.v[0] -= rh.v[0];
    lh.v[1] -= rh.v[1];
    return lh;
}

/**
 * Writes a vector to an ostream for easy printing.
 */
template <int D>
std::ostream& operator<<(std::ostream& os, const vector<D>& v) {
    os << '<' << v[0] << ", " << v[1] << '>';
    return os;
}

using vec2 = vector<2>;
