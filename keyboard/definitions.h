#pragma once
#include <Keyboard.h>

#define STATE_DOWN          1
#define STATE_UP            0

#define KEY_NONE 0x00 // No key pressed
#define KEY_ERR_OVF 0x01 //  Keyboard Error Roll Over - used for all slots if too many keys are pressed ("Phantom key")
// 0x02 //  Keyboard POST Fail
// 0x03 //  Keyboard Error Undefined
#define KEY_A 'a' 
#define KEY_B 'b' 
#define KEY_C 'c'
#define KEY_D 'd'
#define KEY_E 'e' // Keyboard e and E
#define KEY_F 'f' // Keyboard f and F
#define KEY_G 'g' // Keyboard g and G
#define KEY_H 'h' // Keyboard h and H
#define KEY_I 'i'// Keyboard i and I
#define KEY_J 'j' // Keyboard j and J
#define KEY_K 'k' // Keyboard k and K
#define KEY_L 'l' // Keyboard l and L
#define KEY_M 'm' // Keyboard m and M
#define KEY_N 'n' // Keyboard n and N
#define KEY_O 'o' // Keyboard o and O
#define KEY_P 'p' // Keyboard p and P
#define KEY_Q 'q' // Keyboard q and Q
#define KEY_R 'r' // Keyboard r and R
#define KEY_S 's' // Keyboard s and S
#define KEY_T 't' // Keyboard t and T
#define KEY_U 'u' // Keyboard u and U
#define KEY_V 'v' // Keyboard v and V
#define KEY_W 'w' // Keyboard w and W
#define KEY_X 'x' // Keyboard x and X
#define KEY_Y 'y' // Keyboard y and Y
#define KEY_Z 'z' // Keyboard z and Z

#define KEY_1 '1' // Keyboard 1 and !
#define KEY_2 '2' // Keyboard 2 and @
#define KEY_3 '3' // Keyboard 3 and #
#define KEY_4 '4' // Keyboard 4 and $
#define KEY_5 '5' // Keyboard 5 and %
#define KEY_6 '6' // Keyboard 6 and ^
#define KEY_7 '7' // Keyboard 7 and &
#define KEY_8 '8' // Keyboard 8 and *
#define KEY_9 '9' // Keyboard 9 and (
#define KEY_0 '0' // Keyboard 0 and )

#define KEY_LEFTBRACE '['
#define KEY_RIGHTBRACE ']'

#define LAYER_KEY 0xff+1
#define LAYER(layer) (0xff+layer)