const express = require("express")
const mongoose = require("mongoose")
const bodyParser = require("body-parser")

const app = express()
app.use(bodyParser.json())

app.get('/', (req, res)=>{
    res.json('this is just home page')
})

app.post('/api/user', ( req,res)=>{
    let user = req.body
    res.json(user)
})

const HOST = 'localhost'
const PORT = 3000
app.listen(PORT, HOST, ()=>{
    console.log(`server started at port ${PORT} and host ${HOST}`)
})
