`use strict`
const mysql = require('mysql');
const axios = require('axios');
const fs = require('fs');

var access = fs.createWriteStream('output.log');
process.stdout.write = process.stderr.write = access.write.bind(access);

var queries = [

    // get all the data from the database
    "select * from nse_stocks_nitrr_tp;",
    
    // find all the penny stocks (price < 1)
    "select * from `nse_stocks_nitrr_tp` where lastPrice < 100;",
    
    // find most profitable penny stock of the day
    "select symbol, max(lastPrice - open) as dayProfit from `nse_stocks_nitrr_tp` where lastPrice < 100;",
    
    // find volume wise distribution of the penny stocks
    "select symbol, totalTradedVolume, open from `nse_stocks_nitrr_tp` where lastPrice < 100;",
    
    // find the penny stock with highest volume
    "select symbol, max(totalTradedVolume) from `nse_stocks_nitrr_tp` where lastPrice < 100;",
    
    // find all  profit making penny stocks of the day
    "select symbol,lastPrice,open  from `nse_stocks_nitrr_tp` where lastPrice - open > 0 and lastPrice < 100;",
    
    // find all  loss making penny stocks of the day
    "select symbol,lastPrice,open  from `nse_stocks_nitrr_tp` where lastPrice - open < 0 and lastPrice < 100;",
    
    // find all the highly priced stocks (price > 1000)
    "select * from `nse_stocks_nitrr_tp` where lastPrice  > 1000;",
    
    // find most profitable  highly priced stock of the day
    "select symbol, max(lastPrice - open) as dayProfit from `nse_stocks_nitrr_tp` where lastPrice  > 1000;",
    
    // find volume wise distribution of the highly priced stock
    "select symbol, totalTradedVolume from `nse_stocks_nitrr_tp` where lastPrice > 1000;",
    
    // find the  highly priced stock  with highest volume
    "select symbol, max(totalTradedVolume) as volume from `nse_stocks_nitrr_tp` where lastPrice > 1000;",
    
    // find all of profit making highly priced stocks of the day
    "select symbol,lastPrice,open  from `nse_stocks_nitrr_tp` where lastPrice - open > 0 and lastPrice > 1000;",
    
    // find all  loss making highly priced stocks of the day
    "select symbol,lastPrice,open  from `nse_stocks_nitrr_tp` where lastPrice - open < 0 and lastPrice > 1000;",
    
    // add % change column
    "select symbol,lastPrice,open,100*(lastPrice - open)/open as `%change` from `nse_stocks_nitrr_tp`;",
    
    // find all the stocks with % change > 10
    "select * from `nse_stocks_nitrr_tp` where 100*(lastPrice - open)/open > 10;",
    
    // volume and % change wise distribution of the stocks
    "select symbol, totalTradedVolume, 100*(lastPrice - open)/open from `nse_stocks_nitrr_tp` ",
]

var description = [
    `get all the data from the database`,
    `find all the penny stocks (price < 1)`,
    `find most profitable penny stock of the day`,
    `find volume wise distribution of the penny stocks`,
    `find the penny stock with highest volume`,
    `find all  profit making penny stocks of the day`,
    `find all  loss making penny stocks of the day`,
    `find all the highly priced stocks (price > 1000)`,
    `find most profitable  highly priced stock of the day`,
    `find volume wise distribution of the highly priced stock`,
    `find the  highly priced stock  with highest volume`,
    `find all of profit making highly priced stocks of the day`,
    `find all  loss making highly priced stocks of the day`,
    `add % change column`,
    `find all the stocks with % change > 10`,
    `volume and % change wise distribution of the stocks`,

]

let connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'shubham123!@#',
    database: 'nsedata'
});

if (connection)
    console.log(`connection established at ${Date()}\n\n`);

let args = process.argv.slice(2)

try {

    if (args[0] === `help`) {
        console.log({ ...description });
    } else {
        if (args.length === 0)
            args = [...Object.keys(description)]
        getData()
            .then(data => {
                saveData(data)

                handleArgs(args)
                    .then(() => {
                        terminate()
                    })
            }
            );

    }



} catch (e) {
    console.log(e);
}

async function handleArgs(args) {
    try {
        args = args.map(arg => {
            return getDataFromDB(queries[arg]).then(data => {
                console.log(`searching for :${description[arg]} :`);
                console.log(queries[arg]);

                printArray(data);

                console.log(`\n`);
            })
        })
        await Promise.all(args)
        return;

    } catch (e) { console.log(e) }
}

async function getData() {
    try {
        var config = {
            method: 'get',
            url: 'https://api.jsonbin.io/b/628b7256402a5b3802099c19',
            headers: {
                'X-Master-Key': '$2b$10$T0WrN9kitv2YU1CKvdkizuE5O/jw5oZT5zfsWLR2XSp9qfqqEE3HK',
                'X-Access-Key': '$2b$10$9wBzKHmW1qNjvX8BFPVsW.TEzRjuWDpNpm0Ya.F3e.avzslHe9Qzy'
            }
        };
        return new Promise((resolve, reject) => {
            axios(config)
                .then(data => {
                    resolve(data.data)
                })
                .catch(err => {
                    console.log(`err`, err)
                    reject(err)
                }
                )

        })
    } catch (e) { console.log(e) }
}

function saveData(data) {

    try {
        let createStocksTable = `create table if not exists nse_stocks_nitrr_tp(
                                id int primary key auto_increment,
                                symbol varchar(255)not null,
                                open INT(255) not null default 0,
                                dayHigh INT(255) not null default 0,
                                dayLow INT(255) not null default 0,
                                lastPrice INT(255) not null default 0,
                                previousClose INT(255) not null default 0,
                                yearHigh INT(255) not null default 0,
                                yearLow INT(255) not null default 0,
                                totalTradedVolume INT(255) not null default 0
                            )`;


        let clearStocksTable = `DROP TABLE IF EXISTS nse_stocks_nitrr_tp`;

        connection.query(clearStocksTable, function (err, results, fields) {
            if (err) {
                console.log(err.message);
            }
        })
        connection.query(createStocksTable, function (err, results, fields) {
            if (err) {
                console.log(err.message);
            }
        });

        for (let i = 0; i < data
            .length; i++) {    // insert statment
            let script = data[i]
            let sql = `INSERT INTO nse_stocks_nitrr_tp(symbol,open,dayHigh,dayLow,lastPrice,previousClose,yearHigh,yearLow,totalTradedVolume)
        VALUES('${script.symbol}',${script.open},${script.dayHigh},${script.dayLow},${script.lastPrice},${script.previousClose},${script.yearHigh},${script.yearLow},${script.totalTradedVolume})`;

            
        // execute the insert statment
            connection.query(sql);
        }
    } catch (e) {
        console.log(e);
    }

}

function getDataFromDB(query) {

    try {
        return new Promise((resolve, reject) => {
            connection.query(query, function (err, results, fields) {
                if (err) {
                    console.log(err.message);
                }
                resolve(results)
            });
        })
    } catch (e) { console.log(e) }
}

function terminate() {
    connection.end(function (err) {
        if (err) {
            console.log(err.message);
        }
        console.log(`connection terminated at ${Date()}`);
    });
}

function printArray(arr) {
    try {
        for (let i = 0; i < arr.length && i < 5; i++) {
            console.log(JSON.stringify(arr[i]));
        }
        if (arr.length >= 5)
            console.log(` and ${arr.length - 5} more`);
    } catch (e) { console.log(e) }
}

function getObjectFromRowDataPacket() {
    try {
        let keys = Object.keys(data[0]);
        data = data.map(script => {
            let share = {}
            keys.forEach(key => {
                share[key] = script[key]
            })
            return share;
        })
        
        // console.log(data);
    } catch (e) { console.log(e) }
}