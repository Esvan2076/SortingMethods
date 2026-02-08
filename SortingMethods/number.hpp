#pragma once

#include <cstdint>
#include <string>
#include <compare>
#include <fmt/core.h>
#include <fmt/color.h>

class Number {
private:
    int id;
    int val;
    uint32_t color_rgb;
    static int currId;

public:
    Number(int, uint32_t);

    int getId() const;
    int getVal() const;
    uint32_t getColor() const;

    void setVal(int v);
    void setColor(uint32_t);

    auto operator<=>(const Number& other) const {
        return val <=> other.val;
    }

    bool operator==(const Number& other) const {
        return val == other.val;
    }

    void print() const;
};