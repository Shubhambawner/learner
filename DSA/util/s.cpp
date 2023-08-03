#include <iostream>
#include <cxxabi.h>
#include <cstdlib>
#include <memory>
#include <bits/stdc++.h>
using namespace std;


string demangle(const char* mangledName) {
    int status = -1;

    // Demangle the mangled name using abi::__cxa_demangle.
    char* demangledNameCStr = abi::__cxa_demangle(mangledName, nullptr, nullptr, &status);

    string demangledName;
    if (status == 0) {
        // If demangling was successful, copy the result to a C++ string.
        demangledName = demangledNameCStr;
        free(demangledNameCStr); // Free the memory allocated by abi::__cxa_demangle.
    } else {
        // If demangling failed, set the original mangled name as the result.
        demangledName = mangledName;
    }

    return demangledName;
}

// finds wether type of stl container being passed(i.e. T) is nested(contains any other container inside)
template <class T>
string getType(T t){
	const char *type_of_t = typeid(t).name();	 // returned raw type of t, https://en.cppreference.com/w/cpp/types/type_info/name
	string r = demangle(type_of_t); // converted type_of_t to human redable form
	// cout<<dep(r)<<endl;
	return r;
}

int main() {
    // Example usage:
    vector<string> s;
    cout<<getType(s);
    return 0;
}
