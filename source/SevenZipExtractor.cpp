#include "../headers/SevenZipExtractor.h"
#include <iostream>
#include <bit7z/bitfileextractor.hpp>



    void  SevenZipExtractor::extractArchive(const std::string& archivePath, const std::string& extractPath){
        try {
            using namespace bit7z;
            Bit7zLibrary lib{ "../third_party/7z.dll" };
            BitFileExtractor extractor{ lib, BitFormat::SevenZip };
            extractor.extract( archivePath, extractPath);
            std::cout << "файл обработан" << std::endl;
        } catch ( const bit7z::BitException& ex ) {
            std::cerr << "Error: " << ex.what() << std::endl; }
    }

