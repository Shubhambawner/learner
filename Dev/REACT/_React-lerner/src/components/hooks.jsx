import { useState, useEffect } from "react"

let H = ()=>{
    const [d, setd] = useState(50)

    useEffect(() => {
        console.log('useEffect fired',d)
        
    }, [d])

    return(
        <button onClick={()=>{setd(d+1);}}>{d}</button> 
    )
} 

export default H;