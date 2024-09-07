#include <array>
#include <string.h>
#include "definitions.h"
#include "left.h"

#include <Keyboard.h>
#include <KeyboardBLE.h>

// TODO:
// - in setup, check if we are plugged in and if so use HID, not BLE
// - split half communication

typedef struct Layer {
    int val;
    int col;
    int row;
    struct Layer *next;
} Layer;

unsigned int keyboard_state[num_rows][num_cols] = {};

Layer current_layer;


constexpr unsigned int PRESS_KEYS[3] = {
    KEY_LEFT_SHIFT,
    KEY_LEFT_CTRL,
    KEY_LEFT_ALT,
};


void setup() {
    current_layer.val = 0;
    current_layer.row = -1;
    current_layer.col = -1;
    current_layer.next = NULL;

    for (int col = 0; col < num_cols; col++) {
        pinMode(col_pins[col], OUTPUT);
        digitalWrite(col_pins[col], HIGH);
    };


    for (int row = 0; row < num_rows; row++) {
        pinMode(row_pins[row], INPUT_PULLUP);
    };

    /** Turn LED ON **/
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    Serial.begin(115200);
    KeyboardBLE.begin();
    delay(1000);
    
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
    bool isPressed = false;
    for (int col = 0; col < num_cols; col++) {
        digitalWrite(col_pins[col], LOW);
        delayMicroseconds(5);

        for (int row = 0; row < num_rows; row++) {
            if (digitalRead(row_pins[row]) == LOW) {
                // Key pressed
                press(row, col);
            } else {
                release(row, col);
            }
        }
        digitalWrite(col_pins[col], HIGH);
    }
    if (!isPressed) {
        digitalWrite(LED_BUILTIN, HIGH);
    }
}

void press(int row, int col) {
    if (keyboard_state[row][col] == STATE_UP) {
        const unsigned int target_key = layout[current_layer.val][row][col];
        keyboard_state[row][col] = target_key;
        if (isLayerKey(target_key)) {
            shiftLayer(target_key, row, col);
        } else {
            keyDown(target_key, row, col);
        }
        keyboard_state[row][col] = target_key;
    }
}

void release(int row, int col) {
    if (keyboard_state[row][col] != STATE_UP) {
        const unsigned int target = keyboard_state[row][col];

        if (isLayerKey(target)) {
            unshiftLayer(target, row, col);
        } else {
            keyUp(target, row, col);
        }

        keyboard_state[row][col] = STATE_UP;
    }
}

bool isLayerKey(unsigned int key) {
    return key >= LAYER_KEY;
}


void shiftLayer(unsigned int key, int row, int col) {
    int new_value = key - LAYER_KEY;

    Layer new_head;
    new_head.row = row;
    new_head.col = col;
    new_head.val = new_value;
    new_head.next = & current_layer;

    current_layer = new_head;
}

void keyDown(unsigned int key, int row, int col) {
    KeyboardBLE.press(key);
}

void keyUp(unsigned int key, int row, int col) {
    KeyboardBLE.release(key);
}

void unshiftLayer(unsigned int key, int row, int col) {
    int layer_to_unwind = key - LAYER_KEY;

    Layer * l = & current_layer;
    while(l != NULL){
        if(l->row == row && l->col == col && l->val == layer_to_unwind){
            current_layer = * l->next;
            free(l);
            l = NULL;
            break;
        }
        l = l->next;
    }
}