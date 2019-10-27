#!/usr/bin/env php
<?php

// I'm least familiar with unicode shenanigans in PHP, mostly because it's been
// all over the place over the years so I couldn't bother to figure it out,
// until now.
//
// However, it dawned on me that PCRE is effective at isolating unicode
// characters, so...
preg_match_all('/./us', fgets(STDIN), $array);
echo join('', array_reverse($array[0]));

// When in doubt, trust in regex