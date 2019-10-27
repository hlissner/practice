#!/usr/bin/env node

require("fs").readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line != "") {
        var input = line.split(",");
        console.log(input[0] % input[1]);
    }
});
