#!/usr/bin/env node

var lines = require("fs").readFileSync(process.argv[2]).toString().trim().split('\n');
var n = lines.shift();
lines.sort(function(a, b) {
    return a.length >= b.length ? -1 : 1;
});

console.log(lines.slice(0, n).join("\n"));
