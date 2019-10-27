#!/usr/bin/env node

var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== "") {
        var input = line.split(",");
        var n = parseInt(input[0]),
            i = parseInt(input[1]),
            j = parseInt(input[2]);

        var a = (n >> (i-1)) & 1;
        var b = (n >> (j-1)) & 1;
        console.log(a == b ? "true" : "false");
    }
});
