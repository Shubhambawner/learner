let a = 1;

$("#add").on("click", function() {
    console.log("tt")
    $("#list").append(`<li id="item${a}" onClick="changeState(${a})" >Item ${a}  <button id='remove' onClick="removeItem(${a})">remove ${a++}</button></li>`);
})

let changeState = (a)=>{
    $(`div#state`)[0].innerHTML = `<p>${a}</p>`;
}
let removeItem = (a)=>{
    $(`#item${a}`).remove();
}

console.log("script loaded")