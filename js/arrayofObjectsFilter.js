// Array of objects filter
// Complete the function getPassingTests such that it returns all the test results that 
// have a passing grade (10 and above).
/**
 * @param {object[]} results
 */
//   function getPassingTests(results) {
//     const sol = results.filter(result => result.grade>=10 );
//     return sol
//  }

function getPassingTests(results) {
    return results.filter(result => result.grade>=10 );
}



// sample usage (do not modify)
const data = [{
    id: 1,
    grade: 10
}, {
    id: 2,
    grade: 4
}, {
    id: 3,
    grade: 18
},{
    id:4,
    grade:29
}]
console.log(getPassingTests(data))
