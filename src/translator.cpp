
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::set<std::string> make_exit_commands()
{
    std::set<std::string> exit_commands;
    exit_commands.insert("q");
    exit_commands.insert("quit");
    exit_commands.insert("e");
    exit_commands.insert("exit");
    return exit_commands;
}

std::vector<std::string> split(std::string input, char delimiter)
{
    std::vector<std::string> vect;
    std::stringstream s(input);
    std::string token;
    while (std::getline(s, token, delimiter))
    {
        vect.push_back(token);
    }
    return vect;
}

int main(int argc, char **argv)
{
    std::map<std::string, std::string> translate;
    auto exit_value = make_exit_commands();
    std::vector<std::pair<std::string, std::string>> history;
    while (true)
    {
        std::string input;
        std::stringstream stream(input);
        std::cout << "Enter a command: " << std::endl;
        getline(std::cin, input);
        std::vector<std::string> inputArray = split(input, ' ');

        if (exit_value.count(inputArray[0]) > 0)
        {
            break;
        }
        if (inputArray[0].compare("add") == 0)
        {
            translate.emplace(inputArray[1], inputArray[2]);
            history.push_back(std::make_pair(inputArray[1], inputArray[2]));
            std::cout << inputArray[1] << "=>" << inputArray[2] << std::endl;
        }

        if (inputArray[0].compare("translate") == 0)
        {
            /*auto it = translate.find(inputArray[1]);
            std::cout << (it->first.empty() ? "???" : it->second) << std::endl;
            */
            auto it = inputArray.begin() + 1;
            for (; it != inputArray.end(); it++)
            {
                std::cout << (translate[*it].empty() ? "???" : translate[*it]) << std::endl;
            }
        }

        if (inputArray[0].compare("print") == 0)
        {
            for (auto it = translate.begin(); it != translate.end(); it++)
            {
                std::cout << it->first << "=>" << it->second << std::endl;
            }
        }

        if (inputArray[0].compare("history") == 0)
        {
            for (auto it = history.begin(); it != history.end(); it++)
            {
                std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
            }
        }

        if (inputArray[0].compare("save") == 0)
        {
            if (inputArray[1].empty())
            {
                std::cout << "Error : \nneed file" << std::endl;
                continue;
            }
            std::ofstream outfile(inputArray[1]);
            for (auto it = history.begin(); it != history.end(); it++)
            {
                outfile << it->first << "," << it->second << std::endl;
            }
        }

        if (inputArray[0].compare("load") == 0)
        {
            std::string line;
            std::ifstream infile(inputArray[1]);
            if (infile.is_open())
            {
                while (std::getline(infile, line))
                {
                    std::vector<std::string> inputArray2 = split(line, ',');
                    translate.emplace(inputArray2[0], inputArray2[1]);
                }
                infile.close();
            }
        }
        if (inputArray[0].compare("clear") == 0)
        {
            translate.clear();
        }

        if (inputArray[0].compare("remove") == 0)
        {
            translate.erase(inputArray[1]);
        }

        std::cout << std::endl;
    }

    return 0;
}
