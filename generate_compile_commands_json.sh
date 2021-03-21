#!/bin/bash
if [ -f compile_commands.json ]
then
    grep -F -q "$1" compile_commands.json && exit 0
fi

echo "    {" >> compile_commands.json
echo "        \"command\": \"$1\","  >> compile_commands.json
echo "        \"directory\": \"$PWD\","  >> compile_commands.json
echo "        \"file\": \"$2\""  >> compile_commands.json
if [ $3 == "last" ]
then
    echo "    }" >> compile_commands.json
else
    echo "    }," >> compile_commands.json
fi
