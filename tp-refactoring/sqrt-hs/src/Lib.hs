module Lib where

mysqrt :: Double -> Maybe Double
mysqrt x = 
    if x < 0
        then Nothing
        else Just (sqrt x)
