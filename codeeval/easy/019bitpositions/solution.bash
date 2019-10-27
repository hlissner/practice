#!/bin/bash

# Was not accepted by codeeval. "Unrecognized error"
# Works in Bash 4.3.42 however

while read line || [[ -n "$line" ]]; do
    arrIn=(${line//,/ })
    n=${arrIn[0]}
    a=$(( ($n >> (${arrIn[1]} - 1)) & 1 ))
    b=$(( ($n >> (${arrIn[2]} - 1)) & 1 ))
    (( $a == $b )) && echo true || echo false
done < $1
