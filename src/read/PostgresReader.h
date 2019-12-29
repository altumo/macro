#pragma once

#include <string>
using std::string;



namespace macro{

namespace ast{
	class Ast;
}

namespace read{
	
	class PostgresReader{

		ast::Ast read( const string &connection_string );

	};

}

}
