function updateText(id, msg){
    var myElement = document.getElementById(id);
    if(myElement){
        myElement.textContent = msg;
    }else{
        console.log("Can not find Element id");
    }
}
updateText("price_01","700$");