console.log("hello")


/**
 * to go to any url and get the data the server sends on that url:
 *
fetch("https://api.github.com/users/shubhambawner")
    .then(Response => Response.json())
    .then((Res) => {//console.log(Res)
        document.getElementById("img").src = Res["avatar_url"]
    });

/**
 * POST request:
 */
let data = {
    "name": "shubhamasdifjlsdjhfujh",
    "salary": "123",
    "age": "23",
    "id": 56
}
let url = "http://dummy.restapiexample.com/api/v1/create"
let param = 
{
    "method":"post",
    "Headers":{
        "content-type":"application/json"
    },
    "body":JSON.stringify(data)
}

fetch(url, param)
.then(r=>r.json())
.then(r=>console.log(r))
