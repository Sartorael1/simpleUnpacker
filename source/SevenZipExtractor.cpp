#include "../headers/SevenZipExtractor.h"
#include <iostream>
#include <bit7z/bitfileextractor.hpp>



    void  SevenZipExtractor::extractArchive(std::string&  password,const std::string& archivePath, const std::string& extractPath){
        try {
            std::string libPath = "7z.dll";
            using namespace bit7z;
            Bit7zLibrary lib{ libPath};
            BitFileExtractor extractor{ lib, BitFormat::SevenZip };
            extractor.extract( archivePath, extractPath);
            std::cout << "файл обработан" << std::endl;
        } catch ( const bit7z::BitException& ex ) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
std::string SevenZipExtractor::letsplay(){
    std::string Password;

    return Password;
}
std::string aes256Generator(){
    std::string output;

}
