#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/MyApplicationGui.h"
#include "../headers/DispatcherHat.h"
#include <Windows.h>
int main()
{
    SetConsoleOutputCP(65001);
    MyApplicationGui myApplicationGui = *new MyApplicationGui();
    myApplicationGui.initGui();
    return 0;
}
