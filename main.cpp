#include "header.h"

int main() {

    std::map<std::wstring, std::vector<int>> allwordsFinal;
    std::locale::global(std::locale("lt_LT.UTF-8"));
    std::string fileName = "input/article.txt";
    std::wifstream article(fileName);
    std::set<std::wstring> acceptableDomains;
    std::set<std::wstring> wordsWithTer;
    readingDomains("input/tlds-alpha-by-domain.txt", acceptableDomains); //reading acceptable domains from a file

    std::vector<std::wstring> URLtoPrint; //galejau ir i seta det kad nesikartotu
    article.imbue(std::locale()); //imbedding locale
    
    readingFile(fileName, allwordsFinal, URLtoPrint, acceptableDomains, wordsWithTer);

    std::wofstream out;
    out.imbue(std::locale());
    out.open("output/wordsTimes.txt");
    outputWordsCount(allwordsFinal, out);
    out.close();

    out.open("output/crossReference.txt");
    outputCrossReference(allwordsFinal, out);
    out.close();

    out.open("output/URL.txt");
    URLSprint(URLtoPrint, out);
    out.close();

    out.open("output/TER.txt");
    TERprint(wordsWithTer, out);
    out.close();
 
    return 0;
}



