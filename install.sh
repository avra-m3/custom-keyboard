#! /bin/bash

set -eufx


BOARDNAME="rp2040:rp2040:rpipicow"
PORT="$(arduino-cli board list | grep RP2040 | head -n 1 | grep -o -E "^\/dev\/[a-zA-Z0-9\.]+")"

./compile.sh

arduino-cli upload -p "$PORT" --fqbn "$BOARDNAME" keyboard