#!/bin/bash -e

qmk compile -kb keebio/fourier -km t33chong_
qmk flash -kb keebio/fourier -km t33chong_
