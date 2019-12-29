#pragma once

#include <string>
using std::string;

namespace macro{

namespace ast{
	class Ast;
}

namespace parse{
	
	class MacroParser{

		ast::Ast parseFile( const string &filename );
		ast::Ast parse( const string &contents );

	};

}

}
