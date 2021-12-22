console.log("hello")

fetch("fetchapi.txt")
.then(Response => Responce.text())
.then(Response => console.log(Response));