<?php
// 008: Largest product in a series - PHP
// https://projecteuler.net/problem=8
//
// The four adjacent digits in the 1000-digit number that have the greatest product
// are 9 × 9 × 8 × 9 = 5832.
//
//    <SNIP> (See number string below)
//
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest
// product. What is the value of this product?

function largest_product($mask, $ahead) {
    $max = 0;
    $len = strlen($mask);
    for ($i=0; $i < $len-$ahead; ++$i) {
        $sum = intval($mask[$i]);
        if ($sum == 0) continue;
        for ($j=1; $j<$ahead; ++$j) {
            $sum *= intval($mask[$i + $j]);
        }
        if ($sum > $max) {
            $max = $sum;
        }
    }
    return $max;
}

echo largest_product(
    "731671765313306249192251196744265747423553491949349" .
    "698352031277450632623957831801698480186947885184385" .
    "861560789112949495459501737958331952853208805511125" .
    "406987471585238630507156932909632952274430435576689" .
    "664895044524452316173185640309871112172238311362229" .
    "893423380308135336276614282806444486645238749303589" .
    "072962904915604407723907138105158593079608667017242" .
    "712188399879790879227492190169972088809377665727333" .
    "001053367881220235421809751254540594752243525849077" .
    "116705560136048395864467063244157221553975369781797" .
    "784617406495514929086256932197846862248283972241375" .
    "657056057490261407972968652414535100474821663704844" .
    "031998900088952434506585412275886668811642717147992" .
    "444292823086346567481391912316282458617866458359124" .
    "566529476545682848912883142607690042242190226710556" .
    "263211111093705442175069416589604080719840385096245" .
    "544436298123098787992724428490918884580156166097919" .
    "133875499200524063689912560717606058861164671094050" .
    "775410022569831552000559357297257163626956188267042" .
    "8252483600823257530420752963450", 13);

