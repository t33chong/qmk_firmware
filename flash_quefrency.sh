#!/bin/bash -e

qmk compile -kb keebio/quefrency/rev3 -km t33chong
qmk flash -kb keebio/quefrency/rev3 -km t33chong
