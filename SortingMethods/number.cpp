#include "number.hpp"

int Number::currId = 1;

Number::Number(int v, uint32_t cn) {
    id = currId++;
    val = v;
    color_rgb = cn;
}

int Number::getId() const { return id; }
int Number::getVal() const { return val; }
uint32_t Number::getColor() const { return color_rgb; }

void Number::setVal(int v) { val = v; }
void Number::setColor(uint32_t c) { color_rgb = c; }

void Number::print() const {
    fmt::print(fg(fmt::rgb(color_rgb)), "\n--------- NUMBER ---------\n");
    fmt::print(fg(fmt::rgb(color_rgb)), "Id: \t{}\n", id);
    fmt::print(fg(fmt::rgb(color_rgb)), "Val: \t{}\n", val);
    fmt::print(fg(fmt::rgb(color_rgb)), "Color: \t{:#08x}\n", color_rgb);
    fmt::print(fg(fmt::rgb(color_rgb)), "--------------------------\n");
}
