#!/usr/bin/env node

require("fs").readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    line = line.trim();
    if (line != "") {
        var res = line.split(", ");
        var re = new RegExp("["+res[1].trim()+"]", 'ig');
        res[0] = res[0].replace(re, "");
        console.log(res[0].trim());
    }
});
