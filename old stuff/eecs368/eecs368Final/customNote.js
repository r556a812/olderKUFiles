var userArrayFront = [];
var userArrayBack = [];
var position = 0;
var side = 1;

function addQInfo() {
	
    if (position == 0) {
    
        userArrayFront.push(document.getElementById("q").value);
    
    }
    else if (position != (userArrayFront.length - 1)) {
    
        userArrayFront.push(document.getElementById("q").value);
    
    }
    else {
    
        position++;
        userArrayFront[position] = (document.getElementById("q").value);
       
    }
}

function addAInfo() {

    userArrayBack[position] = (document.getElementById("a").value);
	
}

function nextCard() {

    if (position >= (userArrayFront.length - 1)) {

        position = 0;
        side=1;
        getInfo();
    
    }
    else {

        position++;
        side=1;
        getInfo();

    }
}


function getInfo() {

    if (side == 1){
    
        side=0;
        document.getElementById("user").innerHTML = userArrayFront[position];
    
    }
    else {
    
        side=1;
        document.getElementById("user").innerHTML = userArrayBack[position];
    
    }
}
