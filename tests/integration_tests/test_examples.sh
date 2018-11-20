#!/bin/bash
SRC_DIR="$1"


$SRC_DIR/quad_solver <<< "5 6 1" > out.tmp && \
diff out.tmp expected_5_6_1.txt

if [ $? != 0 ]; then
    echo "Failed on: 5 6 1"
fi

$SRC_DIR/quad_solver <<< "1 -3 -4" > out.tmp && \
diff out.tmp expected_1_-3_-4.txt

if [ $? != 0 ]; then
    echo "Failed on: 1 -3 -4"
fi

$SRC_DIR/quad_solver <<< "1 0 -4" > out.tmp && \
diff out.tmp expected_1_0_-4.txt

if [ $? != 0 ]; then
    echo "Failed on: 1 0 -4"
fi

$SRC_DIR/quad_solver <<< "1 0 4" > out.tmp && \
diff out.tmp expected_1_0_4.txt

if [ $? != 0 ]; then
    echo "Failed on: 1 0 4"
fi

$SRC_DIR/quad_solver <<< "6 11 -35" > out.tmp && \
diff out.tmp expected_6_11_-35.txt

if [ $? != 0 ]; then
    echo "Failed on: 6 11 -35"
fi

$SRC_DIR/quad_solver <<< "1 0 -48" > out.tmp && \
diff out.tmp expected_1_0_-48.txt

if [ $? != 0 ]; then
    echo "Failed on: 1 0 -48"
fi

$SRC_DIR/quad_solver <<< "1 -7 0" > out.tmp && \
diff out.tmp expected_1_-7_0.txt

if [ $? != 0 ]; then
    echo "Failed on: 1 -7 0"
fi