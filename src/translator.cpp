#include <iostream>
#include <set>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <sstream>

std::set<std::string> make_exit_commands()
{
    std::set<std::string> value;
    value.insert("e");
    value.insert("exit");
    value.insert("q");
    value.insert("quit");

    return value;
}

int main()
{
    auto command = std::string();
    auto variable = make_exit_commands();
    while (true)
    {
        std::string value;
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        std::cin >> value;

        if (variable.count(value) > 0)
        {
            break;
        }

        int i = 0;
        std::string arr[3];
        std::stringstream ssin(value);
        while (ssin.good() && i < 4)
        {
            ssin >> arr[i];
            ++i;
        }
        if (arr[0] == "add")
        {
            std::cout << arr[1] << "=>" << arr[2] << std::endl;
        }
    }

    return 0;
}