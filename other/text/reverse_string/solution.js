#!/usr/bin/env node

process.stdin.once('data', function(line) {
    line = line.toString().trim();

    process.stdout.write("Naive reverse: " + line.split("").reverse().join("") + "\n");

    process.stdout.write("Proper reverse: " + reverse(line));

    process.exit();
});

// So why not just use line.split("").reverse().join("")? Because of the way
// javascript represents four-byte astral symbols (as surrogate pairs in
// Javascript, see: https://mathiasbynens.be/notes/javascript-encoding#surrogate-pairs)
// doesn't handle four-byte astral characters. Worst. Possible. Thing!
function reverse(str) {
	str = str.replace(/([\0-\u02FF\u0370-\u1DBF\u1E00-\u20CF\u2100-\uD7FF\uDC00-\uFE1F\uFE30-\uFFFF]|[\uD800-\uDBFF][\uDC00-\uDFFF]|[\uD800-\uDBFF])([\u0300-\u036F\u1DC0-\u1DFF\u20D0-\u20FF\uFE20-\uFE2F]+)/g, function($0, $1, $2) {
		return reverse($2) + $1;
	}).replace(/([\uD800-\uDBFF])([\uDC00-\uDFFF])/g, '$2$1');

	var result = '';
	var index = str.length;
	while (index--)
		result += str[index];
	return result;
}
