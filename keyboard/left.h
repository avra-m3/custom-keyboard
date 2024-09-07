
#include <array>
#include <string.h>
#include "definitions.h"

#define IS_MASTER true


extern const short num_rows = 6;
extern const short num_cols = 5;
extern const short num_layers = 2;

extern constexpr std::array<byte, num_rows> row_pins = {21, 20, 19, 18, 27, 26}; //declaring inputs and outputs
extern constexpr std::array<byte, num_cols> col_pins = {2, 3, 4, 6, 7};

extern constexpr unsigned int layout[num_layers][num_rows][num_cols] = {
    // Layer 0
    {
        {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5},
        {KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T},
        {KEY_A, KEY_S, KEY_D, KEY_F, KEY_G},
        {KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B},
        {KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_LEFT_ALT, LAYER(1), KEY_RETURN},
        {KEY_NONE, KEY_NONE, KEY_NONE, KEY_LEFT_GUI, ' '},
    },
    {
        // Layer 1
        {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5},
        {KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T},
        {KEY_A, KEY_S, KEY_D, KEY_F, KEY_G},
        {KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B},
        {KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_LEFT_ALT, LAYER(1), KEY_RETURN},
        {KEY_NONE, KEY_NONE, KEY_NONE, KEY_LEFT_GUI, ' '},
    }};