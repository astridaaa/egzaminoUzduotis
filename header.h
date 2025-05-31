#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <fstream>
#include <map>
#include <sstream>
#include <codecvt>
#include <set>

struct keyValuePair{
    std::wstring word;
    std::vector<int> lines;
};

bool domains(std::wstring segment, std::set<std::wstring> acceptableDomains){
    return (acceptableDomains.find(segment)==acceptableDomains.end());}

bool checkingURL(std::wstring word){
    std::wstring line;
    std::set<std::wstring> acceptableDomains;
    std::wstringstream buffer;

    std::wifstream file("tlds-alpha-by-domain.txt");
     if(!file.is_open()){
        throw std::runtime_error("Failo atidaryti nepavyko");}
    buffer<<file.rdbuf();
    file.close();
    while(getline(buffer, line)){
        std::wistringstream line2(line);
        std::wstring word2;
        while(line2>>word2){
            acceptableDomains.insert(word2);}}
    
    std::wstring possibleDomain;
    for(wchar_t symbol: word2){
        if(symbol != '.' && symbol != '/'){
            possibleDomain += symbol;}
        else if(domains(possibleDomain, acceptableDomains)){
            return true;}
        else possibleDomain="";
    }
    return false;
}

bool suitableLetter(wchar_t let){
    return (std::isalpha(let, std::locale()));
}

//be daug funkciju implementuotas nuskaitymas is failo
void readingFile(std::string fileName, std::map<std::wstring, std::vector<int>>& allWords, std::vector<std::wstring>& url){
    std::wstring line;
    std::wstringstream buffer;
    std::wifstream file(fileName);
    if(!file.is_open()){
        throw std::runtime_error("Failo atidaryti nepavyko");}

    buffer<<file.rdbuf();
    file.close();
    int count=0;
    while(getline(buffer, line)){
        count++;
        std::wistringstream line2(line);
        std::wstring word2;
        while(line2>>word2){
            if()
            //TODO check whether an url
            std::wstring updatedWord;
            for(wchar_t letter: word2){
                if(suitableLetter(letter)){updatedWord += std::toupper(letter, std::locale());}}
            if(allWords.find(updatedWord)==allWords.end()){
                allWords.insert({updatedWord, {count}});
                if (!updatedWord.empty()) {
                    allWords.insert({updatedWord, {count}});
                }
            }
            else if(!updatedWord.empty()){allWords[updatedWord].push_back(count);}//dar patikrint ar tas word nera empty
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
