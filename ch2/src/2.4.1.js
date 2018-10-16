function calc(st) {
    var str = String(st);
    console.log(str);
    var sum = 0;
    var c = 0.5;
    for (var i = 0; i < str.length; i++) {
        if (str[i] === '1') {
            sum += c;
            c /= 2;
        } else if (str[i] === '0') {
            c /= 2;
        }
    }
    console.log(sum);
    return sum;
}

calc('010011001100110011001101');