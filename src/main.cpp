#include "analyzer.h"

void testFunc()
{
    string grammarPath = "../assets/grammar.txt";
    string lexPath = "../assets/lex.txt";
    Analyzer analyzer(grammarPath);
    ifstream infile(lexPath);

    if (!infile)
    {
        cerr << "Error: could not open file \"" << lexPath << "\" for reading.\n";
        std::exit(1);
    }

    analyzer.log << "-------------原本语法如下---------------" << '\n';
    analyzer.printGrammers();
    analyzer.dealGrammers();
    analyzer.log << "-------------去除左递归后---------------" << '\n';
    analyzer.printGrammers();
    analyzer.simplify();
    analyzer.log << "-------------去除多余项后---------------" << '\n';
    analyzer.printGrammers();
    analyzer.dealLeftCommonGrammers();
    analyzer.log << "-------------去除左公因子后---------------" << '\n';
    analyzer.printGrammers();
    analyzer.makeFirst();
    analyzer.makeFollow();
    analyzer.makeTable();

    string lex;
    while(getline(infile, lex))
    {
        vector<string> tokens = splitString(lex, " ");;
        analyzer.analyzer(tokens);
    }

//    string sentence = "if(0) if(1) other else other";
//    analyzer.analyzer(sentence);
//    analyzer.log.close();
}

int main()
{
    testFunc();
    return 0;
}