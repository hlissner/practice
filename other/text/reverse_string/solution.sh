#!/usr/bin/env sh

# First solution - works in bash
read string
for ((i=${#string}-1; i>=0; i--)); do
    echo -n "${string:i:1}"
done

echo

# Second solution (for sh)
# the -n flag doesn't work in sh, so here's an alternative:
reversed=""
for ((i=${#string}-1; i>=0; i--)); do
    reversed="$reversed${string:i:1}"
done

echo $reversed
