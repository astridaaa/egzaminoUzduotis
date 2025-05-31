#include "header.h"

//issiaiskinti kodel viena whitespace vistiek ima 
int main() {

    std::map<std::wstring, std::vector<int>> allwordsFinal;
    std::locale::global(std::locale("lt_LT.UTF-8"));
    std::string fileName = "article.txt";
    std::wifstream article(fileName);
    
    std::vector<std::wstring> beleka;
    article.imbue(std::locale()); //cia applyina locale standarta cj kad gerai coutintu
    
    readingFile(fileName, allwordsFinal, beleka);

    std::wofstream out;
    out.imbue(std::locale());
    out.open("wordsTimes.txt");
    outputWordsCount(allwordsFinal, out);
    out.close();

    out.open("crossReference.txt");
    outputCrossReference(allwordsFinal, out);
    out.close();
 
    return 0;}
