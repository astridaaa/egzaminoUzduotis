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
        for(auto i: uniqueLines){out << i << "eil, ";}
        out<<std::endl;
    }
}