

//general class:
class animal{

    //private field
    #owner = null;
    
    //constructor function, must
    //only one constructor allowed!!
    constructor(owner, name){
        this.owner = owner;
        count++;
        //public field:
        this.name = name //here, we see, public fields need not be decleared first
        //much like function based class!
    }

    //static field
    static count = 0;

    //public field function:
    speak(name) {
        console.log(`${this.name} speaking...`);
    }

    //getters!!!
    get owner(){
        return this.#owner;
    }
}

//inline decleration:
let saje = class vehicle{

}

//function decleration:
function machine(owner){
    //constructor-type function that is itsels a class, 
    //will create instances when called!
}

//usage
let cat = new animal('meo')
cat.speak() //meo speaking...

//inheritance:
class man extends animal{
    //iff child declears separate constructor, 
    //must call super first, before accessing this keyword
    constructor(name, IQ){
        super('god',name)
        this.IQ = IQ
    }
    //if child dosent decleare constructor, the child objects will be created using 
    //parent constructor, just the fields will be over-rided
}

