#!/usr/bin/env php
<?php

$fh = fopen($argv[1], "r");
while (($line = fgets($fh)) !== FALSE) {
    list($n, $i, $j) = explode(",", $line, 3);
    $n = (int) $n;
    $a = ($n >> ((int) $i-1)) & 1;
    $b = ($n >> ((int) $j-1)) & 1;
    echo (($a == $b) ? "true" : "false") . "\n";
}
