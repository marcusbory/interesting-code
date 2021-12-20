// Syntax
// const fruits = [
//   {name: "apple", weight: "100g"},
//   {name: "banana", weight: "80g"},
//   {name: "orange", weight: "70g"},
//   {name: "grape", weight: "200g"}
// ]

// // Basic for loop
// for (let i = 0; i < fruits.length; i++) {
//   console.log(`Name: ${fruits[i].name}, Weight: ${fruits[i].weight}`)
// }

// // Using forEach loop
// fruits.forEach(fruit => console.log(`Name: ${fruit.name}, Weight: ${fruit.weight}`))

// Obvious
// const fruits = [
//   { name: "apple", weight: "100g" },
//   { name: "banana", weight: "80g" },
//   { name: "orange", weight: "70g" },
//   null, null, null,
//   { name: "grape", weight: "200g" }
// ]

// // Basic for loop to add fruits before hitting null
// let fruitBowl1 = []
// let iterator1 = 0
// const getFruit1 = () => {
//   for (; iterator1 < fruits.length; iterator1++) {
//     if (fruits[iterator1] === null) {
//       return
//     }
//     fruitBowl1.push(fruits[iterator1])
//   }
// }
// getFruit1()

// // Using forEach loop to add fruits before hitting null
// let fruitBowl2 = []
// let iterator2 = 0
// const getFruit2 = () => {
//   fruits.forEach(fruit => {
//     iterator2++
//     if (fruit === null) {
//       return
//     }
//     fruitBowl2.push(fruit)
//   })
// }
// getFruit2()

// console.log(fruitBowl1)
// console.log("for loop iterations: " + iterator1)
// console.log(fruitBowl2)
// console.log("forEach loop iterations: " + iterator2)

// Subtle
const {performance} = require('perf_hooks')

const getFruitWeight = (index) => {
  return new Promise(resolve => {
    const fruits = [
      {name: "apple", weight: "100g"},
      {name: "banana", weight: "80g"},
      {name: "orange", weight: "70g"},
      {name: "grape", weight: "200g"}
    ]
    
    setTimeout(() => {
      resolve(fruits[index].weight)
    }, 1000)
  })
}

const getFruitName = (index) => {
  return new Promise(resolve => {
    const fruits = [
      {name: "apple", weight: "100g"},
      {name: "banana", weight: "80g"},
      {name: "orange", weight: "70g"},
      {name: "grape", weight: "200g"}
    ]
    
    setTimeout(() => {
      resolve(fruits[index].name)
    }, 2000)
  })
}

const requests = [{index: 1, get: "W"}, {index: 2, get: "N"}, {index: 3, get: "N"}, {index: 0, get: "W"}]

const makeArrayUsingFor = async () => {
  let compiledArray = []
  for (let i = 0; i < requests.length; i++) {
    if (requests[i].get === "W") {
      compiledArray.push(await getFruitWeight(requests[i].index))
    } else {
      compiledArray.push(await getFruitName(requests[i].index))
    }
  }
  return compiledArray
}

const makeArrayUsingForEach = async () => {
  let compiledArray = []
  requests.forEach(async (request) => {
    if (request.get === "W") {
      compiledArray.push(await getFruitWeight(request.index))
    } else {
      compiledArray.push(await getFruitName(request.index))
    }
  })
  return compiledArray
}

const makeArrayUsingMap = async () => {
  let compiledArray = await Promise.all(requests.map(async (request) => {
    if (request.get === "W") {
      return await getFruitWeight(request.index)
    } else {
      return await getFruitName(request.index)
    }
  }))
  return compiledArray
}

const printFetchedArrays = async () => {
  let startTime = performance.now()
  const forLoopArray = await makeArrayUsingFor()
  let endTime = performance.now()
  console.log(`For Loop: ${forLoopArray} - time: ${endTime - startTime}ms`)
  // startTime = performance.now()
  // const forEachLoopArray = await makeArrayUsingForEach()
  // endTime = performance.now()
  // console.log(`For Each Loop: ${forEachLoopArray} - time: ${endTime - startTime}s`)
  startTime = performance.now()
  const mapArray = await makeArrayUsingMap()
  endTime = performance.now()
  console.log(`Map: ${mapArray} - time: ${endTime - startTime}ms`)
}

printFetchedArrays()