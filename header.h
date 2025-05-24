#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

class keyValuePair{
    std::string key;
    std::vector<int> values;
public:
    const std::string& getKey(){return key;}
    const std::vector<int>& getValues(){return values;}
//galimai reikes daryt ir ne su >>operatorium nes greiciausiai reikes dar pridejinet lietuviskas raides
    friend std::istream& operator>>(std::istream& in, keyValuePair& p) {
        std::string line;
        if (std::getline(in, line)) {
            std::istringstream iss(line);
            if (iss >> p.key) {
                p.values.clear();
                double value;
                while (iss >> value) {
                    p.values.push_back(value);}}}
        return in;}
};
