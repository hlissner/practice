#!/usr/bin/env node

require("fs").readFileSync(file).toString().trim().split('\n').forEach(function(line) {
    if (line.trim() != "") {
        var set = line.split(",").filter(function (val, i, io) { return (i==io.indexOf(val)); });
        set.sort(function (x, y) { return x - y; });
        console.log(set.join(","));
    }
});
