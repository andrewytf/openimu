/*
 * headers.h
 *
 *  Created on: 30/07/2014
 *      Author: root
 */

#ifndef HEADERS_H_
#define HEADERS_H_

//Utilities library
#include <cstdlib> //	General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search
#include <csignal> //	Functions and macro constants for signal management
#include <csetjmp> //	Macro (and function) that saves (and jumps) to an execution context
#include <cstdarg> //	Handling of variable length argument lists
#include <typeinfo> //	Runtime type information utilities
#include <typeindex> // (since C++11)	std::type_index
#include <type_traits> // (since C++11)	Compile-time type information
#include <bitset> //	std::bitset class template
#include <functional> //	Function objects, designed for use with the standard algorithms
#include <utility> //	Various utility components
#include <ctime> //	C-style time/date utilites
#include <chrono> // (since C++11)	C++ time utilites
#include <cstddef> //	typedefs for types such as size_t, NULL and others
#include <initializer_list> // (since C++11)	std::initializer_list class template
#include <tuple> // (since C++11)	std::tuple class template
//Dynamic memory management
#include <new> //	Low-level memory management utilities
#include <memory> //	Higher level memory management utilities
//#include <scoped_allocator> // (since C++11)	Nested allocator class
//Numeric limits
#include <climits> //	limits of integral types
#include <cfloat> //	limits of float types
#include <cstdint> // (since C++11)	fixed-size types and limits of other types
#include <cinttypes> // (since C++11)	formatting macros , intmax_t and uintmax_t math and conversions
#include <limits> //	standardized way to query properties of fundamental types
//Error handling
#include <exception> //	Exception handling utilities
#include <stdexcept> //	Standard exception objects
#include <cassert> //	Conditionally compiled macro that compares its argument to zero
#include <system_error> // (since C++11)	defines std::error_code, a platform-dependent error code
#include <cerrno> //	Macro containing the last error number
//Strings library
#include <cctype> //	functions to determine the type contained in character data
#include <cwctype> //	functions for determining the type of wide character data
#include <cstring> //	various narrow character string handling functions
#include <cwchar> //	various wide and multibyte string handling functions
//#include <cuchar> // (since C++11)	C-style Unicode character conversion functions
#include <string> //	std::basic_string class template
//Containers library
#include <array> // (since C++11)	std::array container
#include <vector> //	std::vector container
#include <deque> //	std::deque container
#include <list> //	std::list container
#include <forward_list> // (since C++11)	std::forward_list container
#include <set> //	std::set and std::multiset associative containers
#include <map> //	std::map and std::multimap associative containers
#include <unordered_set> // (since C++11)	std::unordered_set and std::unordered_multiset unordered associative containers
#include <unordered_map> // (since C++11)	std::unordered_map and std::unordered_multimap unordered associative containers
#include <stack> //	std::stack container adaptor
#include <queue> //	std::queue and std::priority_queue container adaptors
//Algorithms library
#include <algorithm> //	Algorithms that operate on containers
//Iterators library
#include <iterator> //	Container iterators
//Numerics library
#include <cmath> //	Common mathematics functions
#include <complex> //	Complex number type
#include <valarray> //	Class for representing and manipulating arrays of values
#include <random> // (since C++11)	Random number generators and distributions
#include <numeric> //	Numeric operations on values in containers
#include <ratio> // (since C++11)	Compile-time rational arithmetic
#include <cfenv> // (since C++11)	Floating-point environment access functions
//Input/output library
#include <iosfwd> //	forward declarations of all classes in the input/output library
#include <ios> //	std::ios_base class, std::basic_ios class template and several typedefs
#include <istream> //	std::basic_istream class template and several typedefs
#include <ostream> //	std::basic_ostream, std::basic_iostream class templates and several typedefs
#include <iostream> //	several standard stream objects
#include <fstream> //	std::basic_fstream, std::basic_ifstream, std::basic_ofstream class templates and several typedefs
#include <sstream> //	std::basic_stringstream, std::basic_istringstream, std::basic_ostringstream class templates and several typedefs
//#include <strstream> //	std::strstream, std::istrstream, std::ostrstream(deprecated)
#include <iomanip> //	Helper functions to control the format or input and output
#include <streambuf> //	std::basic_streambuf class template
#include <cstdio> //	C-style input-output functions
//Localization library
#include <locale> //	Localization utilities
#include <clocale> //	C localization utilities
//#include <codecvt> // (since C++11)	Unicode conversion facilities
//Regular Expressions library
#include <regex> // (since C++11)	Classes, algorithms and iterators to support regular expression processing
//Atomic Operations library
#include <atomic> // (since C++11)	Atomic operations library
//Thread support library
#include <thread> // (since C++11)	std::thread class and supporting functions
#include <mutex> // (since C++11)	mutual exclusion primitives
//#include <shared_mutex> // (since C++14)	shared mutual exclusion primitives
#include <future> // (since C++11)	primitives for asynchronous computations
#include <condition_variable> // (since C++11)	thread waiting conditions
//C compatibility headers
#include <ciso646> //	empty header. The macros that appear in iso646.h in C are keywords in C++
#include <ccomplex> // (since C++11)	simply includes the header #include <complex> //
#include <ctgmath> // (since C++11)	simply includes the headers #include <ccomplex> // and #include <cmath> //: the overloads equivalent to the contents of the C header tgmath.h are already provided by #include <cmath> // and #include <complex> //
//#include <cstdalign> // (since C++11)	defines one compatibility macro constant
#include <cstdbool> // (since C++11)	defines one compatibility macro constant
//Deprecated headers
#include <assert.h> // (deprecated)	behaves as if each name from #include <cassert> // is placed in global namespace
#include <complex.h> // (deprecated)	behaves as if each name from #include <ccomplex> // is placed in global namespace
#include <ctype.h> // (deprecated)	behaves as if each name from #include <cctype> // is placed in global namespace
#include <errno.h> // (deprecated)	behaves as if each name from #include <cerrno> // is placed in global namespace
#include <fenv.h> // (deprecated)	behaves as if each name from #include <cfenv> // is placed in global namespace
#include <float.h> // (deprecated)	behaves as if each name from #include <cfloat> // is placed in global namespace
#include <inttypes.h> // (deprecated)	behaves as if each name from #include <cinttypes> // is placed in global namespace
#include <iso646.h> // (deprecated)	behaves as if each name from #include <ciso646> // is placed in global namespace
#include <limits.h> // (deprecated)	behaves as if each name from #include <climits> // is placed in global namespace
#include <locale.h> // (deprecated)	behaves as if each name from #include <clocale> // is placed in global namespace
#include <math.h> // (deprecated)	behaves as if each name from #include <cmath> // is placed in global namespace
#include <setjmp.h> // (deprecated)	behaves as if each name from #include <csetjmp> // is placed in global namespace
#include <signal.h> // (deprecated)	behaves as if each name from #include <csignal> // is placed in global namespace
//#include <stdalign.h> // (deprecated)	behaves as if each name from #include <cstdalign> // is placed in global namespace
#include <stdarg.h> // (deprecated)	behaves as if each name from #include <cstdarg> // is placed in global namespace
#include <stdbool.h> // (deprecated)	behaves as if each name from #include <cstdbool> // is placed in global namespace
#include <stddef.h> // (deprecated)	behaves as if each name from #include <cstddef> // is placed in global namespace
#include <stdint.h> // (deprecated)	behaves as if each name from #include <cstdint> // is placed in global namespace
#include <stdio.h> // (deprecated)	behaves as if each name from #include <cstdio> // is placed in global namespace
#include <stdlib.h> // (deprecated)	behaves as if each name from #include <cstdlib> // is placed in global namespace
#include <string.h> // (deprecated)	behaves as if each name from #include <cstring> // is placed in global namespace
#include <tgmath.h> // (deprecated)	behaves as if each name from #include <ctgmath> // is placed in global namespace
#include <time.h> // (deprecated)	behaves as if each name from #include <ctime> // is placed in global namespace
//#include <uchar.h> // (deprecated)	behaves as if each name from #include <cuchar> // is placed in global namespace
#include <wchar.h> // (deprecated)	behaves as if each name from #include <cwchar> // is placed in global namespace
#include <wctype.h> // (deprecated)	behaves as if each name from #include <cwctype> // is placed in global namespace




#endif /* HEADERS_H_ */
