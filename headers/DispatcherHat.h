#ifndef SAMPLECLIONPROJECT2_DISPATCHERHAT_H
#define SAMPLECLIONPROJECT2_DISPATCHERHAT_H

#include <string>


class DispatcherHat {
public:
    static std::string distributor(std::string &libraryPath ,const std::string& archivePath, const std::string& extractPath);

private:
    static std::string getFileExtension(const std::string& filePath);
};

#endif //SAMPLECLIONPROJECT2_DISPATCHERHAT_H