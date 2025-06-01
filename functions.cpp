#include "header.h"

void readingDomains(std::string fileName,  std::set<std::wstring>& acceptableDomains){
    std::wstring line;
    std::wstringstream buffer;
    std::wifstream file(fileName);
     if(!file.is_open()){
        throw std::runtime_error("Failo atidaryti nepavyko");}
    buffer<<file.rdbuf();
    file.close();
    while(getline(buffer, line)){

        if(!line.empty() && line[0] == L'\uFEFF'){
            line.erase(0, 1);
        }

        std::wistringstream line2(line);
        std::wstring word2;
        while(line2>>word2){
            acceptableDomains.insert(word2);
        }
    }
}

bool domains(std::wstring& segment, std::set<std::wstring>& acceptableDomains){
    return (acceptableDomains.find(segment)!=acceptableDomains.end());}

bool checkingURL(std::wstring word, std::set<std::wstring> &acceptableDomains){
    std::transform(word.begin(), word.end(), word.begin(), [](wchar_t c){ return std::toupper(c, std::locale()); });
    size_t start = word.find_first_of(L"./"); 
    if (start == std::wstring::npos)
        return false; 
    start++; 
    while (start < word.length()){
        size_t end = word.find_first_of(L"./", start); 
        std::wstring tempWord = word.substr(start);
        if (end != std::wstring::npos){
            tempWord = word.substr(start, end - start);}
        if (domains(tempWord, acceptableDomains))
            return true;
        if (end == std::wstring::npos)
            break;
        start = end + 1;}
    return false;
} 

bool suitableLetter(wchar_t let){
    return (!iswpunct(let) && !iswdigit(let));
}

void readingFile(std::string fileName, std::map<std::wstring, std::vector<int>> &allWords, std::vector<std::wstring> &url, std::set<std::wstring> &acceptableDomains)
{
    std::wstring line;
    std::wstringstream buffer;
    std::wifstream file(fileName);
    file.imbue(std::locale()); 
    if (!file.is_open())
    {
        throw std::runtime_error("Failo atidaryti nepavyko");
    }
    buffer << file.rdbuf();
    file.close();
    int count = 0;
    bool firstLine = true;
    while (getline(buffer, line)){
        count++;
        if (firstLine && !line.empty() && line[0] == L'\uFEFF'){
            line.erase(0, 1);
            firstLine = false;
        }
        std::wistringstream line2(line);
        std::wstring word2;
        while (line2 >> word2)
        {
            if (checkingURL(word2, acceptableDomains)){
                url.push_back(word2);}
            else{
                std::wstring updatedWord;
                for (wchar_t letter : word2){
                    if (suitableLetter(letter)){ updatedWord += std::toupper(letter, std::locale()); }}
                if (!updatedWord.empty()) {
                    if (allWords.find(updatedWord) == allWords.end()){ allWords.insert({updatedWord, {count}}); }
                    else{ allWords[updatedWord].push_back(count);}
                }
            }
        }
    }
}

void outputWordsCount(std::map<std::wstring, std::vector<int>>& allWords, std::wostream &out){
    for(auto& it : allWords){
        std::set<int> uniqueLines(it.second.begin(), it.second.end());
        out<< it.first << ": "<< uniqueLines.size() <<std::endl;
    }
}

void outputCrossReference(std::map<std::wstring, std::vector<int>>& allWords, std::wostream &out){
    for(auto& it: allWords){
        std::set<int> uniqueLines(it.second.begin(), it.second.end());
        out<<it.first<<": ";
        for(auto i: uniqueLines){out << i << " ";}
        if(uniqueLines.size()==1){out << "eilute"<<std::endl;}
        else out << "eilutes"<<std::endl;
    }
}

void URLSprint(std::vector<std::wstring>& urls, std::wostream &out){
    out<< "Tekste rastos nuorodos:"<<std::endl;
    for(auto it: urls){
        out<< it << std::endl;
    }
}