#!/bin/bash
POS_FLT_MIN="1.1754943509e-38"
POS_FLT_MIN_LESS="1.1754943507e-38"
POS_FLT_MAX="3.4028234663e+38"
POS_FLT_MAX_MORE="3.4028234664e+38"
SRC_DIR="$1"

# Test Minimum values are allowed
$SRC_DIR/quad_solver -n $POS_FLT_MIN 1 1 > /dev/null
OUT_A=$?
$SRC_DIR/quad_solver -n 1 $POS_FLT_MIN 1 > /dev/null
OUT_B=$?
$SRC_DIR/quad_solver -n 1 1 $POS_FLT_MIN > /dev/null
OUT_C=$?
if [ $OUT_A != 0 ] || [ $OUT_B != 0 ] || [ $OUT_C != 0 ]; then
    echo "Quad Solver should allow values equal to $POS_FLT_MIN"
    echo "A: $OUT_A B: $OUT_B C: $OUT_C"
fi

# Test less than Minimum values are NOT allowed
$SRC_DIR/quad_solver -n $POS_FLT_MIN_LESS 1 1 > /dev/null
OUT_A=$?
$SRC_DIR/quad_solver -n 1 $POS_FLT_MIN_LESS 1 > /dev/null
OUT_B=$?
$SRC_DIR/quad_solver -n 1 1 $POS_FLT_MIN_LESS > /dev/null
OUT_C=$?
if [ $OUT_A == 0 ] || [ $OUT_B == 0 ] || [ $OUT_C == 0 ]; then
    echo "Quad Solver should not allow values less than $POS_FLT_MIN"
fi

# Test Maximum values are allowed
$SRC_DIR/quad_solver -n $POS_FLT_MAX 1 1 > /dev/null
OUT_A=$?
$SRC_DIR/quad_solver -n 1 $POS_FLT_MAX 1 > /dev/null
OUT_B=$?
$SRC_DIR/quad_solver -n 1 1 $POS_FLT_MAX > /dev/null
OUT_C=$?
if [ $OUT_A != 0 ] || [ $OUT_B != 0 ] || [ $OUT_C != 0 ]; then
    echo "Quad Solver should allow values equal to $POS_FLT_MAX"
    echo "A: $OUT_A B: $OUT_B C: $OUT_C"
fi

# Test more than Maximum values are NOT allowed
$SRC_DIR/quad_solver -n $POS_FLT_MAX_MORE 1 1 > /dev/null
OUT_A=$?
$SRC_DIR/quad_solver -n 1 $POS_FLT_MAX_MORE 1 > /dev/null
OUT_B=$?
$SRC_DIR/quad_solver -n 1 1 $POS_FLT_MAX_MORE > /dev/null
OUT_C=$?
if [ $OUT_A == 0 ] || [ $OUT_B == 0 ] || [ $OUT_C == 0 ]; then
    echo "Quad Solver should not allow values more than $POS_FLT_MAX"
fi
