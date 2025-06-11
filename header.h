#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
#include <codecvt>
#include <set>

void readingDomains(std::string fileName,  std::set<std::wstring>& acceptableDomains);
bool domains(std::wstring& segment, std::set<std::wstring>& acceptableDomains);
bool checkingURL(std::wstring word, std::set<std::wstring> &acceptableDomains);
bool suitableLetter(wchar_t let);
void readingFile(std::string fileName, std::map<std::wstring, std::vector<int>>& allWords, std::vector<std::wstring>& url, std::set<std::wstring>& acceptableDomains, std::set<std::wstring> &wordsWithTer);
void outputWordsCount(std::map<std::wstring, std::vector<int>>& allWords, std::wostream &out);
void outputCrossReference(std::map<std::wstring, std::vector<int>>& allWords, std::wostream &out);
void URLSprint(std::vector<std::wstring>& urls, std::wostream &out);
void TERprint(std::set<std::wstring> &wordsWithTer, std::wofstream &out);
