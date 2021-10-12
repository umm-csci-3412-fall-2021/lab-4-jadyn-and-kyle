#!/usr/bin/env bash

path=$1
 
cd "$path" || exit

countDir=$(find . -type d | wc -l) 
countFile=$(find . -type f | wc -l)

echo "There were $countDir directories."
echo "There were $countFile regular files."


