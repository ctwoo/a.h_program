#include "../util.h"

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using std::string;

int main(int argc, char** argv) {

	char x = 'a';
	char result = to_hex(x);

    std::cout << result << std::endl;
    return 0;
}
