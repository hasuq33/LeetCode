/**
 * 
 * @param {number[]} nums 
 * @param {number} k 
 * @param {number[][]} edges 
 * @returns { number}
 */

var maximumValueSum = function(nums, k , edges){
    let totalSum = 0;
    let count = 0;
    let positiveMin = Infinity;
    let negetiveMax = -Infinity;

    for(let nodeValue of nums){
        let nodeValueafterOperations = nodeValue ^ k;
        totalSum += nodeValue;
        let netChange = nodeValueafterOperations - nodeValue;

        if(netChange > 0){
            positiveMin = Math.min(positiveMin, netChange);
            totalSum += netChange;
            count +=1;
        }else{
            negetiveMax = Math.max(negetiveMax, netChange);
        }
    }

    if(count %2 === 0){
        return totalSum;
    }

    return Math.max(totalSum - positiveMin, totalSum + negetiveMax);

}