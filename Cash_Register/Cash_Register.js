function checkCashRegister(price, cash, cid) {
const currencyUnits = [
["PENNY", 0.01],
["NICKEL", 0.05],
["DIME", 0.1],
["QUARTER", 0.25],
["ONE", 1],
["FIVE", 5],
["TEN", 10],
["TWENTY", 20],
["ONE HUNDRED", 100]
];
let changeDue = cash - price;
let totalCID = cid.reduce((sum, curr) => sum + curr[1], 0);
// Round to avoid floating point precision issues
totalCID = Math.round(totalCID * 100) / 100;
if (totalCID < changeDue) {
return { 
status: "INSUFFICIENT_FUNDS", change: [] 
};
} else if (totalCID === changeDue) {
return { status: "CLOSED", change: cid };
} else {
let changeArr = [];
let remainingChange = changeDue;
// Iterate from highest to lowest denomination
for (let i = currencyUnits.length - 1; i >= 0; i--) {
let unitName = currencyUnits[i][0];
let unitValue = currencyUnits[i][1];
let unitAvailable = cid[i][1];
let unitToReturn = 0;
while (remainingChange >= unitValue && unitAvailable > 0) {
remainingChange = Math.round((remainingChange - unitValue) * 100) / 100;
unitAvailable = Math.round((unitAvailable - unitValue) * 100) / 100;
unitToReturn = Math.round((unitToReturn + unitValue) * 100) / 100;
}
if (unitToReturn > 0) {
changeArr.push([unitName, unitToReturn]);
}
}
if (remainingChange > 0) {
return { 
status: "INSUFFICIENT_FUNDS", change: [] 
};
}
return { 
status: "OPEN", change: changeArr 
};
}
}