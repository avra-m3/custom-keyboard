
#include <array>
#include <string.h>
#include "definitions.h"

#define IS_MASTER false


const int num_rows = 6;
const int num_cols = 5;

constexpr std::array<byte, num_rows> row_pins = {21, 20, 19, 18, 27, 26}; //declaring inputs and outputs
constexpr std::array<byte, num_cols> col_pins = {2, 3, 4, 6, 7};

constexpr char layout[num_rows][num_cols] = {
    {'6', '7', '8', '9', '0'},
    {'y', 'u', 'i', 'o', 'p'},
    {'h', 'j', 'k', 'l', ';'},
    {'n', 'm', ',', '.', '/'},
    {'-', '=', KEY_RIGHT_ALT, KEY_RIGHT_CTRL, KEY_RETURN},
    {KEY_EMPTY, KEY_EMPTY, KEY_EMPTY, KEY_RIGH_GUI, ' '},
};