import System.IO

add3 :: Int -> Int 
add3 = (+3)

mul2 :: Int -> Int
mul2 = (*2)

mycompute :: Int -> IO Int
mycompute v0 = do
    putStrLn ("add3 " ++ show v0)
    let v1 = add3 v0
    putStrLn ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

mycomputeFile :: Int -> IO Int
mycomputeFile v0 = do
    file <- openFile "log.txt" WriteMode
    hPutStrLn file ("add3 " ++ show v0)
    let v1 = add3 v0
    hPutStrLn file ("mul2 " ++ show v1)
    let v2 = mul2 v1
    hClose file
    return v2

mycomputeF :: (String -> IO()) -> Int -> IO Int
mycomputeF logF v0 = do
    logF ("add3 " ++ show v0)
    let v1 = add3 v0
    logF ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

main :: IO ()
main = do
    putStrLn "this is log-hs"
    
    res <- mycompute 18
    print res

    resFile <- mycomputeFile 18
    print resFile

    res2 <- mycomputeF putStrLn 18
    print res2

    hF <- openFile "logF.txt" WriteMode
    res3 <- mycomputeF (hPutStrLn hF) 18
    hClose hF
    print res3
