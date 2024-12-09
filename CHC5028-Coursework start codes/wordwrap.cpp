#include "wordwrap.h"
#include <iostream>
#include <iterator>
#include <cstdint>

uint16_t consoleWidth = 80;
uint16_t currentConsoleOffset = 0;

void initWordWrap() {
    consoleWidth = 80;
    currentConsoleOffset = 0;
}

void wrapOut(const std::string *text) {
    size_t len = text->length();
    size_t position = 0;

    while (position < len) {
        size_t spaceLeft = consoleWidth - currentConsoleOffset;

        if (len - position < spaceLeft) {
            std::cout << text->substr(position, len - position);
            position = len;
        } else {
            size_t lastSpace = position + spaceLeft - 1;
            while (lastSpace > position && text->at(lastSpace) != ' ') {
                lastSpace--;
            }

            if (lastSpace == position) {
                std::cout << text->substr(position, spaceLeft);
                position += spaceLeft;
            } else {
                std::cout << text->substr(position, lastSpace - position + 1);
                position = lastSpace + 1;
            }

            std::cout << std::endl;
            currentConsoleOffset = 0;
        }
    }
}

void wrapEndPara() {
    std::cout << std::endl;
    currentConsoleOffset = 0;
}