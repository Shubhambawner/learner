
function xlHandler(id, name, email, phone) {
    let hh = document.querySelector(id)
    let query = `${name}&${email}&${phone}`
    let url = `https://script.google.com/macros/s/AKfycbwWfO_055W-u-BdNC4S8V2oJP76Hq9KBjLK3CRjgIWuRjhjB6SJKyusbTiVS4jznFUH/exec?${query}`
    console.log(url)
    hh.onclick = () => {
        fetch(url)
            .then((r) => console.log(r))
    }
}
xlHandler("btn", "shubham", "asdf@sdf.asdf", "234234234");
