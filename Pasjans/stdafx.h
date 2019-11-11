// stdafx.h: plik dołączany dla standardowych systemowych plików dołączanych,
// lub pliki dołączane specyficzne dla projektu, które są często wykorzystywane, ale
// są rzadko zmieniane
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // Wyklucz rzadko używane rzeczy z nagłówków systemu Windows
// Pliki nagłówkowe systemu Windows
#define NOMINMAX
#include <windows.h>

// Pliki nagłówkowe środowiska uruchomieniowego języka C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// w tym miejscu przywołaj dodatkowe nagłówki wymagane przez program
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

// stałe

const int WINDOW_WIDTH = 1680;
const int WINDOW_HEIGHT = 800;

const int CARD_WIDTH = 125;
const int CARD_HEIGHT = 156;

const int FPS = 60;
const int DECK = 2000;
