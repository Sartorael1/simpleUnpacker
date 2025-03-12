#include "../headers/DispatcherHat.h"
#include "../headers/SevenZipExtractor.h"



std::string DispatcherHat::distributor(std::string &libraryPath, const std::string &archivePath, const std::string &extractPath) {
    std::string  answerString = "Укажите пути к файлу и папке";
    std::string  password = "неизвестно";
    if (libraryPath.empty()){
        libraryPath = "7z.dll";
    }
    std::string extension = getFileExtension(archivePath);
    if (!archivePath.empty() && !extractPath.empty()) {
        if (extension == ".7z") {
            SevenZipExtractor extractor = *new SevenZipExtractor();
            password = extractor.letsplay();
            extractor.extractArchive(password,archivePath, extractPath);
            answerString = "готово, Пароль: " + password;
        }// else if () {}
    }

    return answerString;
}
std::string DispatcherHat::getFileExtension(const std::string& filePath) {
    size_t lastDotPos = filePath.find_last_of('.');
    if (lastDotPos != std::string::npos) {
        return filePath.substr(lastDotPos);
    }
    return "";
}


