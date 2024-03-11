function mul2(n) {
    return n*2;
}

function make_handler(target, input) {
    return () => target.innerText = mul2(input.value)
}