
#include "fixed.hpp"

int main(void) {

    Fixed a( 42.42f );
    Fixed b( 100 );

	std::cout << a + b << std::endl;
    return (0);
}