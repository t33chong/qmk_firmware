#!/bin/bash -e

qmk compile -kb dz60 -km t33chong
qmk flash -kb dz60 -km t33chong
