
import Data.List

main :: IO ()
main = putStrLn (intercalate "\n" [ show x | x <- [1,3..99] ])
