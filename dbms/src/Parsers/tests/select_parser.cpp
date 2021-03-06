#include <iostream>

#include <DB/Parsers/ParserSelectQuery.h>
#include <DB/Parsers/parseQuery.h>
#include <DB/Parsers/formatAST.h>
#include <DB/Parsers/parseQuery.h>


int main(int argc, char ** argv)
{
	using namespace DB;

	std::string input =
		" SELECT 18446744073709551615, f(1), '\\\\', [a, b, c], (a, b, c), 1 + 2 * -3, a = b OR c > d.1 + 2 * -g[0] AND NOT e < f * (x + y)"
		" FROM default.hits"
		" WHERE CounterID = 101500 AND UniqID % 3 = 0"
		" GROUP BY UniqID"
		" HAVING SUM(Refresh) > 100"
		" ORDER BY Visits, PageViews"
		" LIMIT 1000, 10";

	ParserSelectQuery parser;
	ASTPtr ast = parseQuery(parser, input.data(), input.data() + input.size(), "");

	std::cout << "Success." << std::endl;
	formatAST(*ast, std::cerr);
	std::cout << std::endl;
	std::cout << std::endl << ast->getTreeID() << std::endl;

	return 0;
}
