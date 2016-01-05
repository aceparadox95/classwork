function generateFunctionList(){
    var fnArr = [];
    for( var i = 0; i < 3; i++){
        fnArr[i] = function(x){
            return function(){
                console.log(x);
            };
    	}(i);
    }
    return fnArr;
}

var functionArray = generateFunctionList();
functionArray[0](); //Expect 0?
functionArray[1](); //Expect 1?
functionArray[2](); //Expect 2?