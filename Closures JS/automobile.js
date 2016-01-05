/*Automobile object constructor*/
function Automobile( year, make, model, type ){
    this.year = year; //integer (ex. 2001, 1995)
    this.make = make; //string (ex. Honda, Ford)
    this.model = model; //string (ex. Accord, Focus)
    this.type = type; //string (ex. Pickup, SUV)
}
/*Generating array of Automobile objects*/
var automobiles = [ 
    new Automobile(1995, "Honda", "Accord", "Sedan"),
    new Automobile(1990, "Ford", "F-150", "Pickup"),
    new Automobile(2000, "GMC", "Tahoe", "SUV"),
    new Automobile(2010, "Toyota", "Tacoma", "Pickup"),
    new Automobile(2005, "Lotus", "Elise", "Roadster"),
    new Automobile(2008, "Subaru", "Outback", "Wagon")
    ];

/*This function sorts arrays using an arbitrary comparator. You pass it a comparator and an array of objects appropriate for that comparator and it will return a new array which is sorted with the largest object in index 0 and the smallest in the last index*/

//Used this source for the algorithm of the selection sort:
//https://www.nczonline.net/blog/2009/09/08/computer-science-in-javascript-selection-sort/
function sortArr( comparator, array ){
	//Create copy of the original array
	var arrCopy = [];
	for (var i = 0; i < array.length; i++){
		arrCopy[i] = new Automobile(automobiles[i].year, automobiles[i].make, automobiles[i].model, automobiles[i].type);
	}
	function swap(inpArr, autoIndex1, autoIndex2){
		var temp = inpArr[autoIndex1];
		inpArr[autoIndex1] = inpArr[autoIndex2];
		inpArr[autoIndex2] = temp;
	}
	var min = 0;
	for (i=0; i <arrCopy.length; i++){
		min = i;
		for(j = i+1; j < arrCopy.length; j++){
			if(comparator(arrCopy[j],arrCopy[min])){
				min = j;
			}
		}
		if (i != min){
			swap(arrCopy, i, min);
		}
	}
	return arrCopy;
}

/*A comparator takes two arguments and uses some algorithm to compare them. If the first argument is larger or greater than the 2nd it returns true, otherwise it returns false. Here is an example that works on integers*/
function exComparator( int1, int2){
    if (int1 > int2){
        return true;
    } else {
        return false;
    }
}

/*For all comparators if cars are 'tied' according to the comparison rules then the order of those 'tied' cars is not specified and either can come first*/

/*This compares two automobiles based on their year. Newer cars are "greater" than older cars.*/
function yearComparator( auto1, auto2){
    if (auto1.year >= auto2.year){
		return true;
	}
	else{
		return false;
	}
}

/*This compares two automobiles based on their make. It should be case insensitive and makes which are alphabetically earlier in the alphabet are "greater" than ones that come later.*/
function makeComparator( auto1, auto2){
    if(auto1.make[0].toUpperCase() <= auto2.make[0].toUpperCase()){
		return true;
	}
	else{
		return false;
	}
}

/*This compares two automobiles based on their type. The ordering from "greatest" to "least" is as follows: roadster, pickup, suv, wagon, (types not otherwise listed). It should be case insensitive. If two cars are of equal type then the newest one by model year should be considered "greater".*/
function typeComparator(auto1, auto2){
	//Internal function used to assign a type ranking to each type so that eaach vehicle type could be compared numerically
	function typeAssigner(auto){
		if(auto.type.toUpperCase() == "ROADSTER"){return 1;}
		else if(auto.type.toUpperCase() == "PICKUP"){return 2;}
		else if(auto.type.toUpperCase() == "SUV"){return 3;}
		else if(auto.type.toUpperCase() == "WAGON"){return 4;}
		else{return 5;}
	}
	if(typeAssigner(auto1) == typeAssigner(auto2)){
		return yearComparator(auto1, auto2);
	}
	if(typeAssigner(auto1) < typeAssigner(auto2)){
		return true;
	}
	else{
		return false;
	}
}
/*Function prototype for the automobile class to print its own properties*/
Automobile.prototype.logMe = function(logInst){
	if (logInst){
		console.log(this.year + " " + this.make + " " + this.model + " " + this.type);
	}
	else{
		console.log(this.year + " " + this.make + " " + this.model);
	}
}

//Used help from this piazza discussion to figure out the logging of the vehicles:
//https://piazza.com/class/iexadsf9t962en?cid=119

console.log("*****");
console.log("The cars sorted by year are:");
yearSort = sortArr(yearComparator, automobiles);
yearSort.forEach(function(auto){auto.logMe(false)});

console.log('\n');
console.log("The cars sorted by make are:");

makeSort = sortArr(makeComparator, automobiles);
makeSort.forEach(function(auto){auto.logMe(false)});

console.log('\n');
console.log("The cars sorted by type are:");

typeSort = sortArr(typeComparator, automobiles);
typeSort.forEach(function(auto){auto.logMe(true)});
/*Your program should output the following to the console.log, including the opening and closing 5 stars. All values in parenthesis should be replaced with appropriate values. Each line is a seperate call to console.log.

Each line representing a car should be produced via a logMe function. This function should be added to the Automobile class and accept a single boolean argument. If the argument is 'true' then it prints "year make model type" with the year, make, model and type being the values appropriate for the automobile. If the argument is 'false' then the type is ommited and just the "year make model" is logged.


*****
The cars sorted by year are:
(year make model of the 'greatest' car)
(...)
(year make model of the 'least' car)

The cars sorted by make are:
(year make model of the 'greatest' car)
(...)
(year make model of the 'least' car)

The cars sorted by type are:
(year make model type of the 'greatest' car)
(...)
(year make model type of the 'least' car)
*****

As an example of the content in the parenthesis:
1990 Ford F-150 */