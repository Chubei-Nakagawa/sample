#include <any>
#include <iostream>
#include <vector>
#include <map>

std::any parsejson(const std::string& orig)
{
    return std::any();
}

void putindent(std::ostream& ostr, int indent)
{
    for (int i = 0; i < indent; ++i){
        ostr << " ";
    }
}

template <typename T>
void purjson(std::ostream& ostr, const T& value, int indent = 0)
{
    ostr << value;
}

void putjson(std::ostream& ostr, double value, int indent = 0)
{
    ostr << value;
}

void putjson(std::ostream& ostr, const std::string& value, int indent = 0)
{
    ostr << '\"' << value << '\"';
}

void putjson(std::ostream& ostr, bool value, int indent = 0)
{
    ostr << value ? "true" : "false";
}

void putjson(std::ostream& ostr, const std::vector<std::any>& value, int indent = 0)
{
}
void putjson(std::ostream& ostr, const std::any& value, int indent = 0)
{
    putindent(ostr, indent);
    auto& t = value.type();
    if (!value.has_value()) {
        ostr << "null";
    } else if (value.type() == typeid(bool)){
        putjson(ostr, std::any_cast<bool>(value));
    } else if (t == typeid(int)){
        putjson(ostr, (double)std::any_cast<int>(value));
    } else if (t == typeid(double)){
        putjson(ostr, std::any_cast<double>(value));
    } else if (t == typeid(std::string)){
        putjson(ostr, std::any_cast<std::string>(value));
    } else if (t == typeid(std::vector<std::any>)){
        ostr << "[" << std::endl;
        for (const auto& item: std::any_cast<std::vector<std::any> >(value)){
            putjson(ostr, item, indent+1);
            ostr << ',' << std::endl;
        }
        putindent(ostr, indent);
        ostr << ']' << std::endl;
    } else if (t == typeid(std::map<std::string, std::any>)){
        ostr << '{' << std::endl;
        for (const auto& pair : std::any_cast<std::map<std::string, std::any> >(value)){
            putjson(ostr, pair.first, indent+1);
            ostr << ": ";
            putjson(ostr, pair.second);
        }
        putindent(ostr, indent);
        ostr << '}' << std::endl;
    } else {
        ostr << "under construction";
    }
}

int main(int argc, char** argv)
{
    std::string desc;
    if (argc > 1){
        for (int i = 1; i < argc; ++i){
            if (!desc.empty()) desc.append(" ");
            desc.append(argv[i]);
        }
    }
    else {
        
    }
    auto o = parsejson(desc);
    std::cout << "nulltest" << std::endl;
    putjson(std::cout , std::any());
    std::cout << std::endl;
    std::cout << "booltest" << std::endl;
    putjson(std::cout, std::any((bool)true));
    std::cout << std::endl;
    std::cout << "floattest" << std::endl;
    putjson(std::cout, std::any((double)1.2));
    std::cout << std::endl;
    std::cout << "listtest" << std::endl;
    std::vector< std::any > lists { 1, 0.3, true };
    putjson(std::cout, std::any(lists));
    std::cout << std::endl;
    std::cout << "maptest" << std::endl;
    std::map< std::string, std::any > maps {
        {"int",1},
        {"float",0.3},
        {"bool",true}
    };
    putjson(std::cout, std::any(maps));
    std::cout << std::endl;
    for (const auto& pair: maps){
        std::cout << pair.first << ":";
        putjson(std::cout, pair.second);
    }
    return 0;
}

