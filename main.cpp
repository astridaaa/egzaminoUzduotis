
    /*
    naudoti maps ir imt zodi kaip key ir tada pair kai vektoriu ir i ji deti visas eilutes kuriose kartojasi zodis ir tada
     jo lenght paimt pirmai uzduociai o antrai uzduociai galiu paimt ir tsg coutint 
    vektoriu i rten bus visos eilutes kuriose yra tas zodis bbz 
    */


#include "header.h"

int main() {

/*dabar could be kad tsg nuskaitys bet visas LT raides rodys kaip arba labai keistus simbolius
arba bbz bet greiciausiai nerodys lietuviskai*/


    std::locale::global(std::locale("lt_LT.UTF-8")); 
    std::string fileName = "article.txt";
    std::ifstream article(fileName);
    article.imbue(std::locale()); //cia applyina locale standarta cj kad gerai coutintu
    if (!article.is_open()){
        std::cerr << "Failas nebuvo atidarytas" << fileName << std::endl;
        return 1;}
    std::map<std::string, std::vector<int>> params;
    keyValuePair pair;
    while (article >> pair) {
        params[pair.getKey()] = pair.getValues();} //kvp i pair i paramFile i article
    article.close();
    /* Alternative Method 2: Simple line-by-line parsing
    std::string line;
    while (std::getline(paramFile, line)) {
        std::istringstream iss(line);
        std::string key;
        if (iss >> key) {
            std::vector<double> values;
            double value;
            while (iss >> value) {
                values.push_back(value);}
            params[key] = values;}}
    */

    
    /*for (const auto& pair : params) {
        std::cout << pair.first << ": ";
        for (double val : pair.second) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }*/



        //BBZ SITAS KODAS IS STACK OVERFLOW PAIMTAS TAI GALIMAI CIA DAXUJA KLAIDU COULD BE KAD BUS
    
    return 0;
}