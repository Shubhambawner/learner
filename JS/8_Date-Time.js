dt = new Date(); // date object, constantly changes
dt2 = Date() //string of current time when loaded
//'Sun Nov 14 2021 22:24:56 GMT+0530 (India Standard Time)'

dt.getFullYear() //2021
dt.getMonth() // 10
dt.getDate() //14
dt.getDay() // 0 (monday)
dt.getHours() // 22 (gets hours passed in a day)
dt.getMinutes() // 24 (minutes of the hour)
dt.getSeconds() // 

dt.getTime()
//1636909283290 total milliseconds passed since 1960 1 aug...

//time handling-------------------------------------------------------------

setTimeout(
    function () {
        console.log("time's up1!")
    }, 
    50000 //milliseconds
)

setInterval(
    function () {
        console.log("time's going!!")
    }, 
    5000 //milliseconds
)

