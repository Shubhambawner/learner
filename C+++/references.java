/**
 * obj
 */
/**
 * cbj
 */
class cbj extends obj {
    public int c= 2000;
    public int a= 6666; // over riding parameter to be 6666
    void set(int a){
        this.a = a;
    }
    
}

class obj {

    public int a= 10;
    void set(int a){
        this.a = a;
    }
    obj f ; //<-----------just a reference, no object attached to it.
    obj(){
        //this.f= new obj();//<----------------this will attach obj to that reference, but it will lead to stack-overflow-like problem as it will loop on...
    }
}
public class references {
    public static void main(String[] args) {

        //to show multiple references can point same object 
        obj a = new obj();
        obj b = a;
        b.set(100);
        System.out.println(a.a+" "+ a+" "+ b);  //100 obj@3e3abc88 obj@3e3abc88 

        //array head is not pointer
        int[] arr = new int[10];
        System.out.println(arr+" "+ arr[0]);  //[I@776ec8df 0

        obj o ;
        cbj cc = new cbj();
        o = cc;
        o.set(1);System.out.println(cc.a); // both still reference to same object on memory
        System.out.println(cc.c);//can access c via cc, as it is reference of type cbj
        //System.out.println(o.c);//<---------down slicing, so comes the error! 
        System.out.println(o.a);// over riding removed!!
        /*
        cc being asigned to reference o of parent type, 
        cant access child specific parameters via o.
        */
        
    }
}
/*
     references in java a:: pointers in c++

similarities:

     1.both are memory location (of some object )
     2.multiple references/pointers to same obj. are possible 
        [references are scope restricted, i.e obj from one scope cant have reference from other scope]
     3.pointers can have null value, references too can.
     4.both references/pointers can be decleared at compile time, & asigned some object via new operator at runtime.
     5.object slicing applicable as it is, to both,  pointers & references
        (i.e. asigning derived class obj to base class pointer, & then all extra param. & methods r sliced off & ....)
        
differences:

    1. pointers have global scope, can manipulate the object belonging to anywhere.
        but, references are scope specific, i.e. can't pass these references 
        to other methods & modify objects from main methid
    2. de-referencing:
        pointers need to be de-referenced to fetch the data , 
        but references dont need to, its automatic.
    3. pointer arithmatic:
        not possible with references, as the references are not accessible as hexa-decimal numbers 

*/