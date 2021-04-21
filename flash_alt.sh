#!/bin/bash -e

qmk compile -kb massdrop/alt -km t33chong
mdloader --first --download massdrop_alt_t33chong.bin --restart
