#include "ghassert.h"
#include <iostream>

using std::cerr;
using std::endl;
void __GH_ASSERT(const char* exp_str, bool exp, const char* file, int line, const char* msg) {
	if (!exp) {
		cerr << "Assert failed:\t" << msg << '\n'
			<< "Source:\t" << file << ", line: " << line << endl;
		abort();
	}
	
}