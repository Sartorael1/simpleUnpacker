#ifndef SAMPLECLIONPROJECT2_MYAPPLICATIONGUI_H
#define SAMPLECLIONPROJECT2_MYAPPLICATIONGUI_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

class MyApplicationGui {
public:
    void initGui();

private:
    void guiVisual();
    static sf::Text createLibraryPathText(const sf::Font& font);
    static sf::RectangleShape createLibraryPathButton(const sf::Font& font,const sf::Text& libraryPathText);
    static sf::Text createButtonLibraryText(const sf::Font&,const sf::RectangleShape& libraryPathButton
                                     ,const sf::String& pathStr);
    static sf::Text createArchivePathText(const sf::Font& font);
    static sf::RectangleShape createArchivePathButton(const sf::Font& font,const sf::Text& archivePathText);
    static sf::Text createButtonArchiveText(const sf::Font& font,const sf::RectangleShape& archivePathButton,
                                     const sf::String& pathStr);

    static sf::Text createExtractPathText(const sf::Font& font);
    static sf::RectangleShape createExtractPathButton(const sf::Font& font,const sf::Text& extractPathText);
    static sf::Text createExtractPathButtonText(const sf::Font& font,const sf::RectangleShape& extractPathButton,
                                         const sf::String& pathStr);
    static sf::Text createOutputText(const sf::Font& font,const sf::RectangleShape& extractPathButton);
    static sf::RectangleShape createStartButton(const sf::Text& outputText);
    static sf::Text createStartText(const sf::Font& font, const sf::RectangleShape& startButton);
    static void createBackGround(sf::RenderWindow *window, sf::Texture& backgroundTexture, sf::Sprite& backgroundSprite);
   void drawing(sf::RenderWindow *window, const sf::Text &libraryPathText, const sf::RectangleShape &libraryPathButton,
            const sf::Text &buttonLibraryText, const sf::Text &archivePathText, const sf::RectangleShape &archiveButton,
             sf::Text &buttonArchiveText, const sf::Text &extractPathText,
            const sf::RectangleShape &extractPathButton,
            const sf::Text &extractPathButtonText, const sf::Text &outputText, const sf::RectangleShape &startButton,
            const sf::Text &startText, sf::Sprite backgroundSprite
            );
    static void
    guiLogic(sf::RenderWindow *window, const sf::Text &libraryPathText, const sf::RectangleShape &libraryPathButton,
             sf::Text buttonLibraryText,
             const sf::Text &archivePathText, const sf::RectangleShape &archiveButton, sf::Text buttonArchiveText,
             const sf::Text &extractPathText,
             const sf::RectangleShape &extractPathButton, sf::Text extractPathButtonText, sf::Text outputText,
             const sf::RectangleShape &startButton,
             sf::Text startText, const sf::Sprite& backgroundSprite);
     static void openDiagWintToChooseArchiveTarget(sf::Text& buttonArchiveText);
     static void  openDiagToChooseLibraryPath(sf::Text&buttonLibraryText);
     static void openDiagWintToChooseFolder(sf::Text &extractPathButtonText);

};


#endif //SAMPLECLIONPROJECT2_MYAPPLICATIONGUI_H
