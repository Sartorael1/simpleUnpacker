#ifndef SEVENZIPEXTRACTOR_H
#define SEVENZIPEXTRACTOR_H
#include <string>




    class SevenZipExtractor {

    public:
         static void extractArchive(std::string&  password,const std::string& archivePath, const std::string& extractPath);
         static std::string letsplay();
    private:
    std::string aes256Generator();

    };



#endif //SEVENZIPEXTRACTOR_H