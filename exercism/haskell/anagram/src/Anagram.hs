module Anagram (anagramsFor) where

import Data.Char (toLower, isAlpha)
import Data.List (sort)

downcase :: String -> String
downcase s = [ toLower c | c <- s, isAlpha c ]

isAnagram :: String -> String -> Bool
isAnagram s o
    | length s /= length o = False
    | str == other = False
    | otherwise = sort str == sort other
    where str = downcase s
          other = downcase o

anagramsFor :: String -> [String] -> [String]
anagramsFor str xs = filter (isAnagram str) xs
