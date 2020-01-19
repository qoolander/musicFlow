#include <iostream>
#include <fstream>
#include "Structures.h"
#include "tclap/CmdLine.h"

int main(int argc, char *argv[]) {
    try{
        TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
        TCLAP::ValueArg<std::string> configArg("c","configFile","path to source config file",true,"","string");
        cmd.add(configArg);

        TCLAP::ValueArg<std::string> destArg("o", "OutputFile", "output of generator", true, "", "string");
        cmd.add(destArg);

        cmd.parse(argc, argv);

        ScreenSystem::Piece piece = ScreenSystem::Piece();
        piece.configureSections();

        std::ofstream outfile (destArg.getValue());
        outfile << piece.generateCSV();
        outfile.close();

        return 0;
    } catch (TCLAP::ArgException &e){
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
        return 0;
    }
}
