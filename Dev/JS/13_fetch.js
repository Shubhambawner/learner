console.log("hello")


/**
 * to go to any url and get the data the server sends on that url:
 *
fetch("https://reqres.in/api/users?page=2")
    .then(Response => Response.json())
    .then((Res) => {
        console.log(Res)
        //document.getElementById("img").src = Res["avatar_url"]
    });

/**
 * POST request:
 */
 async function postData(url, body, headers) {
    let param =
    {
        method: "post",
        headers: {...headers, "Content-Type": "application/json"},
        body: JSON.stringify(body)
    }

    return await fetch(url, param)
        .then(responce =>{ responce = responce.json();console.log(responce); return responce})
    //.then(r => console.log(r))
}/**/

async function getData(url){
    let Res = await fetch(url)
    .then(Response => Response.json())
    .then(r => {
        console.log(r); 
        Res = r; 
        console.log(Res)
        return r
    });
    return Res;
}

let apiKey = "AIzaSyBPtVgftiyxrfVsi3JxTZqCaXip8YnsTnk"
let sheetID = "1U24tfu-q7KqrRzqPEjh3vHHSY7G8FOwJbCfeYazEHTA"

console.log("the data returned is: ",await getData("https://sheets.googleapis.com/v4/spreadsheets/"+sheetID+"/values/Sheet1?key="+apiKey))



/*
let d = postData(
    "https://reqres.in/api/users",
    {
        "email": "eve.holt@reqres.in",
        "password": "cityslicka"
    },
    {}

)*/

async function putData(url, body, headers) {
    let param =
    {
        method: "PUT",
        headers: {...headers, "Content-Type": "application/json"},
        body: JSON.stringify(body)
    }

    return await fetch(url, param)
        .then(responce =>{ responce = responce.json();console.log(responce); return responce})
    //.then(r => console.log(r))
}


let ValueRange = {
    "range": "Sheet1!A1:D5",
    "majorDimension": "ROWS",
    "values": [
      ["Item", "Cost", "Stocked", "Ship Date"],
      ["Wheel", "$20.50", "4", "3/1/2016"],
      ["Door", "$15", "2", "3/15/2016"],
      ["Engine", "$100", "1", "3/20/2016"],
      ["Totals", "=SUM(B2:B4)", "=SUM(C2:C4)", "=MAX(D2:D4)"]
    ],
  }

putData("https://sheets.googleapis.com/v4/spreadsheets/"+sheetID+"/values/Sheet1?key="+apiKey ,ValueRange,{})
















/*
// 1. Load the JavaScript client library.
gapi.load('client', init);

async function init() {
  // 2. Initialize the JavaScript client library.
  await gapi.client.init({
    discoveryDocs: ['https://discovery.googleapis.com/$discovery/rest']
  });
  start();
}


/***

var values = [
    [
      "// Cell values ...","asf","333333333"
    ],
    // Additional rows ...
  ];
  var body = {
    values: values
  };
  gapi.client.sheets.spreadsheets.values.update({
     spreadsheetId: spreadsheetId,
     range: range,
     valueInputOption: valueInputOption,
     resource: body
  }).then((response) => {
    var result = response.result;
    console.log(`${result.updatedCells} cells updated.`);
  });
  */