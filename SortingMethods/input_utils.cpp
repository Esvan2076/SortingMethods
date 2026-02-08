#include "input_utils.hpp"

#include <charconv>
#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <random>

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    fmt::print("\nPress ENTER to continue...");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

short transInputToShort(const std::string& input) {
    if (input.empty()) return -1;

    short val;
    auto [ptr, ec] = std::from_chars(input.data(), input.data() + input.size(), val);

    if (ec == std::errc{} && ptr == input.data() + input.size()) {
        return val;
    }

    return -1;
}

int transInputToInt(const std::string& input) {
    if (input.empty()) return -1;

    int val;
    auto [ptr, ec] = std::from_chars(input.data(), input.data() + input.size(), val);

    if (ec == std::errc{} && ptr == input.data() + input.size()) {
        return val;
    }

    return -1;
}

Number createNumber() {
    bool inValid;
    int val = 0;
    uint32_t selectedColor;

    // Colors
    static const uint32_t colorPalette[] = {
        0xF0F8FF, 0xFAEBD7, 0x00FFFF, 0x7FFFD4, 0xF0FFFF, 0xF5F5DC, 0xFFE4C4, 0xFFEBCD,
        0xDEB887, 0x7FFF00, 0xFF7F50, 0xFFF8DC, 0xFF1493, 0x00BFFF, 0x9ACD32, 0xFFFF00,

        0x1E90FF, 0xFFFAF0, 0xFF00FF, 0xDCDCDC, 0xF8F8FF, 0xFFD700, 0xADFF2F, 0xF0FFF0,
        0xFF69B4, 0xFFFFF0, 0xF0E68C, 0xE6E6FA, 0xFFF0F5, 0x7CFC00, 0xFFFACD, 0xADD8E6,

        0xF08080, 0xE0FFFF, 0xFAFAD2, 0xD3D3D3, 0x90EE90, 0xFFB6C1, 0xFFA07A, 0x20B2AA,
        0x87CEFA, 0xB0C4DE, 0xFFFFE0, 0x00FF00, 0x32CD32, 0xFAF0E6, 0x66CDAA, 0xBA55D3,
        0x9370DB, 0x3CB371, 0x7B68EE, 0x00FA9A, 0x48D1CC, 0xF5FFFA, 0xFFE4E1, 0xFFE4B5,
        0xFFDEAD, 0xFDF5E6, 0xFFA500, 0xDA70D6, 0xEEE8AA, 0x98FB98, 0xAFEEEE, 0xFFEFD5,
        0xFFDAB9, 0xFFC0CB, 0xDDA0DD, 0xB0E0E6, 0xFF0000, 0xFA8072, 0xF4A460, 0xFFF5EE,
        0xC0C0C0, 0x87CEEB, 0xFFFAFA, 0x00FF7F, 0x4682B4, 0xD2B48C, 0xD8BFD8, 0xFF6347,
        0x40E0D0, 0xEE82EE, 0xF5DEB3, 0xFFFFFF, 0xF5F5F5
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<size_t> colorDist(0, (sizeof(colorPalette) / sizeof(colorPalette[0])) - 1);
    selectedColor = colorPalette[colorDist(gen)];

    do {
        inValid = false;

        fmt::print(fg(fmt::color::spring_green), "\nDo you want to create the Number node:\n");
        fmt::print(fg(fmt::color::spring_green), "[1] Auto \t[2] Manual\n");
        fmt::print(fg(fmt::color::light_sky_blue), "Option > ");

        std::string input;
        std::getline(std::cin, input);
        short res = transInputToShort(input);

        if (res == 1) {
            std::uniform_int_distribution<int> valDist(1, 100);
            val = valDist(gen);
        }
        else if (res == 2) {
            fmt::print(fg(fmt::color::spring_green), "\n--- Enter Number Details ---\n");
            fmt::print(fg(fmt::color::light_sky_blue), "Value > ");
            std::getline(std::cin, input);
            val = transInputToInt(input);
            fmt::print(fg(fmt::color::spring_green), "-----------------------------\n");

            if (val == -1) {
                inValid = true;
                fmt::print(fg(fmt::color::red), "Invalid value, try again\n");
                pause();
            }
        }
        else {
            inValid = true;
            fmt::print(fg(fmt::color::red), "Invalid option, try again\n");
            pause();
        }
    } while (inValid);

    return Number(val, selectedColor);
}