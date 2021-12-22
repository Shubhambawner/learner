import TryIT from "./components/try"
import H from "./components/hooks"

//repo navigation :
// * to access file in same folder: ./
// * to go one folder back: ../
// * have to import jsx files without ".js" extension!!

 function App(props) {
     return(
         <>
         <H />
         <TryIT />
         </>
     )
 }
 const y = 8;

 export {y}
 export default App;
 //exports
 // 1. export { component1, component2 }
 //     this exports component1, component2 in NON default way
 // 2. export default COMPONENT_1 
 //     this exports COMPONENT_1 in default way