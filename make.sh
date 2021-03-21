#!/bin/bash
function get_command_line(){
    local FN=$1
    local OUT=$2
    echo "g++-10 -std=c++20 -fconcepts -W -Wall -Wextra -pedantic -Iextern/cpp11-range/ -Iextern/cpp11_range/include -Iextern/kennytm_utils_traits/include -Iextern/eigen -Iinclude -g $FN -o $OUT"
}

./get-extern.sh
echo "[" > compile_commands.json

FILENAME="include/cpp11_fp_list_functions/circularlistfunctions.h"
OUTPUT="circularlistfunctions"
COMMAND=$(get_command_line $FILENAME $OUTPUT)
./generate_compile_commands_json.sh "$COMMAND" "$FILENAME" "inner"

FILENAME="include/cpp11_fp_list_functions/listfunctions.h"
OUTPUT="listfunctions"
COMMAND=$(get_command_line $FILENAME $OUTPUT)
./generate_compile_commands_json.sh "$COMMAND" "$FILENAME" "inner"

FILENAME="include/cpp11_fp_list_functions/listfunctionseigen.h"
OUTPUT="listfunctionseigen"
COMMAND=$(get_command_line $FILENAME $OUTPUT)
./generate_compile_commands_json.sh "$COMMAND" "$FILENAME" "inner"

FILENAME="include/cpp11_fp_list_functions/circularlistfunctions.h"
OUTPUT="circularlistfunctions"
COMMAND=$(get_command_line $FILENAME $OUTPUT)
./generate_compile_commands_json.sh "$COMMAND" "$FILENAME" "inner"

FILENAME="test.cpp"
OUTPUT="test"
COMMAND=$(get_command_line $FILENAME $OUTPUT)
./generate_compile_commands_json.sh "$COMMAND" "$FILENAME" "last"

echo "]" >> compile_commands.json
$COMMAND
