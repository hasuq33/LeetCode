/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k){
    return (nums.reduce((acc,curr)=> acc^curr, 0)^k).toString(2).split('1').length - 1;
}