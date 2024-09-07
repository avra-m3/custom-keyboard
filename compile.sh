#! /bin/bash

set -eufx


BOARDNAME="rp2040:rp2040:rpipicow"

arduino-cli compile --fqbn "$BOARDNAME" --board-options ipbtstack=ipv4btcble keyboard