#!/usr/bin/env sh

for file in $@; do
    cat "$file" | tr '[:upper:]' '[:lower:]'
done
