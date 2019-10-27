console.log(require('fs').readFileSync(process.argv[2]).toString().split("\n").map(
    function(line) {
        return line.split(" ").reverse().join(" ");
    }
).join("\n"));
