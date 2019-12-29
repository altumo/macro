
#include <iostream>
using std::cout;
using std::endl;

#include "Macro.h"


int main( int argc, char** argv ){
	
	macro::Macro macro( argc, argv );

	macro.run();

}