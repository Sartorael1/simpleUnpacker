#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../headers/MyApplicationGui.h"
#include <iostream>
#include <Windows.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../headers/DispatcherHat.h"
#include <fstream>
#include <string>
#include <sstream>
#include <commdlg.h>
#include <shtypes.h>
#include <shlobj.h>


void MyApplicationGui::initGui() {
    try {
        guiVisual();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void MyApplicationGui::guiVisual(){
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    sf::Font font;
    try {font.loadFromFile("mainFont.ttf");}
    catch (const std::exception& a){
        std::cout << a.what() << std::endl;
        std::cout<< "не удалось найти файл шрифтов"<< std::endl;
    }
    std::string defaultPathString = "Искать" ;
    sf::String pathStr = sf::String::fromUtf8(defaultPathString.begin(), defaultPathString.end());
    sf::Text libraryPathText = createLibraryPathText(font);
    sf::RectangleShape libraryPathButton = createLibraryPathButton(font,libraryPathText);
    sf::Text buttonLibraryText = createButtonLibraryText(font,libraryPathButton ,pathStr);
    sf::Text archivePathText = createArchivePathText(font);
    sf::RectangleShape archiveButton = createArchivePathButton(font,archivePathText);
    sf::Text buttonArchiveText = createButtonArchiveText(font,archiveButton,pathStr);
    sf::Text extractPathText = createExtractPathText(font);
    sf::RectangleShape  extractPathButton = createExtractPathButton(font,extractPathText);
    sf::Text extractPathButtonText = createExtractPathButtonText(font,extractPathButton,pathStr);
    sf::Text outputText = createOutputText(font,extractPathButton);
    sf::RectangleShape startButton = createStartButton(outputText);
    sf::Text startText = createStartText(font,startButton);
    MyApplicationGui gui;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    createBackGround(&window, backgroundTexture, backgroundSprite);
    gui.drawing(&window, libraryPathText, libraryPathButton, buttonLibraryText, archivePathText,
                archiveButton, buttonArchiveText, extractPathText,
                extractPathButton, extractPathButtonText, outputText, startButton, startText, backgroundSprite);
    gui.guiLogic(&window, sf::Text(), sf::RectangleShape(), sf::Text(), sf::Text(), sf::RectangleShape(), sf::Text(),
                 sf::Text(), sf::RectangleShape(), sf::Text(), sf::Text(), sf::RectangleShape(), sf::Text(),backgroundSprite);
}

sf::Text MyApplicationGui::createLibraryPathText(const sf::Font& font) {
    std::string defaultLibraryString = "Если нужно - выберите библиотеку\n для работы с архивом или оставьте пустым" ;
    sf::String libraryStr = sf::String::fromUtf8(defaultLibraryString.begin(), defaultLibraryString.end());
    sf::Text libraryPathText(libraryStr, font, 24);
    libraryPathText.setPosition(100, 100);
    return libraryPathText;
}
sf::RectangleShape MyApplicationGui::createLibraryPathButton(const sf::Font& font,const sf::Text& libraryPathText){
    sf::RectangleShape libraryPathButton(sf::Vector2f(200, 30));
    libraryPathButton.setPosition(libraryPathText.getPosition().x+500, libraryPathText.getPosition().y);
    libraryPathButton.setFillColor(sf::Color(00, 0, 255));
    return libraryPathButton;
}
sf::Text MyApplicationGui::createButtonLibraryText(const sf::Font& font,
                                                   const sf::RectangleShape& libraryPathButton,
                                                   const sf::String& pathStr){
    sf::Text buttonLibraryText(pathStr, font, 14);
    buttonLibraryText.setPosition(libraryPathButton.getPosition().x + 150, libraryPathButton.getPosition().y);
    return buttonLibraryText;
}
sf::Text MyApplicationGui::createArchivePathText(const sf::Font& font) {
    std::string defaultArchiveString = "Выберите путь к нужному архиву";
    sf::String archiveStr = sf::String::fromUtf8(defaultArchiveString.begin(), defaultArchiveString.end());
    sf::Text archivePathText(archiveStr, font, 24);
    archivePathText.setPosition(100, 200);
    return archivePathText;
}
sf::RectangleShape MyApplicationGui::createArchivePathButton(const sf::Font& font,const sf::Text& archivePathText){
    sf::RectangleShape archiveButton(sf::Vector2f(200, 30));
    archiveButton.setFillColor(sf::Color(00, 0, 255));
    archiveButton.setPosition(archivePathText.getPosition().x + 500, archivePathText.getPosition().y);
    return archiveButton;
}
sf::Text MyApplicationGui::createButtonArchiveText(const sf::Font& font,const sf::RectangleShape& archiveButton,const sf::String& pathStr){
    sf::Text buttonArchiveText(pathStr, font, 14);
    buttonArchiveText.setPosition(archiveButton.getPosition().x + 150, archiveButton.getPosition().y);
    return buttonArchiveText;
}
sf::Text MyApplicationGui::createExtractPathText(const sf::Font& font){
    std::string defaultExtractString = "Выберите путь разархивирования";
    sf::String extractStr = sf::String::fromUtf8(defaultExtractString.begin(), defaultExtractString.end());
    sf::Text extractPathText(extractStr, font, 24);
    extractPathText.setPosition(100, 300);
    return extractPathText;
}
sf::RectangleShape MyApplicationGui::createExtractPathButton(const sf::Font& font,const sf::Text& extractPathText){
    sf::RectangleShape extractPathButton(sf::Vector2f(200,30));
    extractPathButton.setFillColor(sf::Color(00, 0, 255));
    extractPathButton.setPosition(extractPathText.getPosition().x+500,extractPathText.getPosition().y);
    return extractPathButton;
}
sf::Text MyApplicationGui::createExtractPathButtonText(const sf::Font& font,const sf::RectangleShape& extractPathButton,
                                     const sf::String& pathStr){
    sf::Text extractPathButtonText(pathStr, font, 14);
    extractPathButtonText.setPosition(extractPathButton.getPosition().x+150,extractPathButton.getPosition().y);
    return extractPathButtonText;
}
sf::Text MyApplicationGui::createOutputText(const sf::Font& font,const sf::RectangleShape& extractPathButton ){
    std::string defaultOutputString = "Здесь будет отображаться вывод";
    sf::String outputStr = sf::String::fromUtf8(defaultOutputString.begin(), defaultOutputString.end());
    sf::Text outputText(outputStr, font, 24);
    outputText.setPosition(extractPathButton.getPosition().x+150, extractPathButton.getPosition().y+500);
    return outputText;
}
sf::RectangleShape MyApplicationGui::createStartButton(const sf::Text& outputText){
    sf::RectangleShape startButton(sf::Vector2f(400, 60));
    startButton.setPosition(outputText.getPosition().x, outputText.getPosition().y-300);
    startButton.setFillColor(sf::Color(00, 0, 255));
    return startButton;
}
sf::Text MyApplicationGui::createStartText(const sf::Font& font, const sf::RectangleShape& startButton){
    std::string defaultStartString = "ПУСК";
    sf::String startStr = sf::String::fromUtf8(defaultStartString.begin(), defaultStartString.end());
    sf::Text startText(startStr, font, 40);
    startText.setPosition(startButton.getPosition().x+150, startButton.getPosition().y);
    return startText;
}

void MyApplicationGui::drawing(sf::RenderWindow *window, const sf::Text &libraryPathText,
                               const sf::RectangleShape &libraryPathButton,
                               const sf::Text &buttonLibraryText, const sf::Text &archivePathText,
                               const sf::RectangleShape &archiveButton,
                                sf::Text &buttonArchiveText, const sf::Text &extractPathText,
                               const sf::RectangleShape &extractPathButton,
                               const sf::Text &extractPathButtonText, const sf::Text &outputText,
                               const sf::RectangleShape &startButton,
                               const sf::Text &startText, sf::Sprite backgroundSprite) {
    window->clear();
    window->draw(backgroundSprite);
    window->draw(libraryPathText);
    window->draw(libraryPathButton);
    window->draw(buttonLibraryText);
    window->draw(archivePathText);
    window->draw(archiveButton);
    window->draw(buttonArchiveText);
    window->draw(extractPathText);
    window->draw(extractPathButton);
    window->draw(extractPathButtonText);
    window->draw(outputText);
    window->draw(startButton);
    window->draw(startText);
    window->display();
    guiLogic(window, libraryPathText, libraryPathButton, buttonLibraryText, archivePathText, archiveButton,
             buttonArchiveText, extractPathText,
             extractPathButton, extractPathButtonText, outputText, startButton, startText,backgroundSprite);
}

void MyApplicationGui::guiLogic(sf::RenderWindow *window, const sf::Text &libraryPathText, const sf::RectangleShape &libraryPathButton,
                                sf::Text buttonLibraryText,
                                const sf::Text &archivePathText, const sf::RectangleShape &archiveButton, sf::Text buttonArchiveText,
                                const sf::Text &extractPathText,
                                const sf::RectangleShape &extractPathButton, sf::Text extractPathButtonText, sf::Text outputText,
                                const sf::RectangleShape &startButton,
                                sf::Text startText, const sf::Sprite& backgroundSprite) {
    std::string libraryPath, archivePath, extractPath;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                        if (archiveButton.getGlobalBounds().contains(mousePos)) {
                        openDiagWintToChooseArchiveTarget(buttonArchiveText);
                        window->draw(backgroundSprite);
                            window->draw(libraryPathText);
                            window->draw(libraryPathButton);
                            window->draw(buttonLibraryText);
                            window->draw(archivePathText);
                            window->draw(archiveButton);
                            window->draw(buttonArchiveText);
                            window->draw(extractPathButtonText);
                            window->draw(extractPathText);
                            window->draw(extractPathButton);
                            window->draw(startButton);
                            window->draw(startText);
                            window->display();
                        }
                        if (libraryPathButton.getGlobalBounds().contains(mousePos)) {
                        openDiagToChooseLibraryPath(buttonLibraryText);
                            window->draw(backgroundSprite);
                            window->draw(libraryPathText);
                            window->draw(libraryPathButton);
                            window->draw(buttonLibraryText);
                            window->draw(archivePathText);
                            window->draw(archiveButton);
                            window->draw(buttonArchiveText);
                            window->draw(extractPathButtonText);
                            window->draw(extractPathText);
                            window->draw(extractPathButton);
                            window->draw(startButton);
                            window->draw(startText);
                            window->display();
                        }
                        if(extractPathButton.getGlobalBounds().contains(mousePos)){
                            openDiagWintToChooseFolder(extractPathButtonText);
                            window->draw(backgroundSprite);
                            window->draw(libraryPathText);
                            window->draw(libraryPathButton);
                            window->draw(buttonLibraryText);
                            window->draw(archivePathText);
                            window->draw(archiveButton);
                            window->draw(buttonArchiveText);
                            window->draw(extractPathText);
                            window->draw(extractPathButton);
                            window->draw(extractPathButtonText);
                            window->draw(startButton);
                            window->draw(startText);
                            window->display();
                        }
                        if(startButton.getGlobalBounds().contains(mousePos)){
                            std::string string = "ОЖИДАЙТЕ";
                            sf::String extractStr = sf::String::fromUtf8(string.begin(), string.end());
                            startText.setString(extractStr);
                            DispatcherHat dispatcherHat = *new DispatcherHat();
                            std::string defaultOutputString = dispatcherHat
                                    .distributor((std::string &) libraryPathText
                                    .getString(),
                                    buttonArchiveText.getString(),
                            extractPathButtonText.getString());
                            sf::String outputStr = sf::String::fromUtf8(defaultOutputString.begin(), defaultOutputString.end());
                           outputText.setString(outputStr);
                            window->draw(backgroundSprite);
                            window->draw(libraryPathText);
                            window->draw(libraryPathButton);
                            window->draw(buttonLibraryText);
                            window->draw(archivePathText);
                            window->draw(archiveButton);
                            window->draw(buttonArchiveText);
                            window->draw(extractPathText);
                            window->draw(extractPathButton);
                            window->draw(extractPathButtonText);
                            window->draw(startButton);
                            window->draw(startText);
                            window->draw(outputText);
                            window->display();
                        }
                    }
                    break;



                default:
                    break;
            }

        }
    }
}

 void  MyApplicationGui::createBackGround(sf::RenderWindow *window,sf::Texture& backgroundTexture,sf::Sprite& backgroundSprite) {
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
            static_cast<float>(window->getSize().x) / backgroundTexture.getSize().x,
            static_cast<float>(window->getSize().y) / backgroundTexture.getSize().y
    );
}

    void MyApplicationGui::openDiagWintToChooseArchiveTarget(sf::Text& buttonArchiveText) {
        OPENFILENAMEW ofn;
        wchar_t szFile[MAX_PATH];
        ZeroMemory(&ofn, sizeof(ofn));
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = szFile;
        ofn.lpstrFile[0] = L'\0';
        ofn.nMaxFile = sizeof(szFile) / sizeof(wchar_t);
        ofn.lpstrFilter = L"Все файлы\0*.*\0Текстовые файлы\0*.TXT\0";
        ofn.nFilterIndex = 1;
        ofn.lpstrFileTitle = NULL;
        ofn.nMaxFileTitle = 0;
        ofn.lpstrInitialDir = NULL;
        ofn.lpstrTitle = L"Выберите файл";
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
        if (GetOpenFileNameW(&ofn)) {
            buttonArchiveText.setString(szFile);
            buttonArchiveText.setPosition(buttonArchiveText.getPosition().x-150,buttonArchiveText.getPosition().y);
        } else {
            std::wcout << L"Ошибка выбора файла. Код ошибки: " << GetLastError() << std::endl;
        }
    }
    void MyApplicationGui:: openDiagToChooseLibraryPath(sf::Text&buttonLibraryText){
        OPENFILENAMEW ofn;
        wchar_t szFile[MAX_PATH];
        ZeroMemory(&ofn, sizeof(ofn));
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = szFile;
        ofn.lpstrFile[0] = L'\0';
        ofn.nMaxFile = sizeof(szFile) / sizeof(wchar_t);
        ofn.lpstrFilter = L"Все файлы\0*.*\0Текстовые файлы\0*.TXT\0";
        ofn.nFilterIndex = 1;
        ofn.lpstrFileTitle = NULL;
        ofn.nMaxFileTitle = 0;
        ofn.lpstrInitialDir = NULL;
        ofn.lpstrTitle = L"Выберите файл";
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
        if (GetOpenFileNameW(&ofn)) {
            buttonLibraryText.setString(szFile);
            buttonLibraryText.setPosition(buttonLibraryText.getPosition().x-150,buttonLibraryText.getPosition().y);
        } else {
            std::wcout << L"Ошибка выбора файла. Код ошибки: " << GetLastError() << std::endl;
        }
}
void MyApplicationGui::openDiagWintToChooseFolder(sf::Text &extractPathButtonText) {
    BROWSEINFO bi = { 0 };
    bi.lpszTitle = L"Выберите папку";
    HWND hwndOwner = NULL; // здесь можно указать HWND вашего окна, если нужно
    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL) {
        wchar_t path[MAX_PATH];
        if (SHGetPathFromIDList(pidl, path)) {
            extractPathButtonText.setString(path);
            extractPathButtonText.setPosition(extractPathButtonText.getPosition().x - 150, extractPathButtonText.getPosition().y);
        } else {
            std::wcout << L"Ошибка получения пути к папке." << std::endl;
        }
        CoTaskMemFree(pidl);
    } else {
        std::wcout << L"Ошибка выбора папки." << std::endl;
    }
}


















