import React from "react"
import ReactDOM from "react-dom"
import App ,{y} from "./App"
//imports:
// 1. import DEFAULT_COMPONENT_NAME form "./name/aderss";
//      this imports the default exported component 
// 2. import { COMPONENT_NAME } form "./name/aderss";
//      this imports set of comonents from file that are NOT exported default


//cant pass multiple elements here!!!!
ReactDOM.render(
    <><App /><h1>{y}</h1></>,
    document.getElementById("groot")
)
//render method needs:
//1. jsx element to be rendered
//2. element on the dom inside which this element will be rendered
