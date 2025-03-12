#include "../headers/DispatcherHat.h"
#include "../headers/SevenZipExtractor.h"

void DispatcherHat::distributor(const std::string& archivePath, const std::string& extractPath) {
    std::string extension = getFileExtension(archivePath);
    if (extension == ".7z") {
        SevenZipExtractor extractor = *new SevenZipExtractor();
        extractor.extractArchive(archivePath, extractPath);
    } else {
        // Обработка других типов архивов
    }
}

std::string DispatcherHat::getFileExtension(const std::string& filePath) {
    size_t lastDotPos = filePath.find_last_of('.');
    if (lastDotPos != std::string::npos) {
        return filePath.substr(lastDotPos);
    }
    return "";
}