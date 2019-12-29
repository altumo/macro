#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;


namespace macro{

	class Macro{
		
		public:
			Macro( int argc, char** argv );

			void run();

	};

}