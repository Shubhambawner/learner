function checkname() {
    var name = document.getElementById("name").value;
    var char_regex = /0-9|!|@|#|\$|%|\^|&|\*|\\|<|>|,|\.|:|;|"|'|{|}/;
    if (name.length<=6 || name.match(char_regex)) {
        document.getElementById("name_error").innerHTML = "must be more that 6 characters";
        if(name.match(char_regex))
        document.getElementById("name_error").innerHTML += ", must not have special characters";
        return false;
    } else {
        document.getElementById("name_error").innerHTML = "";
        return true;
    }
}
function checkemail() {
    var email = document.getElementById("email").value;
    var email_regex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
    if (email.match(email_regex)) {
        document.getElementById("email_error").innerHTML = "";
        return true;
    }
    else {
        document.getElementById("email_error").innerHTML = "must be in the proper format"
        return false;
    }
}
function checkpassword() {
    var password = document.getElementById("password").value;
    document.getElementById("password_error").innerHTML =
        password.length <= 6 ? "must be more that 6 characters" : "";
    return password.length > 6;
}

function submit() {
    var name = document.getElementById("name").value;
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    if (checkname() || checkemail() || checkpassword()) {
        window.alert("Success");
        return true;
    }else{
        window.alert("Please fix the errors: " + checkname() + " " + checkemail() + " " + checkpassword());
        return false;
    }

}