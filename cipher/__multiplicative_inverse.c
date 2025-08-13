
#include "logic.h"

#include "math.h"

double __multiplicative_inverse( const double n, const double base, const double exponent ) {
    return mutliplinv( exp( pow( base, exponent ) * ln( n ) ) );
}