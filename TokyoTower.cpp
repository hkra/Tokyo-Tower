#include <iostream>
#include <memory>
#include <boost/program_options.hpp>

#include "BuildConfig.h"
#include "TokyoTower.h"

namespace po = boost::program_options;

namespace
{
    int PrintVersionInfo()
    {
        std::cout << "$$$$$$$$\\        $$\\                                 $$$$$$$$\\\n"
          << "\\__$$  __|       $$ |                                \\__$$  __|\n"
          << "   $$ | $$$$$$\\  $$ |  $$\\ $$\\   $$\\  $$$$$$\\           $$ | $$$$$$\\  $$\\  $$\\  $$\\  $$$$$$\\   $$$$$$\\\n"
          << "   $$ |$$  __$$\\ $$ | $$  |$$ |  $$ |$$  __$$\\          $$ |$$  __$$\\ $$ | $$ | $$ |$$  __$$\\ $$  __$$\\\n"
          << "   $$ |$$ /  $$ |$$$$$$  / $$ |  $$ |$$ /  $$ |         $$ |$$ /  $$ |$$ | $$ | $$ |$$$$$$$$ |$$ |  \\__|\n"
          << "   $$ |$$ |  $$ |$$  _$$<  $$ |  $$ |$$ |  $$ |         $$ |$$ |  $$ |$$ | $$ | $$ |$$   ____|$$ |\n"
          << "   $$ |\\$$$$$$  |$$ | \\$$\\ \\$$$$$$$ |\\$$$$$$  |         $$ |\\$$$$$$  |\\$$$$$\\$$$$  |\\$$$$$$$\\ $$ |\n"
          << "   \\__| \\______/ \\__|  \\__| \\____$$ | \\______/          \\__| \\______/  \\_____\\____/  \\_______|\\__|\n"
          << "                           $$\\   $$ |\n"
          << "                           \\$$$$$$  |\n"
          << "                            \\______/\n\n";

        std::cout << "Version "
                  << TT_VERSION_MAJOR << "."
                  << TT_VERSION_MINOR << "."
                  << TT_VERSION_PATCH << "\n"
                  << "Copyright (C) 2017 Daniel Merritt" << std::endl;
        return 0;
    }

    int StartGame()
    {
        TokyoTower tower;

        tower.Initialize();
        tower.Run();

        return tower.Shutdown();
    }

    po::variables_map* ParseProgramArgs(int argc, char* argv[], po::options_description& desc)
    {
        auto vm = new po::variables_map;
        po::store(po::parse_command_line(argc, argv, desc), *vm);
        po::notify(*vm);
        return vm;
    }
}

void TokyoTower::Initialize()
{

}

void TokyoTower::Run()
{

}

int TokyoTower::Shutdown()
{
    return 0;
}

int main(int argc, char * argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
        ("version,v",   "Print version information")
        ("help",        "Print help message");

    auto argVars = std::unique_ptr<po::variables_map>(ParseProgramArgs(argc, argv, desc));

    if (argVars->count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    if (argVars->count("version"))
        return PrintVersionInfo();

    return StartGame();
}