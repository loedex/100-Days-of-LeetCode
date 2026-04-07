var isHappy = function(n){
    const seen = new Set();
    while(n!==1 && !(seen.has(n))){
        seen.add(n);
        n = findsquare(n);
    }
    return n==1;
}
var findsquare = function(num){
    let totalSum = 0;
    while(num>0){
        let digit = num%10;
        totalSum+=digit*digit;
        num = Math.floor(num/10);
    }
    return totalSum;
}
let number = 2;
console.log(isHappy(number));