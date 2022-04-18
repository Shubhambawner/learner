let a = 1;

$("body").on("click","#add", function() {
    $(this).parents().first().append(
        `<div id="dynamic">Item ${a++}  
            <input type="text" id="item" name="item" placeholder="Item" ></input>
            <button id='remove' >-</button>  
            <button id='add' >++</button> 
            <button id='addSelected' >+=</button> 
        </div>`);
    someIntentionalBug();
})
$("body").on("click","#addSelected", function() {
    $(this).parents().first().append(
        $("#selected").children().clone().attr("id","dynamic")
    );       
    someIntentionalBug();
})

$("body").on("click", "#remove", function(){$(this).parents().first().remove(); someIntentionalBug();})

$("body").on("click", "div#dynamic", function(){$(`div#selected`)[0].innerHTML = `<div>${$(this).html()}</div>`; someIntentionalBug(); })

$("body").on("click", "input", function(){ someIntentionalBug(); })