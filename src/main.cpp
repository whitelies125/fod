#include <iostream>

struct Item {
    std::string_view match_name;
    std::string_view path;
};

const Item g_item[] = {
    // local folder
    {"root", "C:\\Users\\whitelies125\\root"},
    {"code", "C:\\Users\\whitelies125\\root\\program\\Code"},
    {"downloads", "C:\\Users\\whitelies125\\Downloads"},
    {"powershell", "C:\\Users\\whitelies125\\Documents\\WindowsPowerShell"},
    {"markdown", "C:\\Users\\whitelies125\\root\\note\\markdown"},
    {"nvim", "C:\\Users\\whitelies125\\AppData\\Local\\nvim"},
    {"game", "C:\\Users\\whitelies125\\root\\game"},
};

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "valid arguments. only can input 1 parameter.\n"
                     "input \"list\" to show all command." << std::endl;
        return 0;
    }
    auto condition = [&argv](const auto& it) { return it.match_name.starts_with(argv[1]); };
    if (const auto res = std::ranges::find_if(g_item, condition); res != std::end(g_item)) {
        std::cout << res->path << std::endl;
        return 0;
    }
    if (std::string("list").starts_with(argv[1])) {
        for (const auto& [match_name, path] : g_item) {
            std::cout << match_name << " : " << path << std::endl;
        }
        return 1;
    }
    return 1;
}
