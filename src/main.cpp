#include <iostream>

struct Item {
    std::string match_name;
    std::string path;
};

const Item g_item[] = {
    // local folder
    {"root", "C:\\Users\\whitelies125\\root"},
    {"code", "C:\\Users\\whitelies125\\root\\program\\Code"},
    {"downloads", "C:\\Users\\whitelies125\\Downloads"},
    {"powershell", "C:\\Users\\whitelies125\\Documents\\WindowsPowerShell"},

    // help
    {"list", ""},
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "valid arguments. input \"list\" to show all command." << std::endl;
        return 0;
    }
    for (const auto& [match_name, path] : g_item){
        if (match_name.starts_with(argv[1])) {
            std::cout << path << std::endl;
            return 0;
        }
    }
    return 1;
}
