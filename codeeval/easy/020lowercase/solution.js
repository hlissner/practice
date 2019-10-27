#!/usr/bin/env node

console.log(require('fs').readFileSync(process.argv[2]).toString().toLowerCase());
