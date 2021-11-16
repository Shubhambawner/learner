
//1. finding the dom elements -------------------------------------------
e1 = document.getElementById('i1')
e2 = document.getElementsByClassName('c1') 
// note that array of multiple elements will be stored in e2 !!

//CSS query selectors:
q1 = document.querySelector('h') // tag name
q1 = document.querySelector('.person') // class
q1 = document.querySelector('#i1') // id
//advanced CSS:attribute selectors


//2. modifying the dom elements  -------------------------------------------
e1.innerHTML += '<h1>hello many!!</h1>'
//note that we append string to inner html, not asign string to it
e1.style.color = 'red'
//e1.textContent += 'hello menson!'

//3. classlist: adding css class via classlist----------------------------------------

e1.classList.add('red') // css class red will be added
e1.classList.contains('red') //true
//classlist is an arraylike object, so can be iteratd too
e1.classList.forEach(element => {
    console.log(element)
});
e1.classList.remove('red') // css class red will be added

//4. handling the HTML elements---------------------------------------------------
f1 = document.createElement('div') //create
f1.innerHTML = '<button>f1 hook!</button>' //build
f1.innerHTML += '<h3>this is f1</h3>' //build
e1.appendChild(f1) //append


