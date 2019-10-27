#!/usr/bin/env php
<?php

$fh = fopen($argv[1], "r");
while (($line = fgets($fh)) !== FALSE) {
    list($n, $m) = explode(",", $line, 2);
    echo $n % $m;
    echo "\n";
}
