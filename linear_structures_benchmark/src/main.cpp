#include "interface.h"
#include <filesystem>

namespace fs = std::filesystem;

void clear_directory(const std::string& path)
{
    if (!fs::exists(path)) return;

    for (const auto& entry : fs::directory_iterator(path))
    {
        fs::remove_all(entry.path());
    }
}
int main()
{
    char choice;
    std::cout << "Would you like to delete all previous data? (y/n): ";
    std::cin >> choice;

    switch (choice)
    {
        case 'y':
            clear_directory("results");
            clear_directory("visualisation/plots");
            break;
        case 'n':
            break;
        default:
            break;
    }
    

    Interface Interface;
    Interface.show_if();
}