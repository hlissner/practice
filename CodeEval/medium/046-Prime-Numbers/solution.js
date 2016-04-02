#!/usr/bin/env node

function write(s) {
    process.stdout.write(s);
}

function isprime(n) {
    if (n % 2 === 0) return false;
    var sqt = parseInt(Math.sqrt(n));
    for (var i = 3; i <= sqt; i += 2) {
        if (n % i === 0) return false;
    }
    return true;
}

function primes(n) {
    if (n > 2) write("2");
    for (var i = 3; i < n; i += 2) {
        if (isprime(i)) write("," + i.toString());
    }
    write("\n");
}

require("fs").readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    line = line.trim();
    if (line !== "") {
        primes(parseInt(line));
    }
});
