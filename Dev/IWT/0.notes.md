## a1 
audio and video tags
## a2 
table, rowspan, collspan
## a3
iframe
## a4
image hotspots: 
```
<img usemap="#mapName">
<map name="#mapName">
    <area shape="poly" cords:>...
    <area>...
    <area>...
```
## a5, a9, a10
html form, js validation of input fields on keydown event
## a6
CSS z-index, background img, link tags...
## a7
JS clock
---> using custom font from local directory
##### a8, a11 trivial
## a12
JS cookies: 
1. format: string 
2. document.cookie = key=value; key=value; key=value;
3. each one has expiry date and path attributes.
4. to set cookie: `document.cookie+= "newCookie=newValue; expiry=new Date().getUTCstring(); path='/path'"`
5. to modify : set cookie of same name and modified value, older will be overwriten
6. to delete: set expiry < Date.now it will automatically get removed
## xml:
. just html with custom tags, can open in brouser
. can use style sheets in similer way with xml
## using XML data via JS
```
xmlhttp = new XMLHttpRequest();
xmlhttp.open("GET", "a13.xml", false);
xmlhttp.send();
xmlDoc = xmlhttp.responseXML;
var x = xmlDoc.getElementsByTagName("CD");
```
## validating XML with dtd file:
specify doctype in beginning as:
```
<!DOCTYPE BOOKDATA SYSTEM "a15.dtd">
```
where bookdata is to be verified against dtd schema at a15.dtd
