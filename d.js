tab = document.querySelectorAll("tr")
g = document.querySelector("div")
dp = []
let i = 0

function toFixedDecimals(num, maxDecimals) {
    var multiplier = Math.pow(10, maxDecimals);
    return Math.floor(num * multiplier) / multiplier
  }

tab.forEach((element)=>{
    if(parseInt((parseInt(element.cells[9].innerText) - parseInt(element.cells[8].innerText)))>0){
        element.innerHTML = null;
        i++
    }else{
        element.cells[11].innerText = 
        toFixedDecimals((((parseInt(element.cells[9].innerText) - parseInt(element.cells[8].innerText))/parseInt(element.cells[8].innerText))*100),3)

        let uij = 
        toFixedDecimals((((parseInt(element.cells[10].innerText) - parseInt(element.cells[9].innerText))/parseInt(element.cells[9].innerText))*100),3)

        element.cells[12].innerText = uij;
        if(uij>0){
            element.style.background = '#edbcae';
        }
        i++
    }
})


dp.forEach(element => {
    console.log(
        
                (parseInt(element.cells[10].innerText) - parseInt(element.cells[9].innerText)) / parseInt(element.cells[8].innerText) * 100
            + ' , ' +

        element.cells[1].innerText+' , '+ element.cells[0].innerText
    )
}

dc = document.querySelectorAll("tr")

dc.forEach(e=>{
    if(e!=undefined && parseInt(e.cells[9].innerText) < parseInt(e.cells[2].innerText)){
        
        e.cells[2].style.background = '#edbcae';
        
    }else{
        
    }
})