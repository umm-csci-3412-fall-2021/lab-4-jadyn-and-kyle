#!bin/bash

path=$1

countDir=$(find $path -type d | wc -l | xargs)

echo "There are "$countDir" directories."

countFile=$(find $path -type f | wc -l | xargs)

echo "And, there are "$countFile" regular files."


