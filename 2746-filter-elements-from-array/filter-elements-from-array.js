/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const arr2 = [];
    arr.forEach((num, i)=>{
        if(fn(num, i)) arr2.push(num);
    })
    return arr2;
};