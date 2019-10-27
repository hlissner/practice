#!/usr/bin/env php
<?php
$lines = explode("\n", trim(file_get_contents($argv[1])));
foreach ($lines as $line) echo array_sum(str_split($line)) . "\n";
